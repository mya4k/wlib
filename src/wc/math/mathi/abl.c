#include <wc/types.h>

/**
 * @brief	(I64) Absolute 
 * @fn		I64 abi(I64 x)
 * @param	x 
 * @return	I64
 */
I64 abl(I64 x) {
	return (x < 0) ? -x : x;
}