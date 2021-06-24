#include <wc/types.h>

/* String length */
u8 wl_lens(const char* str) {
	register u8 i = 0;	/**<! The length of a string */
	/* Incriment `i` until a null-character is captured */
	while (str[i++]);
	return i;
}