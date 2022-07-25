#ifndef WL_CONFIG_H
#define WL_CONFIG_H	1



/*****************************************************************************
 *                                 CONSTANTS                                 *
 *****************************************************************************/
/* C version constants */
#define WL_CONF_VER_ANSI	199000L
#define WL_CONF_VER_C89		WL_CONF_VER_ANSI
#define	WL_CONF_VER_C90		WL_CONF_VER_ANSI
#define WL_CONF_VER_C94		199409L
#define WL_CONF_VER_C99		199901L
#define WL_CONF_VER_C11		201112L
#define WL_CONF_VER_C17		201710L
#define WL_CONF_VER_C18		WL_CONF_VER_C17
#define WL_CONF_VER_C23		202000L

/* C++ version constants */
#define WL_CONF_VER_CPP98	199711L
#define WL_CONF_VER_CPP11	201103L
#define WL_CONF_VER_CPP14	201402L
#define WL_CONF_VER_CPP17	201703L
#define WL_CONF_VER_CPP20	202002L
#define WL_CONF_VER_CPP23	202100L

/* Optimization constants */
#define WL_CONF_NONE			0
#define WL_CONF_SIZE			1
#define WL_CONF_SPEED			2
#define WL_CONF_MEMORY			3
#define WL_CONF_SIZE_EXTRA		5
#define WL_CONF_SPEED_EXTRA		6
#define WL_CONF_MEMORY_EXTRA	7



/*****************************************************************************
 *                              OVERALL OPTIONS                              *
 *****************************************************************************/

/* C language */
#if !defined(WL_CONF_C) && defined(__STDC__)
#	ifdef __STDC_VERSION__
#		define WL_CONF_C	__STDC_VERSION__
#	else	/* __STDC_VERSION__ */
#		define WL_CONF_C	WL_CONF_VER_ANSI
#	endif	/* __STDC_VERSION__ */
#endif	/*  !defined(WL_CONF_C) && defined(__STDC__) */

/* C++ language */
#if !defined(WL_CONF_CPP) && defined(__cplusplus)
#	define WL_CONF_CPP	__cplusplus
#endif	/* !defined(WL_CONF_CPP) && defined(__cplusplus) */

/* Optimization */
#ifndef WL_CONF_OPTIMIZE
#	ifdef	__OPTIMIZE_SIZE__
#		define WL_CONF_OPTIMIZE WL_CONF_SIZE
#	else
#		define WL_CONF_OPTIMIZE	WL_CONF_SPEED
#	endif
#endif	/* WL_CONF_OPTIMIZE */

/* Use of C library in implementation */
#ifndef WL_CONF_LIBC
#	define WL_CONF_LIBC				1
#endif

/* Use of C++ library in implementation */
#if defined(WL_CONF_CPP) && !defined(WL_CONF_LIBCPP)
#	define WL_CONF_LIBCPP			1
#else
#	define WL_CONF_LIBCPP			0
#endif

/* Enabling `WL_CONF_LIBC` or `WL_CONF_LIBCPP` also enabled next options */
#if WL_CONF_LIBC || WL_CONF_LIBCPP

#	ifndef WL_CONF_LIMITS
#		define WL_CONF_LIMITS			1
#	endif

#	if !defined(WL_CONF_STDINT) && WL_CONF_C >= WL_CONF_VER_C99
#		define	WL_CONF_STDINT		1
#	else
#		define	WL_CONF_STDINT		0
#	endif

#	ifndef WL_CONF_STDLIB
#		define	WL_CONF_STDLIB			1
#	endif

#endif	/* WL_CONF_LIBC || WL_CONF_LIBCPP */



/*****************************************************************************
 *                                 COMPILERS                                 *
 *****************************************************************************/

/* GCC compiler */
#if !defined(WL_CONF_GCC) && defined(__GNUC__)
#	define WL_CONF_GCC				__GNUC__
#else
#	define WL_CONF_GCC				0
#endif

/* Clang compiler */
#if !defined(WL_CONF_CLANG) && defined(__clang__)
#	define WL_CONF_CLANG			1
#else
#	define WL_CONF_CLANG			0
#endif

/* MinGW compiler */
#if !defined(WL_CONF_MINGW) && defined(__MINGW32__)
#	define WL_CONF_MINGW			1
#else
#	define WL_CONF_MINGW			0
#endif

/* MinGW-w64 compiler */
#if !defined(WL_CONF_MINGW64) && defined(__MINGW64__)
#	define WL_CONF_MINGW64			1
#else
#	define WL_CONF_MINGW64			0
#endif

/* CC65 compiler */
#if !defined(WL_CONF_CC65) && defined(__CC65__)
#	define WL_CONF_CC65				__CC65__
#else
#	define WL_CONF_CC65				0
#endif

