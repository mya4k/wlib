#ifndef WL_TYPES_H
#define WL_TYPES_H 1



#include <wl/config.h>



#if WL_STDINT_H
#	include <stdint.h>
#endif	/* WL_STDINT_H */

#if WL_LIMITS_H
#	include <limits.h>
#endif	/* WL_LIMITS_H */



#if !WL_PREFIX
#	define I8l	wl_I8l
#	define U8l	wl_U8l
#	define I16l	wl_I16l
#	define U16l	wl_U16l
#	define I32l	wl_I32l
#	define U32l	wl_U32l
#	define I64l	wl_I64l
#	define U64l	wl_U64l
#	define I8f 	wl_I8f
#	define U8f 	wl_U8f
#	define I16f	wl_I16f
#	define I32f	wl_I32f
#	define I64f	wl_I64f
#	define U16f	wl_U16f
#	define U32f	wl_U32f
#	define U64f	wl_U64f
#	define I8	wl_I8
#	define I16	wl_I16
#	define I32	wl_I32
#	define I64 	wl_I64
#	define U8	wl_U8
#	define U16	wl_U16
#	define U32	wl_U32
#	define U64 	wl_U64
#	define IMax	wl_IMax
#	define UMax	wl_UMax
#	define SPt 	wl_SPt
#	define Pt  	wl_Pt
#	define Bl  	wl_Bl

#define I8LB	WL_I8LB
#define I16LB	WL_I16LB
#define I32LB	WL_I32LB
#define I64LB	WL_I64LB
#define I8FB	WL_I8FB
#define I16FB	WL_I16FB
#define I32FB	WL_I32FB
#define I64FB	WL_I64FB
#define U8LB	WL_U8LB
#define U16LB	WL_U16LB
#define U32LB	WL_U32LB
#define U64LB	WL_U64LB
#define U8FB	WL_U8FB
#define U16FB	WL_U16FB
#define U32FB	WL_U32FB
#define U64FB	WL_U64FB
#define U8LN	WL_U8LN
#define U16LN	WL_U16LN
#define U32LN	WL_U32LN
#define U64LN	WL_U64LN
#define U8FN	WL_U8FN
#define U16FN	WL_U16FN
#define U32FN	WL_U32FN
#define U64FN	WL_U64FN
#define U8LX	WL_U8LX
#define U16LX	WL_U16LX
#define U32LX	WL_U32LX
#define U64LX	WL_U64LX
#define I8LX	WL_I8LX
#define I16LX	WL_I16LX
#define I32LX	WL_I32LX
#define I64LX	WL_I64LX
#define I8LN	WL_I8LN
#define I16LN	WL_I16LN
#define I32LN	WL_I32LN
#define I64LN	WL_I64LN
#define CHB		WL_CHB
#define CHN		WL_CHN
#define CHX		WL_CHX
#define SHN		WL_SHN
#define SHX		WL_SHX
#define USX		WL_USX
#define INN		WL_INN
#define INX		WL_INX
#define UIX		WL_UIX
#define LON		WL_LON
#define LOX		WL_LOX
#define ULX		WL_ULX
#define SCB		WL_SCB
#define BLB		WL_BLB
#define SHB		WL_SHB
#define INB		WL_INB
#define LOB		WL_LOB
#define LLB		WL_LLB
#define UCB		WL_UCB
#define USB		WL_USB
#define UIB		WL_UIB
#define ULB		WL_ULB
#define ULLB	WL_ULLB
#define UCN		WL_UCN
#define USN		WL_USN
#define UIN		WL_UIN
#define ULN		WL_ULN
#define ULLN	WL_ULLN
#define I8N		WL_I8N
#define I16N	WL_I16N
#define I32N	WL_I32N
#define I64N	WL_I64N
#define U8N		WL_U8N
#define U16N	WL_U16N
#define U32N	WL_U32N
#define U64N	WL_U64N
#define I8X		WL_I8X
#define I16X	WL_I16X
#define I32X	WL_I32X
#define I64X	WL_I64X
#define U8X		WL_U8X
#define U16X	WL_U16X
#define U32X	WL_U32X
#define U64X	WL_U64X
#define I8B		WL_I8B
#define I16B	WL_I16B
#define I32B	WL_I32B
#define I64B	WL_I64B
#define U8B		WL_U8B
#define U16B	WL_U16B
#define U32B	WL_U32B
#define U64B	WL_U64B
#define IMN		WL_IMN
#define IMX		WL_IMX
#define UMN		WL_UMN
#define UMX		WL_UMX
#define IMB		WL_IMB
#define UMB		WL_UMB
#define SPTN	WL_SPTN
#define SPTX	WL_SPTX
#define PTN		WL_PTN
#define PTX		WL_PTX
#define PTB		WL_PTB
#define UMB		WL_UMB

