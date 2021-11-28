#include <wc/array.h>



#if !defined(WL_MAL_IMPLIMENTED) || !defined(mal)
#	include <stdlib.h>
#	define mal malloc
#endif



/* Abbreviation for `sizeof(UMax)` */
#define SM	(sizeof(UMax))
/* Pointer add assignment */
#define PADA(a,b) (a = (const void*)((Pt)a+(Pt)b))


Bl _anol(const void* a, As size, Bl r) {
	if (a&&size) {
		for (; size >= SM; PADA(a,SM), size -= SM)
			if (*((UMax*)a)) return r;
		if (size<<=3) {
			const UMax m = ((UMax)1<<size) - 1;
			if (*((UMax*)a)&m) return r;
		}
	}

	return !r;
}
