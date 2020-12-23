/* Numeric Types */
#include <wc/types.h>



/* Macros */
#define HPI			1.5707963267948965579989817342720925807952880859375	/* (F64) Pi/2 (quarter-turn)*/
#define _PI			3.141592653589793115997963468544185161590576171875	/* (F64) Pi constant (half-turn) */
#define TAU			6.28318530717958623199592693708837032318115234375	/* (F64) Tau constant (full-turn) */

/* Floating-point constants */
#ifdef _MSC_VER
#define PID			1e300*1e300			/* (F64) Positive Infinity */
#else
#define PID			1e309					/* (F64) Positive Infinity */
#endif



/* Function declarations */
extern U64	fcq		(U8		n);			/* (U64) Factorial */
extern F64	rmd		(F64	x, F64 y);	/* (F64) Remainder */
extern F64	_pwid	(F64	x, U64 y);	/* (F64) Integer exponent exponentiation */



/* N-th derivative of sin(0) */
static F64 _snd(I64 n) {
	n %= 4;
	switch (n) {
	case 0: return 0.0;
	case 1: return 1.0;
	case 2: return 0.0;
	case 3: return -1.0;
	default: return *(F64*)"_error_";
	}
}

#if NO_I64

/* (F64) Sine (rad) */
F64 snd(F64 x) {
	I8 a = 1;

	if (x < 0) {
		x = -x;
		a = -1;
	}
	if (x>=PID)	return 0.0;
	if (x>_PI)	x = rmd(x-_PI, TAU) - _PI;

	U64 q = x / HPI;

	if (x-q) {
		F64 l = 42.0;
		F64 h = 0.0;

		for (U8 n = 1; l != h; n += 2) {
			l = h;
			h += _snd(n) * _pwid(x,n) / fcq(n);
		}

		return a * h;
	}

	return _snd(q);
}

#else
#define VPD			(U64)0x400921FB54442D18								/* (F64) Bitwise representation of Pi constant */
#define VPID		(U64)0x7F80000000000000								/* (F32) Bitwise representation of Positive Infinity */

/* (F64) Sine (rad) */
F64 snd(F64 x) {
	I8 a = 1;
	U64 bx = *(U64*)&x;

	if (bx&I64N) {
		x = -x;
		bx = *(U64*)&x;
		a = -1;
	}
	if (bx>=VPID)	return 0.0;
	if (bx>VPD)		x = rmf(x-_PI, TAU) - _PI;

	U64 q = x / HPI;

	if (x-q) {
		F64 l = 42.0;
		F64 h = 0.0;

		for (U8 n = 1; l != h; n += 2) {
			l = h;
			h += _snd(n) * _pwid(x,n) / fcq(n);
		}

		return a * h;
	}

	return _snd(q);
}
#endif