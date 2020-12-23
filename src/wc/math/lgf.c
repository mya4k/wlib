/* Includes */
#include <wc/types.h>



/* Macros */

#define VP0F		(U32)0x00000000			/* (F32) Bitwise representation of Positive 0 */
#define VP1F		(U32)0x3F800000			/* (F32) Bitwise representation of Positive 1 */
#define VP2F		(U32)0x40000000			/* (F32) Bitwise representation of Positive 2 */
#define VPIF		(U64)0x7F800000			/* (F64) Bitwise representation of Positive Infinity */
#define VPNF		(U64)0x7FFFFFFF			/* (F64) Bitwise representation of Positive NaN */
#define VEF			(U32)0x402DF854			/* (F32) Bitwise representation of Euler's constant */
#define VPF			(U32)0x40490FDBF		/* (F32) Bitwise representation of Pi constant */
#define VTF			(U32)0x40C90FDB			/* (F32) Bitwise representation of Tau constant */

#ifdef CM_MSC
#define NIF			-1e30f*1e30f			/* (F32) Negative Infinity */
#define NNF			NIF*0.0f				/* (F32) Negative NaN */
#define PIF			1e30f*1e30f				/* (F32) Positive Infinity */
#define PNF			PIF*0.0f				/* (F32) Positive NaN */
#define NID			-1e300*1e300			/* (F64) Negative Infinity */
#define NND			NID*0.0					/* (F64) Negative NaN */
#define PID			-1e300*1e300			/* (F64) Positive Infinity */
#define PND			PID*0.0					/* (F64) Positive NaN */
#else
#define NIF			-1e39f					/* (F32) Negative Infinity */
#define NNF			-0.0f/0.0f				/* (F32) Negative NaN */
#define PIF			1e39f					/* (F32) Positive Infinity */
#define PNF			(0.0f/0.0f)				/* (F32) Positive NaN */
#define NID			-1e309					/* (F64) Negative Infinity */
#define NND			-0.0/0.0				/* (F64) Negative NaN */
#define PID			-1e309					/* (F64) Positive Infinity */
#define PND			0.0/0.0					/* (F64) Positive NaN */
#endif

/* (F32) Natural logarithm of 2 */
#define LN2F		0.693147182464599609375F
/* (F64) Natural logarithm of 2 */
#define LN2			0.69314718055994528622676398299518041312694549560546875



/* Declarations */
F32 abf (F32 x);
F64 abd	(F64 x);

/* Stolen from <math/pwf.c> */
extern F32 _pwif(F32 x, U64 y);	/* (F32) Integer exponent exponentiation */
extern F64 _pwid(F64 x, U64 y);	/* (F64) Integer exponent exponentiation */



/* Function definitions */

/* (F32) Binary Logarithm	*/
F32	lg2f(F32	z) {
	z = abf(z);
	U32 vz = *(U32*)&z;

	if (vz == VP0F)	return NIF;
	if (vz == VP1F)	return 0.0F;
	if (vz == VP2F)	return 1.0F;
	if (vz == VEF)	return 1.44269502162933349609375F;
	if (vz == VPF)	return 1.6514961719512939453125F;
	if (vz == VTF)	return 2.6514961719512939453125F;

	if (vz < VP2F) {
		z = -(z-1.0F);
		F32 l = -1.0F;
		F32 h = 0.0F;
		
		for (U8 n = 1; l != h; n++) {
			l = h;
			h += _pwif(z,n) / -n;
		}

		return h / LN2F;
	}
	else return lg2f(z/2.0F) + 1.0F;
}

/* (F32) Logarithm			*/
F32	lgf(F32	x, F32 z) {
	U32 vx, vz;
	
	x = abf(x);
	z = abf(z);
	vx = *(U32*)&x;
	vz = *(U32*)&z;

	if (vz==VP1F)	return 0.0F;
	if (vz==VP0F)	return NIF;
	if (vz==VP1F)	return 0.0f;
	if (vz == VPIF)	return PIF;
	if (vz > VPIF)	return PNF;
	if (vx==vz)		return 1.0f;
	if (vx == VP2F)	return lg2f(z);
	 
	return lg2f(z) / lg2f(x);
}



#if NO_I64
/* Macros */

#define _E			2.71828182845904509079559829842764884233474731445312
#define _PI			3.141592653589793115997963468544185161590576171875
#define _TAU		6.28318530717958623199592693708837032318115234375



/* (F64) Binary Logarithm	*/
F64	lg2d(F64	z) {

	z = abf(z);

	if (z==0.0)	return NID;
	if (z==1.0)	return 0.0;
	if (z==2.0)	return 1.0;
	if (z==_E)	return 1.442695040888963387004650940070860087871551513671875;
	if (z==_PI)	return 1.6514961294723189411115527036599814891815185546875;
	if (z==_TAU)	return 2.6514961294723189411115527036599814891815185546875;

	if (z<2.0) {
		z = -(z-1.0);
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


/* (F64) Logarithm			*/
F64	lgd(F64	x, F64 z) {
	x = abf(x);
	z = abd(z);

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
#define VED			(U32)0x4005BF0A8B145769	/* (F64) Bitwise representation of Euler's constant */
#define VPD			(U32)0x400921FB54442D18	/* (F64) Bitwise representation of Pi constant */
#define VTD			(U32)0x401921FB54442D18	/* (F64) Bitwise representation of Tau constant */


/* (F64) Binary Logarithm	*/
F64	lg2d(F64	z) {
	z = abf(z);
	U64 vz = *(U64*)&z;

	if (vz == VP0D)	return NID;
	if (vz == VP1D)	return 0.0;
	if (vz == VP2D)	return 1.0;
	if (vz == VED)	return 1.442695040888963387004650940070860087871551513671875;
	if (vz == VPD)	return 1.6514961294723189411115527036599814891815185546875;
	if (vz == VTD)	return 2.6514961294723189411115527036599814891815185546875;

	if (vz < VP2D) {
		z = -(z-1.0);
		F64 l = -1.0;
		F64 h = 0.0;

		for (U8 n = 1; l != h; n++) {
			l = h;
			h += _pwid(z,n) / -n;
		}

		return h / LN2;
	}
	else return lg2d(z / 2.0) + 1.0;
}


/* (F64) Logarithm			*/
F64	lgd(F64	x, F64 z) {
	U64 vx, vz;

	x = abd(x);
	z = abd(z);
	vx = *(U64*)&x;
	vz = *(U64*)&z;


	if (vz == VP0D)	return NID;
	if (vz == VP1D)	return 0.0;
	if (vz == VPID)	return PID;
	if (vz > VPID)	return PND;
	if (vx == vz)	return 1.0;
	if (vx == VP2F)	return lg2f(z);

	return lg2d(z) / lg2d(x);
}

#endif