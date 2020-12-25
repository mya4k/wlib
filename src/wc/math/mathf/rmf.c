#include <wc/types.h>



extern F32 qtf(F32 x, F32 y);	/* (F32) Quotient */



/* (F32) Remainder */
F32 rmf(F32 x, F32 y) {
	if (y<0) return x - y * (qtf(x,y) - 1.0F);
	return x - y * qtf(x,y);
}