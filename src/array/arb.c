#include <wc/array.h>
#include <wc/error.h>



/* Array Replace Byte */
/* Replace all occurrences of byte `b` with `r` in array `a` */
U8 arb(
	const void* restrict const a,
	As sa,
	const char b,
	const char r,
	const Asf flags
) {
/*	Haystack cannot be NULL
 *	check for flags
 *		a)	ASF_COUNT flag will replace every occurance of `b`
 *			1.	Make sure haystack size is specified here
 *			2.	Haystack gets offset to the next occurance of the needle, until
 *				no needles are left
 *			3.	For every needle, 
 *				(i)		assign replacement byte to the needle pointers
 *				(ii)	incriment haystack pointer
 *				(iii)	update the haystack size
 *				(iv)	incriment replacement count/indicator
 *		b)	ASF_REVERSE flag will replace first occurance of `b`
 *		c)	ASF_NORMAL flag will replace last occurance of `b`
 *			1.	Find first/last occurance, replace it, and incriment rci
 */
	U8 rci = 0;

	if (a) {
		char* _a = a;
		/* ASF_COUNT will replace all needles */
#if WL_ERROR
		if (flags&ASF_COUNT)
			if (sa)
				while (( _a = asb(a,sa,b,0) )) {
					*_a = r;
					sa -= (_a++)-(const char* const)a; rci++; 
				}
			else err(arb,ERZERO);
#else
		if (flags&ASF_COUNT && sa)
			while (( a = asb(a,sa,b,0) )) {
				*_a = r;
				sa -= (_a++)-a; rci++;
			}
#endif
		/* ASF_REVERSE will replace the last needle, and ASF_NORMAL the first */
		else if (( _a = asb(a,sa,b,flags&WL_ASF_REVERSED) )) { _a = r; rci++; }
	}
	else { err(arb,ERNULL); } /* -Wempty-body braces suggestion */
	
	return rci;
}
