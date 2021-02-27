#ifndef WC_CORE_H
#define WC_CORE_H

#include <sys/conf.h>
#include <sys/stnd.h>
#include <sys/lang.h>
#include <wc/types.h>

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