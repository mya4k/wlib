#ifndef WC_LIST_H
#define WC_LIST_H



#include <wc/core.h>
#include <wc/types.h>



#ifndef NO_SHORT_NAMES
#define LsMeta	wl_LsMeta
#define Ls		wl_Ls
#endif


/**
 * \brief	Pointer to meta struct of wl_Ls
 * \param	X	Pointer to wl_Ls
 * \return	wl_LsMeta
 */
#define LSMETAOF(X)			((wl_LsMeta*)((wl__Ptr)(X)-sizeof(wl_LsMeta)))
	/**
	 * \brief		Read entry from wl_Ls
	 * \def			wl_lsr(list, index)
	 * \param		list	wl_Ls
	 * \param		index	entry index
	 * \return		Vo*		pointer to the entry
	 */
#	define wl_lsr(list, index)						\
	(	index<length 								\
		? (list + (index * LSMETAOF(list)->size))	\
		: NULL										\
	)





/**
 * \brief	Meta List
 * \struct	wl_LsMeta
 * \typedef	wl_LsMeta
 * 
 * Contains information about a List
 */
typedef struct wl_LsMeta {
#ifndef WLMALLOC
	/* Different libraries use different implimentations for dynamic memory 
	 * allocation. Assuming all of them define memory chunks, where the
	 * size of the allocated segment is stored, relative to the memory
	 * segment pointer, is "implimentation-defined"; therefore, we will
	 * create a feild which will store that size. To keep this struct
	 * only 8-bytes long, all the fields are cut to 21 bits. We think that
	 * 2,097,152 possible entries all of them containing up to 2,097,152
	 * bytes of data is more than sufficient. If for some reason you need
	 * more, use our own implimentation of `wl_mal` and `wl_fre`
	 */
	wl_u64 total:21;	/* Amount of declared entries		*/
	wl_u64 length:21;	/* Amount of defined entries		*/
	wl_u64 size:21;		/* Size of a single entry in bytes	*/
#elif
	wl_u32 length;		/* Amount of defined entries		*/
	wl_u32 size;		/* Size of a single entry in bytes	*/
#endif
} wl_LsMeta;

/**
 * \brief	List
 * \typedef	wl_Ls
 * 
 * List AKA extendable-size array
 */
typedef _Ptr wl_Ls;



/* New wl_Ls */
EXTERN wl_Ls*	wl_lsn(const wl_u32 length, const wl_u32 size);
/* Write an entry to wl_Ls */
EXTERN wl_Ls*	wl_lsw(const wl_Ls* const restrict list, const wl_u32 index, const wl_Ls* restrict const value);



#endif