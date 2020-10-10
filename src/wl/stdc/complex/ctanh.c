#include <wl/stdc/complex.h>
#include <wl/stdc/math.h>

double		complex ctanh	(double			complex z) {
	return csinh(z) / ccosh(z);
}

float		complex ctanhf	(float			complex z) {
	return csinhf(z) / ccoshf(z);
}

long double	complex ctanhl	(long double	complex z) {
	return csinhl(z) / ccoshl(z);
}