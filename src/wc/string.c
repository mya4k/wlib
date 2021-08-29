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
#include <wc/logic.h>
#include <wc/string.h>


#if defined(USE_STDLIB) && !defined(WL_IMP_SL)
#else
	/**
	 * \brief	Offset of the byte filled with zeros if exists
	 * \def		ZEROBYTELOC(X)
	 * \param	X
	 */
#	if NO_I64 == TRUE
#		define ZEROBYTELOC(X) (		\
			NOL((X)&0xFF000000)	+	\
			2*NOL((X)&0xFF0000)	+	\
			3*NOL((X)&0xFF00)	+	\
			4*NOL((X)&0xFF)			\
		)
#	else
#		define ZEROBYTELOC(X)	(			\
			NOL((X)&0xFF00000000000000)	+	\
			2*NOL((X)&0xFF000000000000)	+	\
			3*NOL((X)&0xFF0000000000)	+	\
			4*NOL((X)&0xFF00000000)		+	\
			5*NOL((X)&0xFF000000)		+	\
			6*NOL((X)&0xFF0000)			+	\
			7*NOL((X)&0xFF00)			+	\
			8*NOL((X)&0xFF)					\
		)
#	endif
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
	wl_Sl wl_sl(char* str) {
		U8 i = 0;
	#if	NO_I64 == TRUE
		for (; (i = ZEROBYTELOC(*(U32*)str)); str+=4);
	#else
		for (; (i = ZEROBYTELOC(*(U64*)str)); str+=8);
	#endif
		return str+i;
	}


#endif