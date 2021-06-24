/**
 * \file	io.h
 * \brief	Character I/O
 * 
 * Content:
 * `wl_out(STR)`	Outputs string to STDOUT
 * `wl_in(STR)`		Inputs string from STDIN
 * 
 * Wispy (c) 2021/06/02
 */

/**
 *	\fn			_StrSize wl_lens(const char* str)
 *	\brief		String length
 *	\arg		str String
 *	\return 	_StrSize
 *	\attention	By default _StrSize is 8-bits, therefore it only supports strings less than 256 characters in length
 */


#ifndef WC_CHAR_H
#define WC_CHAR_H

#include <wc/types.h>	/* Types */

/* Convinient aliases */
#ifndef NO_SHORT_NAMES
#	ifndef	lens
#		define	lens	wl_lens
#	endif
#endif

/* String size type */
typedef U8 _StrSize;

#ifdef USE_STDLIB
	/* String length */
#	define wl_lens(STR)	strlen(STR)
#else
	/* String length */
	extern _StrSize wl_lens(const char* str);
#endif

#endif