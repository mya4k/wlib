/* Includes */
#include <wc/types.h>
#include <wc/math/mathi.h>
#include <wc/math/mathf.h>



/* (F64) 2^y */
F64	pw2d(F64 y) {
	const U64 iy = (U64)y;
	F64 r = 0;

	switch (iy) {
	case 0:		r = 1.0; break;
	case 1:		r = 2.0; break;
	case 2:		r = 4.0; break;
	case 3:		r = 8.0; break;
	default:	r = _pwid(2.0, iy); break;
	}

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