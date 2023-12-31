#ifndef WL_BITS_H
#define WL_BITS_H	1



#include <wl/types.h>



#if !WL_PREFIX
#	define b0	wl_b0
#	define b1	wl_b1
#	define br	wl_br
#	define brs	wl_brs
#	define bt	wl_bt
#	define bct0	wl_bct0
#	define bls1	wl_bls1
#	define bmc	wl_bmc

#	define clz	wl_clz
#	define ctz	wl_ctz
#	define pop	wl_pop
#endif



extern wl_U8f wl__ctz_table[64];



/**
 * \brief	Bit Set
 * \def		b1(n)
 * \param	n	Number of the bit to be set
 * 
 * Returns a empty bit-string, but with \a n bit set
 */
#define wl_b1(n)	(((UMax)1<<(n)))

/**
 * \brief	Bit Clear
 * \def		b0(n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be cleared
 * 
 * Returns a bit-string full of set bits, but with \a n bit clear
 */
#define wl_b0(x,n)	(~wl_b1(n))

/**
 * \brief	Bit Read
 * \def		br(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be read
 * 
 * Reads the bit `n` in `x`. 
 */
#define wl_br(x,n) (!!((x) & (UMax)1<<(n)))

/**
 * \brief	Bit Read String
 * \def		brs(x,n,l)
 * \param	x	Pool of bits
 * \param	n	Number of the bit from where to start reading
 * \param	l	Length of the string to be read in bits
 * 
 * Reads `l` bits starting from the bit `n` in `x`
 */
#define wl_brs(x,n,l) ( ((x) & ( (((UMax)1<<(l)) - 1) << (n) ) ) >> (n))

/**
 * \brief	Bit Toggle
 * \def		bt(x,n)
 * \param	x	Pool of bits
 * \param	n	Number of the bit to be toggled
 * 
 * Complements the bit `n` in `x`. 
 * This function does not override the value of `x`
 */
#define wl_bt(x,n)	((1<<(n)) ^ (x))

/**
 * \brief	Bit Convert Trailing zeros
 * \def		bct0(x)
 * \param	x	Pool of bits
 * 
 * Converts trailing zeros to one
 * This function does not override the value of `x`
 */
#define wl_bct0(x)	(((x)-1) | (x))

/**
 * \brief	Bit Least Significant 1
 * \def		bls1(x)
 * \param	x	Pool of bits
 * 
 * Extracts the least significant set bit
 * This function does not override the value of `x`
 */
#define wl_bls1(x)	((x) & -(x))

/**
 * \brief	Bit Masked Copy
 * \def		wl_bls1(a,b,m)
 * \param	a	Pool of bits
 * 
 * Copies a bit from \a a to \a b, if the same bit in \a m is set to 1 
 * This function does not override the value of `x`
 */
#define wl_bmc(a,b,m)	((a & m) | (b & ~m))

/**
 * \brief	Trailing Ones
 * \def		wl_bt1(n)
 * \param	n	Number of trailing ones
 *
 * Returns an empty bit-string, but with n trailing set bits
 */
#define wl_bt1(n)	(wl_b1(n)-1)

/**
 * \brief	Leading Ones
 * \def		wl_bl1(n)
 * \param	n	Number of leading ones
 *
 * Returns an empty bit-string, but with n trailing set bits
 */
#define wl_bl1(n)	(~wl_b1((sizeof(n)*WL_CHB) -n) -1)


/**
 * \brief	Count trailing zeros
 * \def		wl_ctz(x)
 * \param	x
 * 
 * If WL_BUILTIN_CTZ is disabled, we use de Bruijn sequences in order to do
 * this branchless
 */
#if	WL_BUILTIN_CTZ
#	if WL__GENERIC
#		define wl_ctz(x) _Generic((x),				\
			default:			__builtin_ctz(x),	\
			long:				__builtin_ctzl(x),	\
			long long:			__builtin_ctzll(x),	\
			unsigned long:		__builtin_ctzl(x),	\
			unsigned long long:	__builtin_ctzll(x)	\
		)(x)
#	else
#		define wl_ctz(x)	__builtin_ctzll(x)
#	endif
#else
#	if		UMB == 64
#		define WL__DEBRUIJN	0x218A392CD3D5DBF
#		define wl_ctz(x)\
	(wl__ctz_table[((-(U64l)(x)&(U64l)(x)) * WL__DEBRUIJN) >> 58])
#	else
#		define WL__DEBRUIJN	0x4653ADF
#		define wl_ctz(x)\
	(wl__ctz_table[((-(U32l)(x)&(U32l)(x)) * WL__DEBRUIJN) >> 27])
#	endif
#endif

/**
 * \brief	Count leading zeros
 * \def		wl_clz(x)
 * \param	x  
 * 
 * Counts the number of leading zeros in word \a x
 */
#if	WL_BUILTIN_CLZ
#	if WL__GENERIC
#		define wl_clz(x) _Generic((x),				\
			default:			__builtin_clz(x),	\
			long:				__builtin_clzl(x),	\
			long long:			__builtin_clzll(x),	\
			unsigned long:		__builtin_clzl(x),	\
			unsigned long long:	__builtin_clzll(x)	\
		)(x)
#	else
#		define wl_clz(x)	__builtin_clzll(x)
#	endif
#else
	extern inline U8 wl_clz(register UMax x);
#endif

/**
 * \brief	Popcount
 * \def		wl_pop(x)
 * \param	x
 * 
 * Performs a Hamming's weight calculation on x 
 */
#if	WL_BUILTIN_POPCOUNT
#	if WL__GENERIC
#		define wl_pop(x) _Generic((x),					\
			default:			__builtin_popcount(x),	\
			long:				__builtin_popcountl(x),	\
			long long:			__builtin_popcountll(x),\
			unsigned long:		__builtin_popcountl(x),	\
			unsigned long long:	__builtin_popcountll(x)	\
		)(x)
#	else
#		define wl_pop(x)	__builtin_popcountll(x)
#	endif
#else
	extern inline U8 wl_pop(register UMax x);
#endif

#endif
