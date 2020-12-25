/* Includes */
#include <wc/types.h>



/* Compatibility with MVSC */
/* Better than including the whole <wl/DATA/COMP.h>
/* Microsoft Visual C++ */
#if !defined(CM_MSC) && defined(_MSC_VER)
#define CM_MSC _MSC_VER
#endif /* Microsoft Visual C++ */



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
#define VPF			(U32)0x40490FDB			/* (F32) Bitwise representation of Pi constant */
#define VTF			(U32)0x40C90FDB			/* (F32) Bitwise representation of Tau constant */

/* Floating-point constants */
#ifdef CM_MSC
#define NIF			-1e30f*1e30f			/* (F32) Negative Infinity */
#define NNF			NIF*0.0f				/* (F32) Negative NaN */
#define PIF			1e30f*1e30f				/* (F32) Positive Infinity */
#define PNF			PIF*0.0f				/* (F32) Positive NaN */
#define NID			-1e300*1e300			/* (F64) Negative Infinity */
#define NND			NID*0.0					/* (F64) Negative NaN */
#define PID			1e300*1e300				/* (F64) Positive Infinity */
#define PND			PID*0.0					/* (F64) Positive NaN */
#else
#define NIF			-1e39f					/* (F32) Negative Infinity */
#define NNF			-0.0f/0.0f				/* (F32) Negative NaN */
#define PIF			1e39f					/* (F32) Positive Infinity */
#define PNF			(0.0f/0.0f)				/* (F32) Positive NaN */
#define NID			-1e309					/* (F64) Negative Infinity */
#define NND			-0.0/0.0				/* (F64) Negative NaN */
#define PID			1e309					/* (F64) Positive Infinity */
#define PND			0.0/0.0					/* (F64) Positive NaN */
#endif

/* (F32) Natural logarithm of 2 */
#define LN2F		0.693147182464599609375F
/* (F64) Natural logarithm of 2 */
#define LN2			0.69314718055994528622676398299518041312694549560546875

#define OD(X)		X&1



/* Function declarations */

extern U64 fcq	(U8		n);			/*	(U64) Factorial							*/
extern F32 lg2f	(F32	z);			/* (F32) Binary logarithm					*/
extern F64 lg2d	(F64	z);			/* (F32) Binary logarithm					*/
extern F32 pw2f	(F32	y);			/* (F32) Binary exponentiation				*/
extern F64 pw2d	(F64	y);			/* (F64) Binary exponentiation				*/
extern F32 _pwif(F32	x, U64 y);	/* (F32) Integer exponent exponentiation	*/
extern F64 _pwid(F64	x, U64 y);	/* (F64) Integer exponent exponentiation	*/



/* Static functions */
static F32 _pwf(F32 x, F32 y) {
	/* Bitwise representation */
	I32 vx = *(I32*)&x;
	I32 vy = *(I32*)&y;

	/* If x = 0, x^y = 0 */
	if (vx==VP0F)	return 0.0F;
	/* If x = 1, x^y = 1 */
	if (vx==VP1F)	return 1.0F;

	/* If y = 1, x^y = x */
	if (vy==VP1F)	return x;
	/* If y = 2, x^y = x*x */
	if (vy==VP2F)	return x * x;
	/* If y = 3, x^y = x*x*x */
	if (vy==VP3F)	return x * x * x;
	/* If y = inf, x^y = inf */
	if (vy==VPIF)	return PIF;
	/* If y = nan, x^y = nan */
	if (vy==VPNF)	return PNF;
	/* If x = 2, x^y = _pw2f(y) */
	if (vx==VP2F)	return pw2f(y);
	/* If y can't be represented by an integer */
	if (y - (U64)y) return pw2f(y * lg2f(x));
	/* If y can be represented by an integer */
	else return _pwif(x, y);
}


