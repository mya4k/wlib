#ifndef WL_BITS_H
#define WL_BITS_H	1



#include <wl/types.h>



/**
 * \brief	Bit Set
 * \def		wl_bs(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be set
 * 
 * Sets the bit `n` to 1 in `x`. 
 * This function does not override the value of `x`
 */
#define wl_bs(x,n)	(((UMax)1<<(n)) | (x))

/**
 * \brief	Bit Clear
 * \def		wl_bc(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be cleared
 * 
 * Sets the bit `n` to 0 in `x`. 
 * This function does not override the value of `x`
 */
#define wl_bc(x,n)	(~((UMax)1<<(n)) & (x))

/**
 * \brief	Bit Read
 * \def		wl_br(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be read
 * 
 * Reads the bit `n` in `x`. 
 */
#define wl_br(x,n) (!!((x) & (UMax)1<<(n)))

/**
 * \brief	Bit Read String
 * \def		wl_brs(x,n,l)
 * \param	x	Pool of bits
 * \param	n	Number of the bit from where to start reading
 * \param	l	Length of the string to be read in bits
 * 
 * Reads `l` bits starting from the bit `n` in `x`
 */
#define wl_brs(x,n,l) ( ((x) & ( (((UMax)1<<(l)) - 1) << (n) ) ) >> (n))

/**
 * \brief	Bit Toggle
 * \def		wl_bt(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be toggled
 * 
 * Complements the bit `n` in `x`. 
 * This function does not override the value of `x`
 */
#define wl_bt(x,n)	((1<<(n)) ^ (x))

/**
 * \brief	Bit Convert Trailing zeros
 * \def		wl_bct0(x)
 * \param	x	Pool of bits
 * 
 * Converts trailing zeros to one
 * This function does not override the value of `x`
 */
#define wl_bct0(x)	(((x)-1) | (x))

/**
 * \brief	Bit Least Significant 1
 * \def		wl_bls1(x)
 * \param	x	Pool of bits
 * 
 * Extracts the least significant set bit
 * This function does not override the value of `x`
 */
#define wl_bls1(x)	((x) & ~(x))

/**
 * \brief	Bit Masked Copy
 * \def		wl_bls1(a,b,m)
 * \param	a	Pool of bits
 * 
 * Copies a bit from \a a to \a b, if the same bit in \a m is set to 1 
 * This function does not override the value of `x`
 */
#define wl_bmc(a,b,m)	((a & m) | (b & ~m))

#if	WL_CONF_B
#else
#	if		UMB == 32
#		define WL__DEBRUIJN	0x218A392CD3D5DBF
		extern wl_U8f wl__ctz_table[UMB];
#		define ctz(x)\
	(wl__ctz_table[((-(U64l)(x)&(U64l)(x)) * WL__DEBRUIJN) >> 58])
#	else
		extern wl_U8f wl__ctz_table[UMB];
#		define WL__DEBRUIJN	0x4653ADF
#		define wl_ctz(x)\
	(wl__ctz_table[((-(U32l)(x)&(U32l)(x)) * WL__DEBRUIJN) >> 27])
#	endif
#endif



#endif
