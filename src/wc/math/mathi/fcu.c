#include <wc/types.h>

/**
 * @brief	(U32) Factorial 
 * @fn		U32	fcu(U8 n)
 * @param	n 
 * @return U32 
 */
U32	fcu(U8 n) {
	U32 r = 1;
	for (U8 i = 2; i <= n; i++)
		r *= i;
	return r;
}