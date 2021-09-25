#ifndef WC_STRING_H
#define WC_STRING_H



#include <wc/core.h>
#include <wc/types.h>
#include <wc/array.h>


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
#	define s2imax	wl_s2imax
#	define s2umax	wl_s2umax
#	define sas		wl_sas
#	define ss		wl_ss
#	define ssc		wl_ssc
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
#	ifdef USE_STDLIB

#		if WL_INB >= 32
#			define WL_STDLIB_S2I(str) atoi(str)
#			define WL_STDLIB_S2U(str) (wl_U32)atoi(str)
#		else
#			define WL_STDLIB_S2I(str) atol(str)
#			define WL_STDLIB_S2U(str) strtol(str)
#		endif

#		define wl_s2i(str, flags) (					\
			flags&0x3								\
			? (	str[0]=='+'							\
				? wl_s2u(str+1, flags)				\
				: (	str[0]=='-'						\
					? -wl_s2u(str+1, flags)			\
					: wl_s2u(str, flags)	)	)	\
			: WL_STDLIB_S2I(str)					\
		)
#	else
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
#	ifdef USE_STDLIB

#		if WL_LOB >= 64 || LG_C < VR_C99
#			define WL_STDLIB_S2L(str) atol(str)
#			define WL_STDLIB_S2Q(str) strtol(str)
#		else
#			define WL_STDLIB_S2L(str) atoll(str)
#			define WL_STDLIB_S2Q(str) strtoll(str)
#		endif

#		define wl_s2l(str, flags) (					\
			flags&0x3								\
			? (	str[0]=='+'							\
				? wl_s2q(str+1, flags)				\
				: (	str[0]=='-'						\
					? -wl_s2q(str+1, flags)			\
					: wl_s2q(str, flags)	)	)	\
			: atoll(str)							\
		)
#	else
#		define wl_s2l(str, flags) (				\
			str[0]=='+'							\
			? wl_s2q(str+1, flags)				\
			: (	str[0]=='-'						\
				? -wl_s2q(str+1, flags)			\
				: wl_s2q(str, flags)	)		\
		)
#	endif

#	if WL_IMB < 64
#		define wl_s2imax	wl_s2i
#		define wl_s2umax	wl_s2u
#	else
#		define wl_s2imax	wl_s2l
#		define wl_s2umax	wl_s2q
#	endif

/**
 * \brief	String Search Character
 * \def		wl_ssc(str,chr,flags)
 * \param	str Where to search
 * \param	chr Character to search
 * \param	flags one of WL_SEARCH_FLAGS
 * \return	The index of the char found or the count of occurances
 */
#	define wl_ssc(str,chr,flags) (										\
	((flags)==WL_SEARCH_COUNT)											\
	? ((Sl)(_Ptr)wl_asb((str),wl_sl(str),(chr),(flags)))				\
	: (Sl)((_Ptr)wl_asb((str),wl_sl(str),(chr),(flags)) - (_Ptr)(str))	\
)
/**
 * 
 * \brief	String Search
 * \def		wl_ss(str1,str2,flags)
 * \param	str1 Where to search
 * \param	str2 What to search for
 * \param	flags SEARCH flags
 * \see		SEARCH_
 */
#	define wl_ss(str1,str2,flags) (														\
	(flags)==WL_SEARCH_COUNT															\
	? (Sl)wl_asa((str1),wl_sl(str1),(str2),wl_sl(str2),(flags))							\
	: (Sl)((_Ptr)wl_asb((str1),wl_sl(str1),(str2),wl_sl(str2),(flags)) - (_Ptr)(str))	\
)

#	define wl_sas(length,str1,str2) (wl_aas((length)+1,(str1),(str2)))



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
	EXTERN wl_Sl wl_sl(const char* restrict const str);	/* String length */
#endif

EXTERN wl_U32 wl_s2u(const char* restrict const str, const WL_S2_FLAGS flags);	/* String to U32 */
EXTERN wl_U64 wl_s2q(const char* restrict const str, const WL_S2_FLAGS flags);	/* String to U64 */



#endif
