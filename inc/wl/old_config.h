/**
 * \file config.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Configuration
 * \version 0.1
 * \date 2023-01-22
 * 
 * \details This header is responsible for feature checking standard complience 
 */

#ifndef WL_CONFIG_H
#define WL_CONFIG_H	1



/*****************************************************************************
 *                                 CONSTANTS                                 *
 *****************************************************************************/
/* C version constants */
#define WL_VER_ANSI					199000L
#define WL_VER_C89					WL_VER_ANSI
#define	WL_VER_C90					WL_VER_ANSI
#define WL_VER_C94					199409L
#define WL_VER_C95					199409L
#define WL_VER_C99					199901L
#define WL_VER_C11					201112L
#define WL_VER_C17					201710L
#define WL_VER_C18					WL_VER_C17
#define WL_VER_C23					202000L

/* C++ version constants */
#define WL_VER_CPP98				199711L
#define WL_VER_CPP11				201103L
#define WL_VER_CPP14				201402L
#define WL_VER_CPP17				201703L
#define WL_VER_CPP20				202002L
#define WL_VER_CPP23				202100L

/* Optimization constants */
#define WL_OPTIMIZE_NONE			0
#define WL_OPTIMIZE_SIZE			1
#define WL_OPTIMIZE_SPEED			2
#define WL_OPTIMIZE_MEMORY			3
#define WL_OPTIMIZE_SIZE_EXTRA		5
#define WL_OPTIMIZE_SPEED_EXTRA		6
#define WL_OPTIMIZE_MEMORY_EXTRA	7

/* */
#define WL_FIXED_LEAST				0
#define WL_FIXED_FAST				1



/*****************************************************************************
 *                              OVERALL OPTIONS                              *
 *****************************************************************************/
#ifndef WL_CONFIG_H_OVERALL

#ifndef WL_PREFIX
#	define WL_PREFIX	0
#endif	/* WL_PREFIX */

/* C language */
#if !defined(WL_C) && defined(__STDC__)
#	ifdef __STDC_VERSION__
#		define WL_C	__STDC_VERSION__
#	else	/* __STDC_VERSION__ */
#		define WL_C	WL_VER_ANSI
#	endif	/* __STDC_VERSION__ */
#endif	/*  !defined(WL_C) && defined(__STDC__) */

/* C++ language */
#if !defined(WL_CPP) && defined(__cplusplus)
#	define WL_CPP	__cplusplus
#endif	/* !defined(WL_CPP) && defined(__cplusplus) */

/* Optimization */
#ifndef WL_OPTIMIZE
#	ifdef	__OPTIMIZE_SIZE__
#		define WL_OPTIMIZE WL_OPTIMIZE_SIZE
#	else	/* 	__OPTIMIZE_SIZE__ */
#		define WL_OPTIMIZE	WL_OPTIMIZE_SPEED
#	endif	/* 	__OPTIMIZE_SIZE__ */
#endif	/* WL_OPTIMIZE */

/* Use of C library in implementation */
#ifndef WL_LIBC
#	define WL_LIBC					0
#endif	/* WL_LIBC */

/* Use of C++ library in implementation */
#if defined(WL_CPP) && !defined(WL_LIBCPP)
#	define WL_LIBCPP				1
#else	/* defined(WL_CPP) && !defined(WL_LIBCPP) */
#	define WL_LIBCPP				0
#endif	/* defined(WL_CPP) && !defined(WL_LIBCPP) */

/* Enabling `WL_LIBC` or `WL_LIBCPP` also enabled next options */
#if WL_LIBC || WL_LIBCPP

#	ifndef WL_C_LIMITS
#		define WL_C_LIMITS			1
#	endif	/* WL_C_LIMITS */

#	if !defined(WL_C_STDINT) && WL_C >= WL_VER_C99
#		define	WL_C_STDINT			1
#	else	/* !defined(WL_C_STDINT) && WL_C >= WL_VER_C99 */
#		define	WL_C_STDINT			0
#	endif	/* !defined(WL_C_STDINT) && WL_C >= WL_VER_C99 */

#	ifndef WL_C_STDLIB
#		define	WL_C_STDLIB			1
#	endif	/* WL_C_STDLIB */

#	ifndef WL_C_STRING
#		define WL_C_STRING			1
#	endif	/* WL_C_STRING */

#endif	/* WL_LIBC || WL_LIBCPP */

