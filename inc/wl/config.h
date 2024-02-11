/**
 * \file	new_config.h 
 * \author	Wispy (wspvlv@gmail.com)
 * \brief	Configuration and feature checking
 * \version	0.1
 * \date	2023-01-22
 * 
 * This header defines macros for checking compliance with standards, the
 * compilers in use, compilation target,   
 *
 * The macro is considered "enabled" when it is set to 1 and "disabled" when it * is set to 0.
 * 
 * \todo `WL_WORDSIZE`: Figure which architectures are 32-bit, or what 
 * compilers on what conditions generate code in 32-bit mode.
 */

#ifndef WL_CONFIG_H
#define WL_CONFIG_H	1



/* Overall options */
#ifndef	WL_CONFIG_H_OVERALL

#ifndef WL_VERSION
#	define WL_VERSION	0
#endif

/**
 * \brief Prefix
 * \def WL_PREFIX
 * 
 * The beginning of all WLib global library identifiers starts with `wl_` or
 * `WL_` prefix. This is used in order avoid identifier name overlapping when
 * WLib is used alongside different libraries but also in order enforce ISO C
 * standard compliant identifier naming convention as the design of internal
 * WLib identifier may violate those standards.
 * 
 * However, you can disable `WL_PREFIX`, in order to be able to use WLib
 * global identifier without the prefix. Identifiers in this header have to
 * be used with the prefix *always*.
 * 
 * Remember that all WLib source files have to be compiled with `WL_PREFIX`
 * disabled 
 * 
 * By default `WL_PREFIX` is enabled
 */
#ifndef WL_PREFIX
#	define WL_PREFIX	0
#endif	/* WL_PREFIX */

/**
 * \brief C standard version compliance 
 * \def WL_C
 * 
 * `WL_C` is defined if the compiler is compliant with ISO C. `WL_C` expands to
 * the revision of ISO C standard the compiler is compliant with. 
 */
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

#ifndef WL_C
#	ifdef __STDC__
#		ifdef __STDC_VERSION__
#			define WL_C	__STDC_VERSION__
#		else	/* __STDC_VERSION__ */
#			define WL_C	WL_VER_ANSI
#		endif	/* __STDC_VERSION__ */
#	else
#		define WL_C	0
#	endif	/* __STDC__ */
#endif	/* WL_C */


/**
 * \brief C++ Language
 * \def WL_CPP
 * 
 * `WL_CPP` is defined if the compiler is compliant with ISO C++. `WL_CPP`
 * expands to the revision of ISO C++ standard the compiler is compliant with. 
 */
#define WL_VER_CPP98				199711L
#define WL_VER_CPP11				201103L
#define WL_VER_CPP14				201402L
#define WL_VER_CPP17				201703L
#define WL_VER_CPP20				202002L
#define WL_VER_CPP23				202100L

#ifndef WL_CPP
#	ifdef __cplusplus
#		define WL_CPP	__cplusplus	
#	else
#		define WL_CPP	0
#	endif	/* __cplusplus */
#endif	/* WL_CPP */

/**@{*/
/** \brief Optimization
 * 
 * This option is used to determine which optimizations in the function
 * definition should be prioritized.
 * 
 * Acceptable values:
 * 
 * `WL_OPTIMIZE_SIZE` prioritizes optimizations, which will decrease the size 
 * of object files generated as a result of the compilation of WLib. This is 
 * useful is you want WLib library files to take less space on your system.
 * 
 * `WL_OPTIMIZE_SPEED` prioritizes optimizations, which will increase the
 * execution speed of WLib functions. This configuration is optimal for modern
 * systems. 
 * 
 * `WL_OPTIMIZE_MEMORY` prioritizes optimization, which will decrease the 
 * amount of program memory utilized by functions during execution.
 */
#define WL_OPTIMIZE_NONE			0
#define WL_OPTIMIZE_SIZE			1
#define WL_OPTIMIZE_SPEED			2
#define WL_OPTIMIZE_MEMORY			3
#define WL_OPTIMIZE_SIZE_EXTRA		5
#define WL_OPTIMIZE_SPEED_EXTRA		6
#define WL_OPTIMIZE_MEMORY_EXTRA	7

