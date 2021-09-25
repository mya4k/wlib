/**
 * \file array.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Array manipulation functions
 * \version 0.1
 * \date 2021-06-30
 */
#ifndef WC_ARRAY_H
#define WC_ARRAY_H



#include <wc/core.h>
#include <wc/types.h>
#include <wc/logic.h>
#include <wc/memory.h>



/* ALL FUNCTIONS DECLARED THROUGH "ADECL" ARE DEFINED IN "array.c" */



/**
 *       ###    ##       ####    ###     ######  ########  ######  
 *      ## ##   ##        ##    ## ##   ##    ## ##       ##    ## 
 *     ##   ##  ##        ##   ##   ##  ##       ##       ##       
 *    ##     ## ##        ##  ##     ##  ######  ######    ######  
 *    ######### ##        ##  #########       ## ##             ## 
 *    ##     ## ##        ##  ##     ## ##    ## ##       ##    ## 
 *    ##     ## ######## #### ##     ##  ######  ########  ######  
 */
#ifndef NO_SHORT_NAMES
#define AA0		WL_AA0
#define aas		wl_aas
#define ant		wl_ant
#define aan		wl_aan
#define aor		wl_aor
#define axr		wl_axor
#define ann		wl_ann
#define anr		wl_anr
#define anx		wl_anx
#define ano		wl_ano
#define antl	wl_antl
#define aanl	wl_aanl
#define aorl	wl_aorl
#define axrl	wl_axrl
#define annl	wl_annl
#define anrl	wl_anrl
#define anxl	wl_anxl
#define afl		wl_afl
#define asb		wl_asb
#define asa		wl_asa
#define aeq		wl_aeq
#define anq		wl_anq
#define agt		wl_agt
#define alt		wl_alt
#define agq		wl_agq
#define alq		wl_alq
#define SEARCH_FLAGS	WL_SEARCH_FLAGS
#define SEARCH_NORMAL	WL_SEARCH_NORMAL
#define SEARCH_REVERSE	WL_SEARCH_REVERSE
#define SEARCH_COUNT	WL_SEARCH_COUNT
#endif



/***
 *    ##     ##    ###     ######  ########   #######   ######  
 *    ###   ###   ## ##   ##    ## ##     ## ##     ## ##    ## 
 *    #### ####  ##   ##  ##       ##     ## ##     ## ##       
 *    ## ### ## ##     ## ##       ########  ##     ##  ######  
 *    ##     ## ######### ##       ##   ##   ##     ##       ## 
 *    ##     ## ##     ## ##    ## ##    ##  ##     ## ##    ## 
 *    ##     ## ##     ##  ######  ##     ##  #######   ######  
 */
#undef	ADECL1
/** 
 * 	\brief	Declaration for unioperand functions
 *	\def	ADECL1(NAME)
 *	\param	NAME	Function name
 *	\return	result pointer
 *	Most unioperand functions only require next 
 *	parameters
 *	- `s`	size of the operands in bytes
 *	- `a`	the operand
 */
#define ADECL1(NAME)	\
	wl_Vo* NAME(const wl_U32 s, const wl_Vo* const restrict a)

#undef	ADECL2
/** 
 * 	\brief	Declaration for unioperand functions
 *	ADECL1(NAME)
 *	\param	NAME	Function name
 *	Most bioperand functions only require next 
 *	parameters
 *	\return	result pointer
 *	- `s`	size of the operands in bytes
 *	- `a`	the operand A
  *	- `b`	the operand B
 */
#define ADECL2(NAME)	\
	wl_Vo* NAME(const wl_U32 s, wl_Vo* const restrict a, const wl_Vo* const restrict b)

