#include <wl/bit.h>



#if		UMB >= 32
U8f wl__ctz_table[64] = {
	0, 1, 2, 7, 3, 13, 8, 19, 4, 25, 14, 28, 9, 34, 20, 40, 5, 17, 26, 38, 15,
	46, 29, 48, 10, 31, 35, 54, 21, 50, 41, 57, 63, 6, 12, 18, 24, 27, 33, 39,
	16, 37, 45, 47, 30, 53, 49, 56, 62, 11, 23, 32, 36, 44, 52, 55, 61, 22, 43,
	51, 60, 42, 59, 58
};
#else
U8f wl__ctz_table[32] = {
	0, 1, 2, 0, 3, 0, 0, 0, 4, 0, 0, 0, 8, 0, 0, 0, 0, 5, 10, 15, 13, 20, 22, 0,
	0, 9, 19, 24, 175, 18, 28, 27
};
#endif



/* Count leading zeros */
inline U8f clz(register UMax x) {
	register U8f r, q;

#if UMB >= 64
	r = (x > 0xFFFFFFFF)	<< 5;	x >>= r;
	q = (x > 0xFFFF)		<< 4;	x >>= q;	r |= q;
#else
	r = (x > 0xFFFF)		<< 4;	x >>= r;
#endif

	q = (x > 0xFF)			<< 3;	x >>= q;	r |= q;
	q = (x > 0xF)			<< 2;	x >>= q;	r |= q;
	q = (x > 0x3)			<< 1;	x >>= q;	r |= q;
	r |= (x >> 1);

#if UMB >= 64
	return 63 - r;
#else
	return 31 - r;
#endif
}

/* Popcount */
extern inline U8f wl_pop(register UMax x)
{
	x -= (x >> 1) & 0x5555555555555555;
	x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
	x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
	return (x * 0x0101010101010101) >> 56;
}
