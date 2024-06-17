#include <wl/array.h>
#include <wl/memory.h>
#include <wl/variadic.h>



static inline_unless_opt_size char* _amga(
	char* _dst,
	const U8 count,
	char** restrict srcs,
	const U32* restrict const lens
) {
	if_likely (!_dst) _dst = (char*)mal(smau32(count, lens));
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

char* amga(
	char* _dst,
	const U8 count,
	char** restrict srcs,
	const U32* restrict const lens
) {
	return _amga(_dst, count, srcs, lens);
}

char* amgv(char* restrict dst, const U8 count, ...) {
	Va va;
	U8 i;
	char** array = (char**)mal(count*sizeof(void*)); 
	U32* size = (U32*)mal(count*sizeof(U32)); 

	vi(va, count);

	for (i = 0; i < count; i++) {
		array[i] = vn(va, char*);
		size[i] = vn(va, U32);
	}

	vq(va);

	return _amga(dst, count, array, size);
}
