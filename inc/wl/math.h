/**
 * \file math.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2022-08-24
 * 
 * 
 */
#ifndef WL_MATH_H
#define WL_MATH_H	1



#include <wl/types.h>
#include <wl/bit.h>



#if !WL_PREFIX
#	define abi	wl_abi
#	define lg2u wl_lg2u
#	define lgu wl_lgu
#	define pw2u wl_pw2u
#	define pwu wl_pwu
#	define pwi wl_pwi
#endif



/**
 * \brief	Absolute value Integer
 * \def		wl_abi(x)
 * \param	x
 * \return	Absolute value of \a x
 */
#define wl_abi(x)	(((x)<0)*(-1)*(x))

/**
 * \brief	Binary Exponentiation (U64)
 * \def		pw2u(exponent)
 * \param	exponent	Exponent
 * \return	Binary exponentiation by the exponent \a y 
 */
#define wl_pw2u(exponent)	wl_b1(exponent)

/**
 * \brief	Power Signed Integer
 * \def		pwi(base,exponent)
 * 
 */
#define wl_pwi(base, exponent)\
	(1 - 2*(exponent%2 * (base<0))) * wl_pwu(base, exponent)

/**
 * \brief	Binary Logarithm (UMax)
 * \def		lg2u(power)
 * \param	power	Anti-logarithm
 * \return	Binary Logarithm of the power \a z
 * \see		ctz
 */
#define wl_lg2u(power)	wl_ctz(power)

/**
 * \brief	Logarithm (UMax)
 * \def		lgu(base, power)
 * \param	base	Base (UMax)
 * \param	power	Anti-logarithm (UMax)
 * \return	float	Result of operation
 */
#define wl_lgu(base, power)	((float)wl_lg2(power) / (float)wl_lg2(base))



/**
 * \brief	Exponentiation (U64)
 * \fn		extern U64 pwu(U64 base, U8 exponent)
 * \param	base		Base
 * \param	exponent	Exponent
 * \return	Power of \a base to \a exponent
 * 
 * A clever algorithm that quickly computes a power of two unsigned integers.
 */
extern U64 pwu(U64 base, U8 exponent);

extern U32 rt2(U64 power);



#endif
