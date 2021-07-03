#ifndef WC_MEMORY_H
#define WC_MEMORY_H

#include <wc/sys/osys.h>

/* Standard library*/
#ifdef USE_STDLIB
#	include <stdlib.h>
#	define wl_mal(addr, size)	malloc(size)
#	define wl_mal0(addr, size) calloc(size)
#	define wl_mfr(addr, size)	free(addr)
#else

	/* Linux */
#	if defined(OS_LINUX) && !defined(NO_LINUX)
#		include <sys/mman.h>

#		define wl_mal(addr, size)	mmap(addr, size, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0)
#		define wl_mfr(addr, size)	munmap(addr, size)
#	endif

#endif

#endif
