/**
 * @file		types/int.h
 * @author		Wispy
 * @brief		Numeric properties operations
 * @version		0.1
 * @date		2021-04-11
 * @copyright	Wispy (c) 2021
 */
#ifndef WC_INT_H
#define WC_INT_H

#include <wc/types.h>

#undef	digitCount
#define	digitCount	dcu
#undef	digitGet
#define	digitGet	dgu
#undef	digitSet
#define digitSet	dsu

/**
 * @typedef	Dg
 * @brief	Digit type
 * Digits can hold values from 0 to 9 inclusively
 */
/**
 * @typedef	Digit
 * @brief	Digit type
 * Digits can hold values from 0 to 9 inclusively
 */
typedef U8 Dg, Digit;

/**
 * @def		dr(X)
 * @brief	Is in digit range
 * @arg		X
 * Checks whether the value belongs to the range of values of Digit type
 */
#define dr(X)	(X >= 0 && X <= 9)

/**
 * \def		_dc(X)
 * \brief	Digit to Char (no type-check)
 * \param	X	Digit
 * Checks whether the value belongs to the range of values of Digit type.
 */
#define _dc(X)	(x+'0')

/**
 * \fn		inline static char dC(const Digit x)
 * \brief	Digit to Char (with type-check)
 * \param	X	Digit
 * \return	char
 * Checks whether the value belongs to the range of values of Digit type.
 */
inline static char dc(const Digit x) {
	if (dr(x)) return _dc(x);
	else return 'E';
}

/**
 * @fn			U8 dcu(const U32 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcu(const U32 x, const U8 base);

/**
 * @fn			U8 dcq(const U64 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcq(const U64 x, const U8 base);

/**
 * @fn			U8 dci(const U32 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dci(const U32 x, const U8 base);

/**
 * @fn			U8 dcl(const U64 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcl(const U64 x, const U8 base);

/**
 * @fn			Digit dgu(const U32 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgu(const U32 x, const U8 n, const U8 base);

/**
 * @fn			Digit dgq(const U64 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgq(const U64 x, const U8 n, const U8 base);

/**
 * @fn			Digit dgi(const I32 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgi(const I32 x, const U8 n, const U8 base);

/**
 * @fn			Digit dgl(const I64 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgl(const I64 x, const U8 n, const U8 base);

#endif
