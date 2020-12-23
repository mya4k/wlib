/* Numeric Types */
#include <wc/types.h>



/* Macros */
#define VP0F		(U32)0x00000000			/* (F32) Bitwise representation of Positive 0 */
#define VPHF		(U32)0x3F000000			/* (F32) Bitwise representation of Positive 1/2 (0.5) */
#define VP1F		(U32)0x3F800000			/* (F32) Bitwise representation of Positive 1 */




/* Declarations */
extern F32 abf	(F32	x);			/* (F32) Absolute */
extern U64 fcq	(U8		n);			/* (U64) Factorial */
extern F32 rmf	(F32	x, F32 y);	/* (F32) Remainder */
/* Stolen from <math/pwf.c> */
extern F32 _pwif(F32	x, U64 y);	/* (F32) Integer exponent exponentiation */
extern F64 _pwid(F64	x, U64 y);	/* (F64) Integer exponent exponentiation */

/* */
static F32 _snf(F32 x) {
	U32 bx = *(U32*)&x;

	if (bx > VP1F) {
		x = rmf(x + 1.0F, 2.0F) - 1.0F;
		bx = *(U32*)&x;
	}

	if (bx & I32N) return -_snf(abf(x));

	switch (bx) {
	case VP0F: return 0.0F;
	case VPHF: return 1.0F;
	case VP1F: return 0.0F;
	}

	return 0.0F;
}

/* (F32) Sine */
F32 snf(F32 x) {	
	U32 bx = *(U32*)&x;
	F32 l = -1.0F;
	F32 h = 0.0F;

	if (bx > VP1F) {
		x = rmf(x + 1.0F, 2.0F) - 1.0F;
		bx = *(U32*)&x;
	}

		if (bx & I32N) return -snf(abf(x));

	switch (bx) {
	case VP0F: return 0.0F;
	case VPHF: return 1.0F;
	case VP1F: return 0.0F;
	}

	for (U8 n = 1; /*l != h &&*/ n < 32; n += 2) {
		l = h;
		h += /*_pwif(x,n)* */ _snf(n/2.0F) /*/ fcq(n)*/;
		printf("%f\n", h);
	}

	return h;
}