#ifdef TO_BE_CONTINUED
#include <wc/types.h>



/* Flags */
#define S_DEC	0b00	/* Decimal			*/
#define S_BIN	0b01	/* Binary			*/
#define S_OCT	0b10	/* Octal			*/
#define S_HEX	0b11	/* Hexadecimal		*/
#define S_COMMA	0b100	/* Comma delimeters	*/
#define S_DOT	0b1000	/* Dot delimeters	*/
#define S_PLUS	0b10000 /* Plus sign */



/**
 * @brief	F32 to string
 * @fn		char* fS(f32 n, u8 flags)
 * @param	n 
 * @param	flags 
 * @return	char* 
 */
char* fS(f32 n, u8 flags) {
	/* Base */
	U8 b;

	switch (flags & 0b11) {
		case S_BIN:	b = 2;	break;
		case S_OCT: b = 8;	break;
		case S_DEC: b = 10; break;
		case S_HEX:	b = 16;	break;
		default:	b = 10;	break;
	}

	
}
#endif