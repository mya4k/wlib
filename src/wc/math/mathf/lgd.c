/* Includes */
#include <wc/types.h>



/* Macros */
#ifdef CM_MSC
#define NID			-1e300*1e300			/* (F64) Negative Infinity */
#define NND			NID*0.0					/* (F64) Negative NaN */
#define PID			-1e300*1e300			/* (F64) Positive Infinity */
#define PND			PID*0.0					/* (F64) Positive NaN */
#else
#define NID			-1e309					/* (F64) Negative Infinity */
#define NND			-0.0/0.0				/* (F64) Negative NaN */
#define PID			-1e309					/* (F64) Positive Infinity */
#define PND			0.0/0.0					/* (F64) Positive NaN */
#endif

/* (F64) Natural logarithm of 2 */
#define LN2			0.69314718055994528622676398299518041312694549560546875



/* Declarations */
extern F64 lg2d	(F64 z);		/* (F64) Binary Logarithm */
extern F64 _pwid(F64 x, U64 y);	/* (F64) Integer exponent exponentiation */



#if NO_I64
/* Macros */
#define _E			2.71828182845904509079559829842764884233474731445312
#define _PI			3.141592653589793115997963468544185161590576171875
#define _TAU		6.28318530717958623199592693708837032318115234375



/* Declarations */
extern F64 abd(F64 x);		/* (F64) Absolute */



/* (F64) Logarithm			*/
F64	lgd(F64	x, F64 z) {
	if (z < 0.0) {
		z = abd(z);
		if (z < 1.0) return NND;
		return PND;
	}

	if (z == 0.0)	return NID;
	if (z == 1.0)	return 0.0;
	if (z == PID)	return PID;
	if (z > PID)	return PND;
	if (x == z)		return 1.0;
	if (x == 2.0)	return lg2d(z);

	return lg2d(z) / lg2d(x);
}

#else
/* Macros */

#define VP0D		(U64)0x0000000000000000	/* (F64) Bitwise representation of Positive 0 */
#define VP1D		(U64)0x3F80000000000000	/* (F64) Bitwise representation of Positive 1 */
#define VP2D		(U64)0x4000000000000000	/* (F64) Bitwise representation of Positive 2 */
#define VPID		(U64)0x7F80000000000000	/* (F64) Bitwise representation of Positive Infinity */
#define VPND		(U64)0x7FFFFFFFFFFFFFFF	/* (F64) Bitwise representation of Positive NaN */



/* (F64) Logarithm			*/
F64	lgd(F64	x, F64 z) {
	U64 vx, vz;

	vx = *(U64*)&x;
	vz = *(U64*)&z;

	if (vz&I64N) {
		vz &= I64X;
		if (vz<VP1D) return NND;
		return PND;
	}

	if (vz == VP0D)	return NID;
	if (vz == VP1D)	return 0.0;
	if (vz == VPID)	return PID;
	if (vz > VPID)	return PND;
	if (vx == vz)	return 1.0;
	if (vx == VP2D)	return lg2d(z);

	return lg2d(z) / lg2d(x);
}

#endif