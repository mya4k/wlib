#include <wl/array.h>
#include <wl/memory.h>
#include <wl/variadic.h>



char* amga(
	char* _dst,
	const U8 count,
	char** restrict srcs,
	const U32* restrict const lens
) {
	if_likely (!_dst) _dst = mal(smu(lens, count));
	if_likely (_dst) {
		char* dst = _dst;
		U8 i;

		for (i = 0; i < count; i++) {
			ano(srcs[i], lens[i], dst);
			dst += lens[i];
		}
	}

	return _dst;
}

char* amgv(char* restrict dst, const U8 count, ...) {
	Va va;
	U8 i;
	char** array = (char**)mal(count*sizeof(void*)); 
	U32* size = (U32*)mal(count*sizeof(U32)); 

	vi(va, count);

	for (i = 0; i < count; i++) {
		array[i] = va_arg(va, char*);
		size[i] = va_arg(va, U32);
	}

	vq(va);

	return amga(dst, (const U8)count, array, size);
}
