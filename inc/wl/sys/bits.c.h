/* ONLY INCLUDE ONCE PER SOURCE FILE */

/* Count leading zeros */
inline_unless_opt_size U8f clz(register UMax x) {
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
inline_unless_opt_size U8f wl_pop(register UMax x)
{
	x -= (x >> 1) & 0x5555555555555555;
	x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
	x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
	return (x * 0x0101010101010101) >> 56;
}
