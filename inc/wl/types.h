#ifndef WL_TYPES_H
#define WL_TYPES_H	1



#include <wc/config.h>



#if defined(WL_CONF_CPP)

/* If C++, `bool` is a keyword, but `_Bool` is not */
#	define _WL__BOOL_DEFINED	0
#	define _WL_BOOL_DEFINED		1

/* If >C++11, `long long` is a valid type */
#if WL_CONF_CPP >= WL_CONF_VER_CPP11
#	define _WL_LLONG_DEFINED	1
#else
#	define _WL_LLONG_DEFINED	0
#endif /* WL_CONF_CPP >= WL_CONF_VER_CPP11 */

#else

/* Check in case `bool` is defined as a macro */
#	ifdef bool
#	define _WL_BOOL_DEFINED		1
#	else	/* bool */
#	define _WL_BOOL_DEFINED		0
#	endif	/* bool */

/* If >C99, `_Bool` and `long long` are valid types */
#if WL_CONF_C >= WL_CONF_VER_C99
#	define _WL__BOOL_DEFINED	1
#	define _WL_LLONG_DEFINED	1
#else	/* WL_CONF_C >= WL_CONF_VER_C99 */
#	define _WL__BOOL_DEFINED	0
#	define _WL_LLONG_DEFINED	0
#endif	/* WL_CONF_C >= WL_CONF_VER_C99 */

#endif /* defined(WL_CONF_CPP) */



#if !WL_CONF_PREFIX
#	define Bl	wl_Bl
#	define bl	wl_bl
#	define Bool	wl_Bool
#	if	!_WL_BOOL_DEFINED
#	define bool wl_bool
#	endif	/* !_WL_BOOL_DEFINED */

#	define CHN	WL_CHN
#	define SCN	WL_SCN
#	define SHN	WL_SHN
#	define INN	WL_INN
#	define LON	WL_LON
#	define UCN	WL_UCN
#	define USN	WL_USN
#	define UIN	WL_UIN
#	define ULN	WL_ULN

#	define CHX	WL_CHX
#	define SCX	WL_SCX
#	define SHX	WL_SHX
#	define INX	WL_INX
#	define LOX	WL_LOX
#	define UCX	WL_UCX
#	define USX	WL_USX
#	define UIX	WL_UIX
#	define ULX	WL_ULX

#	define CHB	WL_CHB
#	define SCB	WL_SCB
#	define SHB	WL_SHB
#	define INB	WL_INB
#	define LOB	WL_LOB
#	define UCB	WL_UCB
#	define USB	WL_USB
#	define UIB	WL_UIB
#	define ULB	WL_ULB

#	if	_WL_LLONG_DEFINED
#	define LLB	WL_LLB
#	define LLN	WL_LLN
#	define LLX	WL_LLX
#	define ULLB	WL_ULLB
#	define ULLN	WL_ULLN
#	define ULLX	WL_ULLX
#	endif	/* _WL_LLONG_DEFINED */

#	define I8l	wl_I8l
#	define I16l	wl_I16l
#	define I32l	wl_I32l
#	define I64l	wl_I64l
#	define U8l	wl_U8l
#	define U16l	wl_U16l
#	define U32l	wl_U32l
#	define U64l	wl_U64l

#	define i8l	wl_i8l
#	define i16l	wl_i16l
#	define i32l	wl_i32l
#	define i64l	wl_i64l
#	define i8l	wl_i8l
#	define i16l	wl_i16l
#	define i32l	wl_i32l
#	define i64l	wl_i64l

#	define I8f	wl_I8f
#	define I16f	wl_I16f
#	define I32f	wl_I32f
#	define I64f	wl_I64f
#	define U8f	wl_U8f
#	define U16f	wl_U16f
#	define U32f	wl_U32f
#	define U64f	wl_U64f

#	define i8f	wl_i8f
#	define i16f	wl_i16f
#	define i32f	wl_i32f
#	define i64f	wl_i64f
#	define i8f	wl_i8f
#	define i16f	wl_i16f
#	define i32f	wl_i32f
#	define i64f	wl_i64f

#	define I8	wl_I8
#	define I16	wl_I16
#	define I32	wl_I32
#	define I64	wl_I64
#	define U8	wl_U8
#	define U16	wl_U16
#	define U32	wl_U32
#	define U64	wl_U64

#	define i8	wl_i8
#	define i16	wl_i16
#	define i32	wl_i32
#	define i64	wl_i64
#	define i8	wl_i8
#	define i16	wl_i16
#	define i32	wl_i32
#	define i64	wl_i64

#	define IMax	wl_IMax
#	define UMax	wl_UMax
#	define FMax	wl_FMax
#	define CMax	wl_CMax
#	define imax	wl_imax
#	define umax	wl_umax
#	define fmax	wl_fmax
#	define cmax	wl_cmax

#	define Pt	wl_Pt
#	define pt	wl_pt

#	define I8N	WL_I8N
#	define I16N	WL_I16N
#	define I32N	WL_I32N
#	define I64N	WL_I64N
#	define IMN	WL_IMN
#	define U8N	WL_U8N
#	define U16N	WL_U16N
#	define U32N	WL_U32N
#	define U64N	WL_U64N
#	define UMN	WL_UMN

#	define I8X	WL_I8X
#	define I16X	WL_I16X
#	define I32X	WL_I32X
#	define I64X	WL_I64X
#	define IMX	WL_IMX
#	define U8X	WL_U8X
#	define U16X	WL_U16X
#	define U32X	WL_U32X
#	define U64X	WL_U64X
#	define UMX	WL_UMX

