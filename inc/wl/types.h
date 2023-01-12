/**
 * \file types.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2023-01-03
 * \todo No C library fixed-width
 * 
 */
#ifndef WL_TYPES_H
#	define WL_TYPES_H	1



#include <wl/config.h>
#if WL_C_LIMITS
#	include <limits.h>
#endif	/* WL_C_LIMITS */
#if WL_C_STDINT
#	include <stdint.h>
#endif	/* WL_C_STDINT */



#if !WL_PREFIX
#	define I8l 		wl_I8l
#	define U8l 		wl_U8l
#	define I16l		wl_I16l
#	define U16l		wl_U16l
#	define I32l		wl_I32l
#	define U32l		wl_U32l
#	define I64l		wl_I64l
#	define U64l		wl_U64l
#	define I8f		wl_I8f
#	define U8f		wl_U8f
#	define I16f		wl_I16f
#	define I32f		wl_I32f
#	define I64f		wl_I64f
#	define U16f		wl_U16f
#	define U32f		wl_U32f
#	define U64f		wl_U64f
#	define I8		wl_I8
#	define I16		wl_I16
#	define I32		wl_I32
#	define I64		wl_I64
#	define U8		wl_U8
#	define U16		wl_U16
#	define U32		wl_U32
#	define U64		wl_U64
#	define UCN		WL_UCN
#	define USN		WL_USN
#	define UIN		WL_UIN
#	define ULN		WL_ULN
#	define UCX		WL_UCX
#	define USX		WL_USX
#	define UIX		WL_UIX
#	define ULX		WL_ULX
#	define SCX		WL_SCX
#	define SHX		WL_SHX
#	define INX		WL_INX
#	define LOX		WL_LOX
#	define SCN		WL_SCN
#	define SHN		WL_SHN
#	define INN		WL_INN
#	define LON		WL_LON
#	define CHN		WL_CHN
#	define CHX		WL_CHX
#	define CHB		WL_CHB
#	define SCB		WL_SCB
#	define SHB		WL_SHB
#	define INB		WL_INB
#	define LOB		WL_LOB
#	define UCB		WL_UCB
#	define USB		WL_USB
#	define UIB		WL_UIB
#	define ULB		WL_ULB
#	define LLB		WL_LLB
#	define ULLB		WL_ULLB
#	define ULLN		WL_ULLN
#	define ULLX		WL_ULLX
#	define LLX		WL_LLX
#	define LLN		WL_LLN
#	define I8LB		WL_I8LB
#	define I16LB	WL_I16LB
#	define U8LB		WL_U8LB
#	define U16LB	WL_U16LB
#	define I8LN		WL_I8LN
#	define I16LN	WL_I16LN
#	define U8LN		WL_U8LN
#	define U16LN	WL_U16LN
#	define I8LX		WL_I8LX
#	define I16LX	WL_I16LX
#	define U8LX		WL_U8LX
#	define U16LX	WL_U16LX
#	define I32LB	WL_I32LB
#	define U32LB	WL_U32LB
#	define I32LN	WL_I32LN
#	define U32LN	WL_U32LN
#	define I32LX	WL_I32LX
#	define U32LX	WL_U32LX
#	define I64LB	WL_I64LB
#	define U64LB	WL_U64LB
#	define I64LN	WL_I64LN
#	define U64LN	WL_U64LN
#	define I64LX	WL_I64LX
#	define U64LX	WL_U64LX
#	define I8FB		WL_I8FB
#	define U8FB		WL_U8FB
#	define I8FN		WL_I8FN
#	define U8FN		WL_U8FN
#	define I8FX		WL_I8FX
#	define U8FX		WL_U8FX
#	define I16FB	WL_I16FB
#	define I32FB	WL_I32FB
#	define I64FB	WL_I64FB
#	define U16FB	WL_U16FB
#	define U32FB	WL_U32FB
#	define U64FB	WL_U64FB
#	define I16FN	WL_I16FN
#	define I32FN	WL_I32FN
#	define I64FN	WL_I64FN
#	define U16FN	WL_U16FN
#	define U32FN	WL_U32FN
#	define U64FN	WL_U64FN
#	define I16FX	WL_I16FX
#	define I32FX	WL_I32FX
#	define I64FX	WL_I64FX
#	define U16FX	WL_U16FX
#	define U32FX	WL_U32FX
#	define U64FX	WL_U64FX
#	define I8B		WL_I8B
#	define I16B		WL_I16B
#	define I32B		WL_I32B
#	define I64B		WL_I64B
#	define U8B		WL_U8B
#	define U16B		WL_U16B
#	define U32B		WL_U32B
#	define U64B		WL_U64B
#	define I8N		WL_I8N
#	define I16N		WL_I16N
#	define I32N		WL_I32N
#	define I64N		WL_I64N
#	define U8N		WL_U8N
#	define U16N		WL_U16N
#	define U32N		WL_U32N
#	define U64N		WL_U64N
#	define I8X		WL_I8X
#	define I16X		WL_I16X
#	define I32X		WL_I32X
#	define I64X		WL_I64X
#	define U8X		WL_U8X
#	define U16X		WL_U16X
#	define U32X		WL_U32X
#	define U64X		WL_U64X
#endif /* !WL_PREFIX */



