#include <wl/math.h>



U8 lgu(const U32 base, const U64 power) {
	U64 guess = lg2u(power)/lg2u(base), guessLow = guess/2, guessHigh = guess*2;

	for (;;) {
		if_likely (power >= pwu(base, guess)) {
			if_unlikely (power < pwu(base, guess+1)) return guess;
			else guessLow = guess;
		}
		else guessHigh = guess;
		guess = av2(guessLow, guessHigh);
	}
}
