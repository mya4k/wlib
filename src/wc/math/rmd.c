#include <wc/types.h>



extern F64 qtd(F64 x, F64 y);	/* (F64) Quotient */



/* (F64) Remainder */
F64 rmd(F64 x, F64 y) {
	return x - qtd(x,y) * y;
}