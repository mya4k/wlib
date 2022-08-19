#include <wl/array.h>



/* XOR and copy less than word bytes */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
static void _axrsw(
	const char* restrict arr1, 
	const char* restrict arr2, 
	U32 len, 
	char* restrict res
) {
#	if UMB > 32
		if (unlikely(len&4)) {
			*(U32l*)res = *(U32l*)arr1 ^ *(U32l*)arr2;
			res += 4; arr1 += 4; arr2 += 4;
		}
#	endif
		if (unlikely(len&2)) {
			*(U16l*)res = *(U16l*)arr1 ^ *(U16l*)arr2;
			res += 2; arr1 += 2; arr2 += 2;
		}
		if (len) {
			*res = *arr1 ^ *arr2;
			res++; arr1++; arr2++;
		}
}



const void* _axr(
	const char* restrict arr1, 
	const char* restrict arr2, 
	U32 len, 
	char* restrict res
) {
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
				*res = *arr1 ^ *arr2;
				len--; res++; arr++;
			}
#		else
			/* Copy bytes until `res` is aligned */
			Pt rem = (Pt)res % sizeof(UMax);
			if (unlikely(rem > 0)) {
				_axrsw(arr1, arr2, rem, res);
				arr1 += rem; arr2 += rem; res += rem; len -= rem;
			}

			/* Copy words */
			while (unlikely(len >= sizeof(UMax))) {
				*(UMax*)res = *(UMax*)arr1 ^ *(UMax*)arr2;
				res += sizeof(UMax);
				arr1 += sizeof(UMax);
				arr2 += sizeof(UMax);
				len -= sizeof(UMax);
			}

			/* Copy the remaining bytes */
			_axrsw(arr1, arr2, len, res);
#		endif
#	endif
}
