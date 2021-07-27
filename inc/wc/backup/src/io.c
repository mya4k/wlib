/**
 * \file	io.h
 * \brief	Character I/O
 * 
 * Defines:
 * `char* wl_in(char* str)`	Inputs string from STDIN
 * 
 * Wispy (c) 2021/06/01
 */

#include <wc/io.h>
#include <wc/types.h>
#include <wc/sys/osys.h>

#ifdef OS_UNIXLIKE
	/*	Get one character from STDIN
		(It's a macro purely for readility's sake)*/
#	undef	_WL_GETC
#	define _WL_GETC(addr)	_wl_in(addr, 1)

	/* Stardard Input */
	char* wl_in(str, maxSize)
		char* str;
		size_t maxSize;
	{
		/* If maxSize is zero, maxSize is 255 */
		if (!maxSize) maxSize = 255;
		
		/*register*/ char c;	/* The received character */
		register char* p = str;

		_WL_GETC(&c); /* Initial input to set off the loop */
		/* While the character is not \n, buffer it, and get the next one, repeat */
		/* To avoid exploitation, the character limit that can be read is limited 255 */
		for (u8 i = 0; c != '\n' && i < maxSize; i++) {
			*p++ = c;
			_WL_GETC(&c);
		}
		/*	Once \n is encountered or the size limit encountered, 
			null-terminate the string and return	*/
		*p++ = '\0';

		return str;
	}
#elif defined(OS_WIN)
#	include <ntifs.h>
#	define stdout (__acrt_iob_func(1))
	
	typedef void* FILE;
	extern FILE* __acrt_iob_func(unsigned _Ix);

	void wl_out(char* str) {
		HANDLE _stdout;

		NtWriteFile(
			_stdout,

		)
	}
#endif