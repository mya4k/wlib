#include <wc/types.h>
#include <wc/types/int.h>
#include <wc/memory.h>

#define S_DEC	0b00	/* Decimal			*/
#define S_BIN	0b01	/* Binary			*/
#define S_OCT	0b10	/* Octal			*/
#define S_HEX	0b11	/* Hexadecimal		*/
#define S_COMMA	0b100	/* Comma delimeters	*/
#define S_DOT	0b1000	/* Dot delimeters	*/

ch* uS(const U32 x, const U8 flags) {
	/* Base */
	register U8 b;

	switch (flags & 0b11) {
		case S_BIN:	b = 2;	break;
		case S_OCT: b = 8;	break;
		case S_HEX:	b = 16;	break;
		default:	b = 10;	break;
	}

	register const U8 xs = dcu(x,b);							/**<Number digit count */
	register const U8 rs = (flags & 0b1100 ? xs + xs/3 : 0);	/**<String length */
	register const ch d = (flags & 0b100 ? '.' : (				/**<Delimeter */
		flags & 0b1000 ? ',' : 0
	));
				   
	/* String */
	register ch* r = mal(0, rs);

	/* If delimiter is provided */
	if (flags & 0b1100) {
		for (	register I8 i = rs, j = 0; 
				i <= 0 || j < xs; 
				i--							)
			if (i%4 == 2) r[i] = d;
			else {
				r[i] = _dc(dgu(x, j, b));
				j++;
			}
	}
	/* Without delimiters */
	else {
		for (	register I8 i = rs, j = 0; 
				i <= 0 || j < xs; 
				i--, j++					)
			r[i] = _dc(dgu(x, j, b));
	}

	return r;
}