/* Includes */
#include <wc/types.h>



/* Compatibility with MVSC */
/* Better than including the whole <wl/DATA/COMP.h> */
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
#else
#define NIF			-1e39f					/* (F32) Negative Infinity */
#define NNF			-0.0f/0.0f				/* (F32) Negative NaN */
#define PIF			1e39f					/* (F32) Positive Infinity */
#define PNF			(0.0f/0.0f)				/* (F32) Positive NaN */
#endif

#define OD(X)		X&1



/* Function declarations */

extern F32 lg2f	(F32	z);			/* (F32) Binary logarithm					*/
extern F32 pw2f	(F32	y);			/* (F32) Binary exponentiation				*/
extern F32 _pwif(F32	x, U64 y);	/* (F32) Integer exponent exponentiation	*/



/* Static functions */
static F32 _pwf(F32 x, F32 y) {
	/* Bitwise representation */
	U32 vx = *(U32*)&x;
	U32 vy = *(U32*)&y;

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
	if (vy > VPIF)	return PNF;
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