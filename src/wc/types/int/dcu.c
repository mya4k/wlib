#include <wc/types.h>
#include <wc/math/mathi.h>

typedef	U8	Digit;

/**
 * @fn			Digit dcu(const U32 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcu(const U32 x, const U8 base) {
	if (x && base) return lgu(base, x) + 1;
	else return 0;
}