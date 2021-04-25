#include <wc/types.h>
#include <wc/types/array.h>

/**	\fn		VO* afl(register	const	U16	sa, 		\
 *				register			VO*	a, 	\
 *				register			U8	sb, 	\
 *				register	const	VO*	b	)
 *	\param	sa	size of the array A in bytes
 *	\param	a	the array A
 *	\param	sb	size of the array B in bytes
 *	\param	b	the array B
 *	\brief	Takes two arrays and their sizes. Fills the array A with as many
 *			instances of array B as the size of array A can handle.
 *	\return	The array A
 *	Method:
 *		-#	If /e a = NULL, then the array of size /e sa will be allocated
 *		-#	If /e b = NULL and /e sb = 0, then array will be filled with zeros
 *		-#	If /e sb = 0, the function does nothing and returns NULL
 *		-#	Declares a variable /e i, this is be the pointer offset
 *		-#	Assignes array /e b to array /e a offsetted by /e i, and incriments
 *			/e i by /e sb. This step is repeated until less than sb bytes are
 *			left untreated
 *		-#	Assignes the remaining part of array /e a with whatever piece of 
 *			array /e b fits
 */
VO* afl(register	const	U8	sa, 
		register			VO*	a, 
		register			U8	sb, 
		register	const	VO*	b	) {
	if (!a) a = mal(0,sa);

	if (!sb) {
		if (b) return 0;
		else {
			I64 n = 0;
			b = &n;
			sb = sizeof(n);
		}
	}

	const	U16	d = sa/sb*sb;
			U16	i = 0;

	for (; i<d; i+=sb)
		aas(sb, a+i, b);

	aas(sa-d, a+i, b);

	return a;
}
