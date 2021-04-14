#include <wc/types.h>
#include <wc/numerics.h>
#include <wc/memory.h>

#define S_DEC	0b00	/* Decimal			*/
#define S_BIN	0b01	/* Binary			*/
#define S_OCT	0b10	/* Octal			*/
#define S_HEX	0b11	/* Hexadecimal		*/
#define S_COMMA	0b100	/* Comma delimeters	*/
#define S_DOT	0b1000	/* Dot delimeters	*/

ch* uS(const U32 x, const U8 flags) {
	switch (flags & 0b11) {
		case S_BIN:	register const U8 l = dcu(x,2);		break;
		case S_OCT:	register const U8 l = dcu(x,8);		break;
		case S_HEX:	register const U8 l = dcu(x,16);	break;
		default:	register const U8 l = dcu(x,10);	break;
	}

	/* GCC complains, so here's an extra declaration */
	register const U8 l;
				   
	register ch* r = mal(0, l);

	for (register U8 i = 0; i < l; i++)
		r[i] = dgu(x, l-1-i);
}