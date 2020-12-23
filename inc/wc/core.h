#ifndef WC_CORE_H
#define WC_CORE_H

#include <wl/DATA/STND.h>

#if defined(ST_ISO_CPP)
#define C_DECL_BEGIN	extern "C" {
#define C_DECL_END		}
#else
#define C_DECL_BEGIN
#define C_DECL_END
#endif

#endif