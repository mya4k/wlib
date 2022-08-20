#include <wl/array.h>



/* Check less than word bytes */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
static Bl _anolsw(
	const char* restrict arr, const U8 len
) {
#	if UMB > 32
		if (unlikely(len&4)) {
			if (likely(*(U32l*)arr)) return TRUE;
			arr += 4;
		}
#	endif
	if (unlikely(len&2)) {
		if (likely(*(U16l*)arr)) return TRUE;
		arr += 2;
	}
	if (unlikely(len)) {
		if (likely(*arr)) return TRUE;
		arr += 1;
	}
	return FALSE;
}



Bl _anol(const char* restrict arr, U32 len) {
	/* If loops are auto-vectorized we should use the primitive 
	implementation and trust the compiler. Otherwise use a smarter method 
	*/
#	if WL_AUTOVECTOR_LOOPS
		/* Just loop every byte */
		while (unlikely(len > 0)) {
			*res = *arr;
			len--; res++; arr++;
		}
#	else
		/* Check byte until `arr` is aligned */
		Pt rem = (Pt)arr % sizeof(UMax);
		if (unlikely(rem > 0)) {
			if (likely(_anolsw(arr, rem))) return TRUE;
			arr += rem; len -= rem;
		}

		/* Check words */
		while (unlikely(len >= sizeof(UMax))) {
			if (likely(*(UMax*)arr)) return TRUE;
			arr += sizeof(UMax);
			len -= sizeof(UMax);
		}

		/* Copy the remaining bytes */
		if (likely(_anosw(arr, len))) return TRUE;

		return FALSE;
#	endif
}
