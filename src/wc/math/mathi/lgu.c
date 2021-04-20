#include <wc/types.h>

extern U8 lg2u(U32 z);

U8 lgu(U8 x, U32 z) {
	/* Logarithm base change rule */
	return lg2u(z) / lg2u(x);
}