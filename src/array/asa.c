#include <wc/array.h>



Pt asa(
	const void* restrict const	_a,
	As							_sa,
	const void*					b,
	As							sb,
	const Asf					flags
) {
	As c = 0;	/* Counter */

	if (_a && _sa && b && sb) {
		Pt a = (Pt)_a;	/* Preserve initial `a` */
		As sa = _sa;	/* Preserve initial `sa` */

		/* Search for first/last occurrence of *b's first byte (we'll refer to
		 * as "b[0]").
		 * If b[0] was not found anywhere in `*a`, return NULL;
		 * Else check `sb-1` next bytes of `*a` whether they are equal to other
		 * bytes of `*b`
		 */
		while ( (a = asb((const void* const)a,sa,*(const char*)b,flags&1)) && sa ) {
			if ( aeq( (const void*)(a+1), (const void*)(((Pt)b)+1), sb-1 ) ) {
				/* Then the algorithm either returns or increments the counter */
				if (flags&WL_ASF_COUNT) c++;
				else return a - (Pt)_a*(Bl)(flags&2);
			}
			a++;	/* Move onto the next index, to search for the next occurrence */
			/* In count mode we need to recalculate `sa`, as we move on 
			 * with the string 
			 */
			( sa >= a-(Pt)_a ) ? ( sa = _sa - (a-(Pt)_a) ) : ( sa = 0 );
		}
	}
	
	return c;
}
