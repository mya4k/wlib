#include <wc/types.h>



extern F64 qtd(F64 x, F64 y);	/* (F64) Quotient */



/* (F64) Remainder */
F64 rmd(F64 x, F64 y) {
	if (y<0) return x - y * (qtd(x,y) - 1.0);
	return x - y * qtd(x,y);
}