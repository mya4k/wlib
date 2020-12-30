/* Includes */
#include <wc/types.h>



/* (F32) Integer exponent power functions */
F32 _pwif(F32 x, U64 y) {
	F32 r = 1.0F;
	
	while (y>1.0F) {
		if (y&1) r *= x;
		x *= x;
		y >>= 1;
	}

	return r * x;
}