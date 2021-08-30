#ifndef WC_STRING_H
#define WC_STRING_H



#include <wc/core.h>
#include <wc/types.h>
#include <wc/array.h>



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
#endif

#ifdef LONG_ALIAS
#	define StrLength	wl_sl
#	define StrToU32		wl_s2u
#endif



#ifndef REGION_MACROS
	/**
	 * \brief	Cofigurates the type of wl_Sl
	 * \def		WL_SL_TYPE
	 */
#	if defined(USE_STDLIB) && !defined(WL_IMP_SL)
#		include <stdlib.h>
#		define WL_SL_TYPE	size_t
#	elif !defined(WL_SL_TYPE)
#		define WL_SL_TYPE	u16
#	endif

	/**
	 * \brief	Decimal flag for `wl_s2u`, `wl_s2i`, `wl_s2l`, `wl_s2q`
	 * \def		WL_S2U_DEC
	 */
#	define WL_S2_DEC	0

	/**
	 * \brief	Hexadecimal flag for `wl_s2u`
	 * \def		WL_S2U_DEC
	 */
#	define WL_S2_HEX	1

	/**
	 * \brief	Binary flag for `wl_s2u`
	 * \def		WL_S2U_DEC
	 */
#	define WL_S2_BIN	2

	/**
	 * \brief	Octal flag for `wl_s2u`
	 * \def		WL_S2U_OCT
	 */
#	define WL_S2_OCT	3
#endif



#ifndef REGION_MACRO_FUNCS
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
#		define wl_s2i(str, flags) (			\
			str[0]=='+'						\
			? wl_s2u(str+1, flags)			\
			: (	str[0]=='-'					\
				? -wl_s2u(str+1, flags)		\
				: wl_s2u(str, flags)	)	\
		)
#	endif
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
#		define wl_s2l(str, flags) (			\
			str[0]=='+'						\
			? wl_s2q(str+1, flags)			\
			: (	str[0]=='-'					\
				? -wl_s2q(str+1, flags)		\
				: wl_s2q(str, flags)	)	\
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
 */
#	define wl_ssc(str,chr,flags) \
		wl_asb(str,wl_sl(str),chr,flags)
/**
 * \brief	String Search
 * \def		wl_ss(str,chr,flags)
 * \param	str1 Where to search
 * \param	str2 What to search for
 * \param	flags SEARCH flags
 * \see		SEARCH_
 */
#	define wl_asa(str1,str2,flags) \
		wl_asa(str1,wl_sl(str1),str2,wl_sl(str2),flags);
#endif



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
	EXTERN wl_Sl wl_sl(const char* restrict const str);	/* String length */
#endif

EXTERN wl_U32 wl_s2u(const char* restrict const str, const u8 flags);	/* String to U32 */
EXTERN wl_U64 wl_s2q(const char* restrict const str, const u8 flags);	/* String to U64 */



#endif