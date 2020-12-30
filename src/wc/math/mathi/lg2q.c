#include <wc/types.h>

U8 lg2q(U64 z) {
	/*	log2(x) = the position of left-most true bit, counting from the right and from 0:
			10 = 0b1010, the left-most true bit of 10 is has position of 3
	*/

	/* If x != 0: */
	if (z) {
		U8 r = I64B - 1;
		I64 s = I64X;

		while (s) {
			if (z&s) return r;
			else {
				--r;
				s >>= 1;
			}
		}
	}
	/* If z == 0, error */
	else return U64X;
}