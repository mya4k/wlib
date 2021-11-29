#ifndef WC_ARRAY_H
#define WC_ARRAY_H



#include <wc/core.h>
#include <wc/types.h>



#if !WL_PREFIX
#	define ano		wl_ano
#	define aas		wl_aas
#	define ant		wl_ant
#	define anot		wl_anot
#	define aor		wl_aor
#	define aan		wl_aan
#	define aand		wl_aand
#	define axr		wl_axr
#	define axor		wl_axor
#	define anr		wl_anr
#	define anor		wl_anor
#	define ann		wl_ann
#	define anand	wl_anand
#	define anx		wl_anx
#	define anxor	wl_anxor

#	define anol		wl_ano
#	define antl		wl_ant
#	define anotl	wl_anot
#	define aorl		wl_aor
#	define aanl		wl_aan
#	define aandl	wl_aand
#	define axrl		wl_axr
#	define axorl	wl_axor
#	define anrl		wl_anr
#	define anorl	wl_anor
#	define annl		wl_ann
#	define anandl	wl_anand
#	define anxl		wl_anx
#	define anxorl	wl_anxor

#	define aeq		wl_aeq
#	define anq		wl_anq

#	define Af		wl_Af
#	define As		wl_As
#	define Asf		wl_Asf

#	define afa		wl_afa
#	define afb		wl_afb
#	define _anol	wl__anol
#	define afl		wl_afl
#	define asb		wl_asb
#	define asa		wl_asa

#	if	WL_ALIASES
#		define acompl	wl_acompl
#	endif
#endif

#if	WL_ALIASES
#	define wl_acompl	wl_ant
#endif



#if	WL_OPTIMIZE_SPEED == 2
#else
/*
 *	ARRAY BITWISE FUNCTIONS
 */
/* Array Bitwise No Operation [r = a] */
#define wl_ano(r,a,size)		wl_afa((r),	(a),	WL_NULL,	WL_AF_NOA,	(size))
/* Array Assign [a = b] */
#define wl_aas(a,b,size)		wl_ano(a,b,size)
/* Array Bitwise NOT [a = ~b] */
#define wl_ant(r,a,size)		wl_afa((r),	(a),	WL_NULL,	WL_AF_NTA,	(size))
#define wl_anot					wl_ant
/* Array Bitwise OR [r = a|b] */
#define wl_aor(r,a,b,size)		wl_afa((r),	(a),	(b),	WL_AF_ORA,	(size))
/* Array Bitwise AND [r = a&b] */
#define wl_aan(r,a,b,size)		wl_afa((r),	(a),	(b),	WL_AF_ANA,	(size))
#define wl_aand					wl_and
/* Array Bitwise XOR [r = a^b] */
#define wl_axr(r,a,b,size)		wl_afa((r),	(a),	(b),	WL_AF_XRA,	(size))
#define wl_axor					wl_axr
/* Array Bitwise NOR [r = ~(a|b)] */
#define wl_anr(r,a,b,size)		wl_afa((r),	(a),	(b),	WL_AF_NRA,	(size))
#define wl_anor					wl_anr
/* Array Bitwise NAND [r = ~(a&b)] */
#define wl_ann(r,a,b,size)		wl_afa((r),	(a),	(b),	WL_AF_NNA,	(size))
#define wl_anand				wl_ann
/* Array Bitwise NXOR [r = ~(a^b)] */
#define wl_anx(r,a,b,size)		wl_afa((r),	(a),	(b),	WL_AF_NXA,	(size))
#define wl_anxor				wl_anx

/*
 *	ARRAY LOGICAL FUNCTIONS
 */
/* Array Logical No Operation [!!a] or [(Bl)a] */
#define wl_anol(a,size)		wl__anol(a,size,WL_TRUE)
/* Array Logical NOT [!a] */
#define wl_antl(a,size)		wl__anol(a,size,WL_FALSE)
/* Array Logical OR [a||b] */
#define wl_aorl(a,b,size)	(wl_anol(a,size)	||	wl_anol(b,size))
/* Array Logical AND [a||b] */
#define wl_aanl(a,b,size)	(wl_anol(a,size)	&&	wl_anol(b,size))
#define wl_aandl			wl_aanl
/* Array Logical XOR */
#define wl_axrl(a,b,size)	(wl_anol(a,size)	^	wl_anol(b,size))
#define wl_axorl			wl_axrl
/* Array Logical NOR */
#define wl_anrl(a,b,size)	(wl_antl(a,size)	&&	wl_antl(b,size))
#define wl_anorl			wl_anrl
/* Array Logical NAND */
#define wl_annl(a,b,size)	(wl_antl(a,size)	||	wl_antl(b,size))
#define wl_anandl			wl_annl
/* Array Logical NXOR */
#define wl_anxl(a,b,size)	(wl_anol(a,size)	^	wl_antl(b,size))
#define wl_anxorl			wl_anxl
#endif

