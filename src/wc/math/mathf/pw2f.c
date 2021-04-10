/* Includes */
#include <wc/types.h>



/* Macros */
#define LN2F		0.693147182464599609375F



/* Declarations */
extern U64 fcq	(U8		x);
extern F32 _pwif(F32	x, I64 y);



/* (F32) 2^y */
F32	pw2f(F32 y) {
	const U64 iy = (U64)y;
	F32 r = 0;

	switch (iy) {
	case 0:		r = 1.0F; break;
	case 1:		r = 2.0F; break;
	case 2:		r = 4.0F; break;
	case 3:		r = 8.0F; break;
	default:	r = _pwif(2.0F, iy); break;
	}

	y -= iy;

	F32 l = 420.0F;
	F32 h = 1.0F;

	if (y) {
		y *= LN2F;

		for (U8 n = 1; l!=h; n++) {
			l = h;
			h += _pwif(y,n) / fcq(n);
		}

		return r * h;
	}
	else return r;
}