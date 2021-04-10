#include <wc/types.h>

I8 sgl(I64 x) {
	return (x&I64N) ? -1 : (x?1:0);
}