/* Microsoft Visual C++ compiler */
#if !defined(WL_CONF_MSC) && defined(_MSC_VER)
#	define WL_CONF_MSC				_MSC_FULL_VER
#else
#	define WL_CONF_MSC				0
#endif

/* Whether maximal-width type should alias to types defined by standard library
 */
#ifndef WL_CONF_STDMAX
#	define WL_CONF_STDMAX			0
#endif

/* Use built-in functions provided by the compiler (apart from built-in 
 * ISO C library function) */
#ifndef	WL_CONF_BUILT_IN
#	define WL_CONF_BUILT_IN			1
#endif



/****************************************************************************
 *                             FEATURE CHECKING                             *
 ****************************************************************************/

/* Floating-point types */
#ifndef WL_CONF_FLOAT
#	ifdef __GCC_IEC_559
#		define WL_CONF_FLOAT			__GCC_IEC_559
#	elif defined(__CC65__)
#		define WL_CONF_FLOAT			0
#	else
#		define WL_CONF_FLOAT			1
#	endif
#endif

/* Complex types */
#ifndef WL_CONF_COMPLEX
#	if WL_CONF_FLOAT == 0
#		define WL_CONF_COMPLEX				0
#	elif WL_CONG_C >= WL_CONF_VER_C99
#		if defined(__GCC_IEC_559_COMPLEX)
#			define WL_CONF_COMPLEX			__GCC_IEC_559_COMPLEX
#		else
#			define WL_CONF_COMPLEX			1
#		endif
#	else
#		define WL_CONF_COMPLEX				0
#	endif
#endif

/* C attributes */
#if !defined(WL_CONF_C_ATTRIBUTE) && defined(WL_CONF_C) &&\
	WL_CONF_C >= WL_CONF_VER_C23
#	define WL_CONF_C_ATTRIBUTE		1
#else
#	define WL_CONF_C_ATTRIBUTE		0
#endif

/* C++ attributes */
#if !defined(WL_CONF_CPP_ATTRIBUTE) && defined(WL_CONF_CPP) &&\
	WL_LG_CPP >= WL_CONF_VER_CPP17
#	define WL_CONF_CPP_ATTRIBUTE	1
#else
#	define WL_CONF_CPP_ATTRIBUTE	0
#endif

/* Variadic funtions */
#if !defined(WL_CONF_VARIADIC) && WL_CONF_C >= WL_CONF_VER_C99 ||\
	WL_CONF_CPP >= WL_CONF_VER_CPP11
#	define WL_CONF_VARIADIC			1
#else
#	define WL_CONF_VARIADIC			0
#endif

#if !defined(WL_CONF_VARIADIC_MACRO) && WL_CONF_C >= WL_CONF_VER_C99 ||\
	WL_CONF_CPP >= WL_CONF_VER_CPP11
#	define WL_CONF_VARIADIC_MACRO	1
#else
#	define WL_CONF_VARIADIC_MACRO	0
#endif

/* GCC attributes */
#if	!defined(WL_CONF_GCC_ATTRIBUTE) && WL_CONF_GCC &&\
	(__GNUC__ > 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#	define WL_CONF_GCC_ATTRIBUTE	1
#else
#	define WL_CONF_GCC_ATTRIBUTE	0
#endif

/* Vector extensions */
#if !defined(WL_CONF_GCC_VECTOR) && (WL_CONF_GCC >= 4) && WL_CONF_GCC_ATTRIBUTE
#	define WL_CONF_GCC_VECTOR		1
#else
#	define WL_CONF_GCC_VECTOR		0
#endif



/*****************************************************************************
 *                                  HEADERS                                  *
 *****************************************************************************/
/* Use of <limits.h> in implementation */
#	ifndef WL_CONF_LIMITS
#		define WL_CONF_LIMITS		0
#	endif /* WL_CONF_LIMITS */

/* Use of <stdint.h> in implementation */
#	ifndef WL_CONF_STDINT
#		define WL_CONF_STDINT		0
#	endif /* WL_CONF_STDINT */

/* Use of <stdlib.h> in implementation */
#	ifndef WL_CONF_STDLIB
#		define WL_CONF_STDLIB		0
#	endif /* WL_CONF_STDLIB */



/*****************************************************************************
 *                                   TYPES                                   *
 *****************************************************************************/
#ifndef	WL_CONF_FIXED
#	if WL_CONF_OPTIMIZE&4 == WL_CONF_MEMORY
#		define WL_CONF_FIXED		WL_CONF_LEAST
#	else
#		define WL_CONF_FIXED		WL_CONF_FAST
#	endif	/* WL_CONF_OPTIMIZE&4 == WL_CONF_MEMORY */
#endif	/* WL_CONF_FIXED */

#endif
