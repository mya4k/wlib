#include <wl/math.h>



U32 smu(const U32* restrict const addends, U8 count) {
	U32 s = 0;
	
	while (count) {
		s += addends[count--];
	}

	return s;
}