#ifndef TRUE
#	define TRUE	WL_TRUE
#endif

#ifndef FALSE
#	define FALSE	WL_FALSE
#endif

#ifndef NULL
#	define NULL	WL_NULL
#endif
#endif



/**@{*/
/**
 * \brief Minimum-width integer types
 * 
 * `XYl` designate the shortest integer type that is at least *Y* bits wide,
 * where if *X* is `I`, the type is signed, and if *X* is `U`, the type is 
 * unsigned. Acceptable configuration of the number X are: 8, 16, 32, 64. 
 */
#if	WL_STDINT_H
	typedef	int_least8_t				wl_I8l;
	typedef int_least16_t				wl_I16l;
	typedef int_least32_t				wl_I32l;
	typedef int_least64_t				wl_I64l;
	typedef	uint_least8_t				wl_U8l;
	typedef uint_least16_t				wl_U16l;
	typedef uint_least32_t				wl_U32l;
	typedef uint_least64_t				wl_U64l;
#else	/* WL_STDINT_H */
	typedef signed		char			wl_I8l;
	typedef unsigned	char			wl_U8l;

	/*	Even those on these data models `short` and `int` have the same width,
		let's use "natural" integer type (int), in case it is efficient. */
#	if WL_DATAMODEL	== WL_IP16 || WL_DATAMODEL == WL_LP32 
		typedef signed		int			wl_I16l;
		typedef unsigned	int			wl_U16l;
		typedef signed		long		wl_I32l;
		typedef unsigned	long		wl_U32l;
#	else	/* WL_DATAMODEL	== WL_IP16 || WL_DATAMODEL == WL_LP32 */
		typedef signed		short		wl_I16l;
		typedef unsigned	short		wl_U16l;
		typedef signed		int			wl_I32l;
		typedef unsigned	int			wl_U32l;
#	endif	/* WL_DATAMODEL	!= WL_SILP64 */

#	if WL_DATAMODEL	== WL_ILP64 || WL_DATAMODEL == WL_SILP64
		typedef signed		int			wl_I64l;
		typedef unsigned	int			wl_U64l;
#	elif WL_LONG_LONG && (WL_DATAMODEL==WL_IP16 || WL_DATAMODEL==WL_LP32\
	|| WL_DATAMODEL==WL_ILP32 || WL_DATAMODEL==WL_LLP64)
		typedef signed		long long	wl_I64l;
		typedef unsigned	long long	wl_U64l;
#	else
		typedef signed		long		wl_I64l;
		typedef unsigned	long		wl_U64l;
#	endif	/* WL_DATAMODEL	!= WL_SILP64 */


#endif	/* WL_STDINT_H */
/**@}*/

/**@{*/
/**
 * \brief Fastest integer types
 * 
 * `XYf` designate the fastest integer type that is at least *Y* bits wide,
 * where if *X* is `I`, the type is signed, and if *X* is `U`, the type is 
 * unsigned. Acceptable configuration of the number X are: 8, 16, 32, 64. 
 */
#if STDINT_H
	typedef	int_fast8_t					wl_I8f;
	typedef int_fast16_t				wl_I16f;
	typedef int_fast32_t				wl_I32f;
	typedef int_fast64_t				wl_I64f;
	typedef	uint_fast8_t				wl_U8f;
	typedef uint_fast16_t				wl_U16f;
	typedef uint_fast32_t				wl_U32f;
	typedef uint_fast64_t				wl_U64f;