/* Word size of the architecture */
#ifndef WL_WORDSIZE
#	ifdef __WORDSIZE
#		define WL_WORDSIZE	__WORDSIZE
#	else	/* __WORDSIZE */
		/**
		 * \todo Figure which architectures are 32-bit, or what compilers on
		 * what conditions generate code in 32-bit mode
		 */
#		define WL_WORDSIZE	64
#	endif	/* __WORDSIZE */
#endif	/* WL_WORDSIZE */

#endif /* WL_CONFIG_H_OVERALL */


/*****************************************************************************
 *                                 COMPILERS                                 *
 *****************************************************************************/
#ifndef WL_CONFIG_H_COMPILERS

/* Clang compiler */
#if !defined(WL_CLANG) && defined(__clang__)
#	define WL_CLANG				1
#else
#	define WL_CLANG				0
#endif

/* CC65 compiler */
#if !defined(WL_CC65) && defined(__CC65__)
#	define WL_CC65				__CC65__
#else
#	define WL_CC65				0
#endif

/* GCC compiler */
#if !defined(WL_GCC) && defined(__GNUC__)
#	define WL_GCC				__GNUC__
#else
#	define WL_GCC				0
#endif

/* MinGW compiler */
#if !defined(WL_MINGW) && defined(__MINGW32__)
#	define WL_MINGW				1
#else
#	define WL_MINGW				0
#endif

/* MinGW-w64 compiler */
#if !defined(WL_MINGW64) && defined(__MINGW64__)
#	define WL_MINGW64			1
#else
#	define WL_MINGW64			0
#endif

/* Microsoft Visual C++ compiler */
#if !defined(WL_MSC) && defined(_MSC_VER)
#	define WL_MSC				_MSC_FULL_VER
#else
#	define WL_MSC				0
#endif

/* GCC compiler */
#if !defined(WL_TCC) && defined(__TINYC__)
#	define WL_TCC				__TINYC__
#else
#	define WL_TCC				0
#endif

#endif /* WL_CONFIG_H_COMPILERS */

/* Whether maximal-width type should alias to types defined by standard library
 */
#ifndef WL_STDMAX
#	define WL_STDMAX			0
#endif

/* Use built-in functions provided by the compiler (apart from built-in 
 * ISO C library function) */
#ifndef	WL_BUILTIN
#	define WL_BUILTIN			1
#endif



/****************************************************************************
 *                             FEATURE CHECKING                             *
 ****************************************************************************/
/* Template */
#ifdef WL_CONFIG_TEMPLATE
#ifdef WL_C_
#	if WL_C>=WL_VER_C99
#		define WL_C_	1
#	else
#		define WL_C_	0
#	endif
#endif /* WL_C_ */
#endif

/* Support for floating-point types */
#ifndef WL_C_FLOAT
#	ifdef __GCC_IEC_559
#		define WL_C_FLOAT			__GCC_IEC_559
#	elif defined(__CC65__)
#		define WL_C_FLOAT			0
#	else
#		define WL_C_FLOAT			1
#	endif
#endif

/* Support for digraphs (C95/C++) */
#ifndef WL_C_DIGRATHS
#	if WL_C>=WL_VER_C95 || defined(WL_CPP)
#		define WL_C_DIGRATHS	1
#	else
#		define WL_C_DIGRATHS	0
#	endif
#endif /* WL_C_DIGRAPHS */

/* Support for _Bool (C99) */
#ifndef WL_C_BOOL
#	if WL_C>=WL_VER_C99
#		define WL_C_BOOL	1
#	else
#		define WL_C_BOOL	0
#	endif
#endif /* WL_C_BOOL */

/* Support for concatenation of narrow and wide characters (C99) */
#ifdef WL_C_CAT_NARWIDE
#	if WL_C>=WL_VER_C99
#		define WL_C_CAT_NARWIDE	1
#	else
#		define WL_C_CAT_NARWIDE	0
#	endif
#endif /* WL_C_CAT_NARWIDE */

/* Complex floating-point type (C99) */
#ifndef WL_C_COMPLEX
#	if WL_C_FLOAT == 0
#		define WL_C_COMPLEX				0
#	elif WL_CONG_C >= WL_VER_C99
#		if defined(__GCC_IEC_559_COMPLEX)
#			define WL_C_COMPLEX			__GCC_IEC_559_COMPLEX
#		else
#			define WL_C_COMPLEX			1
#		endif
#	else
#		define WL_C_COMPLEX				0
#	endif
#endif /* WL_C_COMPLEX */

