#include <wl/stdc/complex.h>

double		complex cacosh	(double			complex z) {
	return clog( csqrt(z-1) * csqrt(z+1) + z);
}

float		complex cacoshf	(float			complex z) {
	return clogf( csqrtf(z-1) * csqrtf(z+1) + z);
}

long double	complex cacoshl	(long double	complex z) {
	return clogl( csqrtl(z-1) * csqrtl(z+1) + z);
}