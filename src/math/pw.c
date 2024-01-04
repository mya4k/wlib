#include <wl/math.h>



U64 pwu(U64 base, U8 exponent) {
	if_likely(base == 2) return pw2u(exponent);
	
	/* Now base is > 3, so 3^41 would already overflow U64 maximum value */
	if_unlikely(exponent > 40) return U64X;

	/*	Do branchessless multiplication for prime numbers, other numbers will 
		be taken care of by reducing them to prime number exponents */
	switch(exponent) {/* 1	| 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |*/
		case 0:	return	1;
		case 1:	return	base;
		case 2:	return	base*base;
		case 3:	return	base*base*base;
		case 5:	return	base*base*base*base*base;
		case 7:	return	base*base*base*base*base*base*base;
		case 11:return	base*base*base*base*base*base*base*base*base*base*
						base;
		case 13:return	base*base*base*base*base*base*base*base*base*base*
						base*base*base*base;
		case 17:return	base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base;
		case 19:return	base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base;
		case 23:return	base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base*base*
						base*base*base;
		case 29:return	base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base;
		case 31:return	base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base*base*
						base;
		case 37:return	base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base*base*base*base*
						base*base*base*base*base*base*base;
		default:
	}

	if_probability(exponent/2*2 == exponent, 19.0/40.0)
		return wl_pw(wl_pw(base, exponent/2), 2);
	if_probability(exponent/3*3 == exponent, 6.0/40.0)
		return wl_pw(wl_pw(base, exponent/3), 3);
	if_probability(exponent/5*5 == exponent, 2.0/40.0)
		return wl_pw(wl_pw(base, exponent/5), 5);
	/*	Other prime divisors can be skipped, as the lower devisors will take 
		care of all composite numbers until 40 */

	/*	This line should be unreachable, if somehow you have stumbled into
		here, that is a bug, please report */
	return U64X;
}
