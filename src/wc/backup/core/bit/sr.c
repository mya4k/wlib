#include <wc/core/bit.h>

inline I32 sr	(I64 x, U8 n) {
	return (x & I32N) ? ((U32)x >> n) : (x >> n);
}

inline I64 srl	(I64 x, U8 n) {
	return (x & I64N) ? ((U64)x >> n) : (x >> n);
}