#	define I8B	WL_I8B
#	define I16B	WL_I16B
#	define I32B	WL_I32B
#	define I64B	WL_I64B
#	define IMB	WL_IMB
#	define U8B	WL_U8B
#	define U16B	WL_U16B
#	define U32B	WL_U32B
#	define U64B	WL_U64B
#	define UMB	WL_UMB

#	define I8LN		WL_I8LN
#	define I16LN	WL_I16LN
#	define I32LN	WL_I32LN
#	define I64LN	WL_I64LN
#	define U8LN		WL_U8LN
#	define U16LN	WL_U16LN
#	define U32LN	WL_U32LN
#	define U64LN	WL_U64LN

#	define I8LX		WL_I8LX
#	define I16LX	WL_I16LX
#	define I32LX	WL_I32LX
#	define I64LX	WL_I64LX
#	define U8LX		WL_U8LX
#	define U16LX	WL_U16LX
#	define U32LX	WL_U32LX
#	define U64LX	WL_U64LX

#	define I8LB		WL_I8LB
#	define I16LB	WL_I16LB
#	define I32LB	WL_I32LB
#	define I64LB	WL_I64LB
#	define U8LB		WL_U8LB
#	define U16LB	WL_U16LB
#	define U32LB	WL_U32LB
#	define U64LB	WL_U64LB

#	define I8FN		WL_I8FN
#	define I16FN	WL_I16FN
#	define I32FN	WL_I32FN
#	define I64FN	WL_I64FN
#	define U8FN		WL_U8FN
#	define U16FN	WL_U16FN
#	define U32FN	WL_U32FN
#	define U64FN	WL_U64FN

#	define I8FX		WL_I8FX
#	define I16FX	WL_I16FX
#	define I32FX	WL_I32FX
#	define I64FX	WL_I64FX
#	define U8FX		WL_U8FX
#	define U16FX	WL_U16FX
#	define U32FX	WL_U32FX
#	define U64FX	WL_U64FX

#	define I8FB		WL_I8FB
#	define I16FB	WL_I16FB
#	define I32FB	WL_I32FB
#	define I64FB	WL_I64FB
#	define U8FB		WL_U8FB
#	define U16FB	WL_U16FB
#	define U32FB	WL_U32FB
#	define U64FB	WL_U64FB

#	define PTB	WL_PTB
#	define PTN	WL_PTN
#	define PTX	WL_PTX

#	ifndef NULL
#	define NULL		WL_NULL
#	endif

#	ifndef TRUE
#	define TRUE		WL_TRUE
#	endif

#	ifndef FALSE
#	define FALSE	WL_FALSE
#	endif

/* #define CHAR_MIN	WL_CHAR_MIN
#define SCHAR_MIN	WL_SCHAR_MIN
#define SHORT_MIN	WL_SHORT_MIN
#define INT_MIN		WL_INT_MIN
#define LONG_MIN	WL_LONG_MIN
#define UCHAR_MIN	WL_UCHAR_MIN
#define USHORT_MIN	WL_USHORT_MIN
#define UINT_MIN	WL_UINT_MIN
#define ULONG_MIN	WL_ULONG_MIN

#define CHAR_MAX	WL_CHAR_MAX
#define SCHAR_MAX	WL_SCHAR_MAX
#define SHORT_MAX	WL_SHORT_MAX
#define INT_MAX		WL_INT_MAX
#define LONG_MAX	WL_LONG_MAX
#define UCHAR_MAX	WL_UCHAR_MAX
#define USHORT_MAX	WL_USHORT_MAX
#define UINT_MAX	WL_UINT_MAX
#define ULONG_MAX	WL_ULONG_MAX

#define CHAR_BIT	WL_CHAR_BIT
#define SCHAR_BIT	WL_SCHAR_BIT
#define SHORT_BIT	WL_SHORT_BIT
#define INT_BIT		WL_INT_BIT
#define LONG_BIT	WL_LONG_BIT
#define UCHAR_BIT	WL_UCHAR_BIT
#define USHORT_BIT	WL_USHORT_BIT
#define UINT_BIT	WL_UINT_BIT
#define ULONG_BIT	WL_ULONG_BIT

#if _WL_LLONG_DEFINED
#	define LLONG_MIN	WL_LLONG_MIN
#	define ULLONG_MIN	WL_ULLONG_MIN
#	define LLONG_MAX	WL_LLONG_MAX
#	define ULLONG_MAX	WL_ULLONG_MAX
#	define LLONG_BIT	WL_LLONG_BIT
#	define ULLONG_BIT	WL_ULLONG_BIT
#endif */

#define I8_MIN	WL_I8_MIN
#define I16_MIN	WL_I16_MIN
#define I32_MIN	WL_I32_MIN
#define I64_MIN	WL_I64_MIN
#define U8_MIN	WL_U8_MIN
#define U16_MIN	WL_U16_MIN
#define U32_MIN	WL_U32_MIN
#define U64_MIN	WL_U64_MIN

#define I8_MAX	WL_I8_MAX
#define I16_MAX	WL_I16_MAX
#define I32_MAX	WL_I32_MAX
#define I64_MAX	WL_I64_MAX
#define U8_MAX	WL_U8_MAX
#define U16_MAX	WL_U16_MAX
#define U32_MAX	WL_U32_MAX
#define U64_MAX	WL_U64_MAX

