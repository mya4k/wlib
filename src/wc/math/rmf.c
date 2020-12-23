#include <wc/types.h>



extern F32 qtf(F32 x, F32 y);	/* (F32) Quotient */



/* (F32) Remainder */
F32 rmf(F32 x, F32 y) {
	return x - qtf(x,y) * y;
}