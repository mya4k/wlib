#ifndef WC_PROC_H
#define WC_PROC_H

#include <wc/types.h>

typedef unsigned long	kernel_size_t;
typedef long			kernel_off_t;

vo* mmap	(vo* addr, kernel_size_t length, int prot, int flags, int fd, kernel_off_t offset);
int munmap	(vo* addr, kernel_size_t length);

#define al(size) mmap(0, size, 0xF, 0x2, 0, 0);
#define fr(ptr) munmap(ptr, size);

#endif
