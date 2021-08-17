#ifndef LANG_H
#define LANG_H

/* C Language */
#if !defined(LG_C) && defined(__STDC__)

#define VR_C89		0
#define VR_C90		0
#define VR_C94		199409L
#define VR_C99		199901L
#define VR_C11		201112L
#define VR_C18		201710L

#ifdef __STDC_VERSION__
#define	LG_C		__STDC_VERSION__
#else   /* __STDC_VERSION__ */
#define LG_C		VR_C89
#endif  /* __STDC_VERSION__ */

#endif  /* C Language */

/* C++ Language */
#if !defined(LG_CPP) && defined(__cplusplus)

#define VR_CPP98	199711L
#define VR_CPP11	201103L
#define VR_CPP14	201402L
#define VR_CPP17	201703L

#define LG_CPP		__cplusplus

#endif  /* C++ Language */

/* "wl" only supports:
	* C language with ISO/IEC 9899 (ISO C) standard
	* C++ language with ISO/IEC 14882 (ISO C++) standard
 */

#endif /* LANG_H */