#ifndef WL_NO
#	define WL_NO(X)	X
#endif	/* WL_NO */

/* Macros for a work around compilers raising an error because of a cast in
preprocessor */
#	define WL_NOX_(x)
#	define WL_NOX(x)	WL_NOX_ x



/* # Fundamental types */

/* Boolean type is aliased, so look for it deeper in */

/* ## Type limits */

/**
 * \brief	Minimal value of `unsigned char`
 * \def		WL_UCN
 */
#	define WL_UCN	(0)

/**
 * \brief	Minimal value of `unsigned short`
 * \def		WL_USN
 */
#	define WL_USN	(0)

/**
 * \brief	Minimal value of `unsigned int`
 * \def		WL_UIN
 */
#	define WL_UIN	(0)

/**
 * \brief	Minimal value of `unsigned long`
 * \def		WL_ULN
 */
#	define WL_ULN	(0)

/**
 * \brief	Maximal value of `unsigned char`
 * \def		WL_UCX
 */
/**
 * \brief	Maximal value of `unsigned short`
 * \def		WL_USX
 */
/**
 * \brief	Maximal value of `unsigned int`
 * \def		WL_UIX
 */
/**
 * \brief	Maximal value of `unsigned long`
 * \def		WL_ULX
 */
/**
 * \brief	Maximal value of `signed char`
 * \def		WL_SCX
 */
/**
 * \brief	Maximal value of `signed short`
 * \def		WL_SHX
 */
/**
 * \brief	Maximal value of `signed int`
 * \def		WL_INX
 */
/**
 * \brief	Maximal value of `signed long`
 * \def		WL_LOX
 */
/**
 * \brief	Minimal value of `signed char`
 * \def		WL_SCN
 */
/**
 * \brief	Minimal value of `signed short`
 * \def		WL_SHN
 */
/**
 * \brief	Minimal value of `signed int`
 * \def		WL_INN
 */
/**
 * \brief	Minimal value of `signed long`
 * \def		WL_LON
 */
#if WL_C_LIMITS
#	define WL_UCX	UCHAR_MAX
#	define WL_USX	USHRT_MAX
#	define WL_UIX	UINT_MAX
#	define WL_ULX	ULONG_MAX
#	define WL_SCX	CHAR_MAX
#	define WL_SHX	SHRT_MAX
#	define WL_INX	INT_MAX
#	define WL_LOX	LONG_MAX
#	define WL_SCN	CHAR_MIN
#	define WL_SHN	SHRT_MIN
#	define WL_INN	INT_MIN
#	define WL_LON	LONG_MIN
#else	/* WL_C_LIMITS */
#	define WL_UCX	(WL_NOX((unsigned char)-1))
#	define WL_USX	(WL_NOX((unsigned short)-1))
#	define WL_UIX	(WL_NOX((unsigned int)-1))
#	define WL_ULX	(WL_NOX((unsigned long)-1))
#	define WL_SCX	(WL_NOX((WL_UCX/2)))
#	define WL_SHX	(WL_NOX((WL_USX/2)))
#	define WL_INX	(WL_NOX((WL_UIX/2)))
#	define WL_LOX	(WL_NOX((WL_ULX/2)))
#	define WL_SCN	(WL_NOX((signed char)(WL_SCX+1)))
#	define WL_SHN	(WL_NOX((short)(WL_SHX+1)))
#	define WL_INN	(WL_NOX((int)(WL_INX+1)))
#	define WL_LON	(WL_NOX((long)(WL_LOX+1)))
#endif	/* WL_C_LIMITS */



/**
 * \brief	Minimal value of `char`
 * \def		WL_CHN
 */
/**
 * \brief	Maximal value of `char`
 * \def		WL_CHN
 */
#if WL_CHAR_UNSIGNED
#	define WL_CHN		WL_UCN
#	define WL_CHX		WL_UCX
#else	/* WL_CHAR_UNSIGNED */
#	define WL_CHN		WL_UCN
#	define WL_CHX		WL_UCX
#endif	/* WL_CHAR_UNSIGNED */


/* ## Type widths */

/**
 * \brief	Bit width of `char`
 * \def		WL_CHB
 */
