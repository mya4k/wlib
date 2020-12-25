#include <wc/types.h>



extern F64 rt2d(F64 z);



F32 hyd(F32 x, F32 y) {
	return rt2d(x*x + y*y);
}