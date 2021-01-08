#include <wc/core.h>
#include <wc/types.h>

VO _wr(U32* p, U32* d, U32 s) {
	s /= 4;
	for (U32 i = 0; i < s; i++)
		p[i] = d[i];
	return_void
}