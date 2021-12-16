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
/*	1. Make sure there's a haystack and a needle, otherwise return ERNULL.
 *	2. Make sure size of a haystack is specified, otherwise return ERZERO.
 *	3. If ASF_COUNT flag is set, replace every occurance of `*b` with `*r`:
 *	4. Else, get the pointer to the first/last occurance of `*b`
 *		4a. Check if `sb` and `sr` are equal; we can just assign `r` to
 *		`b` if they are.
 *		4b. Otherwise, split `a` into 3 pieces 
 */
	if (a && b && sb) {
		Pt z;
		if (flags&ASF_COUNT) {
			/* Not implimented */
		}
		else {
			if (( z = asa(a,sa,b,sb,flags&ASF_REVERSED) )
				if (sb==sr) aas(b,r,sb);
				else {:
					
				}
		}
	}
#if WL_ERROR
	else	if (sb) err(ERZERO);
			else	err(ERNULL);
#else
}
