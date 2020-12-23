#ifndef WC_MATH_H
#define WC_MATH_H

/* Fixed-type numeric types */
#include <wc/core.h>
#include <wc/types.h>



/* Constants */
#define EF		2.71828174591064453125F
#define PIF		3.1415927410125732421875F
#define TAUF	6.283185482025146484375F

#define E		2.71828182845904509079559829842764884233474731445312
#define PI		3.141592653589793115997963468544185161590576171875
#define TAU		6.28318530717958623199592693708837032318115234375



/* Aliases */
#define fc		fcu
#define fcl		fcq
#define div		qtd
#define mod		rmd
#define log		lgd
#define exp		pwd
#define root	rtd
#define hy		hyd
#define cos		csd
#define sin		snd
#define tan		tnd
#define cot		ctd
#define tg		tnd
#define ctg		ctd
#define abs		abd
#define sgn		sgd



C_DECL_BEGIN
/* Factorial */
extern U32	fcu	(U8		x);			/* (U32) Factorial 			*/
extern U64	fcq	(U8		x);			/* (U32) Factorial 			*/

/* Division */
extern F32	qtf	(F32	x, F32 y);	/* (F32) Quotient			*/
extern F64	qtd	(F64	x, F64 y);	/* (F64) Quotient			*/
extern F32	rmf	(F32	x, F32 y);	/* (F32) Remainder			*/
extern F64	rmd	(F64	x, F64 y);	/* (F64) Remainder			*/

/* Exponential Functions */
extern F32	lg2f(F32	z);			/* (F32) Binary Logarithm	*/
extern F64	lg2d(F64	z);			/* (F64) Binary Logarithm	*/
extern F32	lgf	(F32	x, F32 z);	/* (F32) Logarithm			*/
extern F64	lgd	(F64	x, F64 z);	/* (F64) Logarithm			*/
extern F32	pw2f(F32	y);			/* (F32) Binary Exponent	*/
extern F64	pw2d(F64	y);			/* (F64) Binary Exponent	*/
extern F32	pwf	(F32	x, F32 y);	/* (F32) Power				*/
extern F64	pwd	(F64	x, F64 y);	/* (F64) Power				*/
extern F32	rtf	(F32	y, F32 z);	/* (F32) Root				*/
extern F64	rtd	(F64	y, F64 z);	/* (F64) Root				*/
extern F64	hyf	(F32	x, F32 y);	/* (F32) Hypotenuse			*/
extern F64	hyd	(F32	x, F32 y);	/* (F64) Hypotenuse			*/

/* Trigonometric Functions */
extern F32	csf	(F32	x);			/* (F32) Cosine				*/
extern F64	csd	(F64	x);			/* (F64) Cosine				*/
extern F32	snf	(F32	x);			/* (F32) Sine				*/
extern F64	snd	(F64	x);			/* (F64) Sine				*/
extern F32	tnf	(F32	x);			/* (F32) Tangent			*/
extern F64	tnd	(F64	x);			/* (F64) Tangent			*/
extern F32	ctf	(F32	x);			/* (F32) Cotangent			*/
extern F64	ctd	(F64	x);			/* (F64) Cotangent			*/

/* Sign Functions */
extern F32	abf	(F32	x);			/* (F32) Absolute			*/
extern F64	abd	(F64	x);			/* (F64) Absolute			*/
extern I8	sgf	(F32	x);			/* (F32) Sign				*/
extern I8	sgd	(F64	x);			/* (F64) Sign				*/
C_DECL_END

#endif