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
#	else
#		define WL_OPTIMIZE	WL_OPTIMIZE_SPEED
#	endif
#endif	/* WL_OPTIMIZE */

/* Use of C library in implementation */
#ifndef WL_LIBC
#	define WL_LIBC				1
#endif

/* Use of C++ library in implementation */
#if defined(WL_CPP) && !defined(WL_LIBCPP)
#	define WL_LIBCPP			1
#else
#	define WL_LIBCPP			0
#endif

/* Enabling `WL_LIBC` or `WL_LIBCPP` also enabled next options */
#if WL_LIBC || WL_LIBCPP

#	ifndef WL_C_LIMITS
#		define WL_C_LIMITS			1
#	endif

#	if !defined(WL_C_STDINT) && WL_C >= WL_VER_C99
#		define	WL_C_STDINT		1
#	else
#		define	WL_C_STDINT		0
#	endif

#	ifndef WL_C_STDLIB
#		define	WL_C_STDLIB			1
#	endif

#endif	/* WL_LIBC || WL_LIBCPP */



/*****************************************************************************
 *                                 COMPILERS                                 *
 *****************************************************************************/

/* GCC compiler */
#if !defined(WL_GCC) && defined(__GNUC__)
#	define WL_GCC				__GNUC__
#else
#	define WL_GCC				0
#endif

/* Clang compiler */
#if !defined(WL_CLANG) && defined(__clang__)
#	define WL_CLANG			1
#else
#	define WL_CLANG			0
#endif

/* MinGW compiler */
#if !defined(WL_MINGW) && defined(__MINGW32__)
#	define WL_MINGW			1
#else
#	define WL_MINGW			0
#endif

/* MinGW-w64 compiler */
#if !defined(WL_MINGW64) && defined(__MINGW64__)
#	define WL_MINGW64			1
#else
#	define WL_MINGW64			0
#endif

/* CC65 compiler */
#if !defined(WL_CC65) && defined(__CC65__)
#	define WL_CC65				__CC65__
#else
#	define WL_CC65				0
#endif

/* Microsoft Visual C++ compiler */
#if !defined(WL_MSC) && defined(_MSC_VER)
#	define WL_MSC				_MSC_FULL_VER
#else
#	define WL_MSC				0
#endif

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

/* Floating-point types */
#ifndef WL_C_FLOAT
#	ifdef __GCC_IEC_559
#		define WL_C_FLOAT			__GCC_IEC_559
#	elif defined(__CC65__)
#		define WL_C_FLOAT			0
#	else
#		define WL_C_FLOAT			1
#	endif
#endif

/* Complex types */
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
#endif

/* C attributes */
#if !defined(WL_C_ATTRIBUTE) && defined(WL_C) &&\
	WL_C >= WL_VER_C23
#	define WL_C_ATTRIBUTE		1
#else
#	define WL_C_ATTRIBUTE		0
#endif

/* C++ attributes */
#if !defined(WL_CPP_ATTRIBUTE) && defined(WL_CPP) &&\
	WL_LG_CPP >= WL_VER_CPP17
#	define WL_CPP_ATTRIBUTE	1
#else
#	define WL_CPP_ATTRIBUTE	0
#endif

/* Variadic funtions */
#if !defined(WL_C_VARIADIC)
#	define WL_C_VARIADIC			1
#else
#	define WL_C_VARIADIC			0
#endif

/* Variadic macros */
#if !defined(WL_C_VA_MACRO) && WL_C >= WL_VER_C99 ||\
	WL_CPP >= WL_VER_CPP11
#	define WL_C_VA_MACRO	1
#else
#	define WL_C_VA_MACRO	0
#endif

/* GCC attributes */
#if	!defined(WL_GCC_ATTRIBUTE) && WL_GCC &&\
	(__GNUC__ > 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#	define WL_GCC_ATTRIBUTE	1
#else
#	define WL_GCC_ATTRIBUTE	0
#endif

/* Vector extensions */
#if !defined(WL_GCC_VECTOR) && (WL_GCC >= 4) && WL_GCC_ATTRIBUTE
#	define WL_GCC_VECTOR		1
#else
#	define WL_GCC_VECTOR		0
#endif



/*****************************************************************************
 *                                  HEADERS                                  *
 *****************************************************************************/
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
