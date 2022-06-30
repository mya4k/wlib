#ifndef WL_ARRAY_H
#define WL_ARRAY_H	1



#include <wc/types.h>
#include <wc/core.h>



/* Type for holding enumerated list of functions */
typedef U8	_Af;

/* Enumerator for */
enum _Af {
	_AF_NO = 0,	/* No operation */
	_AF_AN = 1,	/* AND */
	_AF_OR = 2,	/* OR */
	_AF_XR = 3,	/* XOR */
	_AF_NT = 4,	/* NOT */
	_AF_NN = 5,	/* NAND */
	_AF_NR = 6,	/* NOR */
	_AF_NX = 7	/* NXOR */
};



/**
 * \brief	Array No Operation (Array copy)
 * \def		wl_ano(arr, len, res)
 * \arg		arr		Array operand
 * \arg		len	Length of the operand in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Copies \a len bytes from \a arr to \a res.
 * 
 * \see		_afa
 */
#define wl_ano(arr, len, res)	_wl_afa(						\
	(wl_UMax*)(arr1), NULL, (len), (wl_UMax*)(res+0), _AF_NO	\
)

/**
 * \brief	Array AND
 * \def		wl_aan(arr1, arr2, len, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise AND operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_aan(arr1, arr2, len, res)	_wl_afa(							\
	(wl_UMax*)(arr1), (wl_UMax*)(arr2), (len), (wl_UMax*)(res+0), _AF_AN	\
)

/**
 * \brief	Array OR
 * \def		wl_aor(arr1, arr2, len, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise OR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_aor(arr1, arr2, len, res)	_wl_afa(							\
	(wl_UMax*)(arr1), (wl_UMax*)(arr2), (len), (wl_UMax*)(res+0), _AF_OR	\
)

/**
 * \brief	Array XOR
 * \def		wl_aor(arr1, arr2, len, res)
 * \arg		res		Array holding operation result
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len	Length of the operands in bytes
 * 
 * Performs bitwise XOR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_axr(arr1, arr2, len, res)	_wl_afa(							\
	(wl_UMax*)(arr1), (wl_UMax*)(arr2), (len), (wl_UMax*)(res+0), _AF_XR	\
)

/**
 * \brief	Array NOT Operation (Array copy)
 * \def		wl_ano(res, arr, len)
 * \arg		arr		Array operand
 * \arg		len		Length of the operand in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Copies \a len bytes from \a arr to \a res.
 * 
 * \see		_afa
 */
#define wl_ant(res, arr, len)	_wl_afa(						\
	(wl_UMax*)(arr1), NULL, (len), (wl_UMax*)(res+0), _AF_NT	\
)

/**
 * \brief	Array NAND
 * \def		wl_ann(arr1, arr2, len, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise NAND operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_ann(arr1, arr2, len, res)	_wl_afa(							\
	(wl_UMax*)(arr1), (wl_UMax*)(arr2), (len), (wl_UMax*)(res+0), _AF_NN	\
)

/**
 * \brief	Array NOR
 * \def		wl_anr(arr1, arr2, len, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise NOR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_anr(arr1, arr2, len, res)	_wl_afa(							\
	(wl_UMax*)(arr1), (wl_UMax*)(arr2), (len), (wl_UMax*)(res+0), _AF_NR	\
)

/**
 * \brief	Array NXOR
 * \def		wl_anx(arr1, arr2, len, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise NXOR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_anx(arr1, arr2, len, res)	_wl_afa(							\
	(wl_UMax*)(arr1), (wl_UMax*)(arr2), (len), (wl_UMax*)(res+0), _AF_NX	\
)

/**
 *	If \a res is NULL, \a res is allocated
 *	If \a arr1 is NULL, \a arr2 is NULL or \a len is 0, error
 *	No memory overlap protection
 */

/**
 * \brief	Array No Operation Logical
 * \def		wl_aanl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * Returns TRUE, unless all data of the array is set to 0
 */
#define wl_anol(arr, len)	_wl_afb((wl_UMax*)(arr), (len))
/**
 * \brief	Array AND Logical
 * \def		wl_aanl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * 
 * Returns TRUE, if both array are not filled with 0
 */
#define wl_aanl(arr1, arr2, len)
/**
 * \brief	Array No Operation Logical
 * \def		wl_aanl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * 
 * Returns TRUE, if both array are not filled with 0
 */
#define wl_aorl(arr1, arr2, len)
#define wl_axrl(arr1, arr2, len)
#define wl_antl(arr, len)
#define wl_annl(arr1, arr2, len)
#define wl_anrl(arr1, arr2, len)
#define wl_anxl(arr1, arr2, len)



/*  */
EXTERN const UMax* _wl_afa(
	const	UMax*					arr1,
	const	UMax*					arr2,
			U32						len,
			UMax*	restrict const	res,
	const	_Af						func
);

EXTERN	Bl _wl_afb(const UMax* arr, U32 len);



#endif
