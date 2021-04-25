/**********************************************************
 * \file	Array type operations library				  *
 * \brief	Logical and arithmetic operations for arrays  *
 * 			of integers.								  *
 **********************************************************/
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

#undef	EQ
#define	EQ(X,Y)		(X==Y)
#undef	NQ
#define NQ(X,Y)		(X!=Y)
#undef	GT
#define GT(X,Y)		(X>Y)
#undef	LT
#define LT(X,Y)		(X<Y)
#undef	GQ
#define GQ(X,Y)		(X>=Y)
#undef	LQ
#define LQ(X,Y)		(X<=Y)

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
/** 
 * 	\def	Declaration for unioperand functions
 *	\param	NAME	Function name
 *	\brief	Most unioperand functions only require next 
 *			parameters
 *			- `s`	size of the operands in bytes
 *			- `r`	the array where the result is stored
 *			- `a`	the operand
 *
 *			return type is `VO*`
 */
#define ADECL1(NAME)	\
	VO* NAME(const U8 s, register VO* r, register const VO* a)

#undef	ADECL2
/** 
 * 	\def	Declaration for bioperand functions
 *	\param	NAME	Function name
 *	\brief	Most bioperand functions only require next 
 *			parameters
 *			-	`s`	size of the operands in bytes
 *			-	`r`	the array where the result is stored 
 *			-	`a`	the operand A
 *			-	`b`	the operand B
 *				(a user can provide a pointer to an array
 *				and the result will be stored there, if
 *				null pointer is given, the result array
 *				will be automatically allocated)
 *			return type is `VO*`
 */
#define ADECL2(NAME)	\
	VO* NAME(const U8 s, register VO* r, register const VO* a, register const VO* b)

#undef	ADEF1
#if	NO_I64
/** 
 * 	\def	Definition of unioperand logic array operation (32-bit)
 *  \brief	Definition of unioperand logic array operation for systems where
 * 			a 64-bit type is not supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL1
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 4 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 4 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 2 phases
 *				+ First phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Second phase:	if Rsize & 1, then apply FUNC to next 1 bytes
 *	Sorry, I'm not good at explaining things
 */
#define ADEF1(NAME, FUNC) 										\
	ADECL1(NAME) {												\
		if (!r) r = mal(0,s);									\
		register U8 d = s/4;									\
		register U8 m = s%4;									\
		register U16 i = 0;										\
																\
		for (; i < d; i++)										\
			((U32*)r)[i] = FUNC(((U32*)a)[i]);					\
																\
		i *= 4;													\
																\
		if (m&0b01)	{											\
			((U8*)r)[i] = FUNC(((U8*)a)[i]);					\
			i++;												\
		}														\
		if (m&0b10)	{											\
			((U16*)r)[i] = FUNC(((U16*)a)[i]);					\
			i += 2;												\
		}														\
																\
		return r;												\
	}
#else
/** 
 * 	\def	Definition of unioperand logic array operations (64-bit)
 *  \brief	Definition of unioperand logic array operations for systems where
 * 			a 64-bit type is supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL1
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 8 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 8 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 3 phases
 *				+ First phase:	if Rsize & 4, then apply FUNC to next 4 bytes
 *				+ Second phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Third phase:	if Rsize & 1, then apply FUNC to next 1 byte
 *	Sorry, I'm not good at explaining things
 */
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
																\
		return r;												\
	}
#endif

#undef	ADEF2
#if	NO_I64
/** 
 * 	\def	Definition of bioperand logic array operations (32-bit)
 *  \brief	Definition of bioperand logic array operations for systems where
 * 			a 64-bit type is not supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL2
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 4 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 4 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 2 phases
 *				+ First phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Second phase:	if Rsize & 1, then apply FUNC to next 1 bytes
 *	Sorry, I'm not good at explaining things
 */
#define ADEF2(NAME, FUNC) 										\
	ADECL2(NAME) {												\
		if (!r) r = mal(0,s);									\
		register U8 d = s/4;									\
		register U8 m = s%4;									\
		register U16 i = 0;										\
																\
		for (; i < d; i++)										\
			((U32*)r)[i] = FUNC(((U32*)a)[i], ((U32*)b)[i]);	\
																\
		i *= 4;													\
																\
		if (m&0b01)	{											\
			((U8*)r)[i] = FUNC(((U8*)a)[i], ((U8*)b)[i]);		\
			i++;												\
		}														\
		if (m&0b10)	{											\
			((U16*)r)[i] = FUNC(((U16*)a)[i], ((U16*)b)[i]);	\
			i += 2;												\
		}														\
																\
		return r;												\
	}
#else
/** 
 * 	\def	Definition of bioperand logic array operation (64-bit)
 *  \brief	Definition of bioperand logic array operation for systems where
 * 			a 64-bit type is supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL2
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 8 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 8 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 3 phases
 *				+ First phase:	if Rsize & 4, then apply FUNC to next 4 bytes
 *				+ Second phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Third phase:	if Rsize & 1, then apply FUNC to next 1 byte
 *	Sorry, I'm not good at explaining things
 */
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
																\
		return r;												\
	}
#endif

#undef	ADECL1B
/** 
 * 	\def	Declaration for unioperand boolean functions
 *	\param	NAME	Function name
 *	\brief	Most unioperand boolean functions only require next 
 *			parameters
 *			- `s`	size of the operands in bytes
 *			- `a`	the operand
 *			return type is `BL`
 */
