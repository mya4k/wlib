/**
 * \file math.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-08-24
 * 
 * 
 */
#ifndef WL_MATH_H
#define WL_MATH_H	1



#include <wl/types.h>
#include <wl/core.h>


#if !WL_PREFIX
#	define lg2q wl_lg2q
#	define lg2u wl_lg2u
#	define lg2h wl_lg2h
#	define lg2b wl_lg2b
#endif



/**
 * \brief	Binary logarithm (U64)
 * \def		wl_lg2q(z)
 * 
 */
#if WL_BUILTIN_CLZ
#	if		UIB >= U64B
#		define wl_lg2q(z)	(U8)(UIB - 1 - __builtin_clz(z))
#		define wl_lg2u(z)	wl_lg2q(z)
#		define wl_lg2h(z)	wl_lg2q(z)
#		define wl_lg2b(z)	wl_lg2q(z)
#	elif	ULB >= U64B
#		define wl_lg2q(z)	(U8)(ULB - 1 - __builtin_clzl(z))
#		define wl_lg2u(z)	(U8)(UIB - 1 - __builtin_clz(z))
#		define wl_lg2h(z)	wl_lg2u(z)
#		define wl_lg2b(z)	wl_lg2u(z)
#	else
#		define wl_lg2q(z)	(U8)(ULLB - 1 - __builtin_clzll(z))
#		define wl_lg2u(z)	(U8)(ULB - 1 - __builtin_clzl(z))
#		define wl_lg2h(z)	(U8)(UIB - 1 - __builtin_clz(z))
#		define wl_lg2b(z)	wl_lg2h(z)
#	endif
#else
#	define wl_lg2q(z)	wl__lg2q(z)
#	define wl_lg2u(z)	wl__lg2q(z)
#	define wl_lg2h(z)	wl__lg2q(z)
#	define wl_lg2b(z)	wl__lg2q(z)
#endif



#define wl_lg2(z)	_Generic((z),	\
	wl_U8:		wl_lg2b,			\
	wl_U16:		wl_lg2h,			\
	wl_U32:		wl_lg2u,			\
	wl_U64:		wl_lg2q,			\
	wl_I8:		wl_lg2b,			\
	wl_I16:		wl_lg2h,			\
	wl_I32:		wl_lg2u,			\
	wl_I64:		wl_lg2q,			\
	default:	wl_lg2q				\
)



#endif
