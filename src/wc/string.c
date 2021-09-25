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
#include <wc/char.h>
#include <wc/string.h>
#include <wc/error.h>



#if defined(USE_STDLIB) && !defined(WL_IMP_SL)
#else
	/**
	 *	\fn			wl_Sl wl_sl(const char* str)
	*	\brief		String length
	*	\arg		str String
	*	\return 	_StrSize
	*	\attention	By default _StrSize is 2 bytes
	*	Method:
	*	1. i = 0; (Get a varible)
	*	2. while (str[i] != CH_NUL) i = i+1; (Check every character and incriment the `i` until the character is null)
	*	3. return i; (Return the length of the string)
	*/
	wl_Sl wl_sl(const char* restrict const str) {
		const char* a = str;
		for (; *a; a++);
		return a-str;
	}
#endif

/**
 * \brief	String to U32
 * \fn		wl_U32	wl_s2u(const char* restrict const str, const wl_U8 flags)
 * \param	str		String
 * \param	flags	Flags
 * \return	wl_U32 
 * 
 * Converts a string to U32 integer. Will terminate if a non-digit character is found
 * 
 * 	0.	If configured to use STDLIB, return `strtoul(str)` immidietly if decimal flag is set
 * 	1.	Proccess base flags
 * 	2.	Make sure the string doesn't store a number too long to convert (sets EXCSTR error in that case)
 * 	3.	Convert the string accordingly to the base flag
 * 	4.	Return
 */
wl_U32	wl_s2u(const char* restrict const _str, const WL_S2_FLAGS flags) {
#ifdef USE_STDLIB
#	include <stdlib.h>
	if (!flags&0x3) return WL_STDLIB_S2U(str);
#endif
	
	U32 r = 0;
	/* Store the length of the string */
	const Sl s = sl(_str);
	char* const str = aas(s+1,NULL,(char*)_str);
	Sl i = 0;

	/* Figure out the base */
	switch (flags&0x3) {
		/* Binary */
		case WL_S2_BIN: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 32) {
				wl_err(EXCSTR);
				return U32X;
			}

			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && (str[i]&0xFE) == '0'; i++) {
				r *= 2;
				r += c2d(str[i]);
			}
			break;
		}
		/* Octal */
		case WL_S2_OCT: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 11) {
				wl_err(EXCSTR);
				return U32X;
			}
			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && str[i]>='0' && str[i]<='7'; i++) {
				r *= 8;
				r += c2d(str[i]);
			}
			break;
		}
		/* Decimal */
		case WL_S2_DEC:
		default: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 10) {
				wl_err(EXCSTR);
				return U32X;
			}
			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && cid(str[i]); i++) {
				r *= 10;
				r += c2d(str[i]);
			}
			break;
		}
		/* Hexadecimal */
		case WL_S2_HEX: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 8) {
				wl_err(EXCSTR);
				return U32X;
			}
			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && str[i]>='0' && str[i]<='F'; i++) {
				r *= 16;
				r += c2d(c2u(str[i]));
			}
			break;
		}
	}

	mfr(str);

	return r;
}

/**
 * \brief	String to U64
 * \fn		wl_U64	wl_s2q(const char* restrict const str, const wl_U8 flags)
 * \param	str		String
 * \param	flags	Flags
 * \return	wl_U64 
 * 
 * Converts a string to U64 integer. Will terminate if a non-digit character is found
 * 
 * 	0.	If configured to use STDLIB, return `atoi(str)` immidietly if decimal flag is set
 * 	1.	Proccess base flags
 * 	2.	Make sure the string doesn't store a number too long to convert (sets EXCSTR error in that case)
 * 	3.	Convert the string accordingly to the base flag
 * 	4.	Return
 */
wl_U64	wl_s2q(const char* restrict const _str, const WL_S2_FLAGS flags) {
#ifdef USE_STDLIB
#	include <stdlib.h>
	if (!flags&0x3) return WL_STDLIB_S2Q(str);
#endif
	
	U32 r = 0;

	/* Store the length of the string */
	const Sl s = sl(_str);
	char* const str = aas(s,NULL,(char*)_str);
	Sl i = 0;

	/* Figure out the base */
	switch (flags&0x3) {
		/* Binary */
		case WL_S2_BIN: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 64) {
				wl_err(EXCSTR);
				return U32X;
			}

			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && (str[i]&0xFE) == '0'; i++) {
				r *= 2;
				r += c2d(str[i]);
			}
			break;
		}
		/* Octal */
		case WL_S2_OCT: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 22) {
				wl_err(EXCSTR);
				return U32X;
			}
			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && str[i]>='0' && str[i]<='7'; i++) {
				r *= 8;
				r += c2d(str[i]);
			}
			break;
		}
		/* Decimal */
		case WL_S2_DEC:
		default: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 20) {
				wl_err(EXCSTR);
				return U32X;
			}
			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && cid(str[i]); i++) {
				r *= 10;
				r += c2d(str[i]);
			}
			break;
		}
		/* Hexadecimal */
		case WL_S2_HEX: {
			/* Check if the string is too big to fit the number into I32 */
			if (s > 16) {
				wl_err(EXCSTR);
				return U32X;
			}
			/* Convert every character to a digit, and return on first found non-digit */
			for (; i<=s && str[i]>='0' && str[i]<='F'; i++) {
				r *= 16;
				r += c2d(c2u(str[i]));
			}
			break;
		}
	}

	return r;
}