/* Support for compound initializers (C99) */
#ifndef WL_C_COMPOUND
#	if WL_C>=WL_VER_C99
#		define WL_C_COMPOUND	1
#	else
#		define WL_C_COMPOUND	0
#	endif
#endif /* WL_C_COMPOUND */

/* Support for // commenting (C99)*/
#ifdef WL_C_DSLASH
#	if WL_C>=WL_VER_C99
#		define WL_C_DSLASH	1
#	else
#		define WL_C_DSLASH	0
#	endif
#endif /* WL_C_DSLASH */

/* Support for empty arguments in macro definitions (C99) */
#ifdef WL_C_EMPTY_ARGS
#	if WL_C>=WL_VER_C99
#		define WL_C_EMPTY_ARGS	1
#	else
#		define WL_C_EMPTY_ARGS	0
#	endif
#endif /* WL_C_EMPTY_ARGS */

/* Support for `_Exit()` (C99) */
#ifdef WL_C__EXIT
#	if WL_C>=WL_VER_C99
#		define WL_C__EXIT	1
#	else
#		define WL_C__EXIT	0
#	endif
#endif /* WL_C__EXIT */

/* Support for flexible array members (C99) */
#ifndef WL_C_FLEXIBLE
#	if WL_C>=WL_VER_C99
#		define WL_C_FLEXIBLE	1
#	else
#		define WL_C_FLEXIBLE	0
#	endif
#endif /* WL_C_FLEXIBLE */

/* Support for declarations in the init-close of the for loops (C99) */
#ifdef WL_C_FOR_DECL
#	if WL_C>=WL_VER_C99
#		define WL_C_FOR_DECL	1
#	else
#		define WL_C_FOR_DECL	0
#	endif
#endif /* WL_C_FOR_DECL */

/* Support for __FUNC__ definitions (C99)  */
#ifndef WL_C___FUNC__
#	if WL_C>=WL_VER_C99
#		define WL_C___FUNC__	1
#	else
#		define WL_C___FUNC__	0
#	endif
#endif /* WL_C___FUNC__ */

/* Support for hexadecimal floating-point format (C99) */
#ifndef WL_C_HEXFLOAT
#	if WL_C>=WL_VER_C99
#		define WL_C_HEXFLOAT	1
#	else
#		define WL_C_HEXFLOAT	0
#	endif
#endif /* WL_C_HEXFLOAT */

/* Support for `hh` length specifier (C99) */
#ifdef WL_C_HH
#	if WL_C>=WL_VER_C99
#		define WL_C_HH	1
#	else
#		define WL_C_HH	0
#	endif
#endif /* WL_C_HH */

/* Support for `inline` keyword (C99) */
#ifdef WL_C_INLINE
#	if WL_C>=WL_VER_C99
#		define WL_C_INLINE	1
#	else
#		define WL_C_INLINE	0
#	endif
#endif /* WL_C_INLINE */

/* Support for mixed declaration and code (C99) */
#ifdef WL_C_MIXED
#	if WL_C>=WL_VER_C99
#		define WL_C_MIXED	1
#	else
#		define WL_C_MIXED	0
#	endif
#endif /* WL_C_MIXED */

/* Support for monetary formatting (C99) */
#ifdef WL_C_MONETARY
#	if WL_C>=WL_VER_C99
#		define WL_C_MONETARY	1
#	else
#		define WL_C_MONETARY	0
#	endif
#endif /* WL_C_MONETARY */

/* Support for `ll` length specifier (C99) */
#ifdef WL_C_HH
#	if WL_C>=WL_VER_C99
#		define WL_C_LL	1
#	else
#		define WL_C_LL	0
#	endif
#endif /* WL_C_LL */

/* Support for long long (C99/C++11) */
#ifndef WL_C_LONG_LONG
#	if WL_C>=WL_VER_C99 || WL_CPP>=WL_VER_CPP11
#		define WL_C_LONG_LONG	1
#	else
#		define WL_C_LONG_LONG	0
#	endif
#endif /* WL_C_LONG_LONG */

