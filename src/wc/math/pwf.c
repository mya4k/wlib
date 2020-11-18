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
#define VEF			(U32)0x402DF854			/* (F32) Bitwise representation of Euler's constant */
#define VPF			(U32)0x40490FDBF		/* (F32) Bitwise representation of Pi constant */
#define VTF			(U32)0x40C90FDB			/* (F32) Bitwise representation of Tau constant */

#define NIF			-1.0f/0.0f				/* (F32) Negative Infinity */
#define NNF			-0.0f/0.0f				/* (F32) Negative NaN */
#define PIF			1.0f/0.0f				/* (F32) Positive Infinity */
#define PNF			0.0f/0.0f				/* (F32) Positive NaN */

#define _LN2F		0.693147182464599609375F

#define NID			-1.0/0.0				/* (F64) Negative Infinity */
#define NND			-0.0/0.0				/* (F64) Negative NaN */
#define PID			1.0/0.0					/* (F64) Positive Infinity */
#define PND			0.0/0.0					/* (F64) Positive NaN */

#define od(X) X&1							/* Check if X is odd */



/* Extern functions */
/* We need to link them to use them */

extern U32	fcu		(U8		y);		/* (U32) Factorial	*/
extern F32	_pw2f	(F32	y);		/* (F32) pwf(2, y)	*/
extern F64	_pw2d	(F64	y);		/* (F64) pwf(2, y)	*/
extern F32	_lg2f	(F32	z);		/* (F32) lgf(2, z)	*/
extern F64	_lg2d	(F64	z);		/* (F32) lgf(2, z)	*/



/* Static functions */

/* (F32) The main body of the power function */
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
	case VPIF: return PIF;
	/* If y = +nan, x^y = +nan */
	case VPNF: return PNF;
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

/* (F32) Integer exponent power functions */
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

/* (F32) lgf(2, z)	*/
extern F32	_lg2f(F32	z) {
	U32 vz = *(U32*)&z;

	if (vz & I32X) {
		z = -z;
		vz &= I32X;
	}
	if (vz == VP0F)	return NIF;
	if (vz == VP1F)	return 0.0F;
	if (vz == VP2F)	return 1.0F;
	if (vz == VEF)	return 1.44269502162933349609375F;
	if (vz == VPF)	return 1.6514961719512939453125F;
	if (vz == VTF)	return 2.6514961719512939453125F;

	if (vz < VP2F) {
		const U64 iz = (U64)z;
		const U64 z1 = z - 1;

		F32 l = 0;
		F32 h = _LN2F * z;
		F32 pz = z * z;
		F32 pz1 = z1 * z1;

		for (U32 n = 2; ; n++) {
			l = h;
			if (l == h) break;
			pz *= z;
			pz1 *= z1;
			h += pz1 / (n * _LN2F * pz);
		}

		return h;
	}
	else return _lg2f(z / 2.0F) + 1.0F;
}

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

#if NO_I64
#define _E			2.71828182845904509079559829842764884233474731445312
#define _PI			3.141592653589793115997963468544185161590576171875
#define _TAU		6.28318530717958623199592693708837032318115234375
#else
/* Macros */

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
#define VED			(U32)0x4005BF0A8B145769	/* (F64) Bitwise representation of Euler's constant */
#define VPD			(U32)0x400921FB54442D18	/* (F64) Bitwise representation of Pi constant */
#define VTD			(U32)0x401921FB54442D18	/* (F64) Bitwise representation of Tau constant */



/* Static functions */

/* (F64) The main body of the power function */
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
	case VPID: return PID;
	/* If y = +nan, x^y = +nan */
	case VPND: return PND;
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

/* (F64) Integer exponent power functions */
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



/* (F64) 2^y */
F64	_pw2d(F64 y) {
	const U64 iy = (U64)y;
	y = y - iy;

	F64 l = 0;
	F64 h = y * _LN2F + y;

	for (U32 n = 2; ; n++) {
		l = h;
		if (l == h) break;
		h += _pwid(y * _LN2F, n) / fc(n);
	}

	return _pwid(2, iy) * h;
}

/* (F32) lgd(2, z)	*/
extern F64	_lg2d(F64	z) {
	U64 vz = *(U64*)&z;

	if (vz & I64X) {
		z = -z;
		vz &= I64X;
	}
	if (vz == VP0D)	return NID;
	if (vz == VP1D)	return 0.0;
	if (vz == VP2D)	return 1.0;
	if (vz == VED)	return 1.442695040888963387004650940070860087871551513671875;
	if (vz == VPD)	return 1.6514961294723189411115527036599814891815185546875;
	if (vz == VTD)	return 2.6514961294723189411115527036599814891815185546875;

	if (vz < VP2D) {
		const U64 iz = (U64)z;
		const U64 z1 = z - 1;

		F64 l = 0;
		F64 h = _LN2D * z;
		F64 pz = z * z;
		F64 pz1 = z1 * z1;

		for (U32 n = 2; ; n++) {
			l = h;
			if (l==h) break;
			pz *= z;
			pz1 *= z1;
			h += pz1 / (n * _LN2D * pz);
		}

		return h;
	}
	else return _lg2d(z / 2.0) + 1.0;
}

/* (F64) Power */
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