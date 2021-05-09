#ifndef WC_RANDOM_H
#define WC_RANDOM_H

#include <wc/core.h>
#include <wc/types/int.h>

C_DECL_BEGIN

#if NO_I64
	/**
	 * \brief	Middle Square generator
	 * \fn		u16 rms(u32* seed)
	 * \param	seed	Pointer to the seed
	 * \return	u16
	 */
	static inline u16 rms(u16* seed) {
		u32 a = *seed;
		return *seed = ((u32)a*a) >> 8;
	}
#else	/* Optimal behavior */
	/**
	 * \brief	Middle Square generator
	 * \fn		u32 rms(u32* seed)
	 * \param	seed	Pointer to the seed
	 * \return	u32
	 */
	static inline u32 rms(u32* seed) {
		u64 a = *seed;
		return *seed = ((u64)a*a) >> 16;
	}
#endif

/**
 * \brief	Lehmer generator
 * \def		#define rlh(seed)
 * \param	seed	Pointer to the seed
 */
#define rlh(seed)	(*seed = 48271 * *seed % 0x7FFFFFFF)
/* Let's make Park, Miller and Stockmeyer happy by using 48271 :) */

/**
 * \brief	Schrage's method of Lehmer generator
 * \def		#define rsc(seed)
 * \param	seed	Pointer to the seed
 */
#define rsc(seed)	(*seed = *seed%44488 * 48271 - *seed/44488 * 3399)

#if NO_I64
	/**
	 * \brief	Linear congruential generator
	 * \def		#define rlc(seed)
	 * \param	seed	Pointer to the seed
	 */
	#define rlc(seed)	(*seed = 1664525**seed + 1013904223)
#else
	/**
	 * \brief	Linear congruential generator
	 * \def		#define rlc(seed)
	 * \param	seed	Pointer to the seed
	 */
	#define rlc(seed)	(*seed = 6364136223846793005**seed + 1442695040888963407)

C_DECL_END

#endif