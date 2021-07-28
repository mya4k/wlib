/**
 * \file char.c
 * \author Wispy (wspvlv@gmail.com)
 * \brief Definitions for finctions declared in <wc/char.h>
 * \version 0.1
 * \date 2021-06-29
 * 
 * 
 */
#include <wc/types.h>
#include <wc/char.h>	/* <- _Lens */



/**
 *	\fn			_StrSize wl_lens(const char* str)
 *	\brief		String length
 *	\arg		str String
 *	\return 	_StrSize
 *	\attention	By default _StrSize is 8-bits, therefore it only supports strings less than 256 characters in length
 *	Method:
 *	1. i = 0; (Get a varible)
 *	2. while (str[i] != CH_NUL) i = i+1; (Check every character and incriment the `i` until the character is null)
 *	3. return i; (Return the length of the string)
 */
Lens wl_lens(const char* str) {
	register wl_StrSize i = 0;	/**< The length of a string */
	/* Incriment `i` until a null-character is captured */
	while (str[i++]);
	return i;
}