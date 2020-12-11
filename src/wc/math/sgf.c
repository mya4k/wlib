#include <wc/types.h>

I8 sgf(F32 x) {
	U32 bx = *(U32*)&x;
	if (bx&I32X) return 0;
	return bx&I32N ? -1 : 1;
}

#if NO_I64
I8 sgd(F64 x) {
	if (x == 0) return 0;
	return x > 0 ? 1 : -1;
}
#else
I8 sgd(F64 x) {
	U64 bx = *(U64*)&x;
	if (bx&I64X) return 0;
	return bx&I64N ? -1 : 1;
}
#endif