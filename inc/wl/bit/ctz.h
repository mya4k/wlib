/**
 * \file ctz.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2024-06-12
 * 
 * ctz1
 * ctz2
 * ctz4
 * ctz8
 * ctz
 */
#ifndef WL_BIT_CTZ_H
#define WL_BIT_CTZ_H	1



#include <wl/config.h>
#include <wl/types.h>
#include <wl/core.h>


/**
 * \brief	Count trailing zeros (Type size generic)
 * \def		wl_ctz(x)
 * \param	x
 * 
 * If WL_BUILTIN_CTZ is disabled, we use de Bruijn sequences in order to do
 * this branchless
 */

/* Use built-in ctz */
#if WL_BUILTIN_CTZ
#	define wl_ctz8(x)		__builtin_ctz(x)
#	define wl_ctz16(x)		__builtin_ctz(x)
#	if WL_INB >= 32
#		define wl_ctz32(x)	__builtin_ctz(x)
#	else
#		define wl_ctz32(x)	__builtin_ctzl(x)
#	endif
#	define wl_ctz64(x)		__builtin_ctzll(x)

#	if WL__GENERIC
#		define wl_ctz(x) _Generic((x),				\
			default:			__builtin_ctz(x),	\
			long:				__builtin_ctzl(x),	\
			long long:			__builtin_ctzll(x),	\
			unsigned long:		__builtin_ctzl(x),	\
			unsigned long long:	__builtin_ctzll(x)	\
		)(x)
#	else
#		define wl_ctz(x)	__builtin_ctzll(x)
#	endif
/* Use de Bruijn series */
#else

#	define WL__DEBRUIJN8	0x17
#	define WL__DEBRUIJN16	0x9AF
#	define WL__DEBRUIJN32	0x4653ADF
#	define WL__DEBRUIJN64	0x218A392CD3D5DBF

#	if	WL_SHORT_FUNCS
#		define wl_ctz8(x)\
		(wl__ctz_table8[((-(U8l)(x)&(U8l)(x)) * WL__DEBRUIJN8) >> 5])
#		define wl_ctz16(x)\
		(wl__ctz_table16[((-(U16l)(x)&(U16l)(x)) * WL__DEBRUIJN16) >> 12])
#	else
#		define wl_ctz8(x)	wl_ctz32(x)
#		define wl_ctz16(x)	wl_ctz32(x)
#	endif

#	if	UMB < 64 || WL_SHORT_FUNCS
#		define wl_ctz32(x)\
		(wl__ctz_table32[(U32l)((-(U32l)(x)&(U32l)(x)) * WL__DEBRUIJN32) >> (U32LB-5)])
#	else
#		define wl_ctz32(x)	wl_ctz64(x)
#	endif

#	if		UMB >= 64
#		define wl_ctz64(x)\
		(wl__ctz_table64[(U64l)((-(U64l)(x)&(U64l)(x)) * WL__DEBRUIJN64) >> (U64LB-6)])
#	else
#		define wl_ctz64(x)	wl_ctz32(x)
#	endif

#	if WL__GENERIC
#		define wl_ctz(x)	wl_genericInt((x), wl_ctz8, wl_ctz16, wl_ctz32,\
			wl_ctz64, wl_ctz8, wl_ctz16, wl_ctz32, wl_ctz64)(x)
#	else
#		define wl_ctz(x)	__builtin_ctzll(x)
#	endif
#endif

#endif
