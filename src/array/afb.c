#include <wc/array.h>
#include <wc/error.h>



#if !defined(WL_MAL_IMPLIMENTED) || !defined(mal)
#	include <stdlib.h>
#	define mal malloc
#endif



Bl _afb(const char* a, const char* b, As size) {
#	define A (*(UMax*)a)
#	define B (*(UMax*)b)

	/* Proceed if `a` isn't null and `size` is specified */
	if (likely(a && size)) {
		/* If `b` is non-null, check if `*a` and `*b` are equal */
		if (unlikely(b)) {
			/* XOR each byte to check for equality*/
			while (size >= sizeof(UMax)) {
				if (unlikely(A^B)) return WL_FALSE;
				a += sizeof(UMax);
				b += sizeof(UMax);
				size -= sizeof(UMax);
			}
			/* `(A^B) & (1<<size)-1` masks `size` left-most bits with 0 */
			if (size*=8 && (A^B) & ((1<<size)-1)) return WL_TRUE;
			return WL_FALSE;
		}
		/* If `b` is null, just check if `*b` is true */
		else {
			/* If any byte of `a` is not zero, the array is true */
			while (size >= sizeof(UMax)) {
				if (unlikely(A)) return WL_TRUE;
				a += sizeof(UMax);
				size -= sizeof(UMax);
			}
			/* `A & (1<<size)-1` masks `size` left-most bits with 0 */
			if (size*=8 && A & ((1<<size)-1)) return WL_TRUE;
			return WL_FALSE;
		}
	}

	/* Only try to figure out the cause for failure, if error checking is on */
#	if WL_ERROR
		if (size)	err(afa, ERNULL);
		else		err(afa, ERZERO);
#	endif
	return -1;
}
