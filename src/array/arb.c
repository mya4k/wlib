#include <wc/array.h>
#include <wc/error.h>



/* Array Replace Byte */
/* Replace all occurrences of byte `b` with `r` in array `a` */
U8 arb(
	/* const */ void* restrict const a,
	As sa,
	const char b,
	const char r,
	const Asf flags
) {
	U8 rci = 0;

	/* Haystack cannot be NULL */
	if (a) {
		char* _a = a;
		/* ASF_COUNT will replace all needles */
#if WL_ERROR
		if (flags&ASF_COUNT)
			/* Make sure haystack size is specified here */
			if (sa)
				/* Haystack gets offset to the next occurance of the needle, 
				 * until no needles are left. For every needle, 
				 */
				while (( _a = (char*)asb(_a,sa,b,0) )) {
					/* Assign replacement byte to the needle pointers */
					*_a = r;
					/* Incriment haystack pointer and update the haystack size */
					sa -= (_a++)-(const char* const)a; 
					/* Incriment replacement count */
					rci++; 
				}
			else err(arb,ERZERO);
#else
		if (flags&ASF_COUNT && sa) /* Make sure haystack size is specified here */
			/* Haystack gets offset to the next occurance of the needle, 
				 * until no needles are left. For every needle, 
				 */
			while (( _a = (char*)asb(_a,sa,b,0) )) {
					/* Assign replacement byte to the needle pointers */
					*_a = r;
					/* Incriment haystack pointer and update the haystack size */
					sa -= (_a++)-(const char* const)a; 
					/* Incriment replacement count */
					rci++; 
			}
#endif
		/* ASF_REVERSE will replace the last needle, and ASF_NORMAL the first */
		/* Find first/last occurance, replace it, and incriment rci */
		else if (( _a = (char*)asb(_a,sa,b,flags&WL_ASF_REVERSED) )) { *_a = r; rci++; }
	}
	else { err(arb,ERNULL); } /* -Wempty-body braces suggestion */
	
	return rci;
}
