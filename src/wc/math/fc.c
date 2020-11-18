#include <wc/types.h>

/* (U32) Factorial */
static const U32 fcu_[14] = {
	1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600
};

U32	fcu(U8 n) {
	return (n<13) ? fcu_[n] : U32X;
}

/* (U64) Factorial */
#if !NO_I64
static const U64 fcq_[7] = {
	87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000
};

U64	fcu(U8 n) {
	if (n<13) return fcu_[n];
	if (n < 21) return fcq_[n-13];
	return U64X;
}
#endif