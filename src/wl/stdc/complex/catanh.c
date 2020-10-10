#include <wl/stdc/complex.h>

double		complex catanh	(double			complex z) {
	return ( clog(z+1) - clog(z-1) ) / 2;
}

float		complex catanhf	(float			complex z) {
	return ( clogf(z+1) - clogf(z-1) ) / 2;
}

long double	complex catanhl	(long double	complex z) {
	return ( clogl(z+1) - clogl(z-1) ) / 2;
}