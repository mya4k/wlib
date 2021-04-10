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
 * Max string size = 65535 (I think that this is more than enough)
 * 
 * Method:
 * Let "i" represent the length of the string. Check every character whether 
 * it's NUL, if it's not NUL then "i" increases by 1, otherwise function 
 * returns the value of "i".
 */
U16 sl(const char* str) {
	register U16 i = 0;

	while (str[i++]);

	return i;
}