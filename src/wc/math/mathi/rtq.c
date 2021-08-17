#include <wc/types.h>

U32 rtu(U64 z) {
	U32 x = 1;

	while (x*x != z)
		x = (x + z/x) / 2;

	return x;
}