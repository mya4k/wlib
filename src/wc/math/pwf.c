/* Method:
	1.	Store Bitwise representation of base ("x")
		and the exponent ("y"). Nowadays, it's
		better to use more RAM memory in favor of
		speedy execution.
	2.	Check the sign of the exponent:
			if y < 0, x^y = -(x^-y),
			if y = 0, x^y = +1,
			if y > 0, x^y.
	4.	Roll out obvious results:
			x^
			0^y = 0
			1^y = 1
	3.	Figure out whether y can be representented
		by an integer, if so just do exponentiation
		by squaring, otherwise calculate x^y using
		one of logarithmic properties, where
			x^y = 2 ^ (y * log2(x))
*/



/* Includes */
#include <wc/types.h>



/* Macros */

#define VN0F		(U32)0x80000000			/* (F32) Bitwise representation of Negative 0 */
#define VN1F		(U32)0xBF800000			/* (F32) Bitwise representation of Negative 1 */
#define VN2F		(U32)0xC0000000			/* (F32) Bitwise representation of Negative 2 */
#define VN3F		(U32)0xC0400000			/* (F32) Bitwise representation of Negative 3 */
#define VNIF		(U32)0xFF800000			/* (F32) Bitwise representation of Negative Infinity */
#define VNNF		(U32)0xFFFFFFFF			/* (F32) Bitwise representation of Negative NaN */

#define VP0F		(U32)0x00000000			/* (F32) Bitwise representation of Positive 0 */
#define VP1F		(U32)0x3F800000			/* (F32) Bitwise representation of Positive 1 */
#define VP2F		(U32)0x40000000			/* (F32) Bitwise representation of Positive 2 */
#define VP3F		(U32)0x40400000			/* (F32) Bitwise representation of Positive 3 */
#define VPIF		(U32)0x7F800000			/* (F32) Bitwise representation of Positive Infinity */
#define VPNF		(U32)0x7FFFFFFF			/* (F32) Bitwise representation of Positive NaN */

#if !NO_I64
#define VN0D		(U64)0x8000000000000000	/* (F64) Bitwise representation of Negative 0 */
#define VN1D		(U64)0xBF80000000000000	/* (F64) Bitwise representation of Negative 1 */
#define VN2D		(U64)0xC000000000000000	/* (F64) Bitwise representation of Negative 2 */
#define VN3D		(U64)0xC040000000000000	/* (F64) Bitwise representation of Negative 3 */
#define VNID		(U64)0xFF80000000000000	/* (F64) Bitwise representation of Negative Infinity */
#define VNND		(U64)0xFFFFFFFFFFFFFFFF	/* (F64) Bitwise representation of Negative NaN */
#define VP0D		(U64)0x0000000000000000	/* (F64) Bitwise representation of Positive 0 */
#define VP1D		(U64)0x3F80000000000000	/* (F64) Bitwise representation of Positive 1 */
#define VP2D		(U64)0x4000000000000000	/* (F64) Bitwise representation of Positive 2 */
#define VP3D		(U64)0x4040000000000000	/* (F64) Bitwise representation of Positive 3 */
#define VPID		(U64)0x7F80000000000000	/* (F64) Bitwise representation of Positive Infinity */
#define VPND		(U64)0x7FFFFFFFFFFFFFFF	/* (F64) Bitwise representation of Positive NaN */
#endif

#define od(X) X&1							/* Check if X is odd */

#define _LN2F		0.693147182464599609375F
#define _LN2D		0.69314718055994528622676398299518041312694549560546875



/* Extern functions */
/* We need to link them to use them */

extern U32	fc		(I8		y);		/* (U32) fc(y)	*/
extern F32	_pw2f	(F32	y);		/* (F32) pwf(2, y)	*/
extern F64	_pw2d	(F64	y);		/* (F64) pwf(2, y)	*/
extern F32	_lg2f	(F32	z);		/* (F32) lgf(2, z)	*/
extern F64	_lg2d	(F64	z);		/* (F32) lgf(2, z)	*/



/* Static functions */

/* The main body of the power function */
static F32	_pwf(F32 x, F32 y) {
	/* Bitwise representation */
	I32 vx = *(I32*)&x;
	I32 vy = *(I32*)&y;

	/* If x = 0, x^y = 0 */
	if (vx&VP0F) return 0.0F;
	/* If x = 1, x^y = 1 */
	if (vx&VP1F) return 1.0F;
	/* If x = 2, x^y = _pw2f(y) */
	if (vx&VP2F) return _pw2f(y);

	switch (vy) {
	/* If y = +1, x^y = x */
	case VP1F: return x;
	/* If y = +2, x^y = x*x */
	case VP2F: return x * x;
	/* If y = +3, x^y = x*x*x */
	case VP3F: return x * x * x;
	/* If y = +inf, x^y = +inf */
	case VPIF: return 1 / 0;
	/* If y = +nan, x^y = +nan */
	case VPNF: return 0 / 0;
	/* Otherwise */
	default: {
		/* Integer exponent */
		I64 iy = (I64)y;

		/* If y can't be represented by an integer */
		if (y - iy) {
			return _pw2f(y * _lg2f(x));
		}
		/* If y can be represented by an integer */
		else {
			/* Result of calculation */
			F32 r = 1;
			/* Result sign */
			I8 a = 1;

			/* If x < 0: */
			if (vx & VN0F) {
				/* If y is odd, x^y = -(-x)^y */
				/* If y is even, x^y = (-x)^y */
				x = -x;
				if (iy & 1) a = -1;
			}

			/* Calculation by square takes place here */
			for (;;) {
				if (iy & 1) r *= x;
				iy >>= 1;
				if (!iy) break;
				x *= x;
			}

			return a * r;
		}
	}
	}
}

