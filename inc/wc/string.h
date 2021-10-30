#ifndef WC_STRING_H
#define WC_STRING_H



#include <wc/core.h>
#include <wc/types.h>



#ifndef WL_NO_SHORT_NAMES
#	define Sl		wl_Sl
#	define sl		wl_sl
#endif

#ifndef WL_NO_ALIASES
#	define wl_Lens			wl_Sl
#	define wl_Strlen		wl_Sl
#	define wl_StringLength	wl_Sl
#	define wl_lens			wl_sl
#	define wl_strlen		wl_sl
#	define wl_stringLength	wl_Sl
#endif



/**
 * \brief 
 * 
 */
typedef wl_U16 wl_Sl;



/* String length */
EXTERN wl_Sl wl_sl(char* restrict const s);



#endif
