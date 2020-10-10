#include <wl/stdc/complex.h>

double		complex catan	(double			complex z) {
	return ( clog(1 - z*I) - clog(1 + z*I) ) * I / 2;
}

float		complex catanf	(float			complex z) {
	return ( clogf(1 - z*I) - clogf(1 + z*I) ) * I / 2;
}

long double	complex catanl	(long double	complex z) {
	return ( clogl(1 - z*I) - clogl(1 + z*I) ) * I / 2;
}