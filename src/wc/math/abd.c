#include <wl/DATA/CONF.h>
#include <wc/types.h>



/*	If use of pointers of floating-point addresses is allowed 
	or 64-bit integer type is not supported */
#if NO_I64 || defined(FLT_NOPTR)
/* (F64) Absolute */
F64 abd(F64 x) {
	return (x < 0.0) ? -x : x;
}

/* Otherwise (optimal behavior) */
#else
/* (F64) Absolute */
F64 abd(F64 x) {
	return (*(U64*)&x) & I64X;
}
#endif