#	ifdef CHAR_WIDTH
#		define WL_CHB	CHAR_WIDTH
#	elif defined(CHAR_BIT)
#		define WL_CHB	CHAR_BIT
#	else	/* CHAR_WIDTH */
#		define WL_CHB	8	/* In doubt assume 8 */
#	endif	/* CHAR_WIDTH */

/**
 * \brief	Bit width of `signed char`
 * \def		WL_SCB
 */
#	ifdef SCHAR_WIDTH
#		define WL_SCB	SCHAR_WIDTH
#	else	/* SCHAR_WIDTH */
#		define WL_SCB	WL_CHB
#	endif	/* SCHAR_WIDTH */

/* Remember that `sizeof` is evaluated after preprocessor */

/**
 * \brief	Bit width of `short`
 * \def		WL_SHB
 */
#	ifdef SHRT_WIDTH
#		define WL_SHB	SHRT_WIDTH
#	elif	WL_USX & WL_NOX((unsigned long)WL_UCX<<WL_CHB)		/* If 2 bytes */
#		define WL_SHB	(2*WL_CHB)
#	elif	WL_USX & WL_NOX((unsigned long)WL_UCX<<(3*WL_CHB))	/* If 4 bytes */
#		define WL_SHB	(4*WL_CHB)
#	else	/* SHRT_WIDTH */						 			/* Otherwise 8 bytes */
#		define WL_SHB	(8*WL_CHB)
#	endif	/* SHRT_WIDTH */

/**
 * \brief	Bit width of `int`
 * \def		WL_INB
 */
#	ifdef INT_WIDTH
#		define WL_INB	INT_WIDTH
#	elif	WL_UIX & WL_NOX((unsigned long)WL_UCX<<WL_CHB)		/* If 2 bytes */
#		define WL_INB	(2*WL_CHB)
#	elif	WL_UIX & WL_NOX((unsigned long)WL_UCX<<(3*WL_CHB))	/* If 4 bytes */
#		define WL_INB	(4*WL_CHB)
#	else	/* INT_WIDTH */										/* Otherwise 8 bytes */
#		define WL_INB	(8*WL_CHB)
#	endif	/* INT_WIDTH */

/**
 * \brief	Bit width of `long`
 * \def		WL_LOB
 */
#	ifdef LONG_WIDTH
#		define WL_LOB	LONG_WIDTH
#	elif	WL_UIX & WL_NOX((unsigned long)WL_UCX<<(3*WL_CHB))	/* If 4 bytes */
#		define WL_LOB	(4*WL_CHB)
#	else	/* LONG_WIDTH */						 /* Otherwise 8 bytes */
#		define WL_LOB	(8*WL_CHB)
#	endif	/* LONG_WIDTH */

/**
 * \brief	Bit width of `unsigned char`
 * \def		WL_UCB
 */
#	define WL_UCB	WL_CHB

/**
 * \brief	Bit width of `unsigned short`
 * \def		WL_USB
 */
#	define WL_USB	WL_SHB

/**
 * \brief	Bit width of `unsigned int`
 * \def		WL_UIB
 */	
#	define WL_UIB	WL_INB

/**
 * \brief	Bit width of `unsigned long`
 * \def		WL_ULB
 */
#	define WL_ULB	WL_LOB



/* ## All of the above for `long long` */
#if WL_C_LONG_LONG
	/**
	 * \brief	Bit width of `long long`
	 * \def		WL_LLB
	 * \note	>=C99 
	 */
#	ifdef LLONG_WIDTH
#		define WL_LLB	LLONG_WIDTH
#	else	/* LLONG_WIDTH */
#		define WL_LLB	(WL_CHB*8)
#	endif	/* LLONG_WIDTH */

	/**
	 * \brief	Bit width of `unsigned long long`
	 * \def		WL_ULLB
	 * \note	>=C99 
	 */
#	define WL_ULLB		WL_LLB

	/**
	 * \brief	Minimal value of `unsigned long long`
	 * \def		WL_ULLN
	 * \note	>=C99
	 */
#	define WL_ULLN			(0)

	/**
	 * \brief	Maximal value of `unsigned long long`
	 * \def		WL_ULLX
	 * \note	>=C99
	 */
#	define WL_ULLX			((unsigned long long)-1)

	/**
	 * \brief	Maximal value of `long long`
	 * \def		WL_LLX
	 * \note	>=C99
	 */
#	define WL_LLX			((WL_ULLX/2))

	/**
	 * \brief	Minimal value of `long long`
	 * \def		WL_LLN
	 * \note	>=C99
	 */
#	define WL_LLN			((long long)(WL_LLX+1))

#endif /* WL_C_LONG_LONG */


#if WL_DM == WL_DM_SILP64
#	define WL_SHB	64
#	define WL_SHN	((short)0x8000000000000000)
#	define WL_SHX	((short)0x7FFFFFFFFFFFFFFF)

