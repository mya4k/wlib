/************************
 * Standard I/O library	*
 * Wispy (c) 2021		*
 ************************/

#ifndef WC_IO_H
#define WC_IO_H

#include <wc/core.h>
#include <wc/file.h>
#include <wc/types.h>
#include <wc/types/char.h>

/* Write to a buffer from STDIN */
#undef	_in
#define	_in(buf, size)	fr(STDIN_FILENO, buf, size)

VO in(/*const*/ char* buf);

/* Write from a buffer to STDOUT */
#undef	_ou
#define	_ou(buf, size)	fw(STDOUT_FILENO, buf, size)
#undef	_out
#define	_out			_ou

/* Stardard Output */
#undef	ou
#define ou(buf)			_ou(buf, sl(buf))
#undef	out
#define out				ou

/* Standard Output but it adds a newline character at the end */
#undef	oul
#define oul(buf)			ou(buf); _ou("\n", 1)
#undef	outl
#define outl				oul

#endif
