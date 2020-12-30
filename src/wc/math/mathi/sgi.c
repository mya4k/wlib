#include <wc/types.h>

I8 sgi(I32 x) {
	return (x&I32N) ? -1 : (x?1:0);
}