#	define WL_USB	64
#	define WL_USN	((unsigned short)0x000000000000000)
#	define WL_USX	((unsigned short)0xFFFFFFFFFFFFFFF)
#else	/* WL_DM == WL_DM_SILP64 */
#	define WL_SHB	16
#	define WL_SHN	((short)0x8000)
#	define WL_SHX	((short)0x7FFF)

#	define WL_USB	16
#	define WL_USN	((unsigned short)0x0000)
#	define WL_USX	((unsigned short)0xFFFF)
#endif	/* WL_DM == WL_DM_SILP64 */

/* For some reason if `WL_DM` is not defined, this exoression is TRUE, so
 * lets also check that the macro is defined first.
 */
#if defined(WL_DM) && (WL_DM == WL_DM_ILP64 || WL_DM == WL_DM_SILP64)
#	define WL_INB	64
#	define WL_INN	((int)0x8000000000000000)
#	define WL_INX	((int)0x7FFFFFFFFFFFFFFF)

#	define WL_UIB	64
#	define WL_UIN	((unsigned int)0x000000000000000)
#	define WL_UIX	((unsigned int)0xFFFFFFFFFFFFFFF)
#else	/* defined(WL_DM) && (WL_DM == WL_DM_ILP64 || WL_DM == WL_DM_SILP64) */
#	define WL_INB	32
#	define WL_INN	((int)0x80000000)
#	define WL_INX	((int)0x7FFFFFFF)

#	define WL_UIB	32
#	define WL_UIN	((unsigned int)0x00000000)
#	define WL_UIX	((unsigned int)0xFFFFFFFF)
#endif	/* defined(WL_DM) && (WL_DM == WL_DM_ILP64 || WL_DM == WL_DM_SILP64) */

#if WL_DM == WL_DM_LP64 || WL_DM == WL_DM_ILP64 || WL_DM == WL_DM_SILP64
#	define WL_LOB	64
#	define WL_LON	((long)0x8000000000000000)
#	define WL_LOX	((long)0x7FFFFFFFFFFFFFFF)

#	define WL_ULB	64
#	define WL_ULN	((unsigned long)0x000000000000000)
#	define WL_ULX	((unsigned long)0xFFFFFFFFFFFFFFF)
#else /* WL_DM == WL_DM_LP64 || WL_DM == WL_DM_ILP64 || WL_DM == WL_DM_SILP64 */
#	define WL_LOB	32
#	define WL_LON	((long)0x80000000)
#	define WL_LOX	((long)0x7FFFFFFF)

#	define WL_ULB	32
#	define WL_ULN	((unsigned long)0x00000000)
#	define WL_ULX	((unsigned long)0xFFFFFFFF)
#endif	/* WL_DM == WL_DM_LP64 || WL_DM == WL_DM_ILP64 || WL_DM == WL_DM_SILP64 */

#if WL_C_LONG_LONG
#	define WL_LLB	64
#	define WL_LLN	((long long)0x8000000000000000)
#	define WL_LLX	((long long)0x7FFFFFFFFFFFFFFF)

#	define WL_ULLB	64
#	define WL_ULLN	((unsigned long long)0x000000000000000)
#	define WL_ULLX	((unsigned long long)0xFFFFFFFFFFFFFFF)
#endif	/* WL_C_LONG_LONG */

/* # Fixed-size type */

/* Types `I8`, `I16`, `I32`, `I64` will not be their nominated bit width on
 * systems where the width of byte is not 8 bit. Their actual widths are 1, 2,
 * 4, and 8 bytes respectively.
 */
#if WL_C_WARNING && WL_CHB != 8
#	warning "Byte width is not 8 bits on your system, fixed-size types widths \
are multiples of byte's width, not 8."
#elif WL_PRAGMA_MESSAGE
#	pragma message("Byte width is not 8 bits on your system, fixed-size types \
widths are multiples of byte's width, not 8.")
#endif /* WL_C_WARNING && WL_CHB != 8 */

/**
 * \brief	At least 8-bit signed integer
 * \def		wl_I8l
 */
/**
 * \brief	At least 8-bit signed integer
 * \def		wl_i8l
 */
/**
 * \brief	At least 64-bit signed integer
 * \def		wl_I64l
 */
/**
 * \brief	At least 64-bit signed integer
 * \def		wl_i64l
 */
/**
 * \brief	At least 64-bit unsigned integer
 * \def		wl_U64l
 */
/**
 * \brief	At least 64-bit unsigned integer
 * \def		wl_u64l
 */
/**
 * \brief	At least 8-bit unsigned integer
 * \def		wl_U8l
 */
/**
 * \brief	At least 8-bit unsigned integer
 * \def		wl_u8l
 */