#define I8_BIT	WL_I8_BIT
#define I16_BIT	WL_I16_BIT
#define I32_BIT	WL_I32_BIT
#define I64_BIT	WL_I64_BIT
#define U8_BIT	WL_U8_BIT
#define U16_BIT	WL_U16_BIT
#define U32_BIT	WL_U32_BIT
#define U64_BIT	WL_U64_BIT

#define IMAX_MIN	WL_IMAX_MIN
#define IMAX_MAX	WL_IMAX_MAX
#define IMAX_BIT	WL_IMAX_BIT
#define UMAX_MIN	WL_UMAX_MIN
#define UMAX_MAX	WL_UMAX_MAX
#define UMAX_BIT	WL_UMAX_BIT
#define POINTER_MIN	WL_POINTER_MIN
#define POINTER_MAX	WL_POINTER_MAX
#define POINTER_BIT	WL_POINTER_BIT

#endif	/* !WL_CONF_PREFIX */



/**
 *  If `bool` is a keyword (C++), `Bl`, `Bool` == `bool`
 * 	Else if `_Bool` is a keyword (C99), `Bl`, `Bool` == `_Bool`
 * 	Else `Bl` and `Bool` are 
 */
#if _WL_BOOL_DEFINED
	typedef	bool	wl_Bl, wl_bl, wl_Bool, wl_bool;
#elif _WL__BOOL_DEFINED
	typedef	_Bool	wl_Bl, wl_bl, wl_Bool, wl_bool;
#else
	typedef	char	wl_Bl, wl_bl, wl_Bool, wl_bool;
#endif



#if WL_CONF_LIMITS
#	include <limits.h>

/* Minimal values of fundamental types */
#	define WL_CHN	CHAR_MIN
#	define WL_SCN	SCHAR_MIN
#	define WL_SHN	SHORT_MIN
#	define WL_INN	INT_MIN
#	define WL_LON	LONG_MIN
#	define WL_UCN	UCHAR_MIN
#	define WL_USN	USHORT_MIN
#	define WL_UIN	UINT_MIN
#	define WL_ULN	ULONG_MIN

/* Maximal values of fundamental types */
#	define WL_CHX	CHAR_MAX
#	define WL_SCX	SCHAR_MAX
#	define WL_SHX	SHORT_MAX
#	define WL_INX	INT_MAX
#	define WL_LOX	LONG_MAX
#	define WL_UCX	UCHAR_MAX
#	define WL_USX	USHORT_MAX
#	define WL_UIX	UINT_MAX
#	define WL_ULX	ULONG_MAX

/* Minimal and maximal values of `long long` types (>C99/>C++11) */
#	if	_WL_LLONG_DEFINED
#	define WL_LLN	LLONG_MIN
#	define WL_ULLN	ULLONG_MIN

#	define WL_LLX	LLONG_MAX
#	define WL_ULLX	ULLONG_MAX
#	endif	/* _WL_LLONG_DEFINED */

/* Widths of fundamental types */
#	ifdef CHAR_WIDTH
#	define WL_CHB	CHAR_WIDTH
#	else
#	define WL_CHB	CHAR_BIT
#	endif	/* CHAR_WIDTH */

#	ifdef BOOL_WIDTH
#	define WL_BLB	BOOL_WIDTH
#	elif defined(WL_CHB)
#	define WL_BLB	WL_CHB
#	endif	/* BOOL_WIDTH */

#	ifdef SCHAR_WIDTH
#	define WL_SCB	SCHAR_WIDTH
#	elif defined(WL_CHB)
#	define WL_SCB	WL_CHB
#	endif	/* SCHAR_WIDTH */

#	ifdef INT_WIDTH
#	define WL_INB	INT_WIDTH
#	endif	/* INT_WIDTH */

#	ifdef LONG_WIDTH
#	define WL_LOB	LONG_WIDTH
#	endif	/* LONG_WIDTH */

#	ifdef LLONG_WIDTH
#	define WL_LLB	LLONG_WIDTH
#	endif	/* LLONG_WIDTH */

#	ifdef UCHAR_WIDTH
#	define WL_UCB	UCHAR_WIDTH
#	elif defined(WL_CHB)
#	define WL_UCB	WL_CHB
#	endif	/* UCHAR_WIDTH */

#	ifdef UINT_WIDTH
#	define WL_UIB	UINT_WIDTH
#	elif defined(WL_INB)
#	define WL_UIB	WL_INB
#	endif	/* UINT_WIDTH */

#	ifdef ULONG_WIDTH
#	define WL_ULB	ULONG_WIDTH
#	elif defined(WL_LOB)
#	define WL_ULB	WL_LOB
#	endif	/* ULONG_WIDTH */

#	ifdef ULLONG_WIDTH
#	define WL_ULLB	ULLONG_WIDTH
#	elif defined(WL_LLB)
#	define WL_ULLB	WL_LLB
#	endif	/* ULONG_WIDTH */

#else

/* Guess */
#	define WL_CHB	(8)
#	define WL_CHN	((char)0x80)
#	define WL_CHX	((char)0x7F)

#	define WL_SCB	(WL_CHB)
#	define WL_SCN	((signed char)0x80)
#	define WL_SCX	((signed char)0x7F)

#	define WL_UCB	(WL_CHB)
#	define WL_UCN	((unsigned char)0x00)
#	define WL_UCX	((unsigned char)0xFF)


