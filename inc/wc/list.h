#ifndef WC_LIST_H
#define WC_LIST_H



#include <wc/types.h>



/**
 * \brief Meta List
 * \
 */
typedef struct wl_LsMeta {
	wl_u32 length;	/* Length of the list in entries	*/
	wl_u32 size;	/* Size of a single entry in bytes	*/
} wl_LsMeta;



#endif