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
#ifdef OLD_MODEL
	/* Reserve 50% of length for possible extention */
	const Lss total = length + length/2 + (length&1);
	const Lss size = total * entrySize + sizeof(Ls);
	/* Allocate list and the entry data */
	Ls* r = mal(size);
	/* Define how many entries are reserved */
	r->total = total;
	/* Define how many entry are used */
	r->used = length;
	/* Size of each entry in bytes */
	r->entrySize = entrySize;
	/* Whether it should return values are adresses of entries */
	if (entrySize >= sizeof(IMax))
		r->pt2addr = TRUE;
	else
		r->pt2addr = FALSE;
	/* Define value */
	aas(length*entrySize, r+sizeof(Ls), value);
	/* Return the address */
	return r;
#endif
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