#if _WL_DM == _WL_DM_SILP64
#	define WL_SHB	64
#	define WL_SHN	((short)0x8000000000000000)
#	define WL_SHX	((short)0x7FFFFFFFFFFFFFFF)

#	define WL_USB	64
#	define WL_USN	((unsigned short)0x000000000000000)
#	define WL_USX	((unsigned short)0xFFFFFFFFFFFFFFF)
#else
#	define WL_SHB	16
#	define WL_SHN	((short)0x8000)
#	define WL_SHX	((short)0x7FFF)

#	define WL_USB	16
#	define WL_USN	((unsigned short)0x0000)
#	define WL_USX	((unsigned short)0xFFFF)
#endif

#if _WL_DM == _WL_DM_ILP64 || _WL_DM == _WL_DM_SILP64
#	define WL_INB	64
#	define WL_INN	((int)0x8000000000000000)
#	define WL_INX	((int)0x7FFFFFFFFFFFFFFF)

#	define WL_UIB	64
#	define WL_UIN	((unsigned int)0x000000000000000)
#	define WL_UIX	((unsigned int)0xFFFFFFFFFFFFFFF)
#else
#	define WL_INB	32
#	define WL_INN	((int)0x80000000)
#	define WL_INX	((int)0x7FFFFFFF)

#	define WL_UIB	32
#	define WL_UIN	((unsigned int)0x00000000)
#	define WL_UIX	((unsigned int)0xFFFFFFFF)
#endif

#if _WL_DM == _WL_DM_LP64 || _WL_DM == _WL_DM_ILP64 || _WL_DM == _WL_DM_SILP64
#	define WL_LOB	64
#	define WL_LON	((long)0x8000000000000000)
#	define WL_LOX	((long)0x7FFFFFFFFFFFFFFF)

#	define WL_ULB	64
#	define WL_ULN	((unsigned long)0x000000000000000)
#	define WL_ULX	((unsigned long)0xFFFFFFFFFFFFFFF)
#else
#	define WL_LOB	32
#	define WL_LON	((long)0x80000000)
#	define WL_LOX	((long)0x7FFFFFFF)

#	define WL_ULB	32
#	define WL_ULN	((unsigned long)0x00000000)
#	define WL_ULX	((unsigned long)0xFFFFFFFF)
#endif

#if _WL_LLONG_DEFINED
#	define WL_LLB	64
#	define WL_LLN	((long long)0x8000000000000000)
#	define WL_LLX	((long long)0x7FFFFFFFFFFFFFFF)

#	define WL_ULLB	64
#	define WL_ULLN	((unsigned long long)0x000000000000000)
#	define WL_ULLX	((unsigned long long)0xFFFFFFFFFFFFFFF)
#endif

#endif



#if WL_CONF_STDINT
#	include <stdint.h>

	typedef	int_fast8_t		wl_I8f,		wl_i8f;
	typedef	int_fast16_t	wl_I16f,	wl_i16f;
	typedef	int_fast32_t	wl_I32f,	wl_i32f;
	typedef	int_fast64_t	wl_I64f,	wl_i64f;
	typedef	uint_fast8_t	wl_U8f,		wl_u8f;
	typedef	uint_fast16_t	wl_U16f,	wl_u16f;
	typedef	uint_fast32_t	wl_U32f,	wl_u32f;
	typedef	uint_fast64_t	wl_U64f,	wl_u64f;

#	define WL_I8FN	INT_FAST8_MIN
#	define WL_I16FN	INT_FAST16_MIN
#	define WL_I32FN	INT_FAST32_MIN
#	define WL_I64FN	INT_FAST64_MIN
#	define WL_U8FN	UINT_FAST8_MIN
#	define WL_U16FN	UINT_FAST16_MIN
#	define WL_U32FN	UINT_FAST32_MIN
#	define WL_U64FN	UINT_FAST64_MIN

#	define WL_I8FX	INT_FAST8_MAX
#	define WL_I16FX	INT_FAST16_MAX
#	define WL_I32FX	INT_FAST32_MAX
#	define WL_I64FX	INT_FAST64_MAX
#	define WL_U8FX	UINT_FAST8_MAX
#	define WL_U16FX	UINT_FAST16_MAX
#	define WL_U32FX	UINT_FAST32_MAX
#	define WL_U64FX	UINT_FAST64_MAX

#	ifdef	INT_FAST8_WIDTH
#	define WL_I8FB	INT_FAST8_WIDTH
#	elif	INT_FAST8_MAX == 0x7F
#	define WL_I8FB	8
#	elif	INT_FAST8_MAX == 0x7FFF
#	define WL_I8FB	16
#	elif	INT_FAST8_MAX == 0x7FFFFFFF
#	define WL_I8FB	32
#	elif	INT_FAST8_MAX == 0x7FFFFFFFFFFFFFFF
#	define WL_I8FB	64
#	endif	/* INT_FAST8_WIDTH */

#	ifdef	INT_FAST16_WIDTH
#	define WL_I16FB	INT_FAST16_WIDTH
#	elif	INT_FAST16_MAX == 0x7FFF
#	define WL_I16FB	16
#	elif	INT_FAST16_MAX == 0x7FFFFFFF
#	define WL_I16FB	32
#	elif	INT_FAST16_MAX == 0x7FFFFFFFFFFFFFFF
#	define WL_I16FB	64
#	endif	/* INT_FAST16_WIDTH */

