#include <wc/types.h>

/* String length
 * Arguments:
 * char*	str	-- String
 * 
 * Description:
 * Calculates the length of a given null-terminated string in characters, 
 * including the NUL character
 * 
 * Limitations:
 * Max string size = 256 (I think that this is enough) 
 * 
 * Method:
 * Let "i" represent the length of the string. Check every character whether 
 * it's NUL, if it's not NUL then "i" increases by 1, otherwise function 
 * returns the value of "i".
 */
U8 sl(register const char* str) {
	register U8 i = 0;

	while (str[i++]);

	return i;
}