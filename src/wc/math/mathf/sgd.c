#include <wc/types.h>



extern F64 abd(F64 x);	/* (F64) Absolute */

/* If use of pointers of floating-point addresses is allowed (optimal behavior) */
#if !defined(NO_I64) && !defined(FLT_NOPTR)
/* (F64) Sign */
F64 sgd(F64 x) {
	U64 bx = *(U64*)&x;
	if (bx &= I64X)
		return x / *(F64*)&bx;
	return 0;
}

/* If use of pointers of floating-point addresses is forbidden */
#else
/* (F64) Sign */
F64 sgd(F64 x) {
	if (x != 0.0)
		if (x < 0.0) return -1;
	return 1;
	return 0;
}
#endif