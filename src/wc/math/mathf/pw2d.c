/* Includes */
#include <wc/types.h>



/* Declarations */
extern U64 fcq	(U8		x);
extern F64 _pwid(F64	x, I64 y);



/* (F64) 2^y */
F64	pw2d(F64 y) {
	const U64 iy = (U64)y;
	F64 r = 0;

	if (iy == 0)		r = 1.0;
	else if (iy == 1)	r = 2.0;
	else if (iy == 2)	r = 4.0;
	else if (iy == 3)	r = 8.0;
	else			r = _pwid(2.0, iy);

	y -= iy;

	F64 l = 420.0;
	F64 h = 1.0;

	if (y) {
		y *= LN2;

		for (U8 n = 1; l != h; n++) {
			l = h;
			h += _pwid(y, n) / fcq(n);
		}
		return r * h;
	}
	else return r;
}