/**
 * \brief	At least 16-bit signed integer
 * \def		wl_I16l
 */
/**
 * \brief	At least 16-bit signed integer
 * \def		wl_i16l
 */
/**
 * \brief	At least 16-bit unsigned integer
 * \def		wl_U16l
 */
/**
 * \brief	At least 16-bit unsigned integer
 * \def		wl_u16l
 */
/**
 * \brief	At least 32-bit signed integer
 * \def		wl_I32l
 */
/**
 * \brief	At least 32-bit signed integer
 * \def		wl_i32l
 */
/**
 * \brief	At least 32-bit unsigned integer
 * \def		wl_U32l
 */
/**
 * \brief	At least 32-bit unsigned integer
 * \def		wl_u32l
 */
/**
 * \brief	At least 64-bit signed integer
 * \def		wl_I64l
 */
/**
 * \brief	At least 64-bit signed integer
 * \def		wl_i64l
 */
/**
 * \brief	At least 64-bit unsigned integer
 * \def		wl_U64l
 */
/**
 * \brief	At least 64-bit unsigned integer
 * \def		wl_u64l
 */
/**
 * \brief	Fastest 8-bit signed integer
 * \def		wl_I8f
 */
/**
 * \brief	Fastest 8-bit signed integer
 * \def		wl_i8f
 */
/**
 * \brief	Fastest 8-bit unsigned integer
 * \def		wl_U8f
 */
/**
 * \brief	Fastest 8-bit unsigned integer
 * \def		wl_u8f
 */
/**
 * \brief	Fastest 16-bit signed integer
 * \def		wl_I16f
 */
/**
 * \brief	Fastest 16-bit signed integer
 * \def		wl_i16f
 */
/**
 * \brief	Fastest 16-bit unsigned integer
 * \def		wl_U16f
 */
/**
 * \brief	Fastest 16-bit unsigned integer
 * \def		wl_u16f
 */
/**
 * \brief	Fastest 32-bit signed integer
 * \def		wl_I32f
 */
/**
 * \brief	Fastest 32-bit signed integer
 * \def		wl_i32f
 */
/**
 * \brief	Fastest 32-bit unsigned integer
 * \def		wl_U32f
 */
/**
 * \brief	Fastest 32-bit unsigned integer
 * \def		wl_u32f
 */
/**
 * \brief	Fastest 64-bit signed integer
 * \def		wl_I64f
 */
/**
 * \brief	Fastest 64-bit signed integer
 * \def		wl_i64f
 */
/**
 * \brief	Fastest 64-bit unsigned integer
 * \def		wl_U64f
 */
/**
 * \brief	Fastest 64-bit unsigned integer
 * \def		wl_u64f
 */

#if WL_C_STDINT
	/* ## Type definitions */
	/* ### Least */
	typedef int_least8_t			wl_I8l,		wl_i8l;
	typedef int_least16_t			wl_I16l,	wl_i16l;
	typedef int_least32_t			wl_I32l,	wl_i32l;
	typedef int_least64_t			wl_I64l,	wl_i64l;
	typedef uint_least8_t			wl_U8l,		wl_u8l;
	typedef uint_least16_t			wl_U16l,	wl_u16l;
	typedef uint_least32_t			wl_U32l,	wl_u32l;
	typedef uint_least64_t			wl_U64l,	wl_u64l;
	/* ### Fastest */
	typedef int_fast8_t				wl_I8f,		wl_i8f;
	typedef int_fast16_t			wl_I16f,	wl_i16f;
	typedef int_fast32_t			wl_I32f,	wl_i32f;
	typedef int_fast64_t			wl_I64f,	wl_i64f;
	typedef uint_fast8_t			wl_U8f,		wl_u8f;
	typedef uint_fast16_t			wl_U16f,	wl_u16f;
	typedef uint_fast32_t			wl_U32f,	wl_u32f;
	typedef uint_fast64_t			wl_U64f,	wl_u64f;

	/* ## Type widths */
	/* ### Least */
	/* I KNOW `WIDTH` IS OPTIONAL BUT I'M TOO TIRED TO IMPLEMENT A WORD AROUND */
#	define	WL_I8LB					INT_LEAST8_WIDTH
#	define	WL_I16LB				INT_LEAST16_WIDTH
#	define	WL_I32LB				INT_LEAST32_WIDTH
#	define	WL_I64LB				INT_LEAST64_WIDTH
#	define	WL_U8LB					UINT_LEAST8_WIDTH
#	define	WL_U16LB				UINT_LEAST16_WIDTH
#	define	WL_U32LB				UINT_LEAST32_WIDTH
#	define	WL_U64LB				UINT_LEAST64_WIDTH
	/* ### Fastest */