/* Support for restrict keyword (C99) */
#ifndef WL_C_RESTRICT
#	if WL_C>=WL_VER_C99
#		define WL_C_RESTRICT	1
#	else
#		define WL_C_RESTRICT	0
#	endif
#endif /* WL_C_RESTRICT */

/* Support for trailing comma in enums (C99) */
#ifdef WL_C_TRAILING_ENUM
#	if WL_C>=WL_VER_C99
#		define WL_C_TRAILING_ENUM	1
#	else
#		define WL_C_TRAILING_ENUM	0
#	endif
#endif /* WL_C_TRAILING_ENUM */

/* Support for `va_copy()` (C99) */
#ifdef WL_C_VA_COPY
#	if WL_C>=WL_VER_C99
#		define WL_C_VA_COPY	1
#	else
#		define WL_C_VA_COPY	0
#	endif
#endif /* WL_C_VA_COPY */

/* Support for Variadic macros */
#if defined(WL_VA_MACRO) 
#	if WL_C >= WL_VER_C99 ||  WL_CPP >= WL_VER_CPP11
#		define WL_VA_MACRO	1
#	else
#		define WL_VA_MACRO	0
#	endif
#endif /* WL_VA_MACRO */

/* Implicit int (removed in C99) */
#ifndef WL_C_IMPLICIT_INT
#	if WL_C<WL_VER_C99
#		define WL_C_IMPLICIT_INT	1
#	else
#		define WL_C_IMPLICIT_INT	0
#	endif
#endif /* WL_C_IMPLICIT_INT */

/* `gets` (deprecated in C99, removed in C11) */
#ifndef WL_C_GETS
#	if WL_C<WL_VER_C99
#		define WL_C_IMPLICIT	2
#	else	/* WL_C<WL_VER_C99 */
#		if WL_C<WL_VER_C11
#			define WL_C_GETS	1	/* Deprecated */
#		else	/* WL_C<WL_VER_C11 */
#			define WL_C_GETS	0	/* Removed */
#		endif	/* WL_C<WL_VER_C11 */
#	endif	/* WL_C<WL_VER_C99 */
#endif /* WL_C_GETS */

/* `_Generic` (C11) */
#ifndef WL_C_GENERIC
#	if	WL_C<WL_VER_C11
#		define WL_C_GENERIC	0
#	else	/* WL_C<WL_VER_C11 */
#		define WL_C_GENERIC	1
#	endif	/* WL_C<WL_VER_C11 */
#endif	/* WL_C_GENERIC */

/* Support for bool as a keyword (C++) */
#ifndef WL_CPP_BOOL
#	if WL_CPP
#		define WL_CPP_BOOL	1
#	else
#		define WL_CPP_BOOL	0
#	endif
#endif /* WL_CPP_BOOL */


/* C attributes */
#ifndef WL_C_ATTRIBUTE
#	if defined(WL_C) && WL_C >= WL_VER_C23
#		define WL_C_ATTRIBUTE		1
#	else
#		define WL_C_ATTRIBUTE		0
#	endif
#endif

/* C++ attributes */
#ifndef WL_CPP_ATTRIBUTE
#	if defined(WL_CPP) && WL_LG_CPP >= WL_VER_CPP17
#		define WL_CPP_ATTRIBUTE		1
#	else
#		define WL_CPP_ATTRIBUTE		0
#	endif
#endif

/* Variadic funtions */
#ifndef WL_C_VARIADIC
#	define WL_C_VARIADIC			1
#else
#	define WL_C_VARIADIC			0
#endif

/* `alloca` */
#ifndef WL_ALLOCA
#	if defined(WL_GCC) || defined(WL_CLANG)
#		define WL_C_ALLOCA	1
#	else
#		define WL_C_ALLOCA	0
#	endif
#endif

/* `__has_builtin` (Clang 10) */
#ifndef WL_HAS_BUILTIN
#	if	(WL_CLANG && (__clang_major__ >= 10))\
	||	(WL_GCC && (__GNUC__ >= 10))
#		define WL_HAS_BUILTIN	1
#	else
#		define WL_HAS_BUILTIN	0	/* It's defined later, but it's not working */
#		define __has_builtin(x)	0	
#	endif
#endif

/* `ffs` (4.3BSD) */


/* `__builtin_clz/l/ll()` (GCC 3.4.0, Clang 5.?) */
#ifndef WL_BUILTIN_CLZ
#	if	WL_BUILTIN &&\
		(WL_GCC && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4 || __GNUC__ > 3))\
	||	(WL_CLANG && (__clang_major__ > 5))\
	|| 	__has_builtin(__builtin_clz)
