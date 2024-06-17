#include <wl/array.h>
#include <wl/error.h>



/* Array Replace Byte */
void _arb(
	const	char* restrict const	haystack,
			U32						len,
	const	char					needle,
	const	char					rep
) {
	char* a = asb(haystack, len, needle);
	if (unlikely(a)) *a = rep;
}