#ifndef WL_OPTIMIZE
#	ifdef __OPTIMIZE_SIZE__
#		define WL_OPTIMIZE	WL_OPTIMIZE_SIZE
#	else	/* __OPTIMIZE_SIZE__ */
#		define WL_OPTIMIZE	WL_OPTIMIZE_SPEED
#	endif	/* __OPTIMIZE_SIZE__ */
#endif	/* WL_OPTIMIZE */
/**@}*/

/**
 * \brief 	
 * \def		WL_LIBC
 * 
 * When `WL_LIBC` is enabled, it signals the implementation that C library is
 * available and will be used, when possible. Actually, this option's main 
 * function is to enable other options related to use of C library.  
 */
#ifndef WL_LIBC
#	if WL_C
#		define WL_LIBC		1
#	else
#		define WL_LIBC		0
#	endif /* WL_C */
#endif /* WL_LIBC */

/**
 * \brief 	
 * \def		WL_LIBCPP
 * 
 * When `WL_LIBCPP` is enabled, it signals the implementation that C++ library is
 * available and will be used, when possible. Actually, this option's main 
 * function is to enable other options related to use of C library.  
 */
#ifndef WL_LIBCPP
#	if WL_CPP
#		define WL_LIBCPP	1
#	else
#		define WL_LIBCPP	0
#	endif /* WL_CPP */
#endif /* WL_LIBCPP */

#	ifndef WL_STDDEF_H
#		define WL_STDDEF_H	(WL_LIBC || WL_LIBCPP)
#	endif	/* WL_STDDEF_H */

/* #if WL_LIBC || WL_LIBCPP */
#	ifndef WL_LIMITS_H
#		define WL_LIMITS_H	(WL_LIBC || WL_LIBCPP)
#	endif	/* WL_LIMITS_H */

#	ifndef WL_STDLIB_H
#		define WL_STDLIB_H	(WL_LIBC || WL_LIBCPP)
#	endif	/* WL_STDLIB_H */

#	ifndef WL_STRING_H
#		define WL_STRING_H	(WL_LIBC || WL_LIBCPP)
#	endif	/* WL_STRING_H */

#	if WL_C >= WL_VER_C99
#		ifndef WL_STDINT_H
#			define WL_STDINT_H	(WL_LIBC || WL_LIBCPP)
#		endif	/* WL_STDINT_H */ 
#	else
#		define WL_STDINT_H		0
#	endif /* WL_C >= WL_VER_C99 */

#	ifndef WL_STDARG_H
#		define WL_STDARG_H	(WL_LIBC || WL_LIBCPP)
#	endif
/* #endif	 *//* WL_LIBC | WL_LIBCPP */

/**
 * \brief <_mingw_mac.h>
 * \def WL__MINGW_MAC_H
 * 
 * Whether the <_mingw_mac.h> header is available 
 */
#ifndef WL__MINGW_MAC_H
#	if defined(__MINGW32__) || defined(__MINGW64__)
#		define WL__MINGW_MAC_H	1
#	else	/* defined(__MINGW32__) || defined(__MINGW64__) */
#		define WL__MINGW_MAC_H	0
#	endif	/* defined(__MINGW32__) || defined(__MINGW64__) */
#endif	/* WL__MINGW_MAC_H */

#endif	/* WL_CONFIG_H_OVERALL */

/* Architectures */
#ifndef WL_CONFIG_H_ARCHITECTURE

/**
 * \brief	Word size
 * \def		WL_WORDSIZE
 * 
 * The size of a word in a current architecture  
 */
#ifndef WL_WORDSIZE
#	ifdef	__WORDSIZE
#		define WL_WORDSIZE	__WORDSIZE
#	elif	WL_CC65
#		define WL_WORDSIZE	32
#	else	/* __WORDSIZE */
#		define WL_WORDSIZE	64
#	endif	/* __WORDSIZE */
#endif	/* WL_WORDSIZE */