#	define	WL_I8FB					INT_FAST8_WIDTH
#	define	WL_I16FB				INT_FAST16_WIDTH
#	define	WL_I32FB				INT_FAST32_WIDTH
#	define	WL_I64FB				INT_FAST64_WIDTH
#	define	WL_U8FB					UINT_FAST8_WIDTH
#	define	WL_U16FB				UINT_FAST16_WIDTH
#	define	WL_U32FB				UINT_FAST32_WIDTH
#	define	WL_U64FB				UINT_FAST64_WIDTH

	/* ## Type limits */
	/* ### Least */
#	define	WL_I8LN					INT_LEAST8_MIN
#	define	WL_I16LN				INT_LEAST16_MIN
#	define	WL_I32LN				INT_LEAST32_MIN
#	define	WL_I64LN				INT_LEAST64_MIN
#	define	WL_U8LN					UINT_LEAST8_MIN
#	define	WL_U16LN				UINT_LEAST16_MIN
#	define	WL_U32LN				UINT_LEAST32_MIN
#	define	WL_U64LN				UINT_LEAST64_MIN
	/* ### Fastest */
#	define	WL_I8FN					INT_FAST8_MIN
#	define	WL_I16FN				INT_FAST16_MIN
#	define	WL_I32FN				INT_FAST32_MIN
#	define	WL_I64FN				INT_FAST64_MIN
#	define	WL_U8FN					UINT_FAST8_MIN
#	define	WL_U16FN				UINT_FAST16_MIN
#	define	WL_U32FN				UINT_FAST32_MIN
#	define	WL_U64FN				UINT_FAST64_MIN

	/* ### Least */
#	define	WL_I8LX					INT_LEAST8_MAX
#	define	WL_I16LX				INT_LEAST16_MAX
#	define	WL_I32LX				INT_LEAST32_MAX
#	define	WL_I64LX				INT_LEAST64_MAX
#	define	WL_U8LX					UINT_LEAST8_MAX
#	define	WL_U16LX				UINT_LEAST16_MAX
#	define	WL_U32LX				UINT_LEAST32_MAX
#	define	WL_U64LX				UINT_LEAST64_MAX
	/* ### Fastest */
#	define	WL_I8FX					INT_FAST8_MAX
#	define	WL_I16FX				INT_FAST16_MAX
#	define	WL_I32FX				INT_FAST32_MAX
#	define	WL_I64FX				INT_FAST64_MAX
#	define	WL_U8FX					UINT_FAST8_MAX
#	define	WL_U16FX				UINT_FAST16_MAX
#	define	WL_U32FX				UINT_FAST32_MAX
#	define	WL_U64FX				UINT_FAST64_MAX

#else	/* WL_C_STDINT */
	/* Least */
	typedef signed char				wl_I8l,		wl_i8l;
	typedef unsigned char			wl_U8l,		wl_u8l;
	typedef short					wl_I16l,	wl_i16l;
	typedef unsigned short			wl_U16l,	wl_u16l;

#	define	WL_I8LB					WL_SCB
#	define	WL_I16LB				WL_SHB
#	define	WL_U8LB					WL_UCB
#	define	WL_U16LB				WL_USB

#	define	WL_I8LN					WL_SCN
#	define	WL_I16LN				WL_SHN
#	define	WL_U8LN					WL_UCN
#	define	WL_U16LN				WL_USN

#	define	WL_I8LX					WL_SCX
#	define	WL_I16LX				WL_SHX
#	define	WL_U8LX					WL_UCX
#	define	WL_U16LX				WL_USX

#	if (WL_INB/WL_CHB) >= 4
		typedef int					wl_I32l,	wl_i32l;
		typedef unsigned int		wl_U32l,	wl_u32l;

#		define	WL_I32LB			WL_INB
#		define	WL_U32LB			WL_UIB

#		define	WL_I32LN			WL_INN
#		define	WL_U32LN			WL_UIN

#		define	WL_I32LX			WL_INX
#		define	WL_U32LX			WL_UIX
#	else	/* (WL_INB/WL_CHB) >= 4 */
		typedef long				wl_I32l,	wl_i32l;
		typedef unsigned long		wl_U32l,	wl_u32l;

#		define	WL_I32LB			WL_LOB
#		define	WL_U32LB			WL_ULB

#		define	WL_I32LN			WL_LON
#		define	WL_U32LN			WL_ULN

#		define	WL_I32LX			WL_LOX
#		define	WL_U32LX			WL_ULX
#	endif	/* (WL_INB/WL_CHB) >= 4 */

#	if WL_C_LONG_LONG
		typedef long long			wl_I64l,	wl_i64l;
		typedef unsigned long long	wl_U64l,	wl_u64l;

#		define	WL_I64LB			WL_LLB
#		define	WL_U64LB			WL_ULLB

