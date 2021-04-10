#include <wc/core.h>



/* If use of pointers of floating-point addresses is allowed (optimal behavior) */
#ifndef FLT_NOPTR
/* (F32) Absolute */
F32 abf(F32 x) {
	*(I32*)&x &= I32X;
	return x;
}

/* If use of pointers of floating-point addresses is forbidden */
#else
/* (F32) Absolute */
F32 abf(F32 x) {
	return (x < 0.0F) ? -x : x;
}
#endif