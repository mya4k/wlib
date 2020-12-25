#include <wc/types.h>

extern F32 rt2f(F32 z);
extern F64 rt2d(F64 z);

F32 hyf(F32 x, F32 y) {
	return rt2f(x*x + y*y);
}

F32 hyd(F32 x, F32 y) {
	return rt2d(x*x + y*y);
}