#		define	WL_I64LN			WL_LLN
#		define	WL_U64LN			WL_ULLN

#		define	WL_I64LX			WL_LLX
#		define	WL_U64LX			WL_ULLX
#	else	/* WL_C_LONG_LONG */
#		if (WL_LOB/WL_CHB) < 8 && WL_C_WARNING
#			warning No 8-byte integer type is on this system.
#		elif WL_PRAGMA_MESSAGE
#			pragma message("No 8-byte integer type is on this system.")
#		endif /* (WL_LOB/WL_CHB) < 8 && WL_C_WARNING */
		typedef long				wl_I64l,	wl_i64l;
		typedef unsigned long 		wl_U64l,	wl_u64l;

#		define	WL_I64LB			WL_LOB
#		define	WL_U64LB			WL_ULB

#		define	WL_I64LN			WL_LON
#		define	WL_U64LN			WL_ULN

#		define	WL_I64LX			WL_LOX
#		define	WL_U64LX			WL_ULX
#	endif	/* WL_C_LONG_LONG */

	/* Fastest */

	typedef wl_I8l					wl_I8f, 	wl_i8f;
	typedef wl_U8l					wl_U8f, 	wl_u8f;

#	define	WL_I8FB					WL_I8LB
#	define	WL_U8FB					WL_U8LB

#	define	WL_I8FN					WL_I8LN
#	define	WL_U8FN					WL_U8LN

#	define	WL_I8FX					WL_I8LX
#	define	WL_U8FX					WL_U8LX
#	if WL_WORDSIZE >= (8*WL_CHB)
		typedef wl_I64l				wl_I16f,	wl_i16f;
		typedef wl_I64l				wl_I32f,	wl_i32f;
		typedef wl_I64l				wl_I64f,	wl_i64f;
		typedef wl_U64l				wl_U16f,	wl_u16f;
		typedef wl_U64l				wl_U32f,	wl_u32f;
		typedef wl_U64l				wl_U64f,	wl_u64f;

#		define	WL_I16FB			WL_I64LB
#		define	WL_I32FB			WL_I64LB
#		define	WL_I64FB			WL_I64LB
#		define	WL_U16FB			WL_U64LB
#		define	WL_U32FB			WL_U64LB
#		define	WL_U64FB			WL_U64LB

#		define	WL_I16FN			WL_I64LN
#		define	WL_I32FN			WL_I64LN
#		define	WL_I64FN			WL_I64LN
#		define	WL_U16FN			WL_U64LN
#		define	WL_U32FN			WL_U64LN
#		define	WL_U64FN			WL_U64LN

#		define	WL_I16FX			WL_I64LX
#		define	WL_I32FX			WL_I64LX
#		define	WL_I64FX			WL_I64LX
#		define	WL_U16FX			WL_U64LX
#		define	WL_U32FX			WL_U64LX
#		define	WL_U64FX			WL_U64LX
#	else	/* WL_WORDSIZE >= (8*WL_CHB) */
		typedef wl_I32l				wl_I16f,	wl_i16f;
		typedef wl_I32l				wl_I32f,	wl_i32f;
		typedef wl_U32l				wl_U16f,	wl_u16f;
		typedef wl_U32l				wl_U32f,	wl_u32f;
		typedef wl_I64l				wl_I64f,	wl_i64f;
		typedef wl_U64l				wl_U64f,	wl_u64f;

#		define	WL_I16FB			WL_I32LB
#		define	WL_I32FB			WL_I32LB
#		define	WL_I64FB			WL_I32LB
#		define	WL_U16FB			WL_U32LB
#		define	WL_U32FB			WL_U64LB
#		define	WL_U64FB			WL_U64LB

#		define	WL_I16FN			WL_I32LN
#		define	WL_I32FN			WL_I32LN
#		define	WL_I64FN			WL_I32LN
#		define	WL_U16FN			WL_U32LN
#		define	WL_U32FN			WL_U64LN
#		define	WL_U64FN			WL_U64LN

#		define	WL_I16FX			WL_I32LX
#		define	WL_I32FX			WL_I32LX
#		define	WL_I64FX			WL_I32LX
#		define	WL_U16FX			WL_U32LX
#		define	WL_U32FX			WL_U64LX
#		define	WL_U64FX			WL_U64LX
#	endif	/* WL_WORDSIZE >= (8*WL_CHB) */
#endif	/* WL_C_STDINT */

/* ## Optimal */

/**
 * \brief	Optimal 8-bit signed integer
 * \def		wl_I8
 */
/**
 * \brief	Optimal 8-bit signed integer
 * \def		wl_i8
 */
/**
 * \brief	Optimal 8-bit unsigned integer
 * \def		wl_U8
 */