#	ifdef	INT_FAST32_WIDTH
#	define WL_I32FB	INT_FAST32_WIDTH
#	elif	INT_FAST32_MAX == 0x7FFFFFFF
#	define WL_I32FB	32
#	elif	INT_FAST32_MAX == 0x7FFFFFFFFFFFFFFF
#	define WL_I32FB	64
#	endif	/* INT_FAST32_WIDTH */

#	ifdef	INT_FAST64_WIDTH
#	define WL_I64FB	INT_FAST64_WIDTH
#	else
#	define WL_I64FB	64
#	endif	/* INT_FAST64_WIDTH */

	typedef	int_least8_t	wl_I8l,		wl_i8l;
	typedef	int_least16_t	wl_I16l,	wl_i16l;
	typedef	int_least32_t	wl_I32l,	wl_i32l;
	typedef	int_least64_t	wl_I64l,	wl_i64l;
	typedef	uint_least8_t	wl_U8l,		wl_u8l;
	typedef	uint_least16_t	wl_U16l,	wl_u16l;
	typedef	uint_least32_t	wl_U32l,	wl_u32l;
	typedef	uint_least64_t	wl_U64l,	wl_u64l;

#	define WL_I8LN	INT_LEAST8_MIN
#	define WL_I16LN	INT_LEAST16_MIN
#	define WL_I32LN	INT_LEAST32_MIN
#	define WL_I64LN	INT_LEAST64_MIN
#	define WL_U8LN	UINT_LEAST8_MIN
#	define WL_U16LN	UINT_LEAST16_MIN
#	define WL_U32LN	UINT_LEAST32_MIN
#	define WL_U64LN	UINT_LEAST64_MIN

#	define WL_I8LX	INT_LEAST8_MAX
#	define WL_I16LX	INT_LEAST16_MAX
#	define WL_I32LX	INT_LEAST32_MAX
#	define WL_I64LX	INT_LEAST64_MAX
#	define WL_U8LX	UINT_LEAST8_MAX
#	define WL_U16LX	UINT_LEAST16_MAX
#	define WL_U32LX	UINT_LEAST32_MAX
#	define WL_U64LX	UINT_LEAST64_MAX

#	ifdef	INT_LEAST8_WIDTH
#	define WL_I8LB	INT_LEAST8_WIDTH
#	else
#	define WL_I8LB	8
#	endif	/* INT_FAST8_WIDTH */

#	ifdef	INT_LEAST16_WIDTH
#	define WL_I16LB	INT_LEAST16_WIDTH
#	else
#	define WL_I16LB	16
#	endif	/* INT_FAST16_WIDTH */

#	ifdef	INT_LEAST32_WIDTH
#	define WL_I32LB	INT_LEAST32_WIDTH
#	else
#	define WL_I32LB	32
#	endif	/* INT_FAST32_WIDTH */

#	ifdef	INT_LEAST64_WIDTH
#	define WL_I64LB	INT_LEAST32_WIDTH
#	else
#	define WL_I64LB	64
#	endif	/* INT_FAST64_WIDTH */

#	define WL_U8LB	WL_I8LB
#	define WL_U16LB	WL_I16LB
#	define WL_U32LB	WL_I32LB
#	define WL_U64LB	WL_I64LB

#	define WL_U8FB	WL_I8FB
#	define WL_U16FB	WL_I16FB
#	define WL_U32FB	WL_I32FB
#	define WL_U64FB	WL_I64FB

/* 	typedef intmax_t	wl_IMax,	wl_imax;
	typedef uintmax_t	wl_UMax,	wl_umax;

#	define WL_IMN	INTMAX_MIN
#	define WL_UMN	UINTMAX_MIN
#	define WL_IMX	INTMAX_MAX
#	define WL_UMX	UINTMAX_MAX

#	if defined(INTMAX_WIDTH)
#	define WL_IMB	INTMAX_WIDTH
#	else
#	define WL_IMB	WL_I64B
#	endif

#	if defined(UINTMAX_WIDTH)
#	define WL_UMB	UINTMAX_WIDTH
#	else
#	define WL_UMB	WL_U64B
#	endif */

	/*	Use our detective skills, if both `UINTPTR_MIN` and `UINTPTR_MAX` are 
	 *	defined, we can logically conclude that `uintptr_t` is defined as well
	 */
#	if defined(__intptr_t_defined) \
	|| (defined(UINTPTR_MIN) && defined(UINTPTR_MAX))
		typedef uintptr_t	wl_Pt,		wl_pt;
#	define WL_PTN	UINTPTR_MIN
#	define WL_PTX	UINTPTR_MAX
#	if defined(UINTPTR_WIDTH)
#		define WL_PTB UINTPTR_WIDTH
#	else
#		define WL_PTB WL_U64B
#	endif	/* defined(UINTPTR_WIDTH) */
#	else
		typedef uintmax_t	wl_Pt,		wl_pt;
#	define WL_PTN	WL_UMN
#	define WL_PTX	WL_UMX
#	define WL_PTB	WL_UMB
#	endif	/* defined(__intptr_t_defined) ... */
#else
	/*	ISO C89 2.2.4.2:
		ISO C99--C2X 5.2.4.2.1:
	 	"	Their implementation-defined values shall be equal or greater in 
			magnitude (absolute value) to those shown, with the same sign.	"
	 */
	typedef signed char		wl_I8l,	wl_i8l;
	typedef unsigned char	wl_U8l,	wl_u8l;
	typedef short			wl_I16l, wl_i16l;
	typedef unsigned short	wl_U16l, wl_u16l;

