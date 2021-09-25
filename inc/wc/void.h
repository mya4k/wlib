#ifndef WC_VOID_H



#include <wc/types.h>	/* < DEF_VOID */



#ifndef NO_SHORT_NAMES
#	define rv			wl_rv
#	define return_void	wl_return_void
#endif



#ifndef REGION_ALIASES
/**
 * \brief	Return for void functions
 * \def		wl_return_void
 * \see		wl_rv
 * 
 * Alias of `wl_rv`
 */
#	define wl_return_void	wl_rv
#endif



/**
 * \brief	Return for void functions
 * \def		wl_rv
 * 
 * Before C ANSI standard there was no void type. To fix that <wc/types.h>
 * defines `Vo` and `vo` as the smallest integer type (`char`). Therefore,
 * `void` functions would actually be `char` and will need to return a value.
 */
#if DEF_VOID == 1
#	define wl_rv	return
#else
#	define wl_rv	return 0
#endif



#endif
