/* Includes */
#include <wc/types.h>



/* (F32) Square Root */
F64 rt2d(F64 z) {
	F64 x0 = 1.0;
	F64 x1 = 666.0;

	while (x0!=x1) {
		x1 = x0;
		x0 = (x0 + z/x0) / 2.0;
	}

	return x0;
}