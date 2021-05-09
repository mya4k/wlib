/************************************
 *	Integer Mathametical Functions	*
 *	Wispy (C) 2021					*
 ************************************/
#ifndef WC_MATHI_H	/* Make sure this header isn't included twice */
#define WC_MATHI_H



/*
 *	Includes
 */
#include <wc/core.h>	/* C & C++ Compatibility */
#include <wc/types.h>	/* Numeric types */


/*
 *	Includes
 */

/* Aliases */
#define	ab	abi							/* (I32) Absolute			*/
#define fc	fcu							/* (U32) Factorial			*/

/* These are simple functions, let's just inline them */

/**
 * @brief	(I32) Absolute 
 * @def		#define abi(x)
 * @param	x
 */
#define abi(x)		(x<0 ? -x : x)

/**
 * @brief	(I64) Absolute 
 * @def		#define abl(x)
 * @param	x
 */
#define abl(x)		(x<0 ? -x : x)

/**
 * @brief	(U32) Logarithm
 * @def		#define lgu(x,z)
 * @param	x	Base
 * @param	z	Power
 */
#define lgu(x,z)	(lg2u(z)/lg2u(x))

/**
 * @brief	(U32) Logarithm
 * @def		#define lgq(x,z)
 * @param	x	Base
 * @param	z	Power
 */
#define lgq(x,z)	(lg2q(z)/lg2q(x))

/**
 * @brief	(I32) Sign
 * @def		#define sgi(x)
 * @param	x
 */
#define sgi(x)		((x&I32N) ? -1 : (x?1:0))

/**
 * @brief	(I64) Sign
 * @def		#define sgl(x)
 * @param	x
 */
#define sgl(x)		((x&I64N) ? -1 : (x?1:0))



/*
 *	Typedef
 */
#ifndef TYPE_SIGN
	typedef I8 Sign, Sg;
	#define TYPE_SIGN
#endif



/*
 *	Declarations
 */
C_DECL_BEGIN

/* Binary Logarithms */
U8	lg2u(U32	z);				/* (U32) Binary Logarithm	*/
U8	lg2q(U64	z);				/* (U64) Binary Logarithm	*/

/* Factorial */
U32	fcu	(U8		n);				/* (U32) Factorial			*/
U32	fcq	(U8		n);				/* (U64) Factorial			*/

/* Power */
U32	pwu	(U16	x, U8	y);		/* (U32) Power				*/
U64	pwq	(U32	x, U8	y);		/* (U64) Power				*/
I32	pwi	(I16	x, I8	y);		/* (I32) Power				*/
I64	pwl	(I32	x, I8	y);		/* (I64) Power				*/

/* Square Root */
U16 rtu	(U32	z);				/* (I32) Square Root		*/
U32 rtq	(U64	z);				/* (I64) Square Root		*/

/* Cube root or n-th root will not be coming */

C_DECL_END



#endif
