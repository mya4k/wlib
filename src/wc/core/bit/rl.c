#include <wc/core/bit.h>

I32 rl	(I32 x, U8 n) {
	return sl(x,n) & sr(x, 32-n);
}

I64 rll	(I64 x, U8 n) {
	return sll(x,n) & srl(x, 64-n);
}