#define ADECL1B(NAME)	\
	BL NAME(const U8 s, register const VO* a)

#undef	ADECL2B
/** 
 * 	\def	Declaration for bioperand boolean functions
 *	\param	NAME	Function name
 *	\brief	Most bioperand boolean functions only require next 
 *			parameters
 *			-	`s`	size of the operands in bytes
 *			-	`a`	the operand A
 *			-	`b`	the operand B)
 *			return type is `BL`
 */
#define ADECL2B(NAME)	\
	BL NAME(const U8 s, register const VO* a, register const VO* b)

#undef	ADEF1
#if	NO_I64
/** 
 * 	\def	Definition of unioperand logic array operation (32-bit)
 *  \brief	Definition of unioperand logic array operation for systems where
 * 			a 64-bit type is not supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL1
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 4 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 4 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 2 phases
 *				+ First phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Second phase:	if Rsize & 1, then apply FUNC to next 1 bytes
 *	Sorry, I'm not good at explaining things
 */
#define ADEF1(NAME, FUNC) 										\
	ADECL1(NAME) {												\
		if (!r) r = mal(0,s);									\
		register U8 d = s/4;									\
		register U8 m = s%4;									\
		register U16 i = 0;										\
																\
		for (; i < d; i++)										\
			((U32*)r)[i] = FUNC(((U32*)a)[i]);					\
																\
		i *= 4;													\
																\
		if (m&0b01)	{											\
			((U8*)r)[i] = FUNC(((U8*)a)[i]);					\
			i++;												\
		}														\
		if (m&0b10)	{											\
			((U16*)r)[i] = FUNC(((U16*)a)[i]);					\
			i += 2;												\
		}														\
																\
		return r;												\
	}
#else
/** 
 * 	\def	Definition of unioperand logic array operations (64-bit)
 *  \brief	Definition of unioperand logic array operations for systems where
 * 			a 64-bit type is supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL1
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 8 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 8 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 3 phases
 *				+ First phase:	if Rsize & 4, then apply FUNC to next 4 bytes
 *				+ Second phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Third phase:	if Rsize & 1, then apply FUNC to next 1 byte
 *	Sorry, I'm not good at explaining things
 */
#define ADEF1(NAME, FUNC) 										\
	ADECL1(NAME) {												\
		if (!r) r = mal(0,s);									\
		register const U8 d = s/8;								\
		register const U8 m = s%8;								\
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
																\
		return r;												\
	}
#endif

#undef	ADEF2
#if	NO_I64
/** 
 * 	\def	Definition of bioperand logic array operations (32-bit)
 *  \brief	Definition of bioperand logic array operations for systems where
 * 			a 64-bit type is not supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL2
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 4 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 4 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 2 phases
 *				+ First phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Second phase:	if Rsize & 1, then apply FUNC to next 1 bytes
 *	Sorry, I'm not good at explaining things
 */
#define ADEF2(NAME, FUNC) 										\
	ADECL2(NAME) {												\
		if (!r) r = mal(0,s);									\
		register U8 d = s/4;									\
		register U8 m = s%4;									\
		register U16 i = 0;										\
																\
		for (; i < d; i++)										\
			((U32*)r)[i] = FUNC(((U32*)a)[i], ((U32*)b)[i]);	\
																\
		i *= 4;													\
																\
		if (m&0b01)	{											\
			((U8*)r)[i] = FUNC(((U8*)a)[i], ((U8*)b)[i]);		\
			i++;												\
		}														\
		if (m&0b10)	{											\
			((U16*)r)[i] = FUNC(((U16*)a)[i], ((U16*)b)[i]);	\
			i += 2;												\
		}														\
																\
		return r;												\
	}
#else
/** 
 * 	\def	Definition of bioperand logic array operation (64-bit)
 *  \brief	Definition of bioperand logic array operation for systems where
 * 			a 64-bit type is supported.
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL2
 *	
 *	Method:
 *		-#	If user provided a pointer for `r`, the result will be stored 
 *			there, otherwise it will be allocated.
 *		-#	Break up the operand A into chunks of 8 bytes.
 *		-#	Perform FUNC to all chunks of operand A and store the result it in 
 *			`r`
 *		-#	If there's any remaining part of the operand A that happened to be
 *			smaller than 8 bytes, **consider it's size ("Rsize") in binary**. The 
 *			algorithm does the same thing as in the step 3 but in 3 phases
 *				+ First phase:	if Rsize & 4, then apply FUNC to next 4 bytes
 *				+ Second phase:	if Rsize & 2, then apply FUNC to next 2 bytes
 *				+ Third phase:	if Rsize & 1, then apply FUNC to next 1 byte
 *	Sorry, I'm not good at explaining things
 */
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
																\
		return r;												\
	}
#endif



C_DECL_BEGIN

/* Array Assignment */
ADECL1(aas);

/* Array NOT */
ADECL1(ant);

/* Array AND */
ADECL2(aan);

/* Array OR */
ADECL2(aor);

/* Array XOR */
ADECL2(axr);

/* Array NAND */
ADECL2(ann);

/* Array NOR */
ADECL2(anr);

/* Array NXOR */
ADECL2(anx);

/* Array Equals */
bl	aeq(	register	const	U8	s,
					register	const	VO*	a,
					register	const	VO* b	);

/* Array fill */
VO*	afl(	register	const	U8	sa, 
			register			VO*	a, 
			register			U8	sb, 
			register	const	VO*	b	);

C_DECL_END

#endif
