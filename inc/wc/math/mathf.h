/********************************
 * Floating-point Mathmatics	*
 * Wispy (C) 2021				* 
 ********************************/
#ifndef WC_MATHF_H
#define WC_MATHF_H



/*
 *	Includes
 */
#include <wc/core.h>	/* Compatibility */
#include <wc/types.h>	/* Numeric types */



/* 
 *	Constants
 */
#define EF		2.71828174591064453125F
#define RHOF	1.57079637050628662109375F
#define PIF		3.1415927410125732421875F
#define TAUF	6.283185482025146484375F

#define E		2.71828182845904509079559829842764884233474731445312
#define RHO		1.5707963267948965579989817342720925807952880859375
#define PI		3.141592653589793115997963468544185161590576171875
#define TAU		6.28318530717958623199592693708837032318115234375

#define LN2F		0.693147182464599609375F
#define LN2			0.69314718055994528622676398299518041312694549560546875



/* 
 *	Aliases
 */
#define divf	qtd
#define modf	rmd
#define logf	lgd
#define expf	pwd
#define rootf	rtd
#define cosf	csd
#define sinf	snd
#define tanf	tnd
#define cotf	ctd
#define tgf		tnd
#define ctgf	ctd
#define absf	abd
#define sgnf	sgd

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



/*
 *	Statics
 */

/**
 *	@brief	(F32) Absolute
 *	@fn		inline static F32 abf(F32 x)
 *	@param	x
 *	@return	F32
 *	[[ METHOD PLEASE? ]]
 */
#ifndef NO_FLT_PTR	/* Optimal behavior	*/
inline static F32 abf(F32 x) {
	*(I32*)&x &= I32X;
	return x;
}
#else
#define abf(x)		(( (x)<0.0F ) ? (-x) : (x))
#endif

/**
 *	@brief	(F64) Absolute
 *	@fn		inline static F64 abd(F64 x))
 *	@param	x
 *	@return	F32
 *	[[ METHOD PLEASE? ]]
 */
#if defined(NO_FLT_PTR) && NO_I64
#define abd(x)		(( (x)<0.0F ) ? (-x) : (x))
#else				/* Optimal behavior	*/
inline static F64 abf(F64 x) {
	*(I64*)&x &= I64X;
	return x;
}
#endif

/**
 *	@brief	(F32) Sign
 *	@fn		inline static F32 sgf(F32 x)
 *	@param	x
 *	@return	F32
 *	[[ METHOD PLEASE? ]]
 */
inline static F32 sgf(F32 x) {
	U32 bx = *(U32*)&x;
	if (bx &= I32X) 
		return (bx &= I32X) * x / *(F32*)&bx;
	return 0;
}

/**
 *	@brief	(F64) Sign
 *	@fn		inline static F64 sgf(F64 x)
 *	@param	x
 *	@return	F64
 *	[[ METHOD PLEASE? ]]
 */

#if !defined(NO_I64) && !defined(NO_FLT_PTR)		/* Optimal behavior	*/
inline static F64 sgd(F64 x) {
	U64 bx = *(U64*)&x;
	if (bx &= I64X)
		return x / *(F64*)&bx;
	return 0;
}
#else
#define sgd(x)		((x!=0.0) ? ((x<0.0) -1 : 1) : 0)
#endif

/**
 * @brief	(F32) Quotient [x div y]
 * @def		#define qtf(x)
 * @param	x
 * @param	y
 */
#define qtf(x,y)	(I64)((x)/(y))
/**
 * @brief	(F64) Quotient [x div y]
 * @def		#define qtd(x)
 * @param	x
 * @param	y
 */
#define qtd(x,y)	(I64)((x)/(y))

/**
 *	@brief	(F32) Remainder
 *	@def	#define rmf(x,y)
 *	@param	x
  *	@param	y
 *	@return	F32
 *	[[ METHOD PLEASE? ]]
 */
#define rmf(x,y)	( (x) - (y) * ( qtf(x,y) - (F32)((y)<0) ) )
/**
 *	@brief	(F64) Remainder
 *	@def	#define rmd(x,y)
 *	@param	x
 *	@param	y
 *	@return	F64
 *	[[ METHOD PLEASE? ]]
 */
#define rmd(x,y)	( (x) - (y) * ( qtd(x,y) - (F64)((y)<0) ) )

/**
 *	@brief	(F32) Root
 *	@def	#define rtf(y,z)
 *	@param	y
 *	@param	z
 *	Remember from school that rtf(y,z) = pwf(z, 1/y)?
 */
#define rtf(y,z)	pwf(z, 1.0F/(y))
/**
 *	@brief	(F64) Root
 *	@def	#define rtd(y,z)
 *	@param	y
 *	@param	z
 *	Remember from school that rtd(y,z) = pwd(z, 1/y)?
 */
#define rtd(y,z)	pwd(z, 1.0/(y))

/**
 *	@brief	(F32) Hypotenuse
 *	@def	#define hyf(a,b)
 *	@param	a
 *	@param	b
 *	Pythogor theorem
 */
#define hyf(a,b)	rt2f((a)*(a) + (b)*(b))
/**
 *	@brief	(F64) Hypotenuse
 *	@def	#define hyd(a,b)
 *	@param	a
 *	@param	b
 *	Pythogor theorem
 */
#define hyd(a,b)	rt2d((a)*(a) + (b)*(b))

/**
 *	@brief	(F32) Cosine
 *	@def	#define csf(x)
 *	@param	x
 *	cos(x) = sin'(x) = sin(x + rho)
 */
#define csf(x)		snf(x+RHOF)
/**
 *	@brief	(F64) Cosine
 *	@def	#define csd(x)
 *	@param	x
 *	cos(x) = sin'(x) = sin(x + rho)
 */
#define csd(x)		snd(x+RHO)

/**
 *	@brief	(F32) Tangent
 *	@def	#define tnf(x)
 *	@param	x
 *	tan(x) = sin(x)/cos(x)
 */
#define tnf(x)		(snf(x)/csf(x))
/**
 *	@brief	(F64) Tangent
 *	@def	#define tnd(x)
 *	@param	x
 *	tan(x) = sin(x)/cos(x)
 */
#define tnd(x)		(snd(x)/csd(x))

/**
 *	@brief	(F32) Cotangent
 *	@def	#define ctf(x)
 *	@param	x
 *	tan(x) = cos(x)/sin(x)
 */
#define tnf(x)		(csf(x)/snf(x))
/**
 *	@brief	(F64) Cotangent
 *	@def	#define ctd(x)
 *	@param	x
 *	tan(x) = cos(x)/sin(x)
 */
#define tnd(x)		(csd(x)/snd(x))



/*
 *	Declarations
 */
C_DECL_BEGIN

/* Exponential Functions */
F32	lg2f(F32	z);			/* (F32) Binary Logarithm	*/
F64	lg2d(F64	z);			/* (F64) Binary Logarithm	*/
F32	lgf	(F32	x, F32 z);	/* (F32) Logarithm			*/
F64	lgd	(F64	x, F64 z);	/* (F64) Logarithm			*/
F32	pw2f(F32	y);			/* (F32) Binary Exponent	*/
F64	pw2d(F64	y);			/* (F64) Binary Exponent	*/
F32	pwf	(F32	x, F32 y);	/* (F32) Power				*/
F64	pwd	(F64	x, F64 y);	/* (F64) Power				*/

/* Trigonometric Functions */
F32	snf	(F32	x);			/* (F32) Sine				*/
F64	snd	(F64	x);			/* (F64) Sine				*/

C_DECL_END

#endif
