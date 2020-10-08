#ifndef COMP_H
#define COMP_H

#if !defined(NO)
#define NO(X) X 
#endif

/* ACC */
#if !defined(CM_ACC) && defined(_ACC_)
#define CM_ACC
#endif /* ACC */

/* Altium MicroBlaze C */
#if !defined(CM_CMB) && defined(__CMB__)
#if defnied(__BUILD__)
#define CM_CMB __BUILD__
#else
#define CM_CMB 0
#endif
#endif /* Altium MicroBlaze C */

/* Altium C-to-Hardware */
#if !defined(CM_ALTIUM) && defined(__CHC__)
#if defnied(__BUILD__)
#define CM_ALTIUM __BUILD__
#else
#define CM_ALTIUM 0
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
#define CM_ARM 0
#endif
#endif /* ARM Compiler */

/* Aztec C */
#if !defined(CM_AZTEC) && defined(AZTEC_C)
#if defined(__VERSION)
#define CM_AZTEC __VERSION
#else
#define CM_AZTEC 0
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
#else
#define CM_CLANG 0
#endif
#endif  /* Clang */

/* Comeau C++ */
#if !defined(CM_COMO) && defined(__COMO_VERSION__)
#if		defined(__COMO_VERSION__)
#define CM_COMO __COMO_VERSION__
#elif	defined(__COMO__)
#define CM_COMO 0
#endif
#endif /* Comeau C++ */

/* Compaq C/C++ */
#if defined(__DECC) || defined(__DECCXX)
#if		defined(__DECC_VER)
#define CM_DECC __DECC_VER
#elif	defined(__DECCXX_VER)
#define CM_DECC __DECCXX_VER
#else
#define CM_DECC __DECC_VER
#endif
#endif /* Compaq C/C++ */

/* Convex C */
#if !defined(CM_CONVEX) && defined(__convexc__)
#define CM_CONVEX
#endif /* Convex C */

/* CompCert */
#if !defined(CM_COMPCERT) && defined(__COMPCERT__)
#define CM_COMPCERT
#endif /* CompCert */

/* Coverity C/C++ Static Analyzer */
#if !defined(CM_COVERITY) && defined(__COVERITY__)
#define CM_COVERITY
#endif /* Coverity C/C++ Static Analyzer */

/* Cray C */
#if !defined(CM_CRAY) && defined(_CRAYC)
#define CM_CRAY NO(_RELEASE)NO(_RELEASE_MINOR)
#endif /* Cray C */

/* Diab C/C++ */
#if !defined(CM_DCC) && defined(__DCC__)
#if defined(__VERSION_NUMBER__)
#define CM_DCC __VERSION_NUMBER__
#else
#define CM_DCC 0
#endif
#endif /* Diab C/C++ */

/* DICE C */
#if !defined(CM_DICE) && defined(_DICE)
#define CM_DICE
#endif /* DICE C */

/* Digital Mars */
#if !defined(CM_DMC) && defined(__DMC__)
#define CM_DMC __DMC__
#endif /* Digital Mars */

/* Dignus Systems/C++ */
#if !defined(CM_DIGNUS) && defined(__SYSC__)
#if defined(__SYSC_VER__)
#define CM_DIGNUS __SYSC_VER__
#else
#define CM_DIGNUS 0
#endif
#endif /* Dignus Systems/C++ */

/* DJGPP */
#if !defined(CM_DJGPP) && (defined(__DJGPP__) || defined(__GO32__))
#if defined(__DJGPP_MINOR__)
#define CM_DJGPP NO(__DJGPP__)NO(__DJGPP_MINOR__)
#else
#define CM_DJGPP __DJGPP__
#endif
#endif /* DJGPP */

/* EDG C++ Frontend */
#if !defined(CM_EDG) && defined(__EDG__)
#if defined(__EDG_VERSION__)
#define CM_EDG __EDG_VERSION__
#else
#define CM_EDG 0
#endif
#endif /* EDG C++ Frontend */

