#include <wc/types.h>



#define VP0F		(U32)0x00000000			/* (F32) Bitwise representation of Positive 0 */
#define VP1F		(U32)0x3F800000			/* (F32) Bitwise representation of Positive 1 */
#define VP2F		(U32)0x40000000			/* (F32) Bitwise representation of Positive 2 */
#define VPNF		(U64)0x7FFFFFFF			/* (F32) Bitwise representation of Positive NaN */
#define VEF			(U32)0x402DF854			/* (F32) Bitwise representation of Euler's constant */
#define VPF			(U32)0x40490FDBF		/* (F32) Bitwise representation of Pi constant */
#define VTF			(U32)0x40C90FDB			/* (F32) Bitwise representation of Tau constant */

#ifdef CM_MSC
#define NIF			-1e30f*1e30f			/* (F32) Negative Infinity */
#define NNF			NIF*0.0f				/* (F32) Negative NaN */
#define PIF			1e30f*1e30f				/* (F32) Positive Infinity */
#define PNF			PIF*0.0f				/* (F32) Positive NaN */
#else
#define NIF			-1e39f					/* (F32) Negative Infinity */
#define NNF			-0.0f/0.0f				/* (F32) Negative NaN */
#define PIF			1e39f					/* (F32) Positive Infinity */
#define PNF			(0.0f/0.0f)				/* (F32) Positive NaN */
#endif

/* (F32) Natural logarithm of 2 */
#define LN2F		0.693147182464599609375F



/* Declarations */
extern F32 _pwif(F32 x, U32 y);	/* (F64) Integer exponent exponentiation */



/* (F32) Binary Logarithm	*/
F32	lg2f(F32	z) {
	U32 vz = *(U32*)&z;

	if (vz&I32N) {
		vz &= I32X;
		if (vz<VP1F) return NNF;
		return PNF;
	}

	if (vz==VP0F)	return NIF;
	if (vz==VP1F)	return 0.0F;
	if (vz==VP2F)	return 1.0F;
	if (vz==VEF)	return 1.44269502162933349609375F;
	if (vz==VPF)	return 1.6514961719512939453125F;
	if (vz==VTF)	return 2.6514961719512939453125F;
	if (vz==VTF)	return 2.6514961719512939453125F;

	if (vz<VP2F) {
		z = -(z - 1.0F);
		F32 l = 69.0F;
		F32 h = 0.0F;

		for (U8 n = 1; l!=h; n++) {
			l = h;
			h += _pwif(z,n) / -n;
		}

		return h / LN2F;
	}
	else return lg2f(z/2.0F) + 1.0F;
}