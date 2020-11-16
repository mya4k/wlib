#include <wc/core/types.h>
#include <wc/math/mathg/parity.h>

inline	I32 rl		(I32	x, U8	y);
inline	I64 rll		(I64	x, U8	y);
		U32 _pw		(U32	x, U8	y);
		U64 _pwl	(U64	x, U8	y);
inline	U32 _pw2	(U8		y);
inline	U64 _pw2l	(U8		y);
		I32 pw		(I32	x, I8	y);
		I64 pwl		(I64	x, I8	y);
		U32 pwu		(U32	x, U8	y);
		U64 pwq		(U64	x, U8	y);
inline	I32 sr		(I32 x, U8 n);
inline	I64 srl		(I64 x, U8 n);

/* Base-2 exponential function */
inline	U32 _pw2	(U8 y) {
	return 2 << (y-1);
}

/* Base-2 exponential function */
inline	U64 _pw2l	(U8 y) {
	return 2 << (y-1);
}

U32	_pw		(U32 x, U8 y) {
	U32 x0 = x;
	U32 s = I32N;

	y = rl(y,1);

	while (s) {
		x *= (y&s ? x : x0);
		s = sr(s,1);
	}

	return x*x0;
}

U64 _pwl	(U64 x, U8 y) {
	U64 x0 = x;
	U64 s = I64N;

	y = rll(y,1);

	while (s) {
		x *= (y&s ? x : x0);
		s = srl(s,1);
	}

	return x*x0;
}

/* Unsigned 32-bit integer power */
U32 pwu	(U32 x, U8 y) {
	/* x^0 = 1 */
	if (y == 0) return 1;
	/* x^1 = x */
	if (y == 1) return x;
	/* x^2 = x*x */
	if (y == 2) return x*x;
	/* 1^y = 1 */
	if (y == 1) return 1;
	/* 2^y */
	if (x == 2) {
		if (y < 64) return _pw2(y);
		else return U32X;
	}

	return _pwu(x,y);
}

/* Unsigned 64-bit integer power */
U64 pwq	(U64 x, U8 y) {
	/* x^0 = 1 */
	if (y == 0) return 1;
	/* x^1 = x */
	if (y == 1) return x;
	/* x^2 = x*x */
	if (y == 2) return x*x;
	/* 1^y = 1 */
	if (y == 1) return 1;
	/* 2^y */
	if (x == 2) {
		if (y < 64) return _pw2(y);
		else return U32X;
	}

	return _pwq(x,y);
}

/* Signed 32-bit integer power */
I32 pw	(I32 x, I8 y) {
	/* x^0 = 1 */
	if (y == 0) return 1;
	/* x^1 = x */
	if (y == 1) return x;
	/* x^2 = x*x */
	if (y == 2) return x*x;
	
	/* Sign of the output */
	I8 a = 1;
	
	/* If x < 0: */
	if (x & I32N) {
		/* If y is odd, x^y = -(-x)^y */
		/* If y is even, x^y = (-x)^y */
		x = -x;
		if (od(y)) a = -1;
	}
	/* If 1^y = 1 */
	if (x == 1)	return 1;
	/* 2^y */
	if (x == 2)	return a * _pw2(y);
	/* If y < 0, x^y = 1/z = 0 */
	if (y < 0)	return 0;
	
	return a * _pw(x,y);
}

/* Signed 32-bit integer power */
I64 pwl	(I64 x, I8 y) {
	/* x^0 = 1 */
	if (y == 0) return 1;
	/* x^1 = x */
	if (y == 1) return x;
	/* x^2 = x*x */
	if (y == 2) return x*x;
	
	/* Sign of the output */
	I8 a = 1;
	
	/* If x < 0: */
	if (x & I64N) {
		/* If y is odd, x^y = -(-x)^y */
		/* If y is even, x^y = (-x)^y */
		x = -x;
		if (od(y)) a = -1;
	}
	/* If 1^y = 1 */
	if (x == 1)	return 1;
	/* 2^y */
	if (x == 2)	return a * _pw2(y);
	/* If y < 0, x^y = 1/z = 0 */
	if (y < 0)	return 0;
	
	return a * _pw(x,y);
}