#undef	ADEF1
#ifdef	NO_I64
/** 
 * 	\def	ADEF1(NAME, FUNC)
 *  \brief	Definition of unioperand logic array operation (32-bit)
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL1
 *	
 *	Method:
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
#define ADEF1(NAME, FUNC) 												\
	ADECL1(NAME) {														\
		wl_Vo* const r = wl_mal(s);										\
		wl_U32 d = s/4;													\
		wl_U32 m = s%4;													\
		wl_U32 i = 0;													\
																		\
		for (; i < d; i++)												\
			((wl_U32*)r)[i] = FUNC(((wl_U32*)a)[i]);					\
																		\
		i *= 4;															\
																		\
		if (m&0x1)	{													\
			*(wl_U8*)((wl__Ptr)r+i) = FUNC(*(wl_U8*)((wl__Ptr)a+i));	\
			i++;														\
		}																\
		if (m&0x2)	{													\
			*(wl_U16*)((wl__Ptr)r+i) = FUNC(*(wl_U16*)((wl__Ptr)a+i));	\
			i += 2;														\
		}																\
																		\
		return r;														\
	}
#else
/** 
 * 	\def	ADEF1(NAME, FUNC)
 *  \brief	Definition of unioperand logic array operations (64-bit)
 *	\param	NAME	Function name
 *	\param	FUNC	The operation it need to perform
 *	\return	result pointer
 *	\see	ADECL1
 *	
 *	Method:
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
#define ADEF1(NAME, FUNC) 												\
	ADECL1(NAME) {														\
		wl_Vo* const r = wl_mal(s);										\
		wl_U32 d = s/8;													\
		wl_U32 m = s%8;													\
		wl_U32 i = 0;													\
																		\
		for (; i < d; i++)												\
			((wl_U64*)r)[i] = FUNC(((wl_U64*)a)[i]);					\
																		\
		i *= 8;															\
																		\
		if (m&0x1)	{													\
			*(wl_U8*)((wl__Ptr)r+i) = FUNC(*(wl_U8*)((wl__Ptr)a+i));						\
			i++;														\
		}																\
		if (m&0x2)	{													\
			*(wl_U16*)((wl__Ptr)r+i) = FUNC(*(wl_U16*)((wl__Ptr)a+i));					\
			i += 2;														\
		}																\
		if (m&0x4)	{													\
			*(wl_U32*)((wl__Ptr)r+i) = FUNC(*(wl_U32*)((wl__Ptr)a+i));					\
			i += 4;														\
		}																\
																		\
		return r;														\
	}
#endif

#undef	ADEF2
#ifdef	NO_I64
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
#define ADEF2(NAME, FUNC) 																				\
	ADECL2(NAME) {																						\
		wl_Vo* const r = wl_mal(s);																		\
		wl_U32 d = s/4;																					\
		wl_U32 m = s%4;																					\
		wl_U32 i = 0;																					\
																										\
		for (; i < d; i++)																				\
			((wl_U32*)r)[i] = FUNC( ((wl_U32*)a)[i] , ((wl_U32*)b)[i]);									\
																										\
		i *= 4;																							\
																										\
		if (m&0x1)	{																					\
			*(wl_U8*)((wl__Ptr)r+i) = FUNC( *(wl_U8*)((wl__Ptr)a+i) , *(wl_U8*)((wl__Ptr)b+i) );		\
			i++;																						\
		}																								\
		if (m&0x2)	{																					\
			*(wl_U16*)((wl__Ptr)r+i) = FUNC( *(wl_U16*)((wl__Ptr)a+i) , *(wl_U16*)((wl__Ptr)b+i) );		\
			i += 2;																						\
		}																								\
																										\
		return r;																						\
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
#define ADEF2(NAME, FUNC) 																		\
	ADECL2(NAME) {																				\
		wl_Vo* const r = wl_mal(s);																\
		wl_U32 d = s/8;																			\
		wl_U32 m = s%8;																			\
		wl_U32 i = 0;																			\
																								\
		for (; i < d; i++)																		\
			((wl_U64*)r)[i] = FUNC( ((wl_U64*)a)[i] , ((wl_U64*)b)[i] );						\
																								\
		i *= 8;																					\
																								\
		if (m&0x1)	{																			\
			*(wl_U8*)((wl__Ptr)r+i) = FUNC(*(wl_U8*)((wl__Ptr)a+i),*(wl_U8*)((wl__Ptr)b+i));	\
			i++;																				\
		}																						\
		if (m&0x2)	{																			\
			*(wl_U16*)((wl__Ptr)r+i) = FUNC(*(wl_U16*)((wl__Ptr)a+i),*(wl_U16*)((wl__Ptr)b+i));	\
			i += 2;																				\
		}																						\
		if (m&0x4)	{																			\
			*(wl_U32*)((wl__Ptr)r+i) = FUNC(*(wl_U32*)((wl__Ptr)a+i),*(wl_U32*)((wl__Ptr)b+i));	\
			i += 4;																				\
		}																						\
																								\
		return r;																				\
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
	wl_Bl NAME(const wl_U32 s, wl_Vo* const restrict a)

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
	wl_Bl NAME(const wl_U32 s, wl_Vo* const restrict a, wl_Vo* const restrict b)

/**
 */