/**@{*/
/**
 * \brief Data Model
 * 
 * `WL_DATAMODEL` is a macro that expands to a macro signifying the type of
 * data model of the target machine. 
 * `WL_DATAMODEL` may be any of the next acceptable values:
 * -	`WL_DM_UNKNOWN` -- assigned when the data model could not be discovered
 * -	`WL_IP16`	-- 8/16/16/32/16
 * -	`WL_LP32`	-- 8/16/16/32/32
 * -	`WL_ILP32`	-- 8/16/32/32/32
 * -	`WL_LLP64`	-- 8/16/32/32/64
 * -	`WL_LP64`	-- 8/16/32/64/64
 * -	`WL_ILP64`	-- 8/16/64/64/64
 * -	`WL_SILP64`	-- 8/64/64/64/64
 * 
 * If this macro is set to `WL_DM_UNKOWN` or an invalid value, 
 */
#define WL_DM_UNKNOWN	0
#define WL_IP16			1
#define WL_LP32 		2
#define WL_ILP32		3
#define WL_LLP64		4
#define WL_LP64			5
#define WL_ILP64		6
#define WL_SILP64		7

#ifndef WL_DATAMODEL

#	if defined(__IP16__) || defined(_IP16) || defined(__CC65__)
#		define WL_DATAMODEL	WL_IP16
#	endif	/* defined(__IP16__) || defined(_IP16) || defined(__CC65__) */

#	if defined(__LP32__) || defined(_LP32)
#		define WL_DATAMODEL	WL_LP32
#	endif	/* defined(__LP32__) || defined(_LP32) */

#	if defined(__ILP32__) || defined(_ILP32)
#		define WL_DATAMODEL	WL_ILP32
#	endif	/* defined(__ILP32__) || defined(_ILP32) */

#	if defined(__LLP64__) || defined(_LLP64)
#		define WL_DATAMODEL	WL_LLP64
#	endif	/* defined(__LLP64__) || defined(_LLP64) */

#	if defined(__LP64__) || defined(_LP64)
#		define WL_DATAMODEL	WL_LP64
#	endif	/* defined(__LP64__) || defined(_LP64) */

#	if defined(__ILP64__) || defined(_ILP64)
#		define WL_DATAMODEL	WL_ILP64
#	endif	/* defined(__ILP64__) || defined(_ILP64) */

#	if defined(__SILP64__) || defined(_SILP64)
#		define WL_DATAMODEL	WL_SILP64
#	endif	/* defined(__SILP64__) || defined(_SILP64) */

#	ifndef WL_DATAMODEL
#		define	WL_DATAMODEL	WL_DM_UNKNOWN
#	endif	/* WL_DATAMODEL */
/**@}*/

#endif	/* WL_DATAMODEL */

#endif	/* WL_CONFIG_H_ARCHITECTURE */



#ifndef WL_CONFIG_H_COMPILERS

/**
 * \brief	CC65 compiler
 * \def		WL_CLANG
 * If compiler is CC65, this macro is expands to the hex version of the compiler
 */ 
#ifndef WL_CC65
#	ifdef __CC65__
#		define WL_CC65	__CC65__
#	else	/* __CC65__ */
#		define WL_CC65	0
#	endif	/* __CC65__ */
#endif	/* WL_CC65 */

/**
 * \brief	Clang compiler
 * \def		WL_CLANG
 * If compiler is Clang, this macro is expands to the major version of Clang
 */ 
#ifndef WL_CLANG
#	ifdef __clang__
#		define WL_CLANG 	__clang_version__
#	else	/* __clang__ */
#		define WL_CLANG		0
#	endif	/* __clang__ */
#endif	/* WL_CLANG */

/**
 * \brief	GCC compiler
 * \def		WL_GCC
 * If compiler is GCC, this macro is expands to the major version of GCC
 */ 
