/* Includes */
#include <wc/types.h>



/* (F32) Square Root */
F32 rt2f(F32 z) {
	F32 x0 = 0.0F;
	F32 x1 = 1.0F;

	for (;;) {
		x0 = x1;
		if (x0==x1) break;
		x1 = (x1-x0) / 2.0F;
	}

	return x1;
}