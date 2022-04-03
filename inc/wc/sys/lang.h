#ifndef WL_SYS_LANG_H
#define WL_SYS_LANG_H



#define WL_VR_K_R_C	197800L
#define WL_VR_ANSI	198900L
#define WL_VR_C89	199000L
#define WL_VR_C90	199000L
#define WL_VR_C94	199409L
#define WL_VR_C99	199901L
#define WL_VR_C11	201112L
#define WL_VR_C17	201710L
#define WL_VR_C18	201710L
#define WL_VR_C23	202300L
#define WL_VR_C2X	202300L

#define WL_VR_CPP98	199711L
#define WL_VR_CPP03	199711L
#define WL_VR_CPP11	201103L
#define WL_VR_CPP14	201402L
#define WL_VR_CPP17	201703L
#define WL_VR_CPP20 202002L
#define WL_VR_CPP23 202300L

/* C++ Language */
#if !defined(WL_LG_CPP) && defined(__cplusplus)
#	define WL_LG_CPP	__cplusplus
#endif

/* C Language */
#if !defined(WL_LG_C) 
#	ifdef __STDC__
#		ifdef __STDC_VERSION__
#			define WL_LG_C	__STDC_VERSION__
#		else
#			define WL_LG_C	WL_VR_C89
#		endif
#	else
#		define	WL_LG_C	WL_VR_K_R_C
#	endif
#endif

#if WL_LG_CPP >= WL_VR_CPP11
#	define WL_CPP_ATTR	1
#endif

#if WL_LG_C >= WL_VR_C23
#	define WL_C_ATTR	1
#endif

/* "WLib" only supports:
	* C language with ISO/IEC 9899 (ISO C) or ANSI C standard
	* C++ language with ISO/IEC 14882 (ISO C++) standard
 */

#endif /* LANG_H */
