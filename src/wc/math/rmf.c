/* Numeric Types */
#include <wc/types.h>



/* Declaration */
extern F32 qtf(F32 x, F32 y);	/* (F32) Quotient */
extern F64 qtd(F64 x, F64 y);	/* (F64) Quotient */



/* (F32) Remainder */
F32 rmf(F32 x, F32 y) {
	return x - qtf(x,y)*y;
}

/* (F64) Remainder */
F64 rmd(F64 x, F64 y) {
	return x - qtd(x,y)*y; 
}