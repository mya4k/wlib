#include <wl/array.h>



const char* _asa(
	const char* restrict haystack,
	const char* restrict const needle,
	U32 lenh, const U32 lenn
) {
	/* Search for the first byte in `needle` */
	const char* a = asb(haystack, lenh, needle[0]);
	/* If found, check the next bytes, if they are bytes from `needle` */
	if (likely(a)) {
		if ( unlikely(aeq(haystack+1, needle+1, lenn-1)) )
			return a;
		a += lenn;
		lenh -= a - haystack;
		haystack = a;
	}
	return NULL;
}
