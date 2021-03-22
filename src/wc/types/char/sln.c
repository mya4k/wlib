#include <wc/types.h>

/* String length
 * Arguments:
 * char*	str	-- String
 * 
 * Description:
 * Calculates the length of a given null-terminated string in characters, 
 * including the NUL character
 * 
 * Method:
 * Let "i" represent the length of the string. Check every character whether 
 * it's NUL, if it's not NUL then "i" increases by 1, otherwise function 
 * returns the value of "i".
 */
U32 sln(char* str) {
	U32 i = 1;
	
	while (str[i]) i++;

	return i;
}