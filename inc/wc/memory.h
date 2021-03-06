#ifndef WC_MEMORY_H
#define WC_MEMORY_H

#include <wc/types.h>

extern VO*	malloc(int size);
extern VO	free(VO* addr);

#define al	malloc
#define fr	free

#endif