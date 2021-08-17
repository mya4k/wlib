#include <wc/types.h>

U16 rtu(U32 z) {
	U16 x = 1;

	while (x*x != z)
		x = (x + z/x) / 2;

	return x;
}