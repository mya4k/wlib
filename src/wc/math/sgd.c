#include <wc/types.h>



extern F64 abd(F64 x);	/* (F64) Absolute */



/* (F64) Sign */
I8 sgd(F64 x) {
	return x / abd(x);
}