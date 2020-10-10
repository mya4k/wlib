#include <wl/stdc/complex.h>
#include <wl/stdc/math.h>

double		complex ccos	(double			complex z) {
	double x = creal(z);
	double y = cimag(z);
	return CMPLX(cos(x) * cosh(y), -(sin(x) * sinh(y)));
}

float		complex ccosf	(float			complex z) {
	float x = crealf(z);
	float y = cimagf(z);
	return CMPLXF(cosf(x) * coshf(y), -(sinf(x) * sinhf(y)));
}

long double	complex ccosl	(long double	complex z) {
	long double x = creall(z);
	long double y = cimagl(z);
	return CMPLXL(cosl(x) * coshl(y), -(sinl(x) * sinhl(y)));
}