#	define WL_I8LB	WL_SCB
#	define WL_I16LB	WL_SHB
#	define WL_U8LB	WL_UCB
#	define WL_U16LB	WL_USB
#	define WL_I8LN	WL_SCN
#	define WL_I16LN	WL_SHN
#	define WL_U8LN	WL_UCN
#	define WL_U16LN	WL_USN
#	define WL_I8LX	WL_SCX
#	define WL_I16LX	WL_SHX
#	define WL_U8LX	WL_UCX
#	define WL_U16LX	WL_USX


#	if WL_INB > 32
		typedef int					wl_I32l, wl_i32l;
		typedef unsigned int		wl_U32l, wl_u32l;

#	define WL_I32LB	WL_INB
#	define WL_U32LB	WL_UIB
#	define WL_I32LN	WL_INN
#	define WL_U32LN	WL_UIN
#	define WL_I32LX	WL_INX
#	define WL_U32LX	WL_UIX
#	else
		/* `long` is guaranteed to be at least 32-bit */
		typedef long				wl_I32l, wl_i32l;
		typedef unsigned long		wl_U32l, wl_u32l;

#	define WL_I32LB	WL_LOB
#	define WL_U32LB	WL_ULB
#	define WL_I32LN	WL_LON
#	define WL_U32LN	WL_ULN
#	define WL_I32LX	WL_LOX
#	define WL_U32LX	WL_ULX
#	endif

#	if _WL_LLONG_DEFINED
		/* `long long` is guaranteed to be at least 64-bit */
		typedef long long			wl_I64l,	wl_i64l;
		typedef unsigned long long	wl_U64l,	wl_u64l;

#	define WL_I64LB	WL_LLB
#	define WL_I64LN	WL_LLN
#	define WL_I64LX	WL_LLX
#	define WL_U64LB	WL_ULLB
#	define WL_U64LN	WL_ULLN
#	define WL_U64LX	WL_ULLX
#	else
		typedef long				wl_I64l, 	wl_i64l;
		typedef unsigned long		wl_U64l, 	wl_u64l;

#	define WL_I64LB	WL_LOB
#	define WL_I64LN	WL_LON
#	define WL_I64LX	WL_LOX
#	define WL_U64LB	WL_ULB
#	define WL_U64LN	WL_ULN
#	define WL_U64LX	WL_ULX
#	endif



	typedef signed char				wl_I8f, wl_i8f;
	typedef unsigned char			wl_U8f, wl_u8f;
#	if WL_CONF_WORDSIZE == 64
		typedef wl_I64l				wl_I16f, wl_i16f;
		typedef wl_I64l				wl_I32f, wl_i32f;
		typedef wl_I64l				wl_I64f, wl_i64f;
		typedef wl_U64l				wl_U16f, wl_u16f;
		typedef wl_U64l				wl_U32f, wl_u32f;
		typedef wl_U64l				wl_U64f, wl_u64f;
#	else
		typedef wl_I32l				wl_I16f, wl_i16f;
		typedef wl_I32l				wl_I32f, wl_i32f;
		typedef wl_I32l				wl_I64f, wl_i64f;
		typedef wl_U32l				wl_U16f, wl_u16f;
		typedef wl_U32l				wl_U32f, wl_u32f;
		typedef wl_U32l				wl_U64f, wl_u64f;
#	endif

/* Pointer type */
#	if WL_CONF_WORDSIZE == 64
		typedef wl_U64l	wl_Pt, wl_pt;
#	else
		typedef wl_U32l	wl_Pt, wl_pt;
#	endif

#endif



#if WL_CONF_FIXED == WL_CONF_FAST
	typedef wl_I8f	wl_I8,	wl_i8;
	typedef wl_I16f	wl_I16,	wl_i16;
	typedef wl_I32f wl_I32,	wl_i32;
	typedef wl_I64f wl_I64,	wl_i64;

	typedef wl_U8f	wl_U8,	wl_u8;
	typedef wl_U16f	wl_U16,	wl_u16;
	typedef wl_U32f wl_U32,	wl_u32;
	typedef wl_U64f wl_U64,	wl_u64;

#	define WL_I8X	WL_I8FX
#	define WL_I16X	WL_I16FX
#	define WL_I32X	WL_I32FX
#	define WL_I64X	WL_I64FX
#	define WL_U8X	WL_U8FX
#	define WL_U16X	WL_U16FX
#	define WL_U32X	WL_U32FX
#	define WL_U64X	WL_U64FX

#	define WL_I8N	WL_I8FN
#	define WL_I16N	WL_I16FN
#	define WL_I32N	WL_I32FN
#	define WL_I64N	WL_I64FN
#	define WL_U8N	WL_U8FN
#	define WL_U16N	WL_U16FN
#	define WL_U32N	WL_U32FN
#	define WL_U64N	WL_U64FN

