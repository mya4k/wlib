#include <wc/types.h>



extern F32 abf(F32 x);	/* (F32) Absolute */



/* If use of pointers of floating-point addresses is allowed (optimal behavior) */
#ifndef FLT_NOPTR
/* (F32) Sign */
F32 sgf(F32 x) {
	U32 bx = *(U32*)&x;
	if (bx &= I32X) 
		return x / *(F32*)&bx;
	return 0;
}

/* If use of pointers of floating-point addresses is forbidden */
#else
/* (F32) Sign */
F32 sgd(F32 x) {
	if (x!=0.0F)
		if (x<0.0F) return -1;
		return 1;
	return 0;
}
#endif