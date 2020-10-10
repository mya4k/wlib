#include <wl/stdc/complex.h>
#include <wl/stdc/math.h>

double		complex csinh	(double			complex z) {
	double x = creal(z);
	double y = cimag(z);
	return sinh(x)*cos(y) + cosh(x)*sin(y)*I;
}

float		complex csinhf(float			complex z) {
	float x = crealf(z);
	float y = cimagf(z);
	return sinh(x)*cos(y) + cosh(x)*sin(y)*I;
}

long double	complex csinhl	(long double	complex z) {
	long double x = creall(z);
	long double y = cimagl(z);
	return sinh(x)*cos(y) + cosh(x)*sin(y)*I;
}