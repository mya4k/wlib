#include <wc/types.h>

extern U64	pwq(U32	x, U8	y);	/* (U64) Power				*/

I64 pwl(I32 x, I8 y) {
	if (y < 0) return 0;
	else
		if (x < 0) {
			if (y&1)	return -pwq(-x,y);
			else		return	pwq(-x,y);
		}
		else return pwq(x,y);
}