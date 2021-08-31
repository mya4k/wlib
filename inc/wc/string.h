#ifndef WC_STRING_H
#define WC_STRING_H



#include <wc/core.h>
#include <wc/types.h>


/**
 *       ###    ##       ####    ###     ######  ########  ######  
 *      ## ##   ##        ##    ## ##   ##    ## ##       ##    ## 
 *     ##   ##  ##        ##   ##   ##  ##       ##       ##       
 *    ##     ## ##        ##  ##     ##  ######  ######    ######  
 *    ######### ##        ##  #########       ## ##             ## 
 *    ##     ## ##        ##  ##     ## ##    ## ##       ##    ## 
 *    ##     ## ######## #### ##     ##  ######  ########  ######  
 */
#ifndef NO_SHORT_NAMES
#	define S2U_DEC	WL_S2U_DEC
#	define Str		wl_Str
#	define Sl		wl_Sl
#	define Lens		wl_Lens
#	define sl		wl_sl
#	define lens		wl_lens
#	define s2u		wl_s2u
#	define s2i		wl_s2i
#	define s2l		wl_s2l
#	define s2q		wl_s2q
#endif

#ifdef LONG_ALIAS
#	define StrLength	wl_sl
#	define StrToU32		wl_s2u
#endif




/***
 *    ##     ##    ###     ######  ########   #######   ######  
 *    ###   ###   ## ##   ##    ## ##     ## ##     ## ##    ## 
 *    #### ####  ##   ##  ##       ##     ## ##     ## ##       
 *    ## ### ## ##     ## ##       ########  ##     ##  ######  
 *    ##     ## ######### ##       ##   ##   ##     ##       ## 
 *    ##     ## ##     ## ##    ## ##    ##  ##     ## ##    ## 
 *    ##     ## ##     ##  ######  ##     ##  #######   ######  
 */
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
 * \brief	String to I32
 * \def		wl_s2i(str, flags) 
 * \see		wl_s2u
 * 
 * Coverts a null-terminated one-byte string to a 32-byte signed integer
 */
#ifdef USE_STDLIB

#	if sizeof(int)>=4
#		define WL_STDLIB_S2I(str) atoi(str)
#		define WL_STDLIB_S2U(str) (wl_U32)atoi(str)
#	else
#		define WL_STDLIB_S2I(str) atol(str)
#		define WL_STDLIB_S2U(str) strtol(str)
#	endif

#	define wl_s2i(str, flags) (					\
		flags&0x3								\
		? (	str[0]=='+'							\
			? wl_s2u(str+1, flags)				\
			: (	str[0]=='-'						\
				? -wl_s2u(str+1, flags)			\
				: wl_s2u(str, flags)	)	)	\
		: WL_STDLIB_S2I(str)					\
	)
#else
#	define wl_s2i(str, flags) (			\
		str[0]=='+'						\
		? wl_s2u(str+1, flags)			\
		: (	str[0]=='-'					\
			? -wl_s2u(str+1, flags)		\
			: wl_s2u(str, flags)	)	\
	)
#endif

/**
 * \brief	String to I64
 * \def		wl_s2l(str, flags) 
 * \see		wl_s2q
 * 
 * Coverts a null-terminated one-byte string to a 64-byte signed integer
 */
#ifdef USE_STDLIB

#	if sizeof(long)>=8 || LG_C < VR_C99
#		define WL_STDLIB_S2L(str) atol(str)
#		define WL_STDLIB_S2Q(str) strtol(str)
#	else
#		define WL_STDLIB_S2L(str) atoll(str)
#		define WL_STDLIB_S2Q(str) strtoll(str)
#	endif

#	define wl_s2l(str, flags) (					\
		flags&0x3								\
		? (	str[0]=='+'							\
			? wl_s2q(str+1, flags)				\
			: (	str[0]=='-'						\
				? -wl_s2q(str+1, flags)			\
				: wl_s2q(str, flags)	)	)	\
		: atoll(str)							\
	)
#else
#	define wl_s2l(str, flags) (			\
		str[0]=='+'						\
		? wl_s2q(str+1, flags)			\
		: (	str[0]=='-'					\
			? -wl_s2q(str+1, flags)		\
			: wl_s2q(str, flags)	)	\
	)
#endif



/***
 *    ######## ##    ## ########  ########  ######  
 *       ##     ##  ##  ##     ## ##       ##    ## 
 *       ##      ####   ##     ## ##       ##       
 *       ##       ##    ########  ######    ######  
 *       ##       ##    ##        ##             ## 
 *       ##       ##    ##        ##       ##    ## 
 *       ##       ##    ##        ########  ######  
 */
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

/**
 * \brief	Flags for `wl_s2u`, `wl_s2i`, `wl_s2q`, `wl_s2l`
 * \typedef	WL_S2_FLAGS
 * \enum	WL_S2_FLAGS
 */
typedef enum WL_S2_FLAGS {
	WL_S2_DEC = (wl_U8)0,	/**< Decimal */
	WL_S2_HEX = (wl_U8)1,	/**< Hexadecimal */
	WL_S2_BIN = (wl_U8)2,	/**< Binary */
	WL_S2_OCT = (wl_U8)3	/**< Octal */
} WL_S2_FLAGS;



/***
 *    ######## ##     ## ##    ##  ######   ######  
 *    ##       ##     ## ###   ## ##    ## ##    ## 
 *    ##       ##     ## ####  ## ##       ##       
 *    ######   ##     ## ## ## ## ##        ######  
 *    ##       ##     ## ##  #### ##             ## 
 *    ##       ##     ## ##   ### ##    ## ##    ## 
 *    ##        #######  ##    ##  ######   ######  
 */
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



#endif