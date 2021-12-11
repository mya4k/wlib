#ifndef WC_ERROR_H
#define WC_ERROR_H



#if !WL_PREFIX
#	define ERNULL	WL_ERNULL
#	define ERZERO	WL_ERZERO
#	define WRNULL	WL_WRNULL

#	define err		wl_err
#	define wrn		wl_wrn
#endif



#define WL_ERNULL	"Null pointer"
#define WL_ERZERO	"Zero value variable"
#define WL_WRNULL	"Null pointer, allocating"



#if WL_ERROR
#	include <stdio.h>
#	define wl_err(SRC, MSG)	printf("%s: %s\n", #SRC, MSG)
#	define wl_wrn(SRC, MSG)	printf("%s: %s\n", #SRC, MSG)
#else
#	define wl_err(SRC, MSG)
#	define wl_wrn(SRC, MSG)
#endif

#endif