#ifndef WL_GCC
#	if defined(__GNUC__) \
	&& !(defined(__clang__) || defined(__MINGW64__) || defined(__MINGW32__))
#		define WL_GCC		__GNUC__
#	else	/* defined(__GNUC__)... */
#		define WL_GCC		0
#	endif	/* defined(__GNUC__)... */
#endif	/* WL_GCC */


/**
 * \brief	MinGW32 compiler
 * \def		WL_MINGW32
 * If compiler is MinGW32, this macro is expands to the major version of
 * MinGW32
 */ 
#ifndef WL_MINGW32
#	ifdef __MINGW32__
#		if WL__MINGW_MAC_H
#			include <_mingw_mac.h>
#			define	WL_MINGW32		__MINGW32_MAJOR_VERSION
#		else	/* WL__MINGW_MAC_H */
#			define WL_MINGW32		1
#		endif	/* WL__MINGW_MAC_H */
#	else	/* __MINGW32__ */
#		define	WL_MINGW32	0
#	endif	/* __MINGW32__ */
#endif	/* WL_MINGW32 */

/**
 * \brief	MinGW-w64 compiler
 * \def		WL_MINGW32
 * If compiler is MinGW-w64, this macro is expands to the major version of
 * MinGW-w64
 */
#ifndef WL_MINGW64
#	ifdef __MINGW64__
#		if WL__MINGW_MAC_H
#			include <_mingw_mac.h>
#			define	WL_MINGW64		__MINGW64_MAJOR_VERSION
#		else	/* WL__MINGW_MAC_H */
#			define WL_MINGW64		1
#		endif	/* WL__MINGW_MAC_H */
#	else	/* __MINGW64__ */
#		define	WL_MINGW64	0
#	endif	/* __MINGW64__ */
#endif	/* WL_MINGW64 */

/**
 * \brief	MinGW compiler
 * \def		WL_MINGW
 * If compiler is MinGW32 or MinGW-w64, this macro is expands 1
 */
#ifndef WL_MINGW
#	if defined(__MINGW32__) || defined(__MINGW64__)
#		define	WL_MINGW		1
#	else	/* defined(__MINGW32__) || defined(__MINGW64__) */
#		define	WL_MINGW		0
#	endif	/* defined(__MINGW32__) || defined(__MINGW64__) */
#endif	/* WL_MINGW */

/**
 * \brief	Compiler with GNU extensions 
 * \def		WL_GNUC
 * If compiler has GNU extensions, this macro is expands to 1
 */ 
#ifndef WL_GNUC
#	ifdef __GNUC__
#		define WL_GNUC		__GNUC__
#	else	/* __GNUC__ */
#		define WL_GNUC		0
#	endif	/* __GNUC__ */
#endif	/* WL_GNUC */

/**
 * \brief	GNU extensions version testing
 * \def		__GNUC_PREREQ(major, minor)
 * \param	major	Major version number
 * \param	minor	Minor version number
 * 
 * Returns 1, if the version of GNU extensions is newer or equal to the version
 * provided with parameters
 */
#ifndef __GNUC_PREREQ
#	if defined(__GNUC__) && defined(__GNUC_MINOR__)
#		define __GNUC_PREREQ(major, minor) \
		((__GNUC__ << 16) + __GNUC_MINOR__ >= ((major) << 16) + (minor))
#	else	/* defined(__GNUC__) && defined(__GNUC_MINOR__) */
#		define __GNUC_PREREQ(major, minor)	0
#	endif	/* defined(__GNUC__) && defined(__GNUC_MINOR__) */
#endif	/* __GNUC_PREREQ */

/**
 * \brief	GNU extensions version testing
 * \def		WL_GNUC_PREREQ(major, minor)
 * \param	major	Major version number
 * \param	minor	Minor version number
 * 
 * Returns 1, if the version of GNU extensions is newer or equal to the version
 * provided with parameters
 */
#ifndef WL_GNUC_PREREQ
#	define WL_GNUC_PREREQ(major, minor) __GNUC_PREREQ((major), (minor))
#endif

