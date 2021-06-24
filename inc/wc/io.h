/**
 * \file	io.h
 * \brief	Character I/O
 * 
 * Content:
 * `wl_out(STR)`	Outputs string to STDOUT
 * `wl_in(STR)`		Inputs string from STDIN
 * 
 * Wispy (c) 2021/06/01
 */

/**
 * \def		wl_out(STR)
 * \def		out
 * \brief	Outputs string to STDOUT
 * Defines as `puts(STR)` if C standard library is exploited.
 * 
 * Method:
 * 	1.	Get the length of the string `wl_lens(STR)`.
 * 	2.	Write string to STDOUT using `_wl_out(STR, SIZE)`
 * 		(`_wl_out(STR, SIZE)` is defined as `read(STDIN_FILENO, STR, SIZE)` 
 * 		for UNIX-like systems`).
 */
/**
 * \def		wl_in(STR)
 * \def		in
 * \brief	Inputs string from STDIN
 * 
 */

#ifndef WC_IO_H	/* Make sure the header is only included once */
#define WC_IO_H

#include <wc/sys/osys.h>
#include <wc/types.h>
#include <wc/char.h>

#ifndef NO_SHORT_NAMES
#	ifndef	out
#		define	out		wl_out
#	endif
#	ifndef	in
#		define	in		wl_in
#	endif
#endif

/* If we can use standard C library	*/
#ifdef	USE_STDLIB
#	include <stdio.h>	/* Standard I/O */
#	define wl_out(STR)			puts(STR)
#	define wl_in(STR, MAXSIZE)	fgets(STR, MAXSIZE, stdin)
/* Otherwise */
#else	/* Optimal behavior	*/
/*		If we can use unix system calls */
#	ifdef OS_UNIXLIKE
#		include <unistd.h>
#		define _wl_out(STR, SIZE)	write(STDOUT_FILENO, STR, SIZE)
#		define wl_out(STR)			_wl_out( STR, wl_lens(STR) )
#		define _wl_in(STR, SIZE)	read(STDIN_FILENO, STR, SIZE)
		extern char*	wl_in	(char* str, size_t maxSize);
#	elif defined(OS_WIN)
		/* F*CK WINDOWS */
		extern void	wl_out	(char* str);
#	else
		/* NOT IMPLIMENTED YET */
#	endif
#endif

#endif