#undef	ADEF1B
#if	NO_I64
#define	ADEF1B(NAME,FUNC)										\
	ADECL1B(NAME) {												\
		const wl_U32 d = s/4;									\
		const wl_U32 m = s%4;									\
		wl_U32 i = 0;											\
																\
		for (; i < d; i++)										\
			if (FUNC(((wl_U32*)a)[i])) return 0;				\
																\
		i *= 4;													\
																\
		if (m&0x1) {											\
			if (FUNC(*(wl_U8*)((wl__Ptr)a+i))) return 0;		\
			i++;												\
		}														\
		if (m&0x2) {											\
			if (FUNC(*(wl_U16*)((wl__Ptr)a+i))) return 0;		\
			i += 2;												\
		}														\
																\
		return 1;												\
	}
#else
#define	ADEF1B(NAME,FUNC)										\
	ADECL1B(NAME) {												\
		const wl_U32 d = s/8;									\
		const wl_U32 m = s%8;									\
		wl_U32 i = 0;											\
																\
		for (; i < d; i++)										\
			if (FUNC(((wl_U32*)a)[i])) return 0;				\
																\
		i *= 8;													\
																\
		if (m&0x1) {											\
			if (FUNC(*(wl_U8*)((wl__Ptr)a+i))) return 0;		\
			i++;												\
		}														\
		if (m&0x2) {											\
			if (FUNC(*(wl_U16*)((wl__Ptr)a+i))) return 0;		\
			i += 2;												\
		}														\
		if (m&0x4) {											\
			if (FUNC(*(wl_U32*)((wl__Ptr)a+i))) return 0;		\
			i += 4;												\
		}														\
																\
		return 1;												\
	}
#endif

/**
 */
#undef	ADEF2B
#if NO_I64
#define	ADEF2B(NAME,FUNC)											\
	ADECL2B(NAME) {													\
		const wl_U32 d = s/4;											\
		const wl_U32 m = s%4;											\
		wl_U32 i = 0;													\
																	\
		for (; i < d; i++)											\
			if (FUNC( (((wl_U32*)a)[i]) , (((wl_U32*)b)[i]) )) return 0;	\
																	\
		i *= 4;														\
																	\
		if (m&0x1) {												\
			if (FUNC( *(wl_U8*)((wl__Ptr)a+i) , *(wl_U8*)((wl__Ptr)b+i) )) return 0;		\
			i++;													\
		}															\
		if (m&0x2) {												\
			if (FUNC( *(wl_U16*)((wl__Ptr)a+i) , *(wl_U16*)((wl__Ptr)b+i) )) return 0;	\
			i += 2;													\
		}															\																		\
																	\
		return 1;													\
	}
#else
#define	ADEF2B(NAME,FUNC)											\
	ADECL2B(NAME) {													\
		const wl_U32 d = s/8;											\
		const wl_U32 m = s%8;											\
		wl_U32 i = 0;													\
																	\
		for (; i < d; i++)											\
			if (FUNC( ((wl_U64*)a)[i] , ((wl_U64*)b)[i] )) return 0;	\
																	\
		i *= 8;														\
																	\
		if (m&0x1) {												\
			if (FUNC( *(wl_U8*)((wl__Ptr)a+i),*(wl_U8*)((wl__Ptr)b+i) )) return 0;		\
			i++;													\
		}															\
		if (m&0x2) {												\
			if (FUNC( *(wl_U16*)((wl__Ptr)a+i) , *(wl_U16*)((wl__Ptr)b+i) )) return 0;	\
			i += 2;													\
		}															\
		if (m&0x4)	{												\
			if (FUNC( *(wl_U32*)((wl__Ptr)a+i) , *(wl_U32*)((wl__Ptr)b+i) )) return 0;	\
			i += 4;													\
		}															\
																	\
		return 1;													\
	}
#endif

/**
 * \brief	Array Allocate and set 0
 * \def		WL_AA0
 * \param	s Size
 * \return	wl_Vo*
 */
#define WL_AA0(s)	(wl_afl(s, NULL, 1, ""))

/** \brief	Array Not Logical
 *	\def	wl_antl(s,a,b)
 *	\param	s Size
 *	\param	a
 *	\param	b
 */
#define wl_antl(s,a,b)	(!(wl_anol((s),(a),(b))))

/**	\def	wl_ann(s,a,b)
 *	\param	s	size of the operands in bytes
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes logical NAND to the operand A and B to `s` bytes and assignes
			the result in array R
 *	\return	True or false
 */
#define wl_annl(s,a,b)	(!(wl_aanl((s),(a),(b))))

/**	\def	wl_anorl(s,a,b)
 *	\param	s	size of the operands in bytes
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes logical NOR to the operand A and B to `s` bytes
 *	\return True or false
 */
#define wl_anrl(s,a,b)	(!(wl_aorl((s),(a),(b))))

