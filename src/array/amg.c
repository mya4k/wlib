#include <wl/array.h>
#include <wl/memory.h>



const char* amg(
	char** restrict srcs,
	const U32* restrict const lens,
	const U8 count,
	char* _dst
) {
	U32 tmp = smu(lens, count);
	if_likely (!_dst) _dst = mal(tmp);
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
