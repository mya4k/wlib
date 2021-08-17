#include <wc/types.h>
#include <wc/types/int.h>
#include <wc/math/mathi.h>
#include <wc/memory.h>

#define S_DEC	0b00	/* Decimal			*/
#define S_BIN	0b01	/* Binary			*/
#define S_OCT	0b10	/* Octal			*/
#define S_HEX	0b11	/* Hexadecimal		*/
#define S_COMMA	0b100	/* Comma delimeters	*/
#define S_DOT	0b1000	/* Dot delimeters	*/
#define S_PLUS	0b10000 /* Plus sign */

/**
 * @fn		ch* iS(I32 x, ch* str, const U8 flags)
 * @brief	I32 to ch*
 * @param	x		I32
 * @param	str		string	(optional)
 * @param 	flags	flags	(optional)
 * @return	ch* 
 * Converts U32 integer `x` into a string.
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
 * 3) Other
 * 	S_PLUS	Whether to add the plus sign to positive numbers or not
 */
ch* iS(I32 x, ch* str, const U8 flags) {
	/* Base */
	register U8 b;

	switch (flags & 0b11) {
		case S_BIN:	b = 2;	break;
		case S_OCT: b = 8;	break;
		case S_DEC: b = 10; break;
		case S_HEX:	b = 16;	break;
		default:	b = 10;	break;
	}

	/**<Number digit count */
	register const U8 xs = (x ? dci(x,b) : 1);
	/**<`i` parameters limit */
	register const I8 _li = ((x && flags & 0b10000) || x < 0 ? 1 : 0);
	/**<String length */
	register const U8 rs = 
		((flags & 0b1100) ? (xs + xs/3) : xs) + _li;
	/**<Delimeter */
	register const ch d = (flags & 0b100 ? '.' : (
		flags & 0b1000 ? ',' : 0
	));
				   
	/* If str not provided, allocate it */
	if (!str) str = mal(0, rs+1);
	
	/* Null */
	str[rs] = 0;

	/* Sign */
	if (_li) str[0] = (x<0 ? '-' : '+');

	/* The sign bit shall not be proccessed */
	x = abi(x);

	/* If delimiter is provided */
	if (flags & 0b1100) {
		for (	register I8 i = rs-1, j = 0; 
				i >= _li && j < xs; 
				i--							)
			if (i%4 == 2 + _li) str[i] = d;
			else {
				str[i] = dc(dgu(x, j, b), b);
				j++;
			}
	}
	/* Without delimiters */
	else {
		for (	register I8 i = rs-1, j = 0; 
				i >= _li && j < xs; 
				i--, j++					) {
			str[i] = dc(dgu(x, j, b), b);
		}
	}

	return str;
}