/**
 * \brief	Clang version testing
 * \def		WL_CLANG_PREREQ(major, minor)
 * \param	major	Major version number
 * \param	minor	Minor version number
 * 
 * Returns 1, if the version of Clang is newer or equal to the version
 * provided with parameters
 */
#ifndef WL_CLANG_PREREQ
#	if defined(WL_CLANG) && defined(__clang_major__) && defined(__clang_minor__) 
#		define WL_CLANG_PREREQ(major, minor)\
	((__clang_major__ << 16) + __clang_minor__ >= ((major) << 16) + (minor))
#	else	/* defined(WL_CLANG) && defined(__clang_major__) && ... */
#		define WL_CLANG_PREREQ(major, minor)	0
#	endif	/* defined(WL_CLANG) && defined(__clang_major__) && ... */
#endif	/* WL_CLANG_PREREQ */

/**
 * \brief	GCC version testing
 * \def		WL_GCC_PREREQ(major, minor)
 * \param	major	Major version number
 * \param	minor	Minor version number
 * 
 * Returns 1, if the version of GCC is newer or equal to the version
 * provided with parameters
 */
#ifndef WL_GCC_PREREQ
#	ifdef WL_GCC
#		define WL_GCC_PREREQ(major, minor)	__GNUC_PREREQ((major), (minor))
#	endif	/* WL_GCC */
#endif	/* WL_GCC_PREREQ */

/**
 * \brief	MinGW32 version testing
 * \def		WL_MINGW32_PREREQ(major, minor)
 * \param	major	Major version number
 * \param	minor	Minor version number
 * 
 * Returns 1, if the version of MinGW32 is newer or equal to the version
 * provided with parameters
 */
#ifndef WL_MINGW32_PREREQ
#	if defined(WL_MINGW32) && !defined(WL_MINGW64)\
	&& defined(__MINGW32_VERSION_MAJOR) && defined(__MINGW32_VERSION_MINOR) 
#		define WL_MINGW32_PREREQ(major, minor)\
	((__MINGW32_VERSION_MAJOR << 16) + __MINGW32_VERSION_MINOR\
	>= ((major) << 16) + (minor))
#	else	/* defined(WL_MINGW32) && !defined(WL_MINGW64) ... */
#		define WL_MINGW32_PREREQ(major, minor)	0
#	endif	/* defined(WL_MINGW32) && !defined(WL_MINGW64) ... */
#endif	/* WL_MINGW32_PREREQ */

/**
 * \brief	MinGW-w64 version testing
 * \def		WL_MINGW64_PREREQ(major, minor)
 * \param	major	Major version number
 * \param	minor	Minor version number
 * 
 * Returns 1, if the version of MinGW-w64 is newer or equal to the version
 * provided with parameters
 */
#ifndef WL_MINGW64_PREREQ
#	if defined(WL_MINGW64) \
	&& defined(__MINGW64_VERSION_MAJOR) && defined(__MINGW64_VERSION_MINOR) 
#		define WL_MINGW64_PREREQ(major, minor)\
	((__MINGW64_VERSION_MAJOR << 16) + __MINGW64_VERSION_MINOR\
	>= ((major) << 16) + (minor))
#	else	/* defined(WL_MINGW64) ... */
#		define WL_MINGW64_PREREQ(major, minor)	0
#	endif	/* defined(WL_MINGW64) ... */
#endif	/* WL_MINGW64_PREREQ */

#endif	/* WL_CONFIG_H_COMPILERS */

#ifndef WL_CONFIG_H_FEATURES

/**
 * \brief `_Bool` type (C99)
 * \def WL__BOOL
 * Whether `_Bool` type is available
 */
#ifndef WL__BOOL
#	if WL_C>=WL_VER_C99
#		define WL__BOOL	1
#	else	/* WL_C>=WL_VER_C99 */
#		define WL__BOOL	0
#	endif	/* WL_C>=WL_VER_C99 */
#endif /* WL__BOOL */

