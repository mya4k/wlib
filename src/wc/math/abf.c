#include <wc/types.h>



F32 abf(F32 x) {
	return (x < 0.0F) ? -x : x;
}

#if NO_I64
F64 abd(F64 x) {
	return (x < 0.0) ? -x : x;
}
#else
F64 abd(F64 x) {
	return (*(U64*)&x) & I64X;
}
#endif