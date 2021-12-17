#include <wc/array.h>
#include <wc/error.h>



#ifndef mal
#	include <stdlib.h>
#	define mal malloc 
#endif
#ifndef mfr
#	include <stdlib.h>
#	define mfr free
#endif



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
 *		4a. Check if `sr` <= `sb`; we can just assign `r` to `b` if it is. 
 *		Note, when `sr` < `sb`, there will be `sr-sb` rightmost bytes remaining
 *		from `*a`, but you need to treat the array as it has shrunk, and those
 *		bytes are out of its scope. 
 *		4b. Otherwise, create an intermediate buffer `_a`
 *		4c.
 */
	if (a && b && sb) {
		Pt z;
		if (flags&ASF_COUNT) {
			/* Not implimented */
		}
		else {
			if (( z = asa(a,sa,b,sb,flags&ASF_REVERSED) )) {
#if WL_WRITE_UNALLOC
				aas(b,r,sb);
#else
#endif
				if (sr<=sb) aas(b,r,sb);
				else {
			   		const char* _a = mal(sa+sr-sb);
					aas(_a, a, z-(Pt)a); _a += z-(Pt)a;
					aas(_a, a, z); _a += z;
					aas(_a, a, sa-z-(z-(Pt)a));
					mfr((void*)a);
				}
			}
		}
	}
#if WL_ERROR
	else	if (sb) err(ara,ERZERO);
			else	err(ara,ERNULL);
#endif
}
