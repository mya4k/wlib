#include <wl/array.h>


/* AND and copy less than word bytes efficiently (may read out of bounds) */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
static void _aansw(
	const char* restrict arr1,
	const char* restrict arr2,
	const U32 len, 
	char* restrict res
) {
#	if WL_OPTIMIZE != WL_OPTIMIZE_MEMORY_EXTRA
		const UMax m = ((UMax)1<<(CHB*len)) - 1;
		*(UMax*)res = ((*(UMax*)arr1 & *(UMax*)arr2)&m) + ((*(UMax*)res)&(~m));
#	else
		((*(UMax*)res) = 
		((*(UMax*)arr1 & *(UMax*)arr2)&(((UMax)1<<(CHB*len)) - 1)) 
		+ ((*(UMax*)res)&(UMX>>(CHB*len)<<(CHB*len)))))
#	endif
}

/* AND and copy less than word bytes efficiently (won't read out of bounds) */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
static void _aansws(
	const char* restrict arr1, 
	const char* restrict arr2, 
	const U32 len, 
	char* restrict res
) {
#	if UMB > 32
		if (unlikely(len&4)) {
			*(U32l*)res = *(U32l*)arr1 & *(U32l*)arr2;
			res += 4; arr1 += 4; arr2 += 4;
		}
#	endif
		if (unlikely(len&2)) {
			*(U16l*)res = *(U16l*)arr1 & *(U16l*)arr2;
			res += 2; arr1 += 2; arr2 += 2;
		}
		if (len) {
			*res = *arr1 & *arr2;
			res++; arr1++; arr2++;
		}
}



const void* _aan(
	const char* restrict arr1, 
	const char* restrict arr2, 
	U32 len, 
	char* restrict res
) {
	/* Preserve `res` for return */
	const char* const _res = res;

	/* If loops are auto-vectorized we should use the primitive 
	implementation and trust the compiler. Otherwise use a smarter method 
	*/
#	if WL_AUTOVECTOR_LOOPS
		/* Just loop every byte */
		while (unlikely(len > 0)) {
			*res = *arr1 & *arr2;
			len--; res++; arr++;
		}
#	else
		/* If `len` is wordsize, performing a single assignment */
		/* If `len` is less than wordsize, use `_anosws` */
		if (unlikely(len <= sizeof(UMax))) {
			if (likely(len < sizeof(UMax))) {
				_aansws(arr1, arr2, len, res);
			}
			else *(UMax*)res = *(UMax*)arr1 & *(UMax*)arr2;
		}
		/* If `len` is more than wordsize */
		else {
			/* Copy bytes until `res` is aligned */
			{
				Pt rem = (Pt)res % sizeof(UMax);
				if (unlikely(rem > 0)) {
					_aansw(arr1, arr2, rem, res);
					arr1 += rem; arr2 += rem; res += rem; len -= rem;
				}
			}

			/* Copy words */
			while (unlikely(len >= sizeof(UMax))) {
				*(UMax*)res = *(UMax*)arr1 & *(UMax*)arr2;
				res += sizeof(UMax);
				arr1 += sizeof(UMax);
				arr2 += sizeof(UMax);
				len -= sizeof(UMax);
			}

			/* Copy the remaining bytes */
			_aansws(arr1, arr2, len, res);
		}
#	endif

	return _res;
}
