#ifndef WC_MEMORY_H
#define WC_MEMORY_H

/* If Linux system calls are avaliable and allowed, rely on them */
#if defined(OS_LINUX) && !defined(NO_LINUX)
#	include <sys/mman.h>

#	define al(addr, size)	mman(addr, size, PROT_READ|PROT_WRITE, MAP_PRIVATE, 0, 0)
#	define fr(addr, size)	munmap(addr, size)
#endif

#endif