#else	/* STDINT_H */
	typedef	wl_I8l						wl_I8f;
	typedef	wl_U8l						wl_U8f;

#	if WL_WORDSIZE >= 64
		typedef	wl_I64l					wl_I16f; 
		typedef	wl_I64l					wl_I32f; 
		typedef	wl_I64l					wl_I64f; 
		typedef	wl_U64l					wl_U16f; 
		typedef	wl_U64l					wl_U32f; 
		typedef	wl_U64l					wl_U64f;
#	else	/* WL_WORDSIZE >= 64 */
		typedef	wl_I32l					wl_I16f; 
		typedef	wl_I32l					wl_I32f; 
		typedef	wl_U32l					wl_U16f; 
		typedef	wl_U32l					wl_U32f; 
		typedef	wl_I64l					wl_I64f; 
		typedef	wl_U64l					wl_U64f;
#	endif	/* WL_WORDSIZE >= 64 */
#endif	/* STDINT_H */
/**@}*/



/**@{*/
/**	
 *	\brief Limits of fixed-size types
 */
#if	defined(INT_LEAST8_WIDTH)	&& defined(INT_FAST8_WIDTH)	\
&&	defined(INT_LEAST16_WIDTH)	&& defined(INT_FAST16_WIDTH)\
&&	defined(INT_LEAST32_WIDTH)	&& defined(INT_FAST32_WIDTH)\
&&	defined(INT_LEAST64_WIDTH)	&& defined(INT_FAST64_WIDTH)
#	define WL_I8LB				INT_LEAST8_WIDTH
#	define WL_I16LB				INT_LEAST16_WIDTH
#	define WL_I32LB				INT_LEAST32_WIDTH
#	define WL_I64LB				INT_LEAST64_WIDTH

#	define WL_I8FB				INT_FAST8_WIDTH
#	define WL_I16FB				INT_FAST16_WIDTH
#	define WL_I32FB				INT_FAST32_WIDTH
#	define WL_I64FB				INT_FAST64_WIDTH
#else	/* defined(INT_LEAST8_WIDTH)	&& defined(INT_FAST8_WIDTH)	... */
#	define WL_I8LB				8

#	if WL_DATAMODEL == WL_SILP64
#		define WL_I16LB			64
#	else	/* WL_DATAMODEL == WL_SILP64 */
#		define WL_I16LB			16
#	endif	/* WL_DATAMODEL == WL_SILP64 */

#	if WL_DATAMODEL == WL_SILP64 || WL_DATAMODEL == WL_ILP64
#		define WL_I32LB			64
#	else	/* WL_DATAMODEL == WL_SILP64 || WL_DATAMODEL == WL_ILP64 */
#		define WL_I32LB			32
#	endif	/* WL_DATAMODEL == WL_SILP64 || WL_DATAMODEL == WL_ILP64 */

#	if WL_LONG_LONG					|| WL_DATAMODEL == WL_LP64\
	|| WL_DATAMODEL == WL_ILP64	|| WL_DATAMODEL == WL_SILP64
#		define WL_I64LB			64
#	else	/* WL_LONG_LONG	|| WL_DATAMODEL == WL_LP64... */
#		define WL_I64LB			32
#	endif	/* WL_LONG_LONG	|| WL_DATAMODEL == WL_LP64... */

#	define WL_I8FB				WL_I8LB

#	if WL_WORDSIZE >= 64
#		define WL_I16FB			WL_I64LB
#		define WL_I32FB			WL_I64LB
#	else	/* WL_WORDSIZE >= 64 */
#		define WL_I16FB			WL_I32LB
#		define WL_I32FB			WL_I32LB
#	endif	/* WL_WORDSIZE >= 64 */

#	define WL_I64FB				WL_I64LB
#endif	/* defined(INT_LEAST8_WIDTH)	&& defined(INT_FAST8_WIDTH)	... */

