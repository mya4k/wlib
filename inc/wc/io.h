/************************
 * Standard I/O library	*
 * Wispy (c) 2021		*
 ************************/

#ifndef WC_IO_H
#define WC_IO_H

#include <wc/core.h>
#include <wc/file.h>
#include <wc/types.h>

C_DECL_BEGIN

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
static U32 sln(char* str) {
	U32 i = 1;
	
	while (str[i]) i++;

	return i;
}

/* Stardard Input */
VO	in	(char* ptr);

C_DECL_END

/* Write to a buffer from STDIN */
#undef	_in
#define	_in(buf, size)	fr(STDIN_FILENO, buf, size)

/* Write from a buffer to STDOUT */
#undef	_ou
#define	_ou(buf, size)	fw(STDOUT_FILENO, buf, size)
#undef	_out
#define	_out			_ou

/* Stardard Output */
#undef	ou
#define ou(buf)			_ou(buf, sln(buf))
#undef	out
#define out				ou

/* Standard Output but it adds a newline character at the end */
#undef	oul
#define oul(buf)			ou(buf); _ou("\n", 1)
#undef	outl
#define outl				oul

#endif