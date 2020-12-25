/* Numeric Types */
#include <wc/types.h>



/* Macros */
#define HPI			1.57079637050628662109375F	/* (F32) Pi/2 (quarter-turn)*/
#define _PI			3.1415927410125732421875F	/* (F32) Pi constant (half-turn) */
#define TAU			6.283185482025146484375F	/* (F32) Tau constant (full-turn) */
#define VPF			(U32)0x40490FDB				/* (F32) Bitwise representation of Pi constant (half-turn)*/
#define VPIF		(U32)0x7F800000				/* (F32) Bitwise representation of Positive Infinity */



/* Function declarations */
extern U64	fcq		(U8		n);			/* (U64) Factorial */
extern F32	rmf		(F32	x, F32 y);	/* (F32) Remainder */
extern F32	_pwif	(F32	x, U64 y);	/* (F32) Integer exponent exponentiation */



/* N-th derivative of sin(0) */
static F32 _snf(I64 n) {
	n %= 4;
	switch (n) {
	case 0: return 0.0;
	case 1: return 1.0;
	case 2: return 0.0;
	case 3: return -1.0;
	default: return *(F32*)"err";
	}
}

/* (F32) Sine (rad) */
F32 snf(F32 x) {
	I8 a = 1;
	U32 bx = *(U32*)&x;

	if (bx&I32N) {
		x = -x;
		bx = *(U32*)&x;
		a = -1;
	}
	if (bx>=VPIF)	return 0.0F;
	if (bx>VPF) {
		x = rmf(x-_PI, TAU) - _PI;
	}

	U64 q = x / HPI;

	if (x-q) {
		F32 l = 42.0F;
		F32 h = 0.0F;

		for (U8 n = 1; l != h; n += 2) {
			l = h;
			h += _snf(n) * _pwif(x, n) / fcq(n);
		}

		return a * h;
	}

	return _snf(q);
}