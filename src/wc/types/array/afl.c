#include <wc/types.h>
#include <wc/types/array.h>

VO* afl(register	const	U16	sa, 
		register			VO*	a, 
		register	const	U8	sb, 
		register	const	VO*	b	) {
	if (!a) a = mal(0,sa);

	for (register U8 i = 0; i < sa; i += sb)
		aas(sb, b, a+i);

	return a;
}
