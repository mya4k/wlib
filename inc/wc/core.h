/**
 * \file core.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief C & C++ compatibility across standard versions
 * \version 0.1
 * \date 2021-06-29
 * 
 * 
 */
#ifndef WC_CORE_H
#define WC_CORE_H



#include <wc/sys/lang.h>



#ifdef LC_CPP
#	undef	EXTERN
#	define	EXTERN			extern "C"
#	undef	C_DECL_BEGIN
#	define	C_DECL_BEGIN	EXTERN {
#	undef	C_DECL_END
#	define	C_DECL_END		}
#else
#	undef	EXTERN
#	define	EXTERN			extern
#	undef	C_DECL_BEGIN
#	define	C_DECL_BEGIN
#	undef	C_DECL_END
#	define C_DECL_END
#endif

#ifndef NULL
#define NULL	((void*)0)
#endif

#ifndef ERR
#define ERR		
#endif

#include <stdio.h>
#define DEBUG	printf


#endif