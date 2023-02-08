#ifndef WL_STRING_H
#define WL_STRING_H



#include <wl/core.h>



#if !WL_PREFIX
#	define sl		wl_sl

#endif



/* String length */
extern wl_U16 wl_sl(const char* restrict const string);



#endif
