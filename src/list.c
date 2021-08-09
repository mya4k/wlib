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
#include <stdlib.h>
#include <wc/bool.h>
#include <wc/array.h>



/**
 * \brief	New List
 * \fn		wl_Ls*	lsn(wl_Lss length,	wl_Lss entrySize)
 * \param	length 
 * \param	entrySize 
 * \return	wl_Ls* 
 */
Ls* wl_lsn(const Lss length, const Lss entrySize, Vo* value) {
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
}