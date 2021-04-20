#include <wc/types.h>
#include <wc/types/int.h>
#include <wc/memory.h>
#include <stdio.h>

#define S_DEC	0b00	/* Decimal			*/
#define S_BIN	0b01	/* Binary			*/
#define S_OCT	0b10	/* Octal			*/
#define S_HEX	0b11	/* Hexadecimal		*/
#define S_COMMA	0b100	/* Comma delimeters	*/
#define S_DOT	0b1000	/* Dot delimeters	*/

/**
 * @fn		ch* qS(const U64 x, ch* str, const U8 flags)
 * @brief	U64 to ch*
 * @param	x		U64
 * @param	str		string	(optional)
 * @param 	flags	flags	(optional)
 * @return	ch* 
 * Converts U64 integer `x` into a string.
 * If `str` pointer is given, that string will be used to store convert `x` to;
 * otherwise, the string is allocated automatically and returns a
 * pointer to it.
 * Flags:
 * To apply several flags to this function they should be ORed together
 * 1) Base (choose only one)
 * 	S_DEC	`x` to be treated as a decimal number
 * 	S_BIN	`x` to be treated as a binary number
 * 	S_OCT	`x` to be treated as a octal number
 * 	S_HEX	`x` to be treated as a hexadecimal number
 * 2) Delimeter (choose only one)
 * 	S_COMMA	A comma will separate every triplet of digits
 * 	S_DOT	A dot (period) will separate every triplet of digits
 */
ch* qS(const U64 x, ch* str, const U8 flags) {
	/* Base */
	register U8 b;

	switch (flags & 0b11) {
		case S_BIN:	b = 2;	break;
		case S_OCT: b = 8;	break;
		case S_DEC: b = 10; break;
		case S_HEX:	b = 16;	break;
		default:	b = 10;	break;
	}

	register const U8 xs = dcq(x,b);								/**<Number digit count */
	register const U8 rs = ((flags & 0b1100) ? (xs + xs/3) : xs);	/**<String length */
	register const ch d = (flags & 0b100 ? '.' : (					/**<Delimeter */
		flags & 0b1000 ? ',' : 0
	));
				   
	/* If str not provided, allocate it */
	if (!str) str = mal(0, rs+1);
	
	/* Null */
	str[rs] = 0;

	/* If delimiter is provided */
	if (flags & 0b1100) {
		for (	register I8 i = rs-1, j = 0; 
				i >= 0 && j < xs; 
				i--							)
			if (i%4 == 2) str[i] = d;
			else {
				str[i] = dc(dgq(x, j, b), b);
				j++;
			}
	}
	/* Without delimiters */
	else {
		for (	register I8 i = rs-1, j = 0; 
				i >= 0 && j < xs; 
				i--, j++					) {
			str[i] = dc(dgq(x, j, b), b);
		}
	}

	return str;
}