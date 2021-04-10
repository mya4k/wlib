/**
 * @file		numeric.h
 * @author		Wispy
 * @brief		Numeric properties operations
 * @version		0.1
 * @date		2021-04-03
 * @copyright	Wispy (c) 2021
 */
#ifndef WC_NUMERICS_H
#define WC_NUMERICS_H

#include <wc/types.h>

typedef	U8	Digit;

#undef	digitCount
#define	digitCount	dcu
#undef	digitRead
#define	digitRead	dru
#undef	digitWrite
#define digitWrite	dwu

/**
 * @fn			U8 dcu(U32 x, U8 base);
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
Digit dcu(U32 x, U8 base);

/**
 * @fn			U8 dcq(U64 x, U8 base);
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
Digit dcq(U64 x, U8 base);

/**
 * @fn			U8 dci(U32 x, U8 base);
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
Digit dci(U32 x, U8 base);

/**
 * @fn			U8 dcl(U64 x, U8 base);
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
Digit dcl(U64 x, U8 base);

#endif
