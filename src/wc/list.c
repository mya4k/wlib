#ifdef OLD_CODE
/**
 * \file list.c
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2021-07-31
 * 
 * 
 */
#include <wc/list.h>
#include <wc/memory.h>
#include <wc/bool.h>
#include <wc/array.h>



/**
 * \brief	Round the Msz for 8-byte alignment
 * \def		ROUND2ALLIGN(X)
 */
#define ROUND2ALLIGN(X) 		((X)%8 ? (X) : ((X)+8)&0x8)
/**
 * \brief	Pointer to MChunk
 * \def		ROUND2ALLIGN(X)
 * \param	X	Pointer to List
 * 
 * Pointer to MChunk of an allocated data segment by WLib's implimentation of `wl_mal` and `wl_mfr`.
 */
#define MCHUNKOF(X)				(MChunk*)((X)-sizeof(MChunk))
/**
 * \brief	Pointer to List entries
 * \def		DATAOF(X)
 * \param	X	Pointer to List
 */
#define DATAOF(X)				((X)+8)
/**
 * \brief	The size of memory segment allocated for the List
 * \def		SIZEOFLIST(X)
 * \param	MCH
 */
#define SIZEOFLIST(X)			(PTR2NEXT_2_PTR(MCHUNKOF(X))-MCHUNKOF(X)) 
#define PTR2ENTRY(list,index)	(DATAOF((_Ptr)list)+sizeof(Ls)+(index*list->entrySize))




/**
 * \brief	New List
 * \fn		wl_Ls*	lsn(wl_Lss length,	wl_Lss entrySize)
 * \param	length 
 * \param	entrySize 
 * \return	wl_Ls* 
 */
Ls* wl_lsn(const Lss length, const Lss entrySize, const Vo* restrict value) {
	/* Reserve 50% for possible expansion */
	const Msz size = length*entrySize*1.5;
	/* Allocate the list */
	Ls* r = mal(ROUND2ALLIGN(size));
	/* Define how many entry are used */
	r->length = length;
	/* Size of each entry in bytes */
	r->entrySize = entrySize;
	/* Define value */
	aas(length*entrySize, r+sizeof(Ls), value);
	/* Return the address */
	return r;
}

Lse	wl_lsr	(const Ls* restrict list, const Lss index) {
	const Lse* r = (Lse*)PTR2ENTRY(list,index);
	/* If `index` does not exceed `length` */
	if (index <= list->length) {
		/* If entries are smaller than or equal the biggest interger type */
		if (list->entrySize <= sizeof(Lse))
		/* Return the value of the entry */
		return *(Lse*)r;
		/* Otherwise, return the pointer to the entry */
		return r;
	}
	/* Error */
	else return 0;
}

Lse	wl_lsw	(const Ls* restrict list, const Lss index, const Lse value) {
	Lse* p2e = DATAOF((_Ptr)list)+sizeof(List)+(index*list->entrySize);
	/* If `index` does not exceed `length` */
	if (index <= list->length) {
		return *p2e = value;
	else lse();
}
#endif
/**
 * \file list.c
 * \author Wispy (wspvlv@gmail.com)
 * \brief 
 * \version 0.1
 * \date 2021-08-18
 * 
 * 
 */
#include <wc/list.h>
#include <wc/memory.h>
#include <wc/array.h>

/**
 * \brief	New wl_Ls
 * \fn		Ls*	wl_lsn(const u32 length, const u32 size)
 * \param	length	Initial amount of entries in the list
 * \param	size	Size of a single entry
 * \return	wl_Ls* 
 */
Ls*	wl_lsn(const u32 length, const u32 size) {
	/* Reserve 50% space for future expansion */
	const u32 total = length + length>>1 + length&1;
	/* Allocate the list */
	LsMeta* const restrict r = mal(sizeof(LsMeta) + total*size);
	if (r != NULL) {
		/* Initialize a wl_Ls metadata */
		r->length = length;
#ifndef WLMALLOC
		r->total = total;
#endif
		r->size = size;
		/* Return pointer to wl_Ls */
		return r+sizeof(LsMeta);
	}
	/* Failed to allocated memory */
	return NULL;
}

/**
 * \brief	Ls*	wl_lsw(Ls* const restrict list, const u32 index, const Ls* restrict const value)
 * \param	list	wl_Ls
 * \param	index	entry index
 * \param	value	ptr to value to be written to the entry
 * \return Ls* 
 */
Ls*	wl_lsw(const Ls* const restrict list, const u32 index, const Ls* restrict const value) {
/* 	const LsMeta* meta = LSMETAOF(list);
	if (index > meta->length) return NULL;
#endif
	const Ls* ptr = list + index*meta->size;
	wl_aas(meta->size, ptr, value);
	return ptr; */

	/* Store metadata somewhere */
	const LsMeta* meta = LSMETAOF(list);
	/* Check if we're writing to the existing entries */
	if (index < meta->length) {
		/* Pointer to entry */
		const Ls* entry = list + index*meta->size;
		/* Write to the entry */
		wl_aas(meta->size, entry, value);
		/*  */
		return entry;
	}
	/* Or creating a new one */
	else if (index == meta->length && index < meta->total) {

	}
}

/**
 * \brief 
 * 
 * \param list 
 * \param new_length 
 * \return Ls* 
 */
Ls* wl_lsx(const Ls* const restrict list, const u32 new_length) {
	/* Store metadata somewhere */
	LsMeta* const restrict meta = LSMETAOF(list);

	/* If we extend or shrink but we don't need to reallocate */
#ifdef WLMALLOC
	if (new_length > meta->length && new_length <= meta->total || new_length < meta->length) {
#else
	if (new_length > wl__sizeofmem(list) && new_length <= meta->total || new_length < meta->length) {
#endif
		meta->length = new_length;
	}
	/* If we need to reallocate */
	else {
		/* New pointer to the list */
		Ls* p = wl_lsn(new_length, meta->size);
		/* Populate it */
		wl_aas(meta->length, p, list);
		/* Deallocate the old list */
		wl_mfr(list);
		/* Return the pointer to the new wl_Ls */
		return p;
	}
	/* Nothing to do */
	return list;
}