/* (F32) Power */
F32	pwf(F32 x, F32 y) {
	/* If y != 0... */
	if ((*(U32*)&x) & VPNF) {
		/* If y < 0, x^y = -(x^y) */
		if ((*(U32*)&y) & I32N) {
			return 1.0F / _pwf(x, -y);
		}
		/* If y > 0... */
		else {
			return _pwf(x, y);
		}
	}
	/* If y == 0, x^y = 0 */
	else return 1.0F;
}



#if NO_I64

/* Macros */

#define _E			2.71828182845904509079559829842764884233474731445312
#define _PI			3.141592653589793115997963468544185161590576171875
#define _TAU		6.28318530717958623199592693708837032318115234375



/* Static functions */

/* (F64) The main body of the power function */
static F64	_pwd(F64 x, F64 y) {
	/* If x = 0, x^y = 0 */
	if (x == 0.0)	return 0.0;
	/* If x = 1, x^y = 1 */
	if (x == 1.0)	return 1.0;
	/* If y = 1, x^y = x */
	if (y == 1.0)	return x;
	/* If y = 2, x^y = x*x */
	if (y == 2.0)	return x*x;
	/* If y = 3, x^y = x*x*x */
	if (y == 3.0)	return x*x*x;
	/* If y = inf, x^y = inf */
	if (y == PID)	return PID;
	/* If y = +nan, x^y = +nan */
	if (y == PND)	return PND;
	/* If x = 2, x^y = _pw2f(y) */
	if (x == 2.0)	return pw2d(y);
	/* If y can't be represented by an integer */
	if (y - (U64)y) return pw2d(y * lg2d(x));
	/* If y can be represented by an integer */
	else return _pwid(x, y);
}



/* (F64) Power */
F64	pwd(F64 x, F64 y) {
	/* If y == 0... */
	if (y == 0.0)	return 1.0;
	/* If y < 0, x^y = 1/(x^y) */
	if (y < 0.0)	return 1.0 / _pwd(x, -y);
	/* If y < 0, x^y... */
	else			return _pwd(x,y);
}



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
#define VED			(U64)0x4005BF0A8B145769	/* (F64) Bitwise representation of Euler's constant */
#define VPD			(U64)0x400921FB54442D18	/* (F64) Bitwise representation of Pi constant */
#define VTD			(U64)0x401921FB54442D18	/* (F64) Bitwise representation of Tau constant */



/* Static functions */

/* (F64) The main body of the power function */
static F64	_pwd(F64 x, U64 y) {
	/* Bitwise representation */
	U64 vx = *(U64*)&x;
	U64 vy = *(U64*)&y;

	/* If x = 0, x^y = 0 */
	if (vx==VP0D)	return 0.0;
	/* If x = 1, x^y = 1 */
	if (vx==VP1D)	return 1.0;

	/* If y = 1, x^y = x */
	if (vy==VP1D)	return x;
	/* If y = 2, x^y = x*x */
	if (vy==VP2D)	return x * x;
	/* If y = 3, x^y = x*x*x */
	if (vy==VP3D)	return x * x * x;
	/* If y = inf, x^y = inf */
	if (vy==VPID)	return PID;
	/* If y = nan, x^y = nan */
	if (vy>VPID)	return PND;
	/* If x = 2, x^y = _pw2f(y) */
	if (vx==VP2F)	return pw2d(y);
	/* If y can't be represented by an integer */
	if (y - (U64)y) return pw2d(y * lg2d(x));
	/* If y can be represented by an integer */
	else return _pwid(x, y);
}

/* (F64) Power */
F64	pwd(F64 x, F64 y) {
	/* If y != 0... */
	if ((*(U32*)&x) & VPNF) {
		/* If y < 0, x^y = -(x^y) */
		if ((*(U32*)&y) & I32N) {
			return 1.0F / _pwd(x, -y);
		}
		/* If y > 0... */
		else {
			return _pwd(x, y);
		}
	}
	/* If y == 0, x^y = 0 */
	else return 1.0F;
}

#endif