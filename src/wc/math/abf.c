#include <wl/DATA/CONF.h>
#include <wc/types.h>



/* If use of pointers of floating-point addresses is allowed (optimal behavior) */
#ifndef FLT_NOPTR
/* (F32) Absolute */
F32 abf(F32 x) {
	return (*(U32*)&x) & I32X;
}

/* If use of pointers of floating-point addresses is forbidden */
#else
/* (F32) Absolute */
F32 abf(F32 x) {
	return (x < 0.0F) ? -x : x;
}
#endif