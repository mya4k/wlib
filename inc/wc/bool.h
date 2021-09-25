/**
 * \file bool.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Boolean values
 * \version 1.0
 * \date 2021-07-27
 * Content:
 * 	Macros:
 * 		bool[1]
 *		WL_TRUE		True
 *		WL_FALSE	False
 * [1] Only for C;
 */
#ifndef WC_BOOL_H
#define WC_BOOL_H



#include <wc/types.h>
#include <wc/logic.h>



#ifndef NO_SHORT_NAMES
#	ifndef FALSE
#	define FALSE	WL_FALSE
#	endif
#	ifndef TRUE
#	define TRUE		WL_TRUE
#	endif
#	if defined(LG_C)
#		ifndef bool
#			define bool		_Bool
#		endif
#	endif
#endif



/**
 * \brief	False
 * \def		WL_FALSE
 */
#define WL_FALSE	0
/**
 * \brief	True
 * \def		WL_TRUE
 */
#define WL_TRUE		1



#endif
