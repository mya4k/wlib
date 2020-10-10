#include <wl/stdc/complex.h>

double		complex casin	(double			complex z) {
	return clog(z*I + csqrt(1 - z*z)) * -I;
}

float		complex casinf	(float			complex z) {
	return clogf(z*I + csqrtf(1 - z*z)) * -I;
}

long double	complex casinl	(long double	complex z) {
	return clogl(z * I + csqrtl(1 - z * z)) * -I;
}