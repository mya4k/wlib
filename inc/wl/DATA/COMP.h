/*********************************************************
 * This include file defines proprocessor definitions.   *
 * These macros if define indicated that such compiler   *
 * is used. The value of the macro is the compiler       *
 * version.                                              *
 *********************************************************/
 
#ifndef COMP_H
#define COMP_H

/* ACC */
#if !defined(CM_ACC) && defined(_ACC_)
#define CM_ACC
#endif /* ACC */

/* Altium MicroBlaze C */
#if !defined(CM_CMB) && defined(__CMB__)
#if defnied(__BUILD__)
#define CM_CMB __BUILD__
#else
#define CM_CMB
#endif
#endif /* Altium MicroBlaze C */

/* Altium C-to-Hardware */
#if !defined(CM_ALTIUM) && defined(__CHC__)
#if defnied(__BUILD__)
#define CM_ALTIUM __BUILD__
#else
#define CM_ALTIUM
#endif
#endif /* Altium C-to-Hardware */

/* Amsterdam Compiler Kit */
#if !defined(CM_ACK) && defined(__ACK__)
#define CM_ACK
#endif /* Amsterdam Compiler Kit */

/* ARM Compiler */
#if !defined(CM_ARM) && defined(__CC_ARM)
#if defnied(__ARMCC_VERSION)
#define CM_ARM __ARMCC_VERSION
#else
#define CM_ARM
#endif
#endif /* ARM Compiler */

/* Aztec C */
#if !defined(CM_AZTEC) && defined(AZTEC_C)
#if defined(__VERSION)
#define CM_AZTEC __VERSION
#else
#define CM_AZTEC
#endif
#endif /* Aztec C */

/* Borland C++ */
#if !defined(CM_BORLAND) && defined(__BORLANDC__)
#defined CM_BORLAND __BORLANDC__
#endif /* Borland C++ */

/* CC65 */
#if !defined(CM_CC65) && defined(__CC65__)
#define CM_CC65 __CC65__
#endif /* CC65 */

/* Clang */
#if !defined(CM_CLANG) && defined(__clang__)
#if defined(__clang_version__)
#define CM_CLANG __clang_version__
#else	/* defined(__clang_version__) */
#define CM_CLANG 0
#endif	/* defined(__clang_version__) */
#endif	/* Clang */

/* Comeau C++ */
#if !defined(CM_COMO) && defined(__COMO_VERSION__)
#if     defined(__COMO_VERSION__)
#define CM_COMO __COMO_VERSION__
#elif   defined(__COMO__)
#define  CM_COMO
#endif
#endif /* Comeau C++ */

/* Compaq C/C++ */
#if defined(__DECC) || defined(__DECCXX)
#if defined(__DECC_VER)
#define CM_DECC __DECC_VER
#elif defined(__DECCXX_VER)
#define CM_DECC __DECCXX_VER
#else
#define CM_DECC __DECC_VER
#endif /* Compaq C/C++ */

/* To be continued */

/*
#if !defined(CM_) && defined()
#define
#endif 
*/

/* GNU C */
#if !defined(CM_GCC) && defined(__GNUC__) && !defined(__clang__)
#if __GNUC__ >= 3
#define CM_GCC __GNUC__ * 100 + __GNUC_MINOR__ * 10 + __GNUC_PATCHLEVEL__
#else	/* __GNUC__ >= 3 */
#define CM_GCC __GNUC__ * 100 + __GNUC_MINOR__ * 10
#endif	/* __GNUC__ >= 3 */
#endif	/* GNU C */

/* Microsoft Visual C++ */
#if !defined(CM_MSC) && defined(_MSC_VER)
#define CM_MSC _MSC_VER
#endif /* Microsoft Visual C++ */

/* MinGW */
#if !defined(CM_MINGW) && defined(__MINGW32__)
#define CM_MINGW 0
#endif /* MinGW */

#endif