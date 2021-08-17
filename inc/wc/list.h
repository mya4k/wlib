/**
 * \file list.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Array lists
 * \version 0.1
 * \date 2021-07-31
 * 
 * 
 */
#ifndef WC_LIST_H
#define WC_LIST_H



#include <wc/types.h>
#include <wc/core.h>
#include <wc/memory.h>



#ifndef NO_SHORT_NAMES
#define Lss		wl_Lss
#define Lse 	wl_Lse
#define Ls		wl_Ls
#define List	wl_List
#define lsn		wl_lsn
#define lsr		wl_lsr
#define lsw		wl_lsw
#define lsd		wl_lsd
#endif



#ifndef REGION_DEFINES
#define WL_LSSB		24
#define wl_lsd(list)	wl_mfr(list, 0)
#endif



#ifndef REGION_TYPEDEFS
	/**
	 * \brief	wl_Ls size type
	 * \typedef	wl_Lss
	 */
	typedef wl_U64	wl_Lss;
	/**
	 * \brief	wl_Ls entry type
	 * \typedef	wl_Lse
	 * 
	 * 
	 */
	typedef wl_Vo*	wl_Lse;
	/**
	 * \brief	Array list type
	 * \typedef	wl_Ls
	 * \typedef	wl_List
	 */
	typedef struct wl_Ls {
#ifdef OLD_MODEL
		wl_Lss	total:21;		/**< Total size allocated					*/
		wl_Lss	used:21;		/**< Amount of entries						*/
		wl_Lss	entrySize:21;	/**< Size of each entry						*/
		wl_Lss	pt2addr:1;		/**< If set, will point to address of entry	*/
#endif
		wl_U64	length:32;
		wl_U64	entrySize:32;
	} wl_Ls, wl_List;
#endif



EXTERN wl_Ls*	wl_lsn	(const Lss length, const Lss entrySize, Vo* restrict value);	/* Initialize a new wl_Ls	*/
EXTERN wl_Lse	wl_lsr	(wl_Ls* restrict list, wl_Lss index);						/* Read entry from wl_Ls	*/
EXTERN wl_Lse	wl_lsw	(wl_Ls* restrict list, wl_Lss index, wl_Lss value);			/* Write entry to wl_Ls		*/



#endif