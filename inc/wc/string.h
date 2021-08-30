#ifndef WC_STRING_H
#define WC_STRING_H



#include <wc/core.h>
#include <wc/types.h>



#ifndef NO_SHORT_NAMES
#	define S2U_DEC	WL_S2U_DEC
#	define Str		wl_Str
#	define Sl		wl_Sl
#	define Lens		wl_Lens
#	define sl		wl_sl
#	define lens		wl_lens
#endif

#ifdef LONG_ALIAS
#	define StrLength	wl_sl
#	define StrToU32		wl_s2u
#endif



/**
 * \brief	Cofigurates the type of wl_Sl
 * \def		WL_SL_TYPE
 */
#if defined(USE_STDLIB) && !defined(WL_IMP_SL)
#	include <stdlib.h>
#	define WL_SL_TYPE	size_t
#elif !defined(WL_SL_TYPE)
#	define WL_SL_TYPE	u16
#endif

/**
 * \brief	Decimal flag for `wl_s2u`, `wl_s2i`, `wl_s2l`, `wl_s2q`
 * \def		WL_S2U_DEC
 */
#define WL_S2_DEC	0

/**
 * \brief	Hexadecimal flag for `wl_s2u`
 * \def		WL_S2U_DEC
 */
#define WL_S2_HEX	1

/**
 * \brief	Binary flag for `wl_s2u`
 * \def		WL_S2U_DEC
 */
#define WL_S2_BIN	2

/**
 * \brief	Octal flag for `wl_s2u`
 * \def		WL_S2U_OCT
 */
#define WL_S2_OCT	3


/**
 * \brief	Null-terminated String Type
 * \typedef	wl_Str
 */
typedef char*		wl_Str;
/**
 * \brief	String Length (Size) Type
 * \typedef	wl_Sl
 * \typedef	wl_Lens
 */
typedef	WL_SL_TYPE	wl_Sl, wl_Lens;



#if defined(USE_STDLIB) && !defined(WL_IMP_SL)
	/**
	 * \brief	String Length
	 * \def		wl_Sl(str)
	 * \see		strlen(str)
	 */
	#define wl_Sl(str)	strlen(str)
#else
	EXTERN wl_Sl	wl_sl(const char* str);			/* String length */
#endif

EXTERN wl_U32	wl_s2u(const char* str, u8 flags);		/* String to U32 */
EXTERN wl_U32	wl_u2s(wl_U32* str, u8 flags);			/* String to U32 */



#endif