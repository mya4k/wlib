#ifndef WC_CORE_H
#define WC_CORE_H



#include <wc/sys/lang.h>



#ifdef VR_CPP
/* Extern compatibility */
#	ifndef EXTERN
#		define EXTERN		extern "C"
#	endif
/* Beginning of a set of external definitions */
#	ifndef C_DECL_BEGIN
#		define C_DECL_BEGIN	EXTERN {
#	endif
/* End of a set of external definitions */
#	ifndef C_DECL_END
#		define C_DECL_END	}
#	endif
#else
/* Extern compatibility */
#	ifndef EXTERN
#		define EXTERN		extern
#	endif
/* Beginning of a set of external definitions */
#	ifndef C_DECL_BEGIN
#		define C_DECL_BEGIN
#	endif
/* End of a set of external definitions */
#	ifndef C_DECL_END
#		define C_DECL_END
#	endif
#endif



#endif