/* EKOPath */
#if !defined(CM_PATH) && defined(__PATHCC__)
#if defined(__PATHCC_MINOR__) && defined(__PATHCC_PATCHLEVEL__)
#define CM_PATH NO(__PATHCC__)NO(__PATHCC_MINOR__)NO(__PATHCC_PATCHLEVEL__)
#else
#define CM_PATH __PATHCC__
#endif
#endif /* EKOPath */

/* Fujitsu C++ */
#if !defined(CM_FCC) && defined(__FCC_VERSION)
#define CM_FCC __FCC_VERSION
#endif /* Fujitsu C++ */

/* GCC C/C++ */
#if !defined(CM_GCC) && defined(__GNUC__) && !defined(__clang__)
#if __GNUC__ >= 3
#define CM_GCC NO(__GNUC__)NO(__GNUC_MINOR__)NO(__GNUC_PATCHLEVEL__)
#else
#define CM_GCC NO(__GNUC__)NO(__GNUC_MINOR__)
#endif
#endif	/* GCC C/C++ */

/* Green Hill C/C++ */
#if !defined(CM_GHS) && defined(__ghs__)
#if defined(__GHS_VERSION_NUMBER__)
#define CM_GHS __GHS_VERSION_NUMBER__
#endif
#endif /* Green Hill C/C++ */

/* HP ANSI C */
#if !defined(CM_HP_C) && defined(__HP_cc)
#define CM_HP_C
#endif /* HP ANSI C */

/* HP aC++ */
#if !defined(CM_HP_ACC) && defined(__HP_aCC)
#define CM_HP_ACC __HP_aCC
#endif /* HP aC++ */

/* IAR C/C++ */
#if !defined(CM_ICC) && defined(__IAR_SYSTEMS_ICC__)
#if defined(__VER__)
#define CM_ICC __VER__
#else
#define CM_ICC 0
#endif
#endif /* IAR C/C++ */

/* IBM XL C/C++ (Clang-based versions) */
#if !defined(CM_XLC_CLANG) && defined(__ibmxl__) && __clang__
#if defined(__ibmxl_vrm__)
#define CM_XLC_CLANG __ibmxl_vrm__
#else
#define CM_XLC_CLANG 0
#endif
#endif /* IBM XL C/C++ (Clang-based versions) */

/* IBM XL C/C++ (legacy versions) */
#if !defined(CM_XLC) && defined(__xlC__)
#define CM_XLC_LEG __xlC__
#endif /* IBM XL C/C++ (legacy versions) */

/* IBM z/OS XL C/C++ */
#if !defined(CM_XLC_ZOS) && defined(__COMPILER_VER__)
#define CM_XLC_ZOS __COMPILER_VER__
#endif /* IBM z/OS XL C/C++ */

/* ImageCraft C */
#if !defined(CM_IMAGECRAFT) && defined(__IMAGECRAFT__)
#define CM_IMAGECRAFT
#endif /* ImageCraft C */

/* Intel C/C++ */
#if !defined(CM_INTEL) && defined(__INTEL_COMPILER)
#define CM_INTEL __INTEL_COMPILER
#endif /* Intel C/C++ */

/* KAI C++ */
#if !defined(CM_KCC) && defined(__KCC)
#if defined(__KCC_VERSION)
#define CM_KCC __KCC_VERSION
#else
#define CM_KCC 0
#endif
#endif /* KAI C++ */

/* KEIL CARM */
#if !defined(CM_CARM) 
#if		defined(__CA__)
#define CM_CARM __CA__
#elif	defined(__KEIL__)
#define CM_CARM
#endif
#endif /* KEIL CARM */

/* KEIL C166 */
#if !defined(CM_C166) && defined(__C166__)
#define CM_C166 __C166__
#endif /* KEIL C166 */

/* KEIL C51 */
#if !defined(CM_C51) && defined(__C51__)
#define CM_C51 __C51__
#endif /* KEIL C51 */

/* To be continued */

/*
#if !defined(CM_) && defined()
#define
#endif 
*/

/* Microsoft Visual C++ */
#if !defined(CM_MSC) && defined(_MSC_VER)
#define CM_MSC _MSC_VER
#endif /* Microsoft Visual C++ */

/* MinGW */
#if !defined(CM_MINGW) && defined(__MINGW32__)
#define CM_MINGW 0
#endif /* MinGW */

#endif