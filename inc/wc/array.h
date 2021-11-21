#ifndef WC_ARRAY_H
#define WC_ARRAY_H



#include <wc/core.h>
#include <wc/types.h>



#ifndef WL_NO_SHORT_NAME
#	define Af		wl_Af
#	define As		wl_As
#	define Asf		wl_Asf
#	define afa		wl_afa
#	define afb		wl_afb
#	define aas		wl_aas
#	define ant		wl_ant
#	define anot		wl_anot
#	define aan		wl_aan
#	define aand		wl_aand
#	define aor		wl_aor
#	define axr		wl_axr
#	define axor		wl_axor
#	define ann		wl_aan
#	define anand	wl_anand
#	define anr		wl_anr
#	define anor		wl_anor
#	define anx		wl_anx
#	define anxor	wl_anxor
#	define anol		wl_anol
#	define antl		wl_antl
#	define anotl	wl_anotl
#	define aanl		wl_aanl
#	define aandl	wl_aandl
#	define aorl		wl_aorl
#	define axrl		wl_axrl
#	define axorl	wl_axorl
#	define annl		wl_aanl
#	define anandl	wl_anandl
#	define anrl		wl_anrl
#	define anorl	wl_anorl
#	define anxl		wl_anxl
#	define anxorl	wl_anxorl
#	define aeq		wl_aeq
#	define anq		wl_anq
#	define asb		wl_asb
#	ifndef WL_NO_ALIASES
#		define ArraySize		wl_ArraySize
#		define ArrayFunc		wl_ArrayFunc
#		define ArrayFunction	wl_ArrayFunction
#		define ArraySearchFlags	wl_ArraySearchFlags
#	endif
#endif

#ifndef WL_NO_ALIASES
#	define wl_ArraySize			wl_As
#	define wl_ArrayFunc			wl_Af
#	define wl_ArrayFunction		wl_Af
#	define wl_ArraySearchFlags	wl_Asf
#	define WL_POINTERDIFFERENCE	WL_PTRDIFF
#endif



/**
 * \brief Array Assign
 * \def wl_aas(a,b,size)
 * Assigns array `b` to array `a` using `wl_afa`
 * \return `a`
 */
#define wl_aas(a,b,size)	wl_afa((a),	(b),	NULL,	WL_AF_NOA,	(size))
/**
 * \brief Array NOT
 * \def wl_ant(a,b,size)
 * Compliments every bit of array `b` and assigns it to array `a`
 * \return `a`
 */
#define wl_ant(a,b,size)	wl_afa((a),	(b),	NULL,	WL_AF_NTA,	(size))
/**
 * \brief Array OR
 * \def wl_ant(a,b,size)
 * Disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_aor(r,a,b,size)	wl_afa((r),	(a),	(b),	WL_AF_ORA,	(size))
/**
 * \brief Array AND
 * \def wl_aan(r,a,b,size)
 * Conjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_aan(r,a,b,size)	wl_afa((r),	(a),	(b),	WL_AF_ANA,	(size))
/**
 * \brief Array XOR
 * \def wl_axr(r,a,b,size)
 * Exclusive-disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_axr(r,a,b,size)	wl_afa((r),	(a),	(b),	WL_AF_XRA,	(size))
/**
 * \brief Array OR
 * \def wl_anr(r,a,b,size)
 * Invert-disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_anr(r,a,b,size)	wl_afa((r),	(a),	(b),	WL_AF_NRA,	(size))
/**
 * \brief Array NAND
 * \def wl_ann(r,a,b,size)
 * Invert-conjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_ann(r,a,b,size)	wl_afa((r),	(a),	(b),	WL_AF_NNA,	(size))
/**
 * \brief Array NXOR
 * \def wl_anx(r,a,b,size)
 * invert-exclusive-disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_anx(r,a,b,size)	wl_afa((r),	(a),	(b),	WL_AF_NXA,	(size))

/**
 * \brief Array logic NO
 * \def wl_antl(a,b,size)
 * Compliments every bit of array `b` and assigns it to array `a`
 * \return `a`
 */
#define wl_anol(a,size)	wl_afb((a),	NULL,	WL_AF_NTL,	(size))
/**
 * \brief Array logic NOT
 * \def wl_antL(a,b,size)
 * Compliments every bit of array `b` and assigns it to array `a`
 * \return `a`
 */
#define wl_antl(a,size)	wl_afb((a),	NULL,	WL_AF_NOL,	(size))
/**
 * \brief Array logic OR
 * \def wl_aorl(a,b,size)
 * Disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_aorl(a,b,size)	wl_afb((a),	(b),	WL_AF_NRL,	(size))
/**
 * \brief Array logic AND
 * \def wl_aanl(r,a,b,size)
 * Conjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_aanl(a,b,size)	wl_afb((a),	(b),	WL_AF_NNL,	(size))
/**
 * \brief Array logic XOR
 * \def wl_axrl(r,a,b,size)
 * Exclusive-disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_axrl(a,b,size)	wl_afb((a),	(b),	WL_AF_NXL,	(size))
/**
 * \brief Array logic OR
 * \def wl_anrl(r,a,b,size)
 * Invert-disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_anrl(a,b,size)	wl_afb((a),	(b),	WL_AF_ORL,	(size))
/**
 * \brief Array logic NAND
 * \def wl_annl(r,a,b,size)
 * Invert-conjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_annl(a,b,size)	wl_afb((a),	(b),	WL_AF_ANL,	(size))
/**
 * \brief Array logic NXOR
 * \def wl_anxl(r,a,b,size)
 * invert-exclusive-disjuncts arrays `a` and `b` and assigns it to array `r`, if `r` = NULL,
 * a new array is allocated.
 * \return `r`
 */
#define wl_anxl(a,b,size)	wl_afb((a),	(b),	WL_AF_XRL,	(size))

#define wl_aeq(a,b,size)	wl_antl(wl_axr(NULL,	(a),	(b),	(size)	), (size))
#define wl_anq(a,b,size)	wl_anol(wl_axr(NULL,	(a),	(b),	(size)	), (size))




/**
 * \brief	Array Functions
 * \enum	wl_Af
 * \typedef	wl_Af
 * 	
 */
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

/**
 * \brief	Search Flags
 * \enum	wl_Asf
 * \typedef	wl_Asf
 * 
 * 
 */
typedef enum wl_Asf {
	WL_ASF_OFFSET = 0,		
	/**< Return the offset from base pointer */
	WL_ASF_NORMAL = 0,		/**< Searching from beginning to end */
	WL_ASF_REVERSED = 1,	/**< Searching from end to beggining */
	WL_ASF_PTRDIFF = 2,		
	/**< Return pointer difference from the base pointer */
	WL_ASF_COUNT = 4		/**< Return the count of occurrences */
} wl_Asf;

/**
 * \brief	Array Size
 * \typedef wl_As
 * 
 * The maximal size of the array that array functions support.
 */
typedef U16 wl_As;



/* Array Function Assign */
EXTERN const void* wl_afa(
	const void* restrict a, 
	const void* restrict const b,
	const void* restrict const c,
	const Af func,
	const As size
);

/* Array Function Boolean */
EXTERN Bl wl_afb(
	const void* restrict const a, 
	const void* restrict const b,
	const Af func,
	const As size
);

/* Array Fill */
EXTERN const void* wl_afl(
	const void* restrict const a,
	const As sa,
	const void* restrict const b,
	const As sb
);

/* Array Search Byte */
EXTERN Pt wl_asb(
	const void* restrict const	a,
	As							sa,
	const char					b,
	const Asf					flags
);



#endif
