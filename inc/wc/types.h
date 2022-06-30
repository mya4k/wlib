#ifndef WL_TYPES_H
#define WL_TYPES_H	1



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
#		define _WL_BOOL_DEFINED		1
#	else	/* bool */
#		define _WL_BOOL_DEFINED		0
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
#		define bool wl_bool
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
#		define LLB	WL_LLB
#		define LLN	WL_LLN
#		define LLX	WL_LLX
#		define ULLB	WL_ULLB
#		define ULLN	WL_ULLN
#		define ULLX	WL_ULLX
#	endif	/* _WL_LLONG_DEFINED */

#	define I8	wl_I8
#	define I16	wl_I16
#	define I32	wl_I32
#	define I64	wl_I64
#	define IMax	wl_IMax
#	define U8	wl_U8
#	define U16	wl_U16
#	define U32	wl_U32
#	define U64	wl_U64
#	define UMax	wl_UMax
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

#	define PTB	WL_PTB
#	define PTN	WL_PTN
#	define PTX	WL_PTX

#	ifndef NULL
#		define NULL		WL_NULL
#	endif

#	ifndef TRUE
#		define TRUE		WL_TRUE
#	endif

#	ifndef FALSE
#		define FALSE	WL_FALSE
#	endif

#define CHAR_MIN	WL_CHAR_MIN
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
#endif	/* _WL_LLONG_DEFINED */

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
#		define WL_LLN	LLONG_MIN
#		define WL_ULLN	ULLONG_MIN

#		define WL_LLX	LLONG_MAX
#		define WL_ULLX	ULLONG_MAX
#	endif	/* _WL_LLONG_DEFINED */

/* Widths of fundamental types */
#	ifdef CHAR_WIDTH
#		define WL_CHB	CHAR_WIDTH
#	else
#		define WL_CHB	CHAR_BIT
#	endif	/* CHAR_WIDTH */

#	ifdef BOOL_WIDTH
#		define WL_BLB	BOOL_WIDTH
#	elif defined(WL_CHB)
#		define WL_BLB	WL_CHB
#	endif	/* BOOL_WIDTH */

#	ifdef SCHAR_WIDTH
#		define WL_SCB	SCHAR_WIDTH
#	elif defined(WL_CHB)
#		define WL_SCB	WL_CHB
#	endif	/* SCHAR_WIDTH */

#	ifdef INT_WIDTH
#		define WL_INB	INT_WIDTH
#	endif	/* INT_WIDTH */

#	ifdef LONG_WIDTH
#		define WL_LOB	LONG_WIDTH
#	endif	/* LONG_WIDTH */

#	ifdef LLONG_WIDTH
#		define WL_LLB	LLONG_WIDTH
#	endif	/* LLONG_WIDTH */

#	ifdef UCHAR_WIDTH
#		define WL_UCB	UCHAR_WIDTH
#	elif defined(WL_CHB)
#		define WL_UCB	WL_CHB
#	endif	/* UCHAR_WIDTH */

#	ifdef UINT_WIDTH
#		define WL_UIB	UINT_WIDTH
#	elif defined(WL_INB)
#		define WL_UIB	WL_INB
#	endif	/* UINT_WIDTH */

#	ifdef ULONG_WIDTH
#		define WL_ULB	ULONG_WIDTH
#	elif defined(WL_LOB)
#		define WL_ULB	WL_LOB
#	endif	/* ULONG_WIDTH */

#	ifdef ULLONG_WIDTH
#		define WL_ULLB	ULLONG_WIDTH
#	elif defined(WL_LLB)
#		define WL_ULLB	WL_LLB
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

#	if WL_CONF_FIXED == WL_CONF_FAST
		typedef	int_fast8_t		wl_I8,	wl_i8;
		typedef	int_fast16_t	wl_I16,	wl_i16;
		typedef	int_fast32_t	wl_I32,	wl_i32;
		typedef	int_fast64_t	wl_I64,	wl_i64;
		typedef	uint_fast8_t	wl_U8,	wl_u8;
		typedef	uint_fast16_t	wl_U16,	wl_u16;
		typedef	uint_fast32_t	wl_U32,	wl_u32;
		typedef	uint_fast64_t	wl_U64,	wl_u64;

#		define WL_I8N	INT_FAST8_MIN
#		define WL_I16N	INT_FAST16_MIN
#		define WL_I32N	INT_FAST32_MIN
#		define WL_I64N	INT_FAST64_MIN
#		define WL_U8N	UINT_FAST8_MIN
#		define WL_U16N	UINT_FAST16_MIN
#		define WL_U32N	UINT_FAST32_MIN
#		define WL_U64N	UINT_FAST64_MIN

#		define WL_I8X	INT_FAST8_MAX
#		define WL_I16X	INT_FAST16_MAX
#		define WL_I32X	INT_FAST32_MAX
#		define WL_I64X	INT_FAST64_MAX
#		define WL_U8X	UINT_FAST8_MAX
#		define WL_U16X	UINT_FAST16_MAX
#		define WL_U32X	UINT_FAST32_MAX
#		define WL_U64X	UINT_FAST64_MAX

