#include <wc/types.h>

/*	Get one character from STDIN
	(It's a macro purely for readility's sake)*/
#undef	GET
#define GET(addr)	_in(&c, 1)

/* Stardard Input */
VO in(const char* buf) {
	register char c;	/* The received character */
	register char* p = buf-1;



	GET(&c); /* Initial input to set off the loop */
	/* While the character is not \n, buffer it, and get the next one, repeat */
	while (c != '\n') {
		*p++ = c;
		GET(&c);
	}
	/*	Once \n is encountered [VERY LIKELY], 
		null-terminate the string and return	*/
	*p++ = '\0';
}