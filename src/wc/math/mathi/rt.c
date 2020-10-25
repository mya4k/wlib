#include <wc/core/types.h>

inline	U16 _rt2	(U32 z);
inline	U32 _rt2l	(U64 z);
		U16 rt		(U8 y, U32 z);
		U32 rtl		(U8 y, U64 z);

inline	U16 _rt2	(U32 z) {
	U16 x = 1;

	while (x*x != z)
		x = (x + z/x) / 2;

	return x;
}

inline	U32 _rt2l	(U64 z) {
	U32 x = 1;

	while (x*x != z)
		x = (x + z/x) / 2;

	return x;
}

U16 rt		(U8 y, U32 z) {
	if (y < 0)	return 0;
	/* rt(y,0) = 0 */
	if (z == 0)	return 0;
	/* rt(y,1) = 1 */
	if (z == 1)	return 1;
	/* rt(1,z) = 0 */
	if (y == 1)	return z;
	/* rt(2,z) */
	if (y == 2)	return _rt2(z);
	
	/* other cases */
	U8	a = y - 1;
	U16	x[2] = { 1, 0 };

	while (x[0] != x[1]) {
		x[1] = x[0];
		x[0] = (x[0]*a + z / pw(x[0],a)) / y;
	}

	return x[0];
}

U32 rtl		(U8 y, U64 z) {
	if (y < 0)	return 0;
	/* rt(y,0) = 0 */
	if (z == 0)	return 0;
	/* rt(y,1) = 1 */
	if (z == 1)	return 1;
	/* rt(1,z) = 0 */
	if (y == 1)	return z;
	/* rt(2,z) */
	if (y == 2)	return _rt2l(z);

	/* other cases */
	U8	a = y - 1;
	U32	x[2] = { 1, 0 };

	while (x[0] != x[1]) {
		x[1] = x[0];
		x[0] = (x[0] * a + z / pw(x[0], a)) / y;
	}

	return x[0];
}