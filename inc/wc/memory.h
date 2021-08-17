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



#ifndef NO_SHORT_NAMES
#define mal		wl_mal
#define mfr		wl_mfr
#define MSize	wl_MSize
#define Msz		wl_Msz
#define MSZB	WL_MSZB
#endif



#define WL_MSZB	WL_PTB
#define WL_MSZM	WL_PTM
#if WL_MSZB == 64
#define WL_MSZX WL_I64X
#else
#define WL_MSZX	WL_I32X
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
EXTERN Vo*	wl_mal(Msz n);
EXTERN Vo	wl_mfr(Vo* p);
#else
#	define wl_mal(size) (void*)0
#	define wl_mfr(addr)	
#endif



#endif
