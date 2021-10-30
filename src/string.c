#include <wc/string.h>

/**
 * \brief	String length
 * \fn		wl_Sl wl_sl(const char* restrict const s)
 * \param	s	Pointer to string
 * \return	wl_Sl
 */
wl_Sl wl_sl(char* restrict const s) {
	/* 1. Creates a varible which will store the pointer to a character of 
	 * string `s`. The parameter `s` is preserved, in order to calculate
	 * the difference in bytes between `s` and `a` at return point.
	 */
	char* a;
	/* 2. Checks each chacaracter, and if a character is NUL, breaks the loop 
	 */
	for (a=s; *a; a++);
	/* 3. Finds the length of the string by subtracting the pointer to the
	 * beginning of the string `s` by the pointer to the NUL character &mdash;
	 * the end of the string `s` &mdash; `a`
	 */
	return a-s;
}
