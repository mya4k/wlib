#include <wc/array.h>
#include <wc/error.h>



/* Array Replace Bit */
/* Replace all occurrences of byte `b` with `r` in array `a` */
void arb(
	const void* restrict const a,
	const As sa,
	const char b,
	const char r,
	const Asf flags
) {
	if (a) {
		Pt z;
		/* ASF_COUNT will replace all needles */
#if WL_ERROR
		if (flags&ASF_COUNT)
			if (sa)
				while (( z = asb(a,sa,b,0) )) {
					*(char*)z = r; z++;
				}
			else err(arb,ERZERO);
#else
		if (flags&ASF_COUNT && sa)
			while (( z = asb(a,sa,b,0) )) {
				*(char*)z = r; z++;
			}
#endif
		/* ASF_REVERSE will replace the last needle, and ASF_NORMAL the first */
		else if (( z = asb(a,sa,b,flags&WL_ASF_REVERSED) )) *(char*)z = r;
	}
	else err(arb,ERNULL);
}
