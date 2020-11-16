#include <wc/core/types.h>

inline	U8	_lg2	(U32 z);
inline	U8	_lg2l	(U64 z);
		U8	lg		(U16 x, U32 z);
		U8	lgl		(U32 x, U64 z);
inline	I32	sr		(I32 x, U8 n);
inline	I64	srl		(I64 x, U8 n);

U8	_lg2	(U32 z) {
	U8 i = U8X;
	
	while (z) {
		z = sr(z,1);
		i++;
	}
	
	return i;
}

U8	_lg2l	(U64 z) {
	U8 i = U8X;
	
	while (z) {
		z = srl(z,1);
		i++;
	}
	
	return i;
}

U8 lg		(U16 x, U32 z) {
	return _lg2(z) / _lg2(x);
}

U8 lgl		(U32 x, U64 z) {
	return _lg2l(z) / _lg2l(x);
}