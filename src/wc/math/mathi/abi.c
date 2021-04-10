#include <wc/types.h>

I32 abi(I32 x) {
	return (x < 0) ? -x : x;
}