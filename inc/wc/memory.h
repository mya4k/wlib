/**
 * \file	memory.h
 * \author	Wispy (wspvlv@gmail.com)
 * \brief	Memory allocation and deallocation functions
 * \version 0.1
 * \date	2021-07-28
 */
#ifndef WC_MEMORY_H
#define WC_MEMORY_H



#include <wc/core.h>		/* EXTERN */
#include <wc/types.h>
#include <wc/sys/comp.h>



#ifndef NO_SHORT_NAMES
#define mal		wl_mal
#define mfr		wl_mfr
#define MSize	wl_MSize
#define Msz		wl_Msz
#define MSZB	WL_MSZB
#define MChunk	wl_MChunk
#endif



#define WL_MSZB	WL_PTB
#define WL_MSZM	WL_PTM
#if WL_MSZB == 64
#define WL_MSZX WL_I64X
#else
#define WL_MSZX	WL_I32X
#endif



#if defined(CM_GCC) || PTB < INB
#define PEDANTIC_COMPLIENT	0
#else
#define PEDANTIC_COMPLIENT	1
#endif



#if PEDANTIC_COMPLIENT

#	if PTB == 32
#		define GET_PTR2NEXT(i)		((*(wl_MChunk*)(i))&WL_I32X)
#		define GET_ALLOCATED(i)		((*(wl_MChunk*)(i))&WL_I32N)
#		define PTR2NEXT_2_PTR(i)		\
		(GET_PTR2NEXT(i) < (wl__Ptr)(i)	\
		? GET_PTR2NEXT(i) | WL_I32N		\
		: GET_PTR2NEXT(i) | ((wl__Ptr)heap&WL_I32N))
#	else
#		define GET_PTR2NEXT(i)		((*(wl_MChunk*)(i))&WL_I64X)
#		define GET_ALLOCATED(i)		((*(wl_MChunk*)(i))&WL_I64N)
#		define PTR2NEXT_2_PTR(i)		\
		(GET_PTR2NEXT(i) < (wl__Ptr)(i)	\
		? GET_PTR2NEXT(i) | WL_I64N		\
		: GET_PTR2NEXT(i) | ((wl__Ptr)heap&WL_I64N))
#	endif
#else
#	if PTB == 32
#		define PTR2NEXT_2_PTR(i)						\
	(((wl_MChunk*)(i))->ptr2next < (wl__Ptr)(i)			\
	? (wl__Ptr)(((wl_MChunk*)(i))->ptr2next) | WL_I32N 	\
	: (wl__Ptr)(((wl_MChunk*)(i))->ptr2next) | ((wl__Ptr)heap&WL_I32N))
#	else
#		define PTR2NEXT_2_PTR(i)						\
	(((wl_MChunk*)(i))->ptr2next < (wl__Ptr)(i)			\
	? (wl__Ptr)(((wl_MChunk*)(i))->ptr2next) | WL_I64N 	\
	: (wl__Ptr)(((wl_MChunk*)(i))->ptr2next) | ((wl__Ptr)heap&WL_I64N))
#	endif
#endif



#define MCHUNKOF(X)		((wl_MChunk*)((wl__Ptr)(X)-sizeof(wl_MChunk)))


#ifndef REGION_TYPES
/**
 * \brief	Memory chunks for dynamic allocation
 * \typedef	MChunk
 */
typedef struct wl_MChunk {
#if defined(CM_GCC) && !defined(__STRICT_ANSI__) || PTB == INB
	_Ptr	allocated:1;		/* Wether the chunk is allocated */
	_Ptr	ptr2next:(PTB-1);	/* Pointer to the next chunk */
#else
	_Ptr	meta;
#endif
	/* The rest is data */
} wl_MChunk;
#endif



/**
 * \brief	Memory size
 * \typedef	wl_MSize
 * \typedef wl_Msz 
 */
typedef wl__Ptr wl_MSize, wl_Msz;


/* Standard library*/
#ifdef USE_STDLIB
#	include <stdlib.h>
#	define wl_mal(size)	malloc(size)
#	define wl_mfr(addr)	free(addr)
#elif defined(OS_UNIXLIKE)
#	define WLMALLOC	1
	EXTERN wl_Vo*	wl_mal(wl_Msz n);
	EXTERN wl_Vo	wl_mfr(wl_Vo* p);
	EXTERN wl_Msz	wl__sizeofmem(wl_Vo* ptr);
#else
#	define wl_mal(size) (void*)0
#	define wl_mfr(addr)	
#endif



#endif
