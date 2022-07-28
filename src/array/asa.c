#include <wl/array.h>


#define wl_A_asb	wl_asb
#define wl_A_aeq	wl_aeq



const void* _asa(
	const char* restrict const haystack,		U32 lenh,
	const char* restrict const needle,	const	U32 lenn
) {
	/* If `lenn` > `lehn`, return NULL */
	/* If `lenn` == `lehn`, test that both object are the same */
	if (unlikely(lenn>=lenh)) {
		if (unlikely(lenn==lenh))
			return (void*)((Pt)haystack*(wl_A_aeq(haystack, needle, lenh)));
	}
	else {
		const char* restrict _haystack = haystack;
		while (likely(lenh>0)) {
			/* Find the first byte of needle */
			_haystack = wl_A_asb(_haystack, lenh, *needle);
			lenh = _haystack - haystack;
			/* If not found, return NULL */
			if (unlikely(_haystack==NULL)) return NULL;
			/* If found, check wether the next bytes are a match */
			if (wl_A_aeq(_haystack++, needle+1, lenn-1)) return _haystack-1;
		}
	}
	return NULL;
}
