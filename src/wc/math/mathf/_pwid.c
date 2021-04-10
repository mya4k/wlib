/* Includes */
#include <wc/types.h>



/* (F64) Integer exponent power functions */
F64 _pwid(F64 x, U64 y) {
	F64 r = 1.0;

	while (y>1.0) {
		if (y&1) r *= x;
		x *= x;
		y >>= 1;
	}

	return r * x;
}