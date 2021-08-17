#include <wc/types.h>

/* (F64) Integer exponent power functions */
U32 pwu(U16 x, U8 y) {
	if (y)
		if (x) {
			if (x == 1) return 1;
			if (x == 2) return 2 << (y-1);
			if (y == 1) return x;
			if (y == 2) return x * x;
			if (y == 3) return x * x * x;

			/* Exponentiation by squaring */
			F64 r = 1;

			while (y > 1) {
				if (y&1) r *= x;
				x *= x;
				y >>= 1;
			}

			return r * x;
		}
		else return 0;
	else return 1;
}