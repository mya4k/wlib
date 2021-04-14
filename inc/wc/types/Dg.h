#ifndef WC_DG_H
#define WC_DG_H

#include <wc/types.h>

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
 * \fn		inline static char dC(Digit x)
 * \brief	Digit to Char (with type-check)
 * \param	X	Digit
 * \return	char
 * Checks whether the value belongs to the range of values of Digit type.
 */
inline static char dc(Digit x) {
	if (dr(x)) return _dc(x);
	else return 'E';
}

inline 

#endif