/**
 * \brief	Optimal 8-bit unsigned integer
 * \def		wl_u8
 */
/**
 * \brief	Optimal 16-bit signed integer
 * \def		wl_I16
 */
/**
 * \brief	Optimal 16-bit signed integer
 * \def		wl_i16
 */
/**
 * \brief	Optimal 16-bit unsigned integer
 * \def		wl_U16
 */
/**
 * \brief	Optimal 16-bit unsigned integer
 * \def		wl_u16
 */
/**
 * \brief	Optimal 32-bit signed integer
 * \def		wl_I32
 */
/**
 * \brief	Optimal 32-bit signed integer
 * \def		wl_i32
 */
/**
 * \brief	Optimal 32-bit unsigned integer
 * \def		wl_U32
 */
/**
 * \brief	Optimal 32-bit unsigned integer
 * \def		wl_u32
 */
/**
 * \brief	Optimal 64-bit signed integer
 * \def		wl_I64
 */
/**
 * \brief	Optimal 64-bit signed integer
 * \def		wl_i64
 */
/**
 * \brief	Optimal 64-bit unsigned integer
 * \def		wl_U64
 */
/**
 * \brief	Optimal 64-bit unsigned integer
 * \def		wl_u64
 */

#if WL_FIXED == WL_FIXED_LEAST
	typedef	wl_I8l				wl_I8,	wl_i8;
	typedef	wl_I16l				wl_I16,	wl_i16;
	typedef	wl_I32l				wl_I32,	wl_i32;
	typedef	wl_I64l				wl_I64,	wl_i64;
	typedef	wl_U8l				wl_U8,	wl_u8;
	typedef	wl_U16l				wl_U16,	wl_u16;
	typedef	wl_U32l				wl_U32,	wl_u32;
	typedef	wl_U64l				wl_U64,	wl_u64;

#	define	WL_I8B				WL_I8LB
#	define	WL_I16B				WL_I16LB
#	define	WL_I32B				WL_I32LB
#	define	WL_I64B				WL_I64LB
#	define	WL_U8B				WL_U8LB
#	define	WL_U16B				WL_U16LB
#	define	WL_U32B				WL_U32LB
#	define	WL_U64B				WL_U64LB

#	define	WL_I8N				WL_I8LN
#	define	WL_I16N				WL_I16LN
#	define	WL_I32N				WL_I32LN
#	define	WL_I64N				WL_I64LN
#	define	WL_U8N				WL_U8LN
#	define	WL_U16N				WL_U16LN
#	define	WL_U32N				WL_U32LN
#	define	WL_U64N				WL_U64LN

#	define	WL_I8X				WL_I8LX
#	define	WL_I16X				WL_I16LX
#	define	WL_I32X				WL_I32LX
#	define	WL_I64X				WL_I64LX
#	define	WL_U8X				WL_U8LX
#	define	WL_U16X				WL_U16LX
#	define	WL_U32X				WL_U32LX
#	define	WL_U64X				WL_U64LX

#else	/* WL_FIXED == WL_FIXED_LEAST */
	typedef	wl_I8f				wl_I8,	wl_i8;
	typedef	wl_I16f				wl_I16,	wl_i16;
	typedef	wl_I32f				wl_I32,	wl_i32;
	typedef	wl_I64f				wl_I64,	wl_i64;
	typedef	wl_U8f				wl_U8,	wl_u8;
	typedef	wl_U16f				wl_U16,	wl_u16;
	typedef	wl_U32f				wl_U32,	wl_u32;
	typedef	wl_U64f				wl_U64,	wl_u64;

#	define	WL_I8B				WL_I8FB
#	define	WL_I16B				WL_I16FB
#	define	WL_I32B				WL_I32FB
#	define	WL_I64B				WL_I64FB
#	define	WL_U8B				WL_U8FB
#	define	WL_U16B				WL_U16FB
#	define	WL_U32B				WL_U32FB
#	define	WL_U64B				WL_U64FB

#	define	WL_I8N				WL_I8FN
#	define	WL_I16N				WL_I16FN
#	define	WL_I32N				WL_I32FN
#	define	WL_I64N				WL_I64FN
#	define	WL_U8N				WL_U8FN
#	define	WL_U16N				WL_U16FN
#	define	WL_U32N				WL_U32FN
#	define	WL_U64N				WL_U64FN

#	define	WL_I8X				WL_I8FX
#	define	WL_I16X				WL_I16FX
#	define	WL_I32X				WL_I32FX
#	define	WL_I64X				WL_I64FX
#	define	WL_U8X				WL_U8FX
#	define	WL_U16X				WL_U16FX
#	define	WL_U32X				WL_U32FX
#	define	WL_U64X				WL_U64FX
#endif	/* WL_FIXED == WL_FIXED_LEAST */


#endif
