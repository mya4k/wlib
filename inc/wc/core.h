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



#ifndef NO_SHORT_NAMES
#	undef	NULL
#	define	NULL	WL_NULL
#	undef	FALSE
#	define	FALSE	WL_FALSE
#	undef	TRUE
#	define	TRUE	WL_TRUE
#endif

#ifndef REGION_C_CPP_COMPATIBILITY
#	ifdef LC_CPP
#		undef	EXTERN
#		define	EXTERN			extern "C"
#		undef	C_DECL_BEGIN
#		define	C_DECL_BEGIN	EXTERN {
#		undef	C_DECL_END
#		define	C_DECL_END		}
#	else
#		undef	EXTERN
#		define	EXTERN			extern
#		undef	C_DECL_BEGIN
#		define	C_DECL_BEGIN
#		undef	C_DECL_END
#		define	C_DECL_END
#	endif
#endif

#ifndef REGION_VALUES
/**
 * \brief Null pointer 
 * \def WL_NULL
 */
#define WL_NULL	((void*)0)
#endif

/* C99 keywords */
#if defined(LG_C) && LG_C < VR_C99 || defined(LG_CPP)
#	ifndef inline
#		define inline
#	endif
#	ifndef restrict
#		define restrict
#	endif
/*
 * `_Complex` and `_Imaginary` will be implimented later
 */
#endif

#endif
