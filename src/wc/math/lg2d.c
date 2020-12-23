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

#define _E			2.71828182845904509079559829842764884233474731445312
#define _PI			3.141592653589793115997963468544185161590576171875
#define _TAU		6.28318530717958623199592693708837032318115234375

/* (F64) Natural logarithm of 2 */
#define LN2			0.69314718055994528622676398299518041312694549560546875



/* Declarations */
extern F64 abd	(F64 x);		/* (F64) Absolute */
/* Stolen from <math/pw.c>*/
extern F64 _pwid(F64 x, U64 y);	/* (F64) Integer exponent exponentiation */



#if NO_I64
/* (F64) Binary Logarithm	*/
F64	lg2d(F64	z) {
	if (z < 0.0) {
		z = abd(z);
		if (z < 1.0) return NND;
		return PND;
	}

	if (z == 0.0)	return NID;
	if (z == 1.0)	return 0.0;
	if (z == 2.0)	return 1.0;
	if (z == _E)	return 1.442695040888963387004650940070860087871551513671875;
	if (z == _PI)	return 1.6514961294723189411115527036599814891815185546875;
	if (z == _TAU)	return 2.6514961294723189411115527036599814891815185546875;

	if (z < 2.0) {
		z = -(z - 1.0);
		F64 l = 69.0;
		F64 h = 0.0;

		for (U8 n = 1; l != h; n++) {
			l = h;
			h += _pwid(z, n) / -n;
		}

		return h / LN2;
	}
	else return lg2d(z / 2.0) + 1.0;
}

#else

/* Macros */

#define VP0D		(U64)0x0000000000000000	/* (F64) Bitwise representation of Positive 0 */
#define VP1D		(U64)0x3F80000000000000	/* (F64) Bitwise representation of Positive 1 */
#define VP2D		(U64)0x4000000000000000	/* (F64) Bitwise representation of Positive 2 */
#define VPND		(U64)0x7FFFFFFFFFFFFFFF	/* (F64) Bitwise representation of Positive NaN */
#define VED			(U64)0x4005BF0A8B145769	/* (F64) Bitwise representation of Euler's constant */
#define VPD			(U64)0x400921FB54442D18	/* (F64) Bitwise representation of Pi constant */
#define VTD			(U64)0x401921FB54442D18	/* (F64) Bitwise representation of Tau constant */

/* (F64) Binary Logarithm	*/
F64	lg2d(F64	z) {
	U64 vz = *(U64*)&z;

	if (vz&I64N) {
		vz &= I64X;
		if (vz<VP1D) return NND;
		return PND;
	}

	if (vz == VP0D)	return NID;
	if (vz == VP1D)	return 0.0;
	if (vz == VP2D)	return 1.0;
	if (vz == VED)	return 1.442695040888963387004650940070860087871551513671875;
	if (vz == VPD)	return 1.6514961294723189411115527036599814891815185546875;
	if (vz == VTD)	return 2.6514961294723189411115527036599814891815185546875;

	if (vz < VP2D) {
		z = -(z - 1.0);
		F64 l = -1.0;
		F64 h = 0.0;

		for (U8 n = 1; l != h; n++) {
			l = h;
			h += _pwid(z,n) / -n;
		}

		return h / LN2;
	}
	else return lg2d(z/2.0) + 1.0;
}
#endif