#	define WL_I8B	WL_I8FB
#	define WL_I16B	WL_I16FB
#	define WL_I32B	WL_I32FB
#	define WL_I64B	WL_I64FB
#	define WL_U8B	WL_U8FB
#	define WL_U16B	WL_U16FB
#	define WL_U32B	WL_U32FB
#	define WL_U64B	WL_U64FB
#else
	typedef wl_I8l	wl_I8,	wl_i8;
	typedef wl_I16l	wl_I16,	wl_i16;
	typedef wl_I32l wl_I32,	wl_i32;
	typedef wl_I64l wl_I64,	wl_i64;

	typedef wl_U8l	wl_U8,	wl_u8;
	typedef wl_U16l	wl_U16,	wl_u16;
	typedef wl_U32l wl_U32,	wl_u32;
	typedef wl_U64l wl_U64,	wl_u64;

#	define WL_I8X	WL_I8LX
#	define WL_I16X	WL_I16LX
#	define WL_I32X	WL_I32LX
#	define WL_I64X	WL_I64LX
#	define WL_U8X	WL_U8LX
#	define WL_U16X	WL_U16LX
#	define WL_U32X	WL_U32LX
#	define WL_U64X	WL_U64LX

#	define WL_I8N	WL_I8LN
#	define WL_I16N	WL_I16LN
#	define WL_I32N	WL_I32LN
#	define WL_I64N	WL_I64LN
#	define WL_U8N	WL_U8LN
#	define WL_U16N	WL_U16LN
#	define WL_U32N	WL_U32LN
#	define WL_U64N	WL_U64LN

#	define WL_I8B	WL_I8LB
#	define WL_I16B	WL_I16LB
#	define WL_I32B	WL_I32LB
#	define WL_I64B	WL_I64LB
#	define WL_U8B	WL_U8LB
#	define WL_U16B	WL_U16LB
#	define WL_U32B	WL_U32LB
#	define WL_U64B	WL_U64LB
#endif



/* Maximal width types */
#	if WL_CONF_MAXSTD
		/* Maximal-width signed integer type */
		typedef long long									wl_IMax, wl_imax;
		/* Maximal-width unsigned integer type */
		typedef unsigned long long							wl_UMax, wl_umax;
#		define WL_IMB	WL_LLB
#		define WL_IMN	WL_LLN
#		define WL_IMX	WL_LLX
#		define WL_UMB	WL_ULLB
#		define WL_UMN	WL_ULLN
#		define WL_UMX	WL_ULLX

#		if WL_CONF_FLOAT
			/* Maximal-width real floating-point type */
			typedef long double									wl_FMax, wl_fmax;
#			if WL_CONF_COMPLEX
				/* Maximal-width complex floating-point type */
				typedef long double _Complex					wl_CMax, wl_cmax;
#			endif
#		endif
#	else
#		if WL_CONF_INT128
			/* Maximal-width signed integer type */
			typedef __int128								wl_IMax, wl_imax;
			/* Maximal-width unsigned integer type */
			typedef unsigned __int128						wl_UMax, wl_umax;
#		define WL_IMB	WL_LLB
#		define WL_IMN	WL_LLN
#		define WL_IMX	WL_LLX
#		define WL_UMB	WL_ULLB
#		define WL_UMN	WL_ULLN
#		define WL_UMX	WL_ULLX
#		else
			/* Maximal-width signed integer type */
			typedef wl_I64									wl_IMax, wl_imax;
			/* Maximal-width unsigned integer type */
			typedef wl_U64									wl_UMax, wl_umax;
#			define WL_IMB	WL_I64B
#			define WL_IMN	WL_I64N
#			define WL_IMX	WL_I64X
#			define WL_UMB	WL_U64B
#			define WL_UMN	WL_U64N
#			define WL_UMX	WL_U64X
#		endif

/*	Compilers for ancient system (e.g. CC65) may not have a support for 
 *	floating-point types, due to hardware limitation of targets they compile 
 *	for.
 */
#		if	WL_CONF_FLOAT
#			if		WL_CONF_FLOAT128
				/* Maximal-width real floating-point type */
				typedef __float128							wl_FMax, wl_fmax;
#				define FMB	128
#			elif	WL_CONF_FLOAT80
				/* Maximal-width real floating-point type */
				typedef __float80							wl_FMax, wl_fmax;
#				define FMB	128
#			else
				/* Maximal-width real floating-point type */
				typedef long double							wl_FMax, wl_fmax;
#				define FMB	64
#			endif

#			if WL_CONF_COMPLEX
#				if		WL_CONF_FLOAT128
					/* Maximal-width real floating-point type */
					typedef _Complex float __attribute__((mode(TC)))
															wl_CMax, wl_cmax;
#					define CMB	256
#				elif		WL_CONF_FLOAT80
					/* Maximal-width real floating-point type */
					typedef _Complex float __attribute__((mode(XC)))
															wl_CMax, wl_cmax;
#					define CMB	256
#				else
					/* Maximal-width complex floating-point type */
					typedef long double _Complex			wl_CMax, wl_cmax;
#					define CMB	128
#				endif
#			endif
#		else
			/* Floating-point types are not supported */
#		endif
#	endif



#define WL_NULL		((void*)0)

#define WL_FALSE	((Bl)0)
#define WL_TRUE		((Bl)1)



#define WL_CHAR_MIN		WL_CHN
#define WL_SCHAR_MIN	WL_SCN
#define WL_SHORT_MIN	WL_SHN
#define WL_INT_MIN		WL_INN
#define WL_LONG_MIN		WL_LON
#define WL_UCHAR_MIN	WL_UCN
#define WL_USHORT_MIN	WL_USN
#define WL_UINT_MIN		WL_UIN
#define WL_ULONG_MIN	WL_ULN

