/* Includes */
#include <wc/types.h>



/* Compatibility with MVSC */
/* Better than including the whole <wl/DATA/COMP.h> */
/* Microsoft Visual C++ */
#if !defined(CM_MSC) && defined(_MSC_VER)
#define CM_MSC _MSC_VER
#endif /* Microsoft Visual C++ */



/* Floating-point constants */
#ifdef CM_MSC
#define NID			-1e300*1e300			/* (F64) Negative Infinity */
#define NND			NID*0.0					/* (F64) Negative NaN */
#define PID			1e300*1e300				/* (F64) Positive Infinity */
#define PND			PID*0.0					/* (F64) Positive NaN */
#else
#define NID			-1e309					/* (F64) Negative Infinity */
#define NND			-0.0/0.0				/* (F64) Negative NaN */
#define PID			1e309					/* (F64) Positive Infinity */
#define PND			0.0/0.0					/* (F64) Positive NaN */
#endif



#if NO_I64

/* Macros */

#define _E			2.71828182845904509079559829842764884233474731445312
#define _PI			3.141592653589793115997963468544185161590576171875
#define _TAU		6.28318530717958623199592693708837032318115234375



/* Static functions */

/* (F64) The main body of the power function */
#undef _pwd
static F64	_pwd(F64 x, F64 y) {
	/* If x = 0, x^y = 0 */
	if (x == 0.0)	return 0.0;
	/* If x = 1, x^y = 1 */
	if (x == 1.0)	return 1.0;
	/* If y = 1, x^y = x */
	if (y == 1.0)	return x;
	/* If y = 2, x^y = x*x */
	if (y == 2.0)	return x * x;
	/* If y = 3, x^y = x*x*x */
	if (y == 3.0)	return x * x * x;
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
#undef pwd
F64	pwd(F64 x, F64 y) {
	/* If y == 0... */
	if (y == 0.0)	return 1.0;
	/* If y < 0, x^y = 1/(x^y) */
	if (y < 0.0)	return 1.0 / _pwd(x, -y);
	/* If y < 0, x^y... */
	else			return _pwd(x, y);
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



/* Function declarations */

extern F64 lg2d(F64	z);			/* (F32) Binary logarithm					*/
extern F64 pw2d(F64	y);			/* (F64) Binary exponentiation				*/
extern F64 _pwid(F64	x, U64 y);	/* (F64) Integer exponent exponentiation	*/



/* Static functions */

/* (F64) The main body of the power function */
#undef _pwd
static F64	_pwd(F64 x, F64 y) {
	/* Bitwise representation */
	I64 vx = *(I64*)&x;
	I64 vy = *(I64*)&y;

	/* If x = 0, x^y = 0 */
	if (vx == VP0D)	return 0.0;
	/* If x = 1, x^y = 1 */
	if (vx == VP1D)	return 1.0;

	/* If y = 1, x^y = x */
	if (vy == VP1D)	return x;
	/* If y = 2, x^y = x*x */
	if (vy == VP2D)	return x * x;
	/* If y = 3, x^y = x*x*x */
	if (vy == VP3D)	return x * x * x;
	/* If y = inf, x^y = inf */
	if (vy == VPID)	return PID;
	/* If y = nan, x^y = nan */
	if (vy > VPID)	return PND;
	/* If x = 2, x^y = _pw2f(y) */
	if (vx == VP2D)	return pw2d(y);
	/* If y can't be represented by an integer */
	if (y - (U64)y) return pw2d(y * lg2d(x));
	/* If y can be represented by an integer */
	else return _pwid(x, y);
}



/* (F64) Power */
#undef pwd
F64	pwd(F64 x, F64 y) {
	/* If y != 0... */
	if ((*(U64*)&x) & VPND) {
		/* If y < 0, x^y = -(x^y) */
		if ((*(U64*)&y) & I64N) {
			return 1.0 / _pwd(x, -y);
		}
		/* If y > 0... */
		else {
			return _pwd(x, y);
		}
	}
	/* If y == 0, x^y = 0 */
	else return 1.0;
}

#endif