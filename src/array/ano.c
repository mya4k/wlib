#include <wl/array.h>



/* Copy less than word bytes efficiently (may read out of bounds) */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
static void _anosw(
	const char* restrict arr, const U32 len, char* restrict res
) {
#	if WL_OPTIMIZE != WL_OPTIMIZE_MEMORY_EXTRA
		const UMax m = ((UMax)1<<(CHB*len)) - 1;
		*(UMax*)res = ((*(UMax*)arr)&m) + ((*(UMax*)res)&(~m));
#	else
		((*(UMax*)res) = ((*(UMax*)arr)&(((UMax)1<<(CHB*len)) - 1)) +
		((*(UMax*)res)&(UMX>>(CHB*len)<<(CHB*len)))))
#	endif
}

/* Copy less than word bytes efficiently (won't read out of bounds) */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
static void _anosws(
	const char* restrict arr, const U32 len, char* restrict res
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
#	if !WL_C_STRING
		/* Preserve `res` for return */
		const char* const _res = res;
#	endif

#	if WL_C_STRING
		/* If allowed, we make a call to libc's analogous function */
		return memcpy(res, arr, len);
#	else
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
			/* If `len` is wordsize, performing a single assignment */
			/* If `len` is less than wordsize, use `_anosws` */
			if (unlikely(len <= sizeof(UMax))) {
				if (likely(len < sizeof(UMax))) {
					goto copyrem;
				}
				else *(UMax*)res = *(UMax*)arr;
			}
			/* If `len` is more than wordsize */
			else {
				/* Copy bytes until `res` is aligned */
				{
					Pt rem = (Pt)res % sizeof(UMax);
					if (unlikely(rem > 0)) {
						_anosw(arr, rem, res);
						arr += rem; res += rem; len -= rem;
					}
				}

				/* Copy words */
				while (unlikely(len >= sizeof(UMax))) {
					*(UMax*)res = *(UMax*)arr;
					res += sizeof(UMax);
					arr += sizeof(UMax);
					len -= sizeof(UMax);
				}

copyrem:
				/* Copy the remaining bytes */
				_anosws(arr, len, res);
			}
#		endif

		return _res;
#	endif
}
