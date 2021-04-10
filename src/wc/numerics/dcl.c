#include <wc/types.h>
#include <wc/math/mathi.h>

typedef	U8	Digit;

/**
 * @fn			Digit dcl(I32 x, U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
Digit dcl(I64 x, U8 base) {
	return abl( lgl(base, x) + 1 );
}