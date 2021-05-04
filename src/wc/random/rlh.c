#include <wc/types.h>

/* Let's make Park, Miller and Stockmeyer happy :) */
/* Feel free to assign your own multiplier if you really want*/
#define a	48271

/**
 * \brief	Lehmer PRNG
 * \fn		u32 rlh(u32* seed)
 * \param	seed	Pointer to the seed
 * \return	u32
 */
u32 rlh(u32* seed) {
	return *seed *= a;
}