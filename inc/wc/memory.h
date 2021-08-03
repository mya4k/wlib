/**
 * \file	memory.h
 * \author	Wispy (wspvlv@gmail.com)
 * \brief	Memory allocation and deallocation functions
 * \version 0.1
 * \date	2021-07-28
 */
#ifndef WC_MEMORY_H
#define WC_MEMORY_H



#include <wc/sys/osys.h>
#include <wc/core.h>		/* EXTERN */
#include <wc/types.h>		/* wl_U32 */



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
#include <stddef.h>
typedef wl__Ptr wl_MSize, wl_Msz;



/* Standard library*/
#ifdef USE_STDLIB
#	include <stdlib.h>
#	define wl_mal(addr, size)	malloc(size)
#	define wl_mal0(addr, size)	calloc(size)
#	define wl_mfr(addr, size)	free(addr)
#else
EXTERN Vo*	wl_mal(Msz n);
EXTERN Vo	wl_mfr(Vo* p, Msz n);
#endif



#endif
