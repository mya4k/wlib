#include <wl/stdc/complex.h>

double		complex casinh	(double			complex z) {
	return clog( csqrt(z*z + 1) + z );
}

float		complex casinhf	(float			complex z) {
	return clogf( csqrtf(z*z + 1) + z );
}

long double	complex casinhl	(long double	complex z) {
	return clogl( csqrtl(z*z + 1) + z );
}