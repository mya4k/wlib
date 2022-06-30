#ifndef WL_CONFIG_H
#define WL_CONFIG_H	1



/*********************************************************************************
 *                                   CONSTANTS                                   *
 *********************************************************************************/
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



/*********************************************************************************
 *                                OVERALL OPTIONS                                *
 *********************************************************************************/

/* C language */
#if !defined(WL_CONF_C) && defined(__STDC__)
#	ifdef __STDC_VERSION__
#		define WL_CONF_C	__STDC_VERSION__
#	else	/* __STDC_VERSION__ */
#		define WL_CONF_C	WL_CONF_VER_C89
#	endif	/* __STDC_VERSION__ */
#endif	/*  !defined(WL_CONF_C) && defined(__STDC__) */

/* C++ language */
#if !defined(WL_CONF_CPP) && defined(__cplusplus)
#	define WL_CONF_C	__cplusplus
#endif	/* !defined(WL_CONF_CPP) && defined(__cplusplus) */

/* Optimization */
#ifndef WL_CONF_OPTIMIZE
#	define WL_CONF_OPTIMIZE	WL_CONF_SPEED
#endif	/* WL_CONF_OPTIMIZE */

/* Use built-in functions provided by the compiler (apart from built-in 
 * ISO C library function) */
#define WL_CONF_BUILT_IN	1

/* Use of C library in implementation */
#define WL_CONF_LIBC		1

/* Use of C++ library in implementation */
#ifdef WL_CONF_CPP
#	define WL_CONF_LIBCPP	1
#else
#	define WL_CONF_LIBCPP	0
#endif

/* Enabling `WL_CONF_LIBC` or `WL_CONF_LIBCPP` also enabled next options */
#if WL_CONF_LIBC || WL_CONF_LIBCPP

#	define	WL_CONF_LIMITS	1
#	define	WL_CONF_STDINT	1
#	define	WL_CONF_STDLIB	1

#endif	/* WL_CONF_LIBC || WL_CONF_LIBCPP */



/*********************************************************************************
 *                                    HEADERS                                    *
 *********************************************************************************/
/* Use of <limits.h> in implementation */
#	ifndef WL_CONF_LIMITS
#		define WL_CONF_LIMITS	0
#	endif /* WL_CONF_LIMITS */

/* Use of <stdint.h> in implementation */
#	ifndef WL_CONF_STDINT
#		define WL_CONF_STDINT	0
#	endif /* WL_CONF_STDINT */

/* Use of <stdlib.h> in implementation */
#	ifndef WL_CONF_STDLIB
#		define WL_CONF_STDLIB	0
#	endif /* WL_CONF_STDLIB */



/*********************************************************************************
 *                                     TYPES                                     *
 *********************************************************************************/
#ifndef	WL_CONF_FIXED
#	if WL_CONF_OPTIMIZE&4 == WL_CONF_MEMORY
#		define WL_CONF_FIXED	WL_CONF_LEAST
#	else
#		define	WL_CONF_FIXED	WL_CONF_FAST
#	endif	/* WL_CONF_OPTIMIZE&4 == WL_CONF_MEMORY */
#endif	/* WL_CONF_FIXED */

#endif
