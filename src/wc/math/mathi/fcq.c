#include <wc/types.h>



extern U32	fcu(U8 n);



#if NO_I64 == 1
/* If 64-bit integer type not supported */
/* (U64) Factorial */
U64 fcq(U8 n) {
	return fcu(n);
}
#else
/* (U64) Factorial */
U64 fcq(U8 n) {
	if (n >= 13)
		switch (n) {
		case 13:	return 6227020800;
		case 14:	return 87178291200;
		case 15:	return 1307674368000;
		case 16:	return 20922789888000;
		case 17:	return 355687428096000;
		case 18:	return 6402373705728000;
		case 19:	return 121645100408832000;
		case 20:	return 2432902008176640000;
		default:	return U64X;
		}
	else return fcu(n);
}
#endif