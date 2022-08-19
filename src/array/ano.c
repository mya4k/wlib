#include <wl/array.h>



/* Copy less than word bytes */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
static void _anosw(
	const char* restrict arr, U32 len, char* restrict res
) {
#	if UMB > 32
		if (unlikely(len&4)) {
			*(U32l*)res = *(U32l*)arr;
			res += 4; arr += 4;
		}
#	endif
		if (unlikely(len&2)) {
			*(U16l*)res = *(U16l*)arr;
			res += 2; arr += 2;
		}
		if (len) {
			*res = *arr;
			res++; arr++;
		}
}



const void* _ano(const char* restrict arr, U32 len, char* restrict res) {
#	if !WL_C_MIXED && !WL_C_STRING
		/**	If declaration and code cannot be mixed and we don't make calls to 
		 *	libc, we should declare it right away, before we test `res`.
		 */
		const void* _res;
#	endif

	/* If NULL is a not valid pointer address (optimal behavior) */
#	if !WL_ALLOW_NULL
		/* Allocate destination if \a res is NULL*/
		if (unlikely(res == NULL)) {
			res = mal(len);
		}
#	endif

#	if WL_C_STRING
		/* If allowed, we make a call to libc's analogous function */
		return memcpy(res, arr, len);
#	else
		/* Preserve `res` for return */
#		if WL_C_MIXED
			/* If mixed declaration and code are allowed, we define this object here*/
			const _Afa_U512* const _res = res;
#		else
			_res = res;
#		endif

		/* If loops are auto-vectorized we should use the primitive 
		implementation and trust the compiler. Otherwise use a smarter method 
		*/
#		if WL_AUTOVECTOR_LOOPS
			/* Just loop every byte */
			while (unlikely(len > 0)) {
				*res = *arr;
				len--; res++; arr++;
			}
#		else
			/* Copy bytes until `res` is aligned */
			Pt rem = (Pt)res % sizeof(UMax);
			if (unlikely(rem > 0)) {
				_anosw(arr, rem, res);
				arr += rem; res += rem; len -= rem;
			}

			/* Copy words */
			while (unlikely(len >= sizeof(UMax))) {
				*(UMax*)res = *(UMax*)arr;
				res += sizeof(UMax);
				arr += sizeof(UMax);
				len -= sizeof(UMax);
			}

			/* Copy the remaining bytes */
			_anosw(arr, len, res);
#		endif
#	endif
}
