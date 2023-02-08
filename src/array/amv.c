#include <wl/array.h>



const void* _amv(
	const char* restrict const src, 
	const U32 len, 
	const char* restrict const dst
) {
#	if WL_C_STRING
		/* If allowed, we make a call to libc's analogous function */
		return memmove(dst, src, len);
#	else
		/* If dst overlaps the object at `src` */
		if (unlikely(dst < src+len && dst+len > src && src != dst)) {
			/* Get the length of overlapping data */
#			define delta ((src+len) - dst)
			/* Get the offset from `src` where overlap happens */
#			define offset (dst-src)
			/* Copy the overlapping area first */
			ano(dst, delta, dst+offset);
			/* Copy the rest */
			ano(src, offset, dst);
		}
		else ano(src, len, dst);

		return dst;
#	endif
}
