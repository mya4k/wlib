#include <wc/types.h>
#include <wc/types/char.h>

#define S_DEC	0b00	/* Decimal			*/
#define S_BIN	0b01	/* Binary			*/
#define S_OCT	0b10	/* Octal			*/
#define S_HEX	0b11	/* Hexadecimal		*/

/* #define inRange(x, _min, _max) (x >= _min && x <= _max)

inline static bl charInDigitRange(char c, u8 base) {
	if (base <= 10) return inRange(c, '0', '0'-1+base);
	else return inRange(c, '0', '9') || inRange(c, 'A', 'F');
} */

/**
 * @brief	string to u32
 * @fn		u32 sU(char* str, u8 size, u8 flags)
 * 
 * @param	str 
 * @param	size 
 * @param	flags 
 * @return	u32 
 */
u32 sU(char* str, u8 size, u8 flags) {
	if (!str) return 0;
	if (!size) size = sl(str);

	u8 base;
	u32 r;

	/* Determine the base */
	switch (flags & 0b11) {
		case S_DEC: base = 10;	break;
		case S_BIN: base = 2;	break;
		case S_OCT: base = 8;	break;
		case S_HEX: base = 16;	break;
	}

	for (
		u8 i = 0, a = 0, s = 1; 
		i < size; 
		i++, s *= 10;
	)
		if ( (a = cd(str[i],base)) != 255)
			r += (a != 255) * r * s;
}
