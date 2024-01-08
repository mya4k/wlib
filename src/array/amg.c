#include <wl/array.h>



const char* amg(
	char** restrict srcs,
	const U32* restrict const lens,
	const U8 count,
	char* restrict dst
) {
	const char* restrict const _dst = dst;
	U8 i;

	for (i = 0; i < count; i++) {
		ano(srcs[i], lens[i], dst);
		dst += lens[i];
	}

	return _dst;
}
