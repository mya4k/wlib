#ifndef WC_ARRAY_H
#define WC_ARRAY_H

#include <wc/core.h>
#include <wc/types.h>
#include <wc/memory.h>

/* ALL FUNCTIONS DECLARED THROUGH "ADECL" ARE DEFINED IN "array.c" */


#undef	NO
#define NO(X)		(X)
#undef	NT
#define NT(X)		(~X)
#undef	AN
#define AN(X,Y)		(X&Y)
#undef	OR
#define OR(X,Y)		(X|Y)
#undef	XR
#define XR(X,Y)		(X^Y)
#undef	NN
#define NN(X,Y)		(~(X&Y))
#undef	NR
#define NR(X,Y)		(~(X|Y))
#undef	NX
#define NX(X,Y)		(~(X^Y))

#undef	NG
#define NG(X)		(-X)
#undef	IC
#define	IC(X)		(X++)
#undef	DC
#define DC(X)		(X--)
#undef	AD
#define	AD(X,Y)		(X+Y)
#undef	SB
#define SB(X,Y)		(X-Y)
#undef	ML
#define ML(X,Y)		(X*Y)
#undef	DV
#define DV(X,Y)		(X/Y)
#undef	MD
#define MD(X,Y)		(X%Y)


#undef	ADECL1
#define ADECL1(NAME)	\
	VO* NAME(const U16 s, register const VO* a, register VO* r)
#undef	ADECL2
#define ADECL2(NAME)	\
	VO* NAME(const U16 s, register const VO* a, register const VO* b, register VO* r)

/* Function prototype */
	/* If r == NULL, then we need to allocate memory for the result */
	/* Otherwise store the result in the user-provided pointer */
	/* Divide the algorithm to two loops for efficiency
	 * In the first loop assigns the values in chunks of 8 bytes
	 * If there's a portion of the array left that is less than 8 bytes,
	 * it will be handled by the second loop
	 */
#undef	ADEF1
#define ADEF1(NAME, FUNC) 										\
	ADECL1(NAME) {												\
		if (!r) r = mal(0,s);									\
		register U8 d = s/8;									\
		register U8 m = s%8;									\
		register U16 i = 0;										\
																\
		for (; i < d; i++)										\
			((U64*)r)[i] = FUNC(((U64*)a)[i]);					\
																\
		i *= 8;													\
																\
		if (m&0b001)	{										\
			((U8*)r)[i] = FUNC(((U8*)a)[i]);					\
			i++;												\
		}														\
		if (m&0b010)	{										\
			((U16*)r)[i] = FUNC(((U16*)a)[i]);					\
			i += 2;												\
		}														\
		if (m&0b100)	{										\
			((U32*)r)[i] = FUNC(((U32*)a)[i]);					\
			i += 4;												\
		}														\
		return r;												\
	}

#undef	ADEF2
#define ADEF2(NAME, FUNC) 										\
	ADECL2(NAME) {												\
		if (!r) r = mal(0,s);									\
		register U8 d = s/8;									\
		register U8 m = s%8;									\
		register U16 i = 0;										\
																\
		for (; i < d; i++)										\
			((U64*)r)[i] = FUNC(((U64*)a)[i], ((U64*)b)[i]);	\
																\
		i *= 8;													\
																\
		if (m&0b001)	{										\
			((U8*)r)[i] = FUNC(((U8*)a)[i], ((U8*)b)[i]);		\
			i++;												\
		}														\
		if (m&0b010)	{										\
			((U16*)r)[i] = FUNC(((U16*)a)[i], ((U16*)b)[i]);	\
			i += 2;												\
		}														\
		if (m&0b100)	{										\
			((U32*)r)[i] = FUNC(((U32*)a)[i], ((U32*)b)[i]);	\
			i += 4;												\
		}														\
		return r;												\
	}

C_DECL_BEGIN
ADECL1(aas);							/*	Array Assign		*/
ADECL1(ant);							/*	Array NOT			*/
ADECL2(aan);							/*	Array AND			*/
ADECL2(aor);							/*	Array OR			*/
ADECL2(axr);							/*	Array XR			*/
ADECL2(ann);							/*	Array NAND			*/
ADECL2(anr);							/*	Array NOR			*/
ADECL2(anx);							/*	Array NXOR			*/
VO* afl(register	const	U16	sa, 
		register			VO*	a, 
		register	const	U8	sb, 
		register	const	VO*	b	);	/*	Array Fill */
C_DECL_END

#endif
