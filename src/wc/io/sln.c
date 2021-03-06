/********************
 * String length 	*
 * Wispy (c) 2021	*
 ********************/

#include <wc/types.h>	/* For U32 */

typedef U32 _Size;	/* Size type */

/* String length
 * Arguments:
 * char*	str	String
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
_Size sln(char* str) {
	_Size i = 1;
	
	while (str[i]) i++;

	return i;
}