/**
 * \brief `bool` type (C23/C++)
 * \def WL_BOOL
 * Whether `bool` type is available
 */
#ifndef WL_BOOL
#	if WL_C>=WL_VER_C23 || WL_CPP
#		define WL_BOOL	1
#	else	/* WL_C>=WL_VER_C23 || WL_CPP */
#		define WL_BOOL	0
#	endif	/* WL_C>=WL_VER_C23 || WL_CPP */
#endif /* WL__BOOL */

/**
 * \brief Mixed declaration and code
 * \def WL_MIXED
 * Support for mixed declaration and code (C99)
 */
#ifndef WL_MIXED
#	if WL_C>=WL_VER_C99
#		define WL_MIXED	1
#	else	/* WL_C>=WL_VER_C99 */
#		define WL_MIXED	0
#	endif	/* WL_C>=WL_VER_C99 */
#endif /* WL_MIXED */

/**
 * \brief `long long` type (C99/C++11)
 * \def WL_LONG_LONG
 * Support for the `long long` type
 */
#ifndef WL_LONG_LONG
#	if WL_C>=WL_VER_C99 || WL_CPP>=WL_VER_CPP11
#		define WL_LONG_LONG	1
#	else	/* WL_C>=WL_VER_C99 || WL_CPP>=WL_VER_CPP11 */
#		define WL_LONG_LONG	0
#	endif	/* WL_C>=WL_VER_C99 || WL_CPP>=WL_VER_CPP11 */
#endif /* WL_LONG_LONG */

/**
 * \brief `restrict` keyword (C99/C++11)
 * \def WL_RESTRICT	
 * Support for the `restrict` keyword
 */
#ifndef WL_RESTRICT
#	if WL_C>=WL_VER_C99
#		define WL_RESTRICT	1
#	else	/* WL_C>=WL_VER_C99 */
#		define WL_RESTRICT	0
#	endif	/* WL_C>=WL_VER_C99 */
#endif /* WL_RESTRICT */

/**
 * \brief Variadic macro (C99/C++11)
 * \def WL_VA_MACRO
 * Support for variadic macro functions
 */
#ifndef WL_VA_MACRO
#	if WL_C >= WL_VER_C99 ||  WL_CPP >= WL_VER_CPP11
#		define WL_VA_MACRO	1
#	else	/* WL_C >= WL_VER_C99 ||  WL_CPP >= WL_VER_CPP11 */
#		define WL_VA_MACRO	0
#	endif	/* WL_C >= WL_VER_C99 ||  WL_CPP >= WL_VER_CPP11 */
#endif /* WL_VA_MACRO */

/**
 * \brief _Generic keyword (C11)
 * \def WL__GENERIC
 * Support for generic selection
 */
#ifndef WL__GENERIC
#	if WL_C >= WL_VER_C11
#		define WL__GENERIC	1
#	else	/* WL_C >= WL_VER_C11 */
#		define WL__GENERIC	0
#	endif	/* WL_C >= WL_VER_C11 */
#endif /* WL__GENERIC */

/**
 * \brief	`__builtin_` functions 
 * \def		WL_BUILTIN	
 * 
 * This macro permits ALL built-in functions to be used by WLib
 */
#ifndef WL_BUILTIN
#	define WL_BUILTIN	0
#elif WL_BUILTIN == 1
#	ifndef WL_BUILTIN_CLZ
#		define	WL_BUILTIN_CLZ	1
#	endif	/* WL_BUILTIN_CLZ */

#	ifndef WL_BUILTIN_CTZ
#		define	WL_BUILTIN_CTZ	1
#	endif	/* WL_BUILTIN_CTZ */

#	ifndef WL_BUILTIN_POPCOUNT
#		define	WL_BUILTIN_POPCOUNT	1
#	endif	/* WL_BUILTIN_POPCOUNT */
#endif	/* WL_BUILTIN */

#endif	/* WL_CONFIG_H_FEATURES */



#endif	/* WL_CONFIG_H */
