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
U8 dcl(const I64 x, const U8 base) {
	if (x && base) return lgq(base, abl(x)) + 1;
	else return 0;
}