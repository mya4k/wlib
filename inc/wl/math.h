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


#if !WL_PREFIX
#	define lg2 wl_lg2
#endif



/**
 * \brief	Binary logarithm (U64)
 * \def		wl_lg2q(z)
 * 
 */
#define wl_lg2(z)	wl_ctz(z)



#endif