#define WL_U8LB					WL_I8LB
#define WL_U16LB				WL_I16LB
#define WL_U32LB				WL_I32LB
#define WL_U64LB				WL_I64LB

#define WL_U8FB					WL_I8FB
#define WL_U16FB				WL_I16FB
#define WL_U32FB				WL_I32FB
#define WL_U64FB				WL_I64FB

#	define WL_U8LN				0
#	define WL_U16LN				0
#	define WL_U32LN				0
#	define WL_U64LN				0

#	define WL_U8FN				0
#	define WL_U16FN				0
#	define WL_U32FN				0
#	define WL_U64FN				0

#if WL_STDINT_H
#	define WL_U8LX				UINT_LEAST8_MAX
#	define WL_U16LX				UINT_LEAST16_MAX
#	define WL_U32LX				UINT_LEAST32_MAX
#	define WL_U64LX				UINT_LEAST64_MAX

#	define WL_I8LN				INT_LEAST8_MIN
#	define WL_I16LN				INT_LEAST16_MIN
#	define WL_I32LN				INT_LEAST32_MIN
#	define WL_I64LN				INT_LEAST64_MIN

#	define WL_I8LX				INT_LEAST8_MAX
#	define WL_I16LX				INT_LEAST16_MAX
#	define WL_I32LX				INT_LEAST32_MAX
#	define WL_I64LX				INT_LEAST64_MAX

#	define WL_U8FX				UINT_FAST8_MAX
#	define WL_U16FX				UINT_FAST16_MAX
#	define WL_U32FX				UINT_FAST32_MAX
#	define WL_U64FX				UINT_FAST64_MAX

#	define WL_I8FN				INT_FAST8_MIN
#	define WL_I16FN				INT_FAST16_MIN
#	define WL_I32FN				INT_FAST32_MIN
#	define WL_I64FN				INT_FAST64_MIN

#	define WL_I8FX				INT_FAST8_MAX
#	define WL_I16FX				INT_FAST16_MAX
#	define WL_I32FX				INT_FAST32_MAX
#	define WL_I64FX				INT_FAST64_MAX
#else	/* WL_STDINT_H */
#	define WL_U8LX				0xFF
#	define WL_U16LX				0xFFFF
#	define WL_U32LX				0xFFFFFFFF
#	if WL_LONG_LONG				|| WL_DATAMODEL == WL_LP64\
|| WL_DATAMODEL == WL_ILP64	|| WL_DATAMODEL == WL_SILP64
#		define WL_U64LX				0xFFFFFFFFFFFFFFFF
#	else	/* WL_LONG_LONG || WL_DATAMODEL == WL_LP64... */
#		define WL_U64LX				WL_U32LX
#	endif	/* WL_LONG_LONG || WL_DATAMODEL == WL_LP64... */

#	define WL_I8LX				0x7F
#	define WL_I16LX				0x7FFF
#	define WL_I32LX				0x7FFFFFFF
#	if WL_LONG_LONG				|| WL_DATAMODEL == WL_LP64\
|| WL_DATAMODEL == WL_ILP64	|| WL_DATAMODEL == WL_SILP64
#	define WL_I64LX				0x7FFFFFFFFFFFFFFF
#	else	/* WL_LONG_LONG || WL_DATAMODEL == WL_LP64... */
#	define WL_I64LX				WL_U32LX
#	endif	/* WL_LONG_LONG || WL_DATAMODEL == WL_LP64... */

#	define WL_I8LN				(-0x80)
#	define WL_I16LN				(-0x8000)
#	define WL_I32LN				(-0x80000000)
#	if WL_LONG_LONG				|| WL_DATAMODEL == WL_LP64\
|| WL_DATAMODEL == WL_ILP64	|| WL_DATAMODEL == WL_SILP64
#		define WL_I64LN			(-0x8000000000000000)
#	else	/* WL_LONG_LONG || WL_DATAMODEL == WL_LP64... */
#		define WL_I64LN			WL_U32LN
#	endif	/* WL_LONG_LONG || WL_DATAMODEL == WL_LP64... */
#endif	/* WL_STDINT */
/**@}*/



