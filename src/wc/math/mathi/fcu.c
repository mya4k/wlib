#include <wc/types.h>

/* (U32) Factorial */
U32	fcu(U8 n) {
	switch (n) {
	case 0:		return 1;
	case 1:		return 1;
	case 2:		return 2;
	case 3:		return 6;
	case 4:		return 24;
	case 5:		return 120;
	case 6:		return 720;
	case 7:		return 5040;
	case 8:		return 40320;
	case 9:		return 362880;
	case 10:	return 3628800;
	case 11:	return 39916800;
	case 12:	return 479001600;
	default:	return U32X;
	}
}