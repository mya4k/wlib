#include <wl/math.h>



double rt2d(double power) {
	/* x is our initial guess, x1 and x2 will store the previous values of x */
	double x = 1, x1, x2;
	double a;
	U8 i;

	for (i = 0; x*x != power; i++) {
		/* We use Bakhshali method */
		a = (power - x*x) / (2*x);
		
		x2 = x1;
		x1 = x;
		x = (x+a) - ((a*a) / (2*(x+a)));

		/*	Make sure we aren't stuck in an infinite loop going through several
			values */
		if_unlikely (x1 == x || x2 == x) return x;
	}

	return x;
}



U32 rt2u(U64 power) {
	if_unlikely (power == 0) return 0;
	if_unlikely (power < 4) return 1;

	U64 guess, guessLow, guessHigh;

	/*	For power <= 64, `lg2u(power)` is closer or as close to 
		`rt2u(power)` as `1 << (lg2u(power)/2)`  */
	if_likely (power <= 64) guess = lg2u(power);
	else guess = 1 << (lg2u(power)/2);

	guessLow = guess/2; guessHigh = guess*2;

	for (;;) {
		if_likely (power >= sq(guess)) {
			if_unlikely (power < sq(guess+1)) return guess;
			else guessLow = guess;
		}
		else guessHigh = guess;
		guess = av2(guessLow, guessHigh);
	}
}
