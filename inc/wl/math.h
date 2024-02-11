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
 * \def		abi(x)
 * \param	x
 * \return	Absolute value of \a x
 */
#define wl_abi(x)	(((x)<0)*(-1)*(x))

/**
 * \brief	Square
 * \def		sq(x)
 * \param	x
 * \return	Square of x
 */
#define wl_sq(x)	((x)*(x))

/**
 * \brief	Average of two
 * \def		av2(min, max)
 * \param	min	Lower Value
 * \param	max	Higher Value
 * \return	Average of min and max
 */
#define av2(min, max)	((min) + ((max)-(min))/(U8f)2)

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
/* #define wl_lgu(base, power)	((float)wl_lg2(power) / (float)wl_lg2(base))
 */

#if WL__GENERIC
#	define wl_sma(count, addends) wl_genericInt((*(addends)),\
		wl_smab, wl_smaw, wl_smau, wl_smaq, wl_smac, wl_smah, wl_smai, wl_smal\
	)((count), (addends))
#endif

#define wl_smac(count, addends)	((wl_I8 )wl_smab((count), (const wl_I8 * const)(addends)))
#define wl_smah(count, addends)	((wl_I16)wl_smaw((count), (const wl_I16* const)(addends)))
#define wl_smai(count, addends)	((wl_I32)wl_smau((count), (const wl_I32* const)(addends)))
#define wl_smal(count, addends)	((wl_I64)wl_smaq((count), (const wl_I64* const)(addends)))
#define wl_smvc					(wl_I8)(wl_smvb)
#define wl_smvh					(wl_I16)(wl_smvw)
#define wl_smvi					(wl_I32)(wl_smvu)
#define wl_smvl					(wl_I64)(wl_smvl)

/**
 * \brief	Exponentiation (U64)
 * \fn		extern U64 pwu(U64 base, U8 exponent)
 * \param	base		Base
 * \param	exponent	Exponent
 * \return	Power of \a base to \a exponent
 * 
 * A clever algorithm that quickly computes a power of two unsigned integers.
 */
extern wl_U64 wl_pwu(wl_U64 base, wl_U8 exponent);

extern wl_U32 wl_rt2u(wl_U64 power);

extern wl_U8	wl_smab(wl_U8 count, const wl_U8 * restrict const addends);
extern wl_U16	wl_smaw(wl_U8 count, const wl_U16* restrict const addends);
extern wl_U32	wl_smau(wl_U8 count, const wl_U32* restrict const addends);
extern wl_U64	wl_smaq(wl_U8 count, const wl_U64* restrict const addends);
extern wl_U8	wl_smvb(wl_U8 count, ...);
extern wl_U16	wl_smvw(wl_U8 count, ...);
extern wl_U32	wl_smvu(wl_U8 count, ...);
extern wl_U64	wl_smvq(wl_U8 count, ...);



#endif
