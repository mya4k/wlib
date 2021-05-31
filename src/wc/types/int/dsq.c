#include <wc/types.h>
#include <wc/types/int.h>
#include <wc/math/mathi.h>

/**
 * @brief	Set digit
 * @fn		Digit dsq(U64 x, U8 n, U8 base, Digit y)
 * 
 * @param x		le numba
 * @param n		digit index
 * @param base	base
 * @param y		replacement digit
 * @return	Digit 
 */
Digit dsq(U64 x, U8 n, U8 base, Digit y) {
	return x + (y - dgq(x,n,base)) * pwq(10,n);
}