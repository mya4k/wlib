/* Includes */
#include <wc/types.h>



/* (F64) Square Root */
F64 rt2d(F64 z) {
	F64 x0 = 0.0;
	F64 x1 = 1.0;
	
	for (;;) {
		x0 = x1;
		if (x0==x1) break;
		x1 = (x1-x0) / 2.0;
	}
	
	return x1;
}