#include <wl/stdc/complex.h>
#include <wl/stdc/math.h>

double		complex ccosh	(double			complex z) {
	double x = creal(z);
	double y = cimag(z);
	return cosh(x)*cos(y) + sinh(x)*sin(y)*I;
}

float		complex ccoshf(float			complex z) {
	float x = crealf(z);
	float y = cimagf(z);
	return coshf(x)*cosf(y) + sinhf(x)*sinf(y)*I;
}

long double	complex ccoshl	(long double	complex z) {
	long double x = creall(z);
	long double y = cimagl(z);
	return coshl(x)*cosl(y) + sinhl(x)*sinl(y)*I;
}