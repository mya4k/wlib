#include <wc/types.h>
#include <wc/math/mathi.h>

typedef	U8	Digit;

/**
 * @fn			Digit dcq(U64 x, U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcq(const U64 x, const U8 base) {
	if (x && base) return lgq(base, x) + 1;
	else return 0;
}