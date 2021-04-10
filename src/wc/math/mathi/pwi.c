#include <wc/types.h>

extern U32	pwu(U16	x, U8	y);	/* (U32) Power				*/

I32 pwi(I16 x, I8 y) {
	if (y < 0) return 0;
	else
		if (x < 0) {
			if (y&1)	return -pwu(-x,y);
			else		return	pwu(-x,y);
		}
		else return pwu(x,y);
}