/**@{*/
/**
 * \brief Limits of fundamental C types 
 */
#if WL_LIMITS_H
#	define WL_CHB				CHAR_BIT
#	define WL_CHN				CHAR_MIN
#	define WL_SCN				SCHAR_MIN
#	define WL_SHN				SHRT_MIN
#	define WL_INN				INT_MIN
#	define WL_LON				LONG_MIN
#	define WL_SCX				SCHAR_MAX
#	define WL_SHX				SHRT_MAX
#	define WL_INX				INT_MAX
#	define WL_LOX				LONG_MAX
#	define WL_UCX				UCHAR_MAX
#	define WL_USX				USHRT_MAX
#	define WL_UIX				UINT_MAX
#	define WL_ULX				ULONG_MAX
#else
/* Assume 8 and let the user override*/
#	ifndef WL_CHB
#		define WL_CHB			8
#	endif	/* WL_CHB */

#	if WL_CHAR_UNSIGNED
#		define WL_CHN			0
#		define WL_CHX			WL_UCX
#	else	/* WL_CHAR_UNSIGNED */
#		define WL_CHN			WL_SCN
#		define WL_CHX			WL_SCX
#	endif	/* WL_CHAR_UNSIGNED */

#	if WL_DATAMODEL == WL_SILP64
#		define WL_SHN			WL_I64LN
#		define WL_INN			WL_I64LN
#		define WL_LON			WL_I64LN

#		define WL_SHX			WL_I64LX
#		define WL_INX			WL_I64LX
#		define WL_LOX			WL_I64LX

#		define WL_USX			WL_U64LX
#		define WL_UIX			WL_U64LX
#		define WL_ULX			WL_U64LX

#	else	/* WL_DATAMODEL == WL_SILP64 */
#		define WL_SHN			WL_I16LN
#		define WL_SHX			WL_I16LX
#		define WL_USX			WL_U16LX

#		if WL_DATAMODEL == WL_ILP64
#			define WL_INN		WL_I64LN
#			define WL_INX		WL_I64LX
#			define WL_UIX		WL_U64LX

#			define WL_LON		WL_I64LN
#			define WL_LOX		WL_I64LX
#			define WL_ULX		WL_U64LX
#		elif WL_DATAMODEL == WL_IP16 || WL_DATAMODEL == WL_LP32
#			define WL_INN		WL_I16LN
#			define WL_INX		WL_I16LX
#			define WL_UIX		WL_U16LX
#			define WL_LON		WL_I32LN
#			define WL_LOX		WL_I32LX
#			define WL_ULX		WL_U32LX
#		else	/* WL_DATAMODEL == WL_ILP64 */
#			define WL_INN		WL_I32LN
#			define WL_INX		WL_I32LX
#			define WL_UIX		WL_U32LX
#			if WL_DATAMODEL == WL_LLP64
#				define WL_LON		WL_I32LN
#				define WL_LOX		WL_I32LX
#				define WL_ULX		WL_U32LX
#			else	/* WL_DATAMODEL == WL_LLP64 */
#				define WL_LON		WL_I64LN
#				define WL_LOX		WL_I64LX
#				define WL_ULX		WL_U64LX
#			endif	/* WL_DATAMODEL == WL_LLP64 */
#		endif	/* WL_DATAMODEL == WL_ILP64 */
#	endif	/* WL_DATAMODEL == WL_SILP64 */

#endif	/* WL_LIMITS_H */

#define WL_SCB					WL_CHB

#define WL_BLB					1

#if defined(SHRT_WIDTH) && defined(INT_WIDTH) && defined(LONG_WIDTH)
#	define WL_SHB				SHRT_WIDTH
#	define WL_INB				INT_WIDTH
#	define WL_LOB				LONG_WIDTH
#else	/* defined(SHRT_WIDTH) && defined(INT_WIDTH) && defined(LONG_WIDTH) */
#	if WL_DATAMODEL == WL_SILP64
#		define WL_SHB			64
#		define WL_INB			64
#		define WL_LOB			64