#		define WL_BUILTIN_CLZ	1
#	else
#		define WL_BUILTIN_CLZ	0
#	endif
#endif

/* `__builtin_ctz/l/ll()` (GCC 3.4.0, Clang 5.?) */
#ifndef WL_BUILTIN_CTZ
#	if	WL_BUILTIN &&\
		(WL_GCC && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4 || __GNUC__ > 3))\
	||	(WL_CLANG && (__clang_major__ > 5))\
	|| 	__has_builtin(__builtin_ctz)
#		define WL_BUILTIN_CTZ	1
#	else
#		define WL_BUILTIN_CTZ	0
#	endif
#endif

/* `__builtin_ffs/l/ll()` (GCC 3.4.0, Clang 5.?) */
#ifndef WL_BUILTIN_FFS
#	if	WL_BUILTIN &&\
		(WL_GCC && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4 || __GNUC__ > 3))\
	||	(WL_CLANG && (__clang_major__ > 5))\
	|| 	__has_builtin(__builtin_ctz)
#		define WL_BUILTIN_FFS	1
#	else
#		define WL_BUILTIN_FFS	0
#	endif
#endif

/* GCC attributes */
#if	!defined(WL_GCC_ATTRIBUTE) 
#	if WL_GCC && (__GNUC__ > 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#		define WL_GCC_ATTRIBUTE	1
#	else
#		define WL_GCC_ATTRIBUTE	0
#	endif
#endif

/* Vector extensions */
#if !defined(WL_GCC_VECTOR) && (WL_GCC >= 4) && WL_GCC_ATTRIBUTE
#	define WL_GCC_VECTOR		1
#else
#	define WL_GCC_VECTOR		0
#endif

/* Signedness of `char` */
#  ifdef __CHAR_UNSIGNED__
#   define WL_CHAR_UNSIGNED
#  else
#   define WL_CHAR_SIGNED
#  endif



/*****************************************************************************
 *                                  HEADERS                                  *
 *****************************************************************************/
/* Use of <fenv.h> in implementation */
#	ifndef WL_C_FENV
#		define WL_C_FENV		0
#	endif /* WL_C_FENV */

/* Use of <inttypes.h> in implementation */
#	ifndef WL_C_INTTYPES
#		define WL_C_INTTYPES	0
#	endif /* WL_C_INTTYPES */

/* Use of <iso646.h> in implementation */
#	ifndef WL_C_ISO646
#		define WL_C_ISO646		0
#	endif /* WL_C_ISO646 */

/* Use of <limits.h> in implementation */
#	ifndef WL_C_LIMITS
#		define WL_C_LIMITS		0
#	endif /* WL_C_LIMITS */

/* Use of <stdint.h> in implementation */
#	ifndef WL_C_STDINT
#		define WL_C_STDINT		0
#	endif /* WL_C_STDINT */

/* Use of <stdlib.h> in implementation */
#	ifndef WL_C_STDLIB
#		define WL_C_STDLIB		0
#	endif /* WL_C_STDLIB */

/* Use of <string.h> in implementation */
#	ifndef WL_C_STRING
#		define WL_C_STRING		0
#	endif /* WL_C_STRING */

/* Use of <tgmath.h> in implementation */
#	ifndef WL_C_TGMATH
#		define WL_C_TGMATH		0
#	endif /* WL_C_TGMATH */

/* Use of <wchar.h> in implementation */
#	ifndef WL_C_WCHAR
#		define WL_C_WCHAR		0
#	endif /* WL_C_WCHAR */

/* Use of <wctype.h> in implementation */
#	ifndef WL_C_WCTYPE
#		define WL_C_WCTYPE		0
#	endif /* WL_C_WCTYPE */



/*****************************************************************************
 *                                   TYPES                                   *
 *****************************************************************************/

#ifndef	WL_FIXED
#	if WL_OPTIMIZE&4 == WL_OPTIMIZE_MEMORY
#		define WL_FIXED		WL_FIXED_LEAST
#	else
#		define WL_FIXED		WL_FIXED_FAST
#	endif	/* WL_OPTIMIZE&4 == WL_OPTIMIZE_MEMORY */
#endif	/* WL_FIXED */

#endif
