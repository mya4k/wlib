#ifndef WL_BITS_H
#define WL_BITS_H	1



#include <wl/types.h>



/**
 * \brief	Bit Set
 * \def		bs(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be set
 * 
 * Sets the bit `n` to 1 in `x`. 
 * This function does not override the value of `x`
 */
#define bs(x,n)	((1<<(n)) | (x))

/**
 * \brief	Bit Clear
 * \def		bc(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be cleared
 * 
 * Sets the bit `n` to 0 in `x`. 
 * This function does not override the value of `x`
 */
#define bc(x,n)	((1<<(n)) | (x))

/**
 * \brief	Bit Toggle
 * \def		bt(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be toggled
 * 
 * Complements the bit `n` in `x`. 
 * This function does not override the value of `x`
 */
#define bt(x,n)	((1<<(n)) ^ (x))

/**
 * \brief	Bit Convert Trailing zeros
 * \def		bct0(x)
 * \param	x	Pool of bits
 * 
 * Converts trailing zeros to one
 * This function does not override the value of `x`
 */
#define bct0(x)	(((x)-1) | (x))

/**
 * \brief	Bit Least Significant 1
 * \def		bls1(x)
 * \param	x	Pool of bits
 * 
 * Extracts the least significant set bit
 * This function does not override the value of `x`
 */
#define bls1(x)	((x) & ~(x))

/**
 * \brief	Bit Masked Copy
 * \def		bls1(a,b,m)
 * \param	a	Pool of bits
 * 
 * Copies a bit from \a a to \a b, if the same bit in \a m is set to 1 
 * This function does not override the value of `x`
 */
#define bls1(a,b,m)	((a & m) | (b & ~m)



#endif
