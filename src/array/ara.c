#include <wc/array.h>

void ara(
	const void* restrict const a,
	const As sa,
	const void* restrict const b,
	const As sb,
	const void* restrict const r,
	const As sr,
	const Asf flags
) {
	if (a && b && sb) {
		Pt z;
		if (flags&ASF_COUNT) {
			/* Not implimented */
		}
		else {
			if (( z = asa(a,sa,b,sb,flags ))
				if (sb==sr) aas(b,r,sb);
				else {
				}
		}
	}
#if WL_ERROR
	else	if (sb) err(ERZERO);
			else	err(ERNULL);
#else
}
