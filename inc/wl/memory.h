#ifndef WL_MEMORY_H
#define WL_MEMORY_H	1



#include <wl/config.h>



#if !WL_PREFIX
#	define mal	wl_mal
#	define mfr	wl_mfr
#	define alh	wl_alh
#	define als	wl_als
#	define frh	wl_frh
#	define frs	wl_frs
#endif



/* Depricated */
#define wl_mal	wl_hal
#define wl_mfr	wl_hfr

#if WL_STDLIB_H
#	include <stdlib.h>
#	define wl_hal(n)	malloc(n)
#	define wl_hra(n,s)	realloc(n,s)
#	define wl_hfr(p)	free(p)
#else
#	define wl_hal(n)	(NULL)
#	define wl_hra(n,s)	(NULL)
#	define wl_hfr(p)
#endif

#if WL_ALLOCA_H
#	include <alloca.h>
#	define wl_sal(n)	alloca(n)
#	define wl_sfr(p)
#else
#	define wl_sal(n)	wl_alh(n)
#	define wl_sfr(p)	wl_frh(p)
#endif



#endif
