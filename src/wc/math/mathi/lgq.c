#include <wc/types.h>

U8 lg2q(U64 z);

U8 lgq(U8 x, U64 z) {
	/* Logarithm base change rule */
	return lg2q(z) / lg2q(x);
}