#	else	/* WL_DATAMODEL == WL_SILP64 */
#		define WL_SHB			16
#		if WL_DATAMODEL == WL_ILP64
#			define WL_INB		64
#			define WL_LOB		64
#		elif WL_DATAMODEL == WL_IP16 || WL_DATAMODEL == WL_LP32
#			define WL_INB		16
#			define WL_LOB		32
#		else	/* WL_DATAMODEL == WL_ILP64 */
#			define WL_INB		32
#			if WL_DATAMODEL == WL_LLP64
#				define WL_LOB	32
#			else	/* WL_DATAMODEL == WL_LLP64 */
#				define WL_LOB	64
#			endif	/* WL_DATAMODEL == WL_LLP64 */
#		endif	/* WL_DATAMODEL == WL_ILP64 */
#	endif	/* WL_DATAMODEL == WL_SILP64 */
#endif	/* defined(SHRT_WIDTH) && defined(INT_WIDTH) && defined(LONG_WIDTH) */

#if WL_LONG_LONG
#	define	WL_LLB				64
#else	/* WL_LONG_LONG */
#	define	WL_LLB				WL_LOB
#endif	/* WL_LONG_LONG */

#define WL_UCB					WL_SCB
#define WL_USB					WL_SHB
#define WL_UIB					WL_INB
#define WL_ULB					WL_LOB
#define WL_ULLB					WL_LLB

#define WL_UCN					0
#define WL_USN					0
#define WL_UIN					0
#define WL_ULN					0
#define WL_ULLN					0
/**@}*/



/**@{*/
/**
 * \brief Optimal fixed-size types
 */
#if WL_FIXED == WL_FIXED_LEAST
typedef wl_I8l					wl_I8;
typedef wl_I16l					wl_I16;
typedef wl_I32l					wl_I32;
typedef wl_I64l					wl_I64;
typedef wl_U8l					wl_U8;
typedef wl_U16l					wl_U16;
typedef wl_U32l					wl_U32;
typedef wl_U64l					wl_U64;

#define WL_I8N					WL_I8LN
#define WL_I16N					WL_I16LN
#define WL_I32N					WL_I32LN
#define WL_I64N					WL_I64LN
#define WL_U8N					WL_U8LN
#define WL_U16N					WL_U16LN
#define WL_U32N					WL_U32LN
#define WL_U64N					WL_U64LN

#define WL_I8X					WL_I8LX
#define WL_I16X					WL_I16LX
#define WL_I32X					WL_I32LX
#define WL_I64X					WL_I64LX
#define WL_U8X					WL_U8LX
#define WL_U16X					WL_U16LX
#define WL_U32X					WL_U32LX
#define WL_U64X					WL_U64LX

#define WL_I8B					WL_I8LB
#define WL_I16B					WL_I16LB
#define WL_I32B					WL_I32LB
#define WL_I64B					WL_I64LB
#define WL_U8B					WL_U8LB
#define WL_U16B					WL_U16LB
#define WL_U32B					WL_U32LB
#define WL_U64B					WL_U64LB
#else	/* WL_FIXED == WL_FIXED_LEAST */
typedef wl_I8f					wl_I8;
typedef wl_I16f					wl_I16;
typedef wl_I32f					wl_I32;
typedef wl_I64f					wl_I64;
typedef wl_U8f					wl_U8;
typedef wl_U16f					wl_U16;
typedef wl_U32f					wl_U32;
typedef wl_U64f					wl_U64;

#define WL_I8N					WL_I8FN
#define WL_I16N					WL_I16FN
#define WL_I32N					WL_I32FN
#define WL_I64N					WL_I64FN
#define WL_U8N					WL_U8FN
#define WL_U16N					WL_U16FN
#define WL_U32N					WL_U32FN
#define WL_U64N					WL_U64FN

#define WL_I8X					WL_I8FX
#define WL_I16X					WL_I16FX
#define WL_I32X					WL_I32FX
#define WL_I64X					WL_I64FX
#define WL_U8X					WL_U8FX
#define WL_U16X					WL_U16FX
#define WL_U32X					WL_U32FX
#define WL_U64X					WL_U64FX

