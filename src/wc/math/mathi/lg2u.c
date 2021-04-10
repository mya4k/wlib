#include <wc/types.h>

U8 lg2u(U32 z) {
	/*	log2(x) = the position of left-most true bit, counting from the right and from 0:
			10 = 0b1010, the left-most true bit of 10 is has position of 3
	*/

	/* If z != 0, */
	if (z) {
		U8 r = I32B - 1;
		I32 s = I32X;

		while (s) {
			if (z&s) return r;
			else {
				--r;
				s >>= 1;
			}
		}
	}
	/* If z == 0, error */ 
	return U8X;
}