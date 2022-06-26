#ifndef WL_ARRAY_H
#define WL_ARRAY_H	1



#include <wc/types.h>
#include <wc/core.h>



/* Type for holding enumerated list of functions */
typedef U8	_Af;
typedef U32	Sz;
#define SZB	U32B



/**
 * \brief	Array No Operation (Array copy)
 * \def		wl_ano(arr, count, res)
 * \arg		arr		Array operand
 * \arg		count	Length of the operand in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Copies \a count bytes from \a arr to \a res.
 * 
 * \see		_afa
 */
#define wl_ano(arr, count, res)

/**
 * \brief	Array AND
 * \def		wl_aan(arr1, arr2, count, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise AND operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_aan(arr1, arr2, count, res)

/**
 * \brief	Array OR
 * \def		wl_aor(arr1, arr2, count, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise OR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_aor(arr1, arr2, count, res)

/**
 * \brief	Array XOR
 * \def		wl_aor(arr1, arr2, count, res)
 * \arg		res		Array holding operation result
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * 
 * Performs bitwise XOR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_axr(arr1, arr2, count, res)

/**
 * \brief	Array NOT Operation (Array copy)
 * \def		wl_ano(res, arr, count)
 * \arg		arr		Array operand
 * \arg		count	Length of the operand in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Copies \a count bytes from \a arr to \a res.
 * 
 * \see		_afa
 */
#define wl_ant(res, arr, count)

/**
 * \brief	Array NAND
 * \def		wl_ann(arr1, arr2, count, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise NAND operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_ann(arr1, arr2, count, res)

/**
 * \brief	Array NOR
 * \def		wl_anr(arr1, arr2, count, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise NOR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_anr(arr1, arr2, count, res)

/**
 * \brief	Array NXOR
 * \def		wl_anx(arr1, arr2, count, res)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * \arg		res		Pointer to store the result in (optional)
 * 
 * Performs bitwise NXOR operation on bits from \a arr1 and \a arr2, coping the
 * result to \a res.
 * 
 * \see		_afa
 */
#define wl_anx(arr1, arr2, count, res)

/**
 *	If \a res is NULL, \a res is allocated
 *	If \a arr1 is NULL, \a arr2 is NULL or \a count is 0, error
 *	No memory overlap protection
 */

/**const UMax* _afa(
	const	UMax*					arr1,
	const	UMax*					arr2,
			Sz						len,
			UMax*	restrict const	res,
	const	_Af						func
)
 * Returns TRUE, unless all data of the array is set to 0
 */
#define wl_anol(arr, count)
/**
 * \brief	Array No Operation Logical
 * \def		wl_aanl(arr1, arr2, count)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * 
 * Returns TRUE, if both array are not filled with 0
 */
#define wl_aanl(arr1, arr2, count)
/**
 * \brief	Array No Operation Logical
 * \def		wl_aanl(arr1, arr2, count)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		count	Length of the operands in bytes
 * 
 * Returns TRUE, if both array are not filled with 0
 */
#define wl_aorl(arr1, arr2, count)
#define wl_axrl(arr1, arr2, count)
#define wl_antl(arr, count)
#define wl_annl(arr1, arr2, count)
#define wl_anrl(arr1, arr2, count)
#define wl_anxl(arr1, arr2, count)



/*  */
EXTERN const UMax* _afa(
	const	UMax*					arr1,
	const	UMax*					arr2,
			Sz						len,
			UMax*	restrict const	res,
	const	_Af						func
);



#endif
