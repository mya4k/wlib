#define _PI		3.1415926535
#define _PIF	3.1415926535f
#define _PIL	3.1415926535L

#include <wl/stdc/complex.h>

double		complex cacos	(double			complex z) {
	return _PI/2 - casin(z);
}

float		complex cacosf	(float			complex z) {
	return _PIF/2 - casinf(z);
}

long double	complex cacosl	(long double	complex z) {
	return _PIL/2 - casinl(z);
}