#include <wc/types.h>
#include <wc/types/char.h>

/**
 * @brief	Char search
 * @fn		const u8 cs(register const char* str, register char find, u8 flags) 
 * 
 * @param str 	String, where the search will happen
 * @param find	Character to find in `str`
 * @return bl 
 */
u8 cs(register const char* str, register char find, u8 flags) {
	register const u8 s = sl(str);
	if (flags&0b1) {
		for (register u8 i = s; i > 0; i--)
			if (str[i] == find) return i;
	}
	else {
		for (register u8 i = 0; i < s; i++)
			if (str[i] == find) return i;
	}
	return SS_NOT_FOUND;
}