#define WL_CHAR_MAX		WL_CHX
#define WL_SCHAR_MAX	WL_SCX
#define WL_SHORT_MAX	WL_SHX
#define WL_INT_MAX		WL_INX
#define WL_LONG_MAX		WL_LOX
#define WL_UCHAR_MAX	WL_UCX
#define WL_USHORT_MAX	WL_USX
#define WL_UINT_MAX		WL_UIX
#define WL_ULONG_MAX	WL_ULX

#define WL_CHAR_BIT		WL_CHB
#define WL_SCHAR_BIT	WL_SCB
#define WL_SHORT_BIT	WL_SHB
#define WL_INT_BIT		WL_INB
#define WL_LONG_BIT		WL_LOB
#define WL_UCHAR_BIT	WL_UCB
#define WL_USHORT_BIT	WL_USB
#define WL_UINT_BIT		WL_UIB
#define WL_ULONG_BIT	WL_ULB

#if _WL_LLONG_DEFINED
#	define WL_LLONG_MIN		WL_LLN
#	define WL_ULLONG_MIN	WL_ULLN
#	define WL_LLONG_MAX		WL_LLX
#	define WL_ULLONG_MAX	WL_ULLX
#	define WL_LLONG_BIT		WL_LLB
#	define WL_ULLONG_BIT	WL_ULLB
#endif

#define WL_I8L_MIN		WL_I8LN
#define WL_I16L_MIN		WL_I16LN
#define WL_I32L_MIN		WL_I32LN
#define WL_I64L_MIN		WL_I64LN
#define WL_U8L_MIN		WL_U8LN
#define WL_U16L_MIN		WL_U16LN
#define WL_U32L_MIN		WL_U32LN
#define WL_U64L_MIN		WL_U64LN

#define WL_I8L_MAX		WL_I8LX
#define WL_I16L_MAX		WL_I16LX
#define WL_I32L_MAX		WL_I32LX
#define WL_I64L_MAX		WL_I64LX
#define WL_U8L_MAX		WL_U8LX
#define WL_U16L_MAX		WL_U16LX
#define WL_U32L_MAX		WL_U32LX
#define WL_U64L_MAX		WL_U64LX

#define WL_I8L_BIT		WL_I8LB
#define WL_I16L_BIT		WL_I16LB
#define WL_I32L_BIT		WL_I32LB
#define WL_I64L_BIT		WL_I64LB
#define WL_U8L_BIT		WL_U8LB
#define WL_U16L_BIT		WL_U16LB
#define WL_U32L_BIT		WL_U32LB
#define WL_U64L_BIT		WL_U64LB

#define WL_I8F_MIN		WL_I8FN
#define WL_I16F_MIN		WL_I16FN
#define WL_I32F_MIN		WL_I32FN
#define WL_I64F_MIN		WL_I64FN
#define WL_U8F_MIN		WL_U8FN
#define WL_U16F_MIN		WL_U16FN
#define WL_U32F_MIN		WL_U32FN
#define WL_U64F_MIN		WL_U64FN

#define WL_I8F_MAX		WL_I8FX
#define WL_I16F_MAX		WL_I16FX
#define WL_I32F_MAX		WL_I32FX
#define WL_I64F_MAX		WL_I64FX
#define WL_U8F_MAX		WL_U8FX
#define WL_U16F_MAX		WL_U16FX
#define WL_U32F_MAX		WL_U32FX
#define WL_U64F_MAX		WL_U64FX

#define WL_I8F_BIT		WL_I8FB
#define WL_I16F_BIT		WL_I16FB
#define WL_I32F_BIT		WL_I32FB
#define WL_I64F_BIT		WL_I64FB
#define WL_U8F_BIT		WL_U8FB
#define WL_U16F_BIT		WL_U16FB
#define WL_U32F_BIT		WL_U32FB
#define WL_U64F_BIT		WL_U64FB

#define WL_I8_MIN		WL_I8N
#define WL_I16_MIN		WL_I16N
#define WL_I32_MIN		WL_I32N
#define WL_I64_MIN		WL_I64N
#define WL_U8_MIN		WL_U8N
#define WL_U16_MIN		WL_U16N
#define WL_U32_MIN		WL_U32N
#define WL_U64_MIN		WL_U64N

#define WL_I8_MAX		WL_I8X
#define WL_I16_MAX		WL_I16X
#define WL_I32_MAX		WL_I32X
#define WL_I64_MAX		WL_I64X
#define WL_U8_MAX		WL_U8X
#define WL_U16_MAX		WL_U16X
#define WL_U32_MAX		WL_U32X
#define WL_U64_MAX		WL_U64X

#define WL_I8_BIT		WL_I8B
#define WL_I16_BIT		WL_I16B
#define WL_I32_BIT		WL_I32B
#define WL_I64_BIT		WL_I64B
#define WL_U8_BIT		WL_U8B
#define WL_U16_BIT		WL_U16B
#define WL_U32_BIT		WL_U32B
#define WL_U64_BIT		WL_U64B

#define WL_IMAX_MIN		WL_IMN
#define WL_IMAX_MAX		WL_IMX
#define WL_IMAX_BIT		WL_IMB
#define WL_UMAX_MIN		WL_UMN
#define WL_UMAX_MAX		WL_UMX
#define WL_UMAX_BIT		WL_UMB
#define WL_POINTER_MIN	WL_PTN
#define WL_POINTER_MAX	WL_PTX
#define WL_POINTER_BIT	WL_PTB

#endif
