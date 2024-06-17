#ifndef WL_DYNAMIC_H



#include <wl/types.h>
#include <wl/core.h>
#include <wl/memory.h>



#if !WL_PREFIX
#	define Da	wl_Da
#	define dam	wl_dam
#	define dad	wl_dam
#	define dal	wl_dal
#	define daa	wl_daa

#	define _dal	wl_daa
#	define _dra	wl_dra
#	define _daa	wl_daa
#endif



typedef struct wl_Da {
	wl_U64l allocated;	/* Overall memory allocated in bytes */
	wl_U32l elmSize;
	wl_U32l elmCount;
} wl_Da;



/**
 * \brief 	Dynamic Array Metadata
 * \def		dap(ptr)
 * \param	ptr	Pointer to Dynamic array data
 * \return	Pointer to the struct holding metadata of the Dinamic array 
 */
#define wl_dam(ptr) (wl_Da*)((wl_Pt)(ptr)-(sizeof(Da)))

#define wl_dad(ptr)	(void*)((wl_Pt)(ptr)+(sizeof(Da)))

#define wl_dal(elmSize, elmCount)			wl__dal(wl__dal((elmSize), (elmCount)))
#define wl_dra(array, elmCount)				wl__dra(wl__dra(wl_dam(array), (elmCount)))
#define wl_daa(array, appendData, count)	wl__daa(wl__dra(wl_dam(array), (void*)(appendData), count))



void* wl__dal(const wl_U32 elmSize, const wl_U32 elmCount);
void* wl__dra(void* meta, const wl_U32 elmCount);
void* wl__daa(wl_Da* meta, void* appendData, const wl_U32 count);



#endif
