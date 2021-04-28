#include <wc/types.h>

/**
 * @brief	(I32) Absolute 
 * @fn		I32 abi(I32 x)
 * @param	x 
 * @return	I32 
 */
I32 abi(I32 x) {
	return (x < 0) ? -x : x;
}