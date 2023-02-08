#include <wl/array.h>
#include <wl/memory.h>



const char* _ara(
	const char* restrict const src,
	const char* restrict const ndl,
	const char* restrict const rep,
	const U32 lens, const U32 lenn, const U32 lenr 
) {
	/* Find the needle */
	const char* where = asa(src, ndl, lens, lenn);
	/* If found */
	if (likely(where)) {
		/* Just replace `ndl` with `rep`*/
		if (lenn == lenr) ano(rep, lenr, where);
		/* If replacement data is longer than needle data */
		else if (lenr > lenn) {
			/* Preserve the data proceeding `ndl` */
			const char* slice;
			Pt sliceSize;
			where += lenn;
			sliceSize = lens-(where-src);
#if WL_C_ALLOCA
			slice = alloca(sliceSize);
#else
			slice = mal(sliceSize);
#endif
			ano(where, sliceSize, slice);
			where -= lenn;
			/* Replace */
			ano(rep, lenr, where);
			/* Reattach the sliced data */
			ano(slice, lens-sliceSize, where+lenr);
		}
		/* If replacement data shorter than needle data */
		else {
			/* Overwrite needle with replacement data */
			ano(rep, lenr, where);
			/* Shift the data proceeding replaced data to fill the gap*/
			asl(where+lenr, lens-(where-src)+lenr, lenn-lenr);
		}
	}

	return src;
}
