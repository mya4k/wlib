#include <wc/types.h>
#include <wc/types/int.h>
#include <wc/math/mathi.h>

/**
 * @brief	Set digit
 * @fn		Digit dsu(U32 x, U8 n, U8 base, Digit y)
 * 
 * @param x		le numba
 * @param n		digit index
 * @param base	base
 * @param y		replacement digit
 * @return	Digit 
 */
Digit dsu(U32 x, U8 n, U8 base, Digit y) {
	return x + (y - dgu(x,n,base)) * pwu(10,n);
}