/*
 *	ARRAY COMPARISON FUNCTIONS
 */
/* Array Equal [a==b] */
#define wl_aeq(a,b,size)	wl_antl(wl_axr(NULL,	(a),	(b),	(size)	), (size))
/* Array Not Equal [a!=b] */
#define wl_anq(a,b,size)	wl_anol(wl_axr(NULL,	(a),	(b),	(size)	), (size))



/* Array Functions */
typedef enum wl_Af {
	WL_AF_NO = 0,	/**< Bitwise no operation */
	WL_AF_AN = 1,	/**< Bitwise AND */
	WL_AF_OR = 2,	/**< Bitwise OR */
	WL_AF_XR = 3,	/**< Bitwise XOR */
	WL_AF_NT = 4,	/**< Bitwise NOT */
	WL_AF_NN = 5,	/**< Bitwise NAND */
	WL_AF_NR = 6,	/**< Bitwise NOR */
	WL_AF_NX = 7,	/**< Bitwise NXOR */
	WL_AF_NOA = 8,	/**< Bitwise no operation assignment */
	WL_AF_ANA = 9,	/**< Bitwise AND assignment */
	WL_AF_ORA = 10,	/**< Bitwise OR assignment */
	WL_AF_XRA = 11,	/**< Bitwise XOR assignment */
	WL_AF_NTA = 12,	/**< Bitwise NOT assignment */
	WL_AF_NNA = 13,	/**< Bitwise NAND assignment */
	WL_AF_NRA = 14,	/**< Bitwise NOR assignment */
	WL_AF_NXA = 15,	/**< Bitwise NXOR assignment */
	WL_AF_NOL = 16, /**< Logic no operation */
	WL_AF_ANL = 17, /**< Logic AND */
	WL_AF_ORL = 18, /**< Logic OR */
	WL_AF_XRL = 19, /**< Logic XOR */
	WL_AF_NTL = 20, /**< Logic NOT */
	WL_AF_NNL = 21, /**< Logic NAND */
	WL_AF_NRL = 22, /**< Logic NOR */
	WL_AF_NXL = 23 	/**< Logic NXOR */
} wl_Af;
/* The maximal size of the array that array functions support. */
typedef U16 wl_As;
/* Search Flags */
typedef enum wl_Asf {
	WL_ASF_OFFSET = 0,		/**< Return the offset from base pointer */
	WL_ASF_NORMAL = 0,		/**< Searching from beginning to end */
	WL_ASF_REVERSED = 1,	/**< Searching from end to beggining */
	WL_ASF_PTRDIFF = 2,		/**< Return pointer difference from the base pointer */
	WL_ASF_COUNT = 4		/**< Return the count of occurrences */
} wl_Asf;



/* Array Function Assign */
EXTERN const void* wl_afa(
	const void* restrict a, 
	const void* restrict const b,
	const void* restrict const c,
	const wl_Af func,
	const wl_As size
);

/* Array Function Boolean */
EXTERN Bl wl_afb(
	const void* restrict const a, 
	const void* restrict const b,
	const wl_Af func,
	const wl_As size
);

/* Array Logical No Operation/NOT */
EXTERN Bl wl__anol(const void* a, wl_As size, Bl r);

/* Array Fill */
EXTERN const void* wl_afl(
	const void* restrict const a,
	const wl_As sa,
	const void* restrict const b,
	const wl_As sb
);

/* Array Search Byte */
EXTERN Pt wl_asb(
	const void* restrict const	a,
	wl_As						sa,
	const char					b,
	const wl_Asf				flags
);

/* Array Search Array */
EXTERN Pt wl_asa(
	const void* restrict const	_a,
	wl_As						sa,
	const void*					b,
	wl_As						sb,
	const wl_Asf				flags
);



#endif