/**	\fn		wl_anxl(s,a,b)
 *	\param	s	size of the operands in bytes
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes logical NXOR to the operand A and B to `s` bytes
 *	\return	The array of object that have been exclusively disjuncted and inversed
 */
#define wl_anxl(s,a,b)	(!(wl_axrl((s),(a),(b))))

/** \brief	Array Not Equal
 *	\def	wl_anq(s,a,b)
 *	\param	s Size
 *	\param	a
 *	\param	b
 */
#define wl_anq(s,a,b)	(!(wl_aeq((s),(a),(b))))

/** \brief	Array Less than or eQual to
 *	\def	wl_alq(s,a,b)
 *	\param	s Size
 *	\param	a
 *	\param	b
 */
#define wl_alq(s,a,b)	(!(wl_agt((s),(a),(b))))


/** \brief	Array Greater than or eQual to
 *	\def	wl_agq(s,a,b)
 *	\param	s Size
 *	\param	a
 *	\param	b
 */
#define wl_agq(s,a,b)	(!(wl_alt((s),(a),(b))))




/***
 *    ######## ##    ## ########  ########  ######  
 *       ##     ##  ##  ##     ## ##       ##    ## 
 *       ##      ####   ##     ## ##       ##       
 *       ##       ##    ########  ######    ######  
 *       ##       ##    ##        ##             ## 
 *       ##       ##    ##        ##       ##    ## 
 *       ##       ##    ##        ########  ######  
 */
/**
 * \brief	wl_Vo* or integer
 * \typedef	wl_Vopu
 * \typedef wl_vopu
 * \typedef	wl_Vopi
 * \typedef	wl_vopi
 * 
 * A type for functions that return wl_Vo* and an integer
 */
typedef wl_Vo* wl_Vopu, wl_vopu, wl_Vopi, wl_vopi;
/**
 * \brief	Flags for searching data in memory (+ strings)
 * \typedef	WL_SEARCH_FLAGS
 * \enum	WL_SEARCH_FLAGS
 */
typedef enum WL_SEARCH_FLAGS {
	WL_SEARCH_NORMAL	= (wl_U8)0,	/**< Search from the beginning */
	WL_SEARCH_REVERSE	= (wl_U8)1,	/**< Search from the end */
	WL_SEARCH_COUNT		= (wl_U8)2	/**< Count the occurances */
} WL_SEARCH_FLAGS;



/***
 *    ######## ##     ## ##    ##  ######   ######  
 *    ##       ##     ## ###   ## ##    ## ##    ## 
 *    ##       ##     ## ####  ## ##       ##       
 *    ######   ##     ## ## ## ## ##        ######  
 *    ##       ##     ## ##  #### ##             ## 
 *    ##       ##     ## ##   ### ##    ## ##    ## 
 *    ##        #######  ##    ##  ######   ######  
 */
/* Array Assignment */
EXTERN wl_Vo* wl_aas(const wl_U32 s, wl_Vo* a, const wl_Vo* const restrict b);
EXTERN ADECL1(wl_ant);		/* Array NOT */
EXTERN ADECL2(wl_aan);		/* Array AND */
EXTERN ADECL2(wl_aor);		/* Array OR */
EXTERN ADECL2(wl_axr);		/* Array XOR */
EXTERN ADECL2(wl_ann);		/* Array AND */
EXTERN ADECL2(wl_anr);		/* Array OR */
EXTERN ADECL2(wl_anx);		/* Array XOR */

EXTERN ADECL1B(wl_anol);	/* Array Logical No Operation */
EXTERN ADECL2B(wl_aanl);	/* Array Logical AND */
EXTERN ADECL2B(wl_aorl);	/* Array Logical OR */
EXTERN ADECL2B(wl_axrl);	/* Array Logical XOR */
EXTERN ADECL2B(wl_aeq);		/* Array Equals */
EXTERN ADECL2B(wl_agt);		/* Array Greater Than */
EXTERN ADECL2B(wl_alt);		/* Array Less Than */

EXTERN wl_Vo*	wl_afl(	const	wl_U32	sa, 
								wl_Vo*	a, 
								wl_U32	sb, 
								wl_Vo*	b	);

EXTERN wl_Vopu	wl_asb(	const	wl_Vo* restrict const	src,
						const	wl_U32					srcSize,
						const	wl_U8					_byte,
						const	WL_SEARCH_FLAGS			flags	);


EXTERN wl_Vopu	wl_asa(	const	wl_Vo* restrict const	src,
						const	wl_U32					srcSize,
						const	wl_Vo* restrict const	target,
								wl_U32					targetSize,
						const	WL_SEARCH_FLAGS			flags	);



#endif
