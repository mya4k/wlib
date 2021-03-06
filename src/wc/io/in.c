/********************
 * Stanard Input 	*
 * Wispy (c) 2021	*
 ********************/

#include <io.h>		/* For _in */

#define _SIZE 64	/* Segment size */

typedef U32 _Size;	/* Size type */

/* Standard Input */
VO in(char*	ptr) {
	for (_Size i = 0;; i += _SIZE) {
		_in(ptr+i, _SIZE);
		if (ptr[i] == '\n') {
			ptr[i] = '\000';
			break;
		}
	}

	return_void;
}