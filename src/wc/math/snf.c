#include <wc/types.h>



/* Macros */
#define VQ0F		(U32)0x00000000			/* (F32) Bitwise representation of Positive 0 */
#define VQ1F		(U32)0x3E800000			/* (F32) Bitwise representation of Positive 1/4 (0.25) */
#define VQ2F		(U32)0x3F000000			/* (F32) Bitwise representation of Positive 1/2 (0.5) */
#define VQ3F		(U32)0x3F400000			/* (F32) Bitwise representation of Positive 3/4 (0.75)*/



/* Declarations */
extern F32 abf	(F32	x);			/* (U32) Absolute */
extern F64 abd	(F64	x);			/* (U64) Absolute */
extern U64 fcq	(U8		n);			/* (U64) Factorial */
/* Stolen from <math/pwf.c> */
extern F32 _pwif(F32	x, U64 y);	/* (F32) Integer exponent exponentiation */
extern F64 _pwid(F64	x, U64 y);	/* (F64) Integer exponent exponentiation */



/* (F32) Sine */
F32 snf(F32 x) {
	/* Binary representation of X */
	I32 bx = *(I32*)&x;
	/* sin(-x) = -sin(x) */
	if (bx&I32N) return -snf(abf(x));
	/* sin(x) = sin(x mod 1) */
	x -= (U32)x;

	switch (bx) {
	/* sin(0) = 0 */
	case VQ0F: return 0.0F;
	/* sin(0.25) = 1 */
	case VQ1F: return 1.0F;
	/* sin(0.5) = 0 */
	case VQ2F: return 0.0F;
	/* sin(0.75) = -1 */
	case VQ3F: return -1.0F;
	}

	/* x - 0.5 */
	const d = x - 0.5F;
	/* if x>0.5 => sin(x) = -sin(x-0.5) */
	if (bx>VQ2F) return -snf(d); 
	/* Taylor series approximation */
	F32 l = 2.0F;
	F32 h = 0.0F;
	
	for (U8 n = 1; l != h; n++) {
		if (n&1) l = h;
		h += snf((n+2.0F) / 4.0F) * _pwif(d,n) / fcq(n);
	}

	return h;
}