#define WL_I8B					WL_I8FB
#define WL_I16B					WL_I16FB
#define WL_I32B					WL_I32FB
#define WL_I64B					WL_I64FB
#define WL_U8B					WL_U8FB
#define WL_U16B					WL_U16FB
#define WL_U32B					WL_U32FB
#define WL_U64B					WL_U64FB
#endif	/* WL_FIXED == WL_FIXED_LEAST */

/**@}*/



/**@{*/
/**
 * \brief Maximal-width type
 */
#if WL_STDINT_H
	typedef intmax_t			wl_IMax;
	typedef uintmax_t			wl_UMax;

#	define	WL_IMN				INTMAX_MIN
#	define	WL_IMX				INTMAX_MAX

#	define	WL_UMN				0
#	define	WL_UMX				UINTMAX_MAX
#else	/* WL_STDINT_H */
	typedef wl_I64				wl_IMax;
	typedef wl_U64				wl_UMax;

#	define	WL_IMN				WL_I64N
#	define	WL_IMX				WL_U64X

#	define	WL_UMN				WL_U64N
#	define	WL_UMX				WL_U64X
#endif	/* WL_STDINT_H */

#ifdef INTMAX_WIDTH
#	define	WL_IMB				INTMAX_WIDTH
#else	/* INTMAX_WIDTH */
#	define	WL_IMB				WL_I64B
#endif	/* INTMAX_WIDTH */

#	define	WL_UMB				WL_IMB
/**@}*/

#ifdef __intptr_t_defined
	typedef intptr_t			wl_SPt;
	typedef uintptr_t			wl_Pt;

#	define	WL_SPTN				INTPTR_MIN
#	define	WL_SPTX				INTPTR_MAX

#	define	WL_PTN				0
#	define	WL_PTX				UINTPTR_MAX
#else	/* WL_STDINT_H */
#	if WL_DATAMODEL == WL_IP16
		typedef wl_I16l				wl_SPt;
		typedef wl_U16l				wl_Pt;
#		define	WL_SPTN				WL_I16LN
#		define	WL_SPTX				WL_U16LX
#		define	WL_PTN				WL_U16LN
#		define	WL_PTX				WL_U16LX
#	elif WL_DATAMODEL == WL_LP32 || WL_DATAMODEL == WL_ILP32
		typedef wl_I32l				wl_SPt;
		typedef wl_U32l				wl_Pt;
#		define	WL_SPTN				WL_I32LN
#		define	WL_SPTX				WL_U32LX
#		define	WL_PTN				WL_U32LN
#		define	WL_PTX				WL_U32LX
#	else	/* WL_DATAMODEL == WL_ IP16 */
		typedef wl_I64l				wl_SPt;
		typedef wl_U64l				wl_Pt;
#		define	WL_SPTN				WL_I64LN
#		define	WL_SPTX				WL_U64LX
#		define	WL_PTN				WL_U64LN
#		define	WL_PTX				WL_U64LX
#	endif	/* WL_DATAMODEL == WL_IP16 */
#endif	/* WL_STDINT_H */

#ifdef INTPTR_WIDTH
#	define	WL_PTB				INTPTR_WIDTH
#else	/* INTMAX_WIDTH */
#	if WL_DATAMODEL == WL_IP16
#		define	WL_PTB				WL_I16LB
#	elif WL_DATAMODEL == WL_LP32 || WL_DATAMODEL == WL_ILP32
#		define	WL_PTB				WL_I32LB
#	else	/* WL_DATAMODEL == WL_IP16 */
#		define	WL_PTB				WL_I64LB
#	endif	/* WL_DATAMODEL == WL_IP16 */
#endif	/* INTMAX_WIDTH */

#	define	WL_UMB				WL_IMB

/**
 * \brief Boolean type
 * 
 */
typedef wl_I8f					wl_Bl;

#define WL_TRUE					1
#define WL_FALSE				0
#define WL_NULL					((void*)0)



#endif /* WL_TYPES_H*/
