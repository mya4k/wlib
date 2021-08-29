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
#	define WL_SL_TYPE	size_t
#elif !defined(WL_SL_TYPE)
#	define WL_SL_TYPE	u16
#endif

/**
 * \brief	Decimal flag for `wl_s2u`
 * \def		WL_S2U_DEC
 */
#define WL_S2U_DEC



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
	EXTERN wl_Sl	wl_sl	(wl_Str str);			/* String length */
#endif

EXTERN wl_U32	wl_s2u	(wl_Str str, u8 flags);		/* String to U32 */



#endif