#		ifdef	INT_FAST8_WIDTH
#			define WL_I8B	INT_FAST8_WIDTH
#		elif	INT_FAST8_MAX == 0x7F
#			define WL_I8B	8
#		elif	INT_FAST8_MAX == 0x7FFF
#			define WL_I8B	16
#		elif	INT_FAST8_MAX == 0x7FFFFFFF
#			define WL_I8B	32
#		elif	INT_FAST8_MAX == 0x7FFFFFFFFFFFFFFF
#			define WL_I8B	64
#		endif	/* INT_FAST8_WIDTH */

#		ifdef	INT_FAST16_WIDTH
#			define WL_I16B	INT_FAST16_WIDTH
#		elif	INT_FAST16_MAX == 0x7FFF
#			define WL_I16B	16
#		elif	INT_FAST16_MAX == 0x7FFFFFFF
#			define WL_I16B	32
#		elif	INT_FAST16_MAX == 0x7FFFFFFFFFFFFFFF
#			define WL_I16B	64
#		endif	/* INT_FAST16_WIDTH */

#		ifdef	INT_FAST32_WIDTH
#			define WL_I32B	INT_FAST32_WIDTH
#		elif	INT_FAST32_MAX == 0x7FFFFFFF
#			define WL_I32B	32
#		elif	INT_FAST32_MAX == 0x7FFFFFFFFFFFFFFF
#			define WL_I32B	64
#		endif	/* INT_FAST32_WIDTH */

#		ifdef	INT_FAST64_WIDTH
#			define WL_I64B	INT_FAST64_WIDTH
#		else
#			define WL_I64B	64
#		endif	/* INT_FAST64_WIDTH */

#	else	/* WL_CONF_FIXED == WL_CONF_LEAST */
		typedef	int_least8_t	wl_I8,	wl_i8;
		typedef	int_least16_t	wl_I16,	wl_i16;
		typedef	int_least32_t	wl_I32,	wl_i32;
		typedef	int_least64_t	wl_I64,	wl_i64;
		typedef	uint_least8_t	wl_U8,	wl_u8;
		typedef	uint_least16_t	wl_U16,	wl_u16;
		typedef	uint_least32_t	wl_U32,	wl_u32;
		typedef	uint_least64_t	wl_U64,	wl_u64;

#		define WL_I8N	INT_LEAST8_MIN
#		define WL_I16N	INT_LEAST16_MIN
#		define WL_I32N	INT_LEAST32_MIN
#		define WL_I64N	INT_LEAST64_MIN
#		define WL_U8N	UINT_LEAST8_MIN
#		define WL_U16N	UINT_LEAST16_MIN
#		define WL_U32N	UINT_LEAST32_MIN
#		define WL_U64N	UINT_LEAST64_MIN

#		define WL_I8X	INT_LEAST8_MAX
#		define WL_I16X	INT_LEAST16_MAX
#		define WL_I32X	INT_LEAST32_MAX
#		define WL_I64X	INT_LEAST64_MAX
#		define WL_U8X	UINT_LEAST8_MAX
#		define WL_U16X	UINT_LEAST16_MAX
#		define WL_U32X	UINT_LEAST32_MAX
#		define WL_U64X	UINT_LEAST64_MAX

#		ifdef	INT_LEAST8_WIDTH
#			define WL_I8B	INT_LEAST8_WIDTH
#		else
#			define WL_I8B	8
#		endif	/* INT_FAST8_WIDTH */

#		ifdef	INT_LEAST16_WIDTH
#			define WL_I16B	INT_LEAST16_WIDTH
#		else
#			define WL_I16B	16
#		endif	/* INT_FAST16_WIDTH */

#		ifdef	INT_LEAST32_WIDTH
#			define WL_I32B	INT_LEAST32_WIDTH
#		else
#			define WL_I32B	32
#		endif	/* INT_FAST32_WIDTH */

#		ifdef	INT_LEAST64_WIDTH
#			define WL_I64B	INT_LEAST32_WIDTH
#		else
#			define WL_I64B	64
#		endif	/* INT_FAST64_WIDTH */
#	endif	/* WL_CONF_FIXED == WL_CONF_LEAST */

#	define WL_U8B	WL_I8B
#	define WL_U16B	WL_I16B
#	define WL_U32B	WL_I32B
#	define WL_U64B	WL_I64B

	typedef intmax_t	wl_IMax,	wl_imax;
	typedef uintmax_t	wl_UMax,	wl_umax;

#	define WL_IMN	INTMAX_MIN
#	define WL_UMN	UINTMAX_MIN
#	define WL_IMX	INTMAX_MAX
#	define WL_UMX	UINTMAX_MAX

#	if defined(INTMAX_WIDTH)
#		define WL_IMB	INTMAX_WIDTH
#	else
#		define WL_IMB	WL_I64B
#	endif

