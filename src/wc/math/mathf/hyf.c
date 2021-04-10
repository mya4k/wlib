#include <wc/types.h>



extern F32 rt2f(F32 z);



F32 hyf(F32 x, F32 y) {
	return rt2f(x*x + y*y);
}