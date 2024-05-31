#ifndef WL_MEMORY_H
#define WL_MEMORY_H	1



#include <wl/config.h>



#if !WL_CONF_PREFIX
#	define mal	wl_mal
#	define mfr	wl_mfr
#	define alh	wl_alh
#	define als	wl_als
#	define frh	wl_frh
#	define frs	wl_frs
#endif



/* Depricated */
#define wl_mal	wl_alh
#define wl_mfr	wl_frh

#if WL_STDLIB_H
#	include <stdlib.h>
#	define wl_alh(n)	malloc(n)
#	define wl_frh(p)	free(p)
#else
#	define wl_alh(n)	(NULL)
#	define wl_frh(p)
#endif

#if WL_ALLOCA_H
#	include <alloca.h>
#	define wl_als(n)	alloca(n)
#	define wl_frs(p)
#else
#	define wl_als(n)	wl_alh(n)
#	define wl_frs(p)	wl_frh(p)
#endif



#endif
