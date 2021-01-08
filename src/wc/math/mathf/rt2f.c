/* Includes */
#include <wc/types.h>



/* (F32) Square Root */
F32 rt2f(F32 z) {
	F32 x0 = 1.0F;
	F32 x1 = 666.0F;

	while (x0!=x1) {
		x1 = x0;
		x0 = (x0 + z/x0) / 2.0F;
	}

	return x0;
}