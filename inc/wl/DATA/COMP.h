/*********************************************************
 * This include file defines proprocessor definitions.   *
 * These macros if define indicated that such compiler   *
 * is used. The value of the macro is the compiler       *
 * version.                                              *
 *********************************************************/
 
#ifndef COMP_H
#define COMP_H

/* Clang Compiler */
#if !defined(CM_CLANG) && defined(__clang__)
#if defined(__clang_version__)
#define CM_CLANG __clang_version__
#else	/* defined(__clang_version__) */
#define CM_CLANG 0
#endif	/* defined(__clang_version__) */
#endif	/* Clang Compiler */

/* GNU C Compiler */
#if !defined(CM_GCC) && defined(__GNUC__) && !defined(__clang__)
#if __GNUC__ >= 3
#define CM_GCC __GNUC__.__GNUC_MINOR__.__GNUC_PATCHLEVEL__
#else	/* __GNUC__ >= 3 */
#define CM_GCC __GNUC__.__GNUC_MINOR__
#endif	/* __GNUC__ >= 3 */
#endif	/* GNU C Compiler */

/* Microsoft Visual C++ Compiler */
#if !defined(CM_MSC) && defined(_MSC_VER)
#define CM_MSC _MSC_VER
#endif

/* MinGW Compiler */
#if !defined(CM_MINGW) && defined(__MINGW32__)
#define CM_MINGW 0
#endif

#endif