#include <wc/types.h>

/**
 * @brief	(U64) Factorial 
 * @fn		U64	fcq(U8 n)
 * @param	n 
 * @return	U64
 */
U64	fcq(U8 n) {
	U64 r = 1;
	for (U8 i = 2; i <= n; i++)
		r *= i;
	return r;
}