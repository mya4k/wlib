#include <wc/core/bit.h>

I32 rr	(I32 x, U8 n) {
	return sr(x,n) & sl(x, 32-n);
}

I64 rrl	(I64 x, U8 n) {
	return srl(x,n) & sll(x, 64-n);
}