#include <wc/types.h>

bl	aeq(register	const	U8	s,
		register	const	VO*	a,
		register	const	VO* b	) {
	register const U8 d = s/8;
	register const U8 m = s%8;
	register U16 i = 0;

	for (; i < d; i++)
		if (((U64*)a)[i] != ((U64*)b)[i]) return 0;
	
	i *= 8;

	if (m&0b001) {
		if (((U8*)a)[i] != ((U8*)b)[i]) return 0;
		i++;
	}
	if (m&0b010) {
		if (((U16*)a)[i] != ((U16*)b)[i]) return 0;
		i += 2;
	}
	if (m&0b100)	{
		if (((U16*)a)[i] != ((U16*)b)[i]) return 0;
		i += 4;
	}

	return 1;
}