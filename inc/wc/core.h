/********************************
 *  Core development definition *
 *  Mostly for compatibility    *
 *  Wispy (c) 2021              *
 ********************************/
#ifndef WC_CORE_H
#define WC_CORE_H
							/************************/
#include <wc/sys/conf.h>	/* User configuration	*/
#include <wc/sys/stnd.h>	/* C or C++				*/
#include <wc/sys/lang.h>	/* C/C++ version		*/
#include <wc/types.h>		/* Fixed numeric types	*/
							/************************/

/* C and C++ compatibility*/
#if defined(ST_ISO_CPP)
#undef	C_DECL_BEGIN
#define C_DECL_BEGIN	extern "C" {
#undef	C_DECL_END
#define C_DECL_END		}
#else
#define C_DECL_BEGIN
#define C_DECL_END
#endif

/* pre-C89 and post-C89 compatibility */
#if DEF_VOID == 1
#undef	return_void
#define return_void
#else
#undef	return_void
#define return_void return '\000';
#endif

#endif