#if !NO_I64
static F64	_pwd(F64 x, U64 y) {
	/* Bitwise representation */
	U64 vx = *(U64*)&x;
	U64 vy = *(U64*)&y;

	/* If x = 0, x^y = 0 */
	if (vx&VP0D) return 0.0F;
	/* If x = 1, x^y = 1 */
	if (vx&VP1D) return 1.0F;
	/* If x = 2, x^y = _pw2f(y) */
	if (vx&VP2D) return _pw2d(y);

	switch (vy) {
	/* If y = +1, x^y = x */
	case VP1D: return x;
	/* If y = +2, x^y = x*x */
	case VP2D: return x * x;
	/* If y = +3, x^y = x*x*x */
	case VP3D: return x * x * x;
	/* If y = +inf, x^y = +inf */
	case VPID: return 1 / 0;
	/* If y = +nan, x^y = +nan */
	case VPND: return 0 / 0;
	/* Otherwise */
	default: {
		/* Integer exponent */

		/* If y can't be represented by an integer */
		if (y - (I64)y) return _pw2d(y * _lg2d(x));
		/* If y can be represented by an integer */
		else return _pwid(x, y);
		}
	}
	}
}
#endif

static F32 _pwif(F32 x, U64 y) {
	/* Result of calculation */
	F64 r = 1;
	/* Result sign */
	I8 a = 1;

	/* If x < 0: */
	if (*(I64*)&x & VN0F) {
		/* If y is odd, x^y = -(-x)^y */
		/* If y is even, x^y = (-x)^y */
		x = -x;
		if (y&1) a = -1;
	}

	/* Calculation by square takes place here */
	for (;;) {
		if (y&1) r *= x;
		y >>= 1;
		if (!y) break;
		x *= x;
	}

	return a * r;
}

#if !NO_I64
static F64 _pwid(F64 x, U64 y) {
	/* Result of calculation */
	F64 r = 1;
	/* Result sign */
	I8 a = 1;

	/* If x < 0: */
	if (*(I64*)&x & VN0F) {
		/* If y is odd, x^y = -(-x)^y */
		/* If y is even, x^y = (-x)^y */
		x = -x;
		if (y&1) a = -1;
	}

	/* Calculation by square takes place here */
	for (;;) {
		if (y&1) r *= x;
		y >>= 1;
		if (!y) break;
		x *= x;
	}

	return a * r;
}
#endif

/* Function Definitions */

/* (F32) 2^y */
F32	_pw2f(F32 y) {
	const U64 iy = (U64)y;
	y = y - iy;

	F32 l = y;
	F32 h = y * _LN2F;

	for (U32 n = 2; ; n++) {
		l = h;
		if (l==h) break;
		h += _pwif(y*_LN2F, n) / fc(n);
	}

	return _pwif(2,iy) * h;
}

#if !NO_I64
/* (F64) 2^y */
F64	_pw2d(F64 y) {
	const U64 iy = (U64)y;
	y = y - iy;

	F64 l = y;
	F64 h = y * _LN2F;

	for (U32 n = 2; ; n++) {
		l = h;
		if (l==h) break;
		h += _pwid(y*_LN2F, n) / fc(n);
	}

	return _pwid(2,iy) * h;
}
#endif

/* (F32) Power */
F32	pwf(F32 x, F32 y) {
	/* If y != 0... */
	if ((*(I32*)&x) & VPNF) {
		/* If y < 0, x^y = -(x^y) */
		if ((*(I32*)&y) & VPNF) return 1.0F / _pwf(x, -y);
		/* If y > 0... */
		else return _pwf(x, y);
	}
	/* If y == 0, x^y = 0 */
	else return 1.0F;
}

/* (F64) Power */
#if !NO_I64
F64	pwd(F64 x, F64 y) {
	/* If y != 0... */
	if ((*(I64*)&x) & VPND) {
		/* If y < 0, x^y = -(x^y) */
		if ((*(I64*)&y) & VPND) return 1.0 / _pwd(x, -y);
		/* If y > 0... */
		else return _pwd(x, y);
	}
	/* If y == 0, x^y = 0 */
	else return 1.0;
}
#endif