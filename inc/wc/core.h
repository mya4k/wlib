#ifndef WC_CORE_H
#define WC_CORE_H

#include <wl/DATA/STND.h>
#include <wl/DATA/LANG.h>


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
#if LG_C <= VR_C89
#undef	return_void
#define return_void return '\000';
#else
#undef	return_void
#define return_void
#endif

#endif