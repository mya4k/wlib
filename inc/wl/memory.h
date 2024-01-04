#ifndef WL_MEMORY_H
#define WL_MEMORY_H	1



#include <wl/config.h>



#if !WL_CONF_PREFIX
#	define mal	wl_mal
#	define mfr	wl_mfr
#endif



#if WL_STDLIB_H
#	include <stdlib.h>
#	define wl_mal(n)	malloc(n)
#	define wl_mfr(p)	free(p)
#else
#	define wl_mal(n)	(NULL)
#	define wl_mfr(p)
#endif



#endif
