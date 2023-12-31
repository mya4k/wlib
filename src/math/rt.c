#include <wl/math.h>



double rt2d(double power) {
	/* x is our initial guess, x1 and x2 will store the previous values of x */
	double x = 1, x1, x2;
	double a;
	U8 i;

	for (i = 0; i<32 && x*x != power; i++) {
		/* We use Bakhshali method */
		a = (power - x*x) / (2*x);
		
		x2 = x1;
		x1 = x;
		x = (x+a) - ((a*a) / (2*(x+a)));

		/*	Make sure we aren't stuck in an infinite loop going through several
			values */
		if (x1 == x || x2 == x) return x;
	}

	return x;
}