#	if defined(UINTMAX_WIDTH)
#		define WL_UMB	UINTMAX_WIDTH
#	else
#		define WL_UMB	WL_U64B
#	endif

	/*	Use our detective skills, if both `UINTPTR_MIN` and `UINTPTR_MAX` are 
	 *	defined, we can logically conclude that `uintptr_t` is defined as well
	 */
#	if defined(__intptr_t_defined) \
	|| (defined(UINTPTR_MIN) && defined(UINTPTR_MAX))
		typedef uintptr_t	wl_Pt,		wl_pt;
#		define WL_PTN	UINTPTR_MIN
#		define WL_PTX	UINTPTR_MAX
#		if defined(UINTPTR_WIDTH)
#			define WL_PTB UINTPTR_WIDTH
#		else
#			define WL_PTB WL_U64B
#		endif	/* defined(UINTPTR_WIDTH) */
#	else
		typedef uintmax_t	wl_Pt,		wl_pt;
#		define WL_PTN	WL_UMN
#		define WL_PTX	WL_UMX
#		define WL_PTB	WL_UMB
#	endif	/* defined(__intptr_t_defined) ... */
#else
	/*	ISO C89 2.2.4.2:
		ISO C99--C2X 5.2.4.2.1:
	 	"	Their implementation-defined values shall be equal or greater in 
			magnitude (absolute value) to those shown, with the same sign.	"
	 */
	typedef signed char		wl_I8,	wl_i8;
	typedef unsigned char	wl_U8,	wl_u8;
	typedef short			wl_I16, wl_i16;
	typedef unsigned short	wl_U16, wl_u16;

#	define WL_I8B	WL_SCB
#	define WL_I16B	WL_SHB
#	define WL_U8B	WL_UCB
#	define WL_U16B	WL_USB
#	define WL_I8N	WL_SCN
#	define WL_I16N	WL_SHN
#	define WL_U8N	WL_UCN
#	define WL_U16N	WL_USN
#	define WL_I8X	WL_SCX
#	define WL_I16X	WL_SHX
#	define WL_U8X	WL_UCX
#	define WL_U16X	WL_USX


#	if WL_INB > 32
		typedef int					wl_I32, wl_i32;
		typedef unsigned int		wl_U32, wl_u32;

#		define WL_I32B	WL_INB
#		define WL_U32B	WL_UIB
#		define WL_I32N	WL_INN
#		define WL_U32N	WL_UIN
#		define WL_I32X	WL_INX
#		define WL_U32X	WL_UIX
#	else
		/* `long` is guaranteed to be at least 32-bit */
		typedef long				wl_I32, wl_i32;
		typedef unsigned long		wl_I32, wl_i32;

#		define WL_I32B	WL_LOB
#		define WL_U32B	WL_ULB
#		define WL_I32N	WL_LON
#		define WL_U32N	WL_ULN
#		define WL_I32X	WL_LOX
#		define WL_U32X	WL_ULX
#	endif

#	if _WL_LLONG_DEFINED
		/* `long long` is guaranteed to be at least 64-bit */
		typedef long long			wl_I64,		wl_i64;
		typedef unsigned long long	wl_U64,		wl_u64;
		typedef long long			wl_IMax,	wl_imax;
		typedef unsigned long long	wl_UMax,	wl_umax;
		typedef unsigned long long	wl_Pt,		wl_pt;

#		define WL_I64B	WL_LLB
#		define WL_I64N	WL_LLN
#		define WL_I64X	WL_LLX
#		define WL_U64B	WL_ULLB
#		define WL_U64N	WL_ULLN
#		define WL_U64X	WL_ULLX
#		define WL_IMB	WL_LLB
#		define WL_IMN	WL_LLN
#		define WL_IMX	WL_LLX
#		define WL_UMB	WL_ULLB
#		define WL_UMN	WL_ULLN
#		define WL_UMX	WL_ULLX
#		define WL_PTB	WL_ULLB
#		define WL_PTN	WL_ULLN
#		define WL_PTX	WL_ULLX
#	else
		typedef long				wl_I64, 	wl_i64;
		typedef unsigned long		wl_U64, 	wl_u64;
		typedef long				wl_IMax,	wl_imax;
		typedef unsigned long 		wl_UMax,	wl_umax;
		typedef unsigned long		wl_Pt,		wl_pt;

#		define WL_I64B	WL_LOB
#		define WL_I64N	WL_LON
#		define WL_I64X	WL_LOX
#		define WL_U64B	WL_ULB
#		define WL_U64N	WL_ULN
#		define WL_U64X	WL_ULX
#		define WL_IMB	WL_LOB
#		define WL_IMN	WL_LON
#		define WL_IMX	WL_LOX
#		define WL_UMB	WL_ULB
#		define WL_UMN	WL_ULN
#		define WL_UMX	WL_ULX
#		define WL_PTB	WL_ULB
#		define WL_PTN	WL_ULN
#		define WL_PTX	WL_ULX
#	endif
#endif



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
