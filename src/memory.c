#include <sys/mman.h>	/* `mmap`			*/
#include <wc/types.h>	/* types			*/
#include <wc/void.h>	/* `return_void`	*/
#include <wc/memory.h>	/*  				*/
#include <unistd.h>		/* sysconf & sbrk	*/
#include <wc/bool.h>	/* TRUE & FALSE		*/
#include <wc/array.h>	/* afl				*/



#ifndef REGION_MACROS
#	define MAL_SMALL_REQUEST	0xFF
#	define MMAP_THRESHOLD		0x100000
#	define DEV_ZERO				(int)-1
#	define ROUND2PAGESIZE(n)	(n/pagesize + (_Bool)(n%pagesize))
#endif



#ifndef REGION_TYPES
typedef struct MChunk {
	Bl	allocated:1;
	Msz	size:(MSZB-1);
	/* The rest is                data */
} MChunk;
#endif



#ifndef REGION_VARS
long pagesize = 0;
#endif



/**
 * \brief	Allocates new pages
 * \fn		static Vo* _new_page(Msz n)
 * \param	n size in bytes
 * \return	Vo* 
 */
static Vo* _new_page(Msz n) {
	/* Ask what page size is from the kernel */
	if (!pagesize) pagesize = sysconf(_SC_PAGESIZE);

	/* If we need to allocate a chunk so big that we need to use `mmap(2)` */
	if (n >= MMAP_THRESHOLD)
		return mmap(	(void*)0,
						n, 
						PROT_READ | PROT_WRITE,
						MAP_PRIVATE | MAP_ANONYMOUS,
						DEV_ZERO,
						0							);
	/* Otherwise just `sbrk(2)` it */
	else {
		/* Exist briefly, I don't think they deserve to utilize memory */
		register Vo* a = sbrk(0);	/* Current break */
		register Vo* b = sbrk(n);	/* New break */
		afl(n, a, 1, 0);
		return b;
	};
}

/**
 * \brief Allocates a new memory chunk in a page
 * \b
 * \param page 
 * \param n 
 * \return Vo* Pointer to the new chunk
 * 
 * 
 */
static Vo* _new_mchunk(Vo* page, const Msz n) {
	const Vo* page_end = (Vo*)((_Ptr)page+pagesize);
	/* Search for any unallocated space in the page */
	for (; page < page_end; ) {
		/* If there's an allocated chuck, jump over it */
		if ( (*(MChunk*)page).allocated )
			page = (Vo*)((_Ptr)page + (_Ptr)(sizeof(MChunk)+(*(MChunk*)page).size));
		/* Otherwise allocate a new chunk */
		else {
			/* If there's not enough space for the chunk*/
			if (((_Ptr)page_end-(_Ptr)page) < (sizeof(MChunk)+n)) return NULL;
			/* Otherwise, make the new chunk */
			(*(MChunk*)page).allocated = TRUE;
			(*(MChunk*)page).size = n;
		}
	}
	return NULL;	/* Looks like the page is full of chunks */
}

static Vo* _delete_mchunk(Vo* page) {

}





/**
 * \brief	Allocates vitrual memory
 * \fn		Vo* mal(Msz n)
 * \param	n	bytes to allocate
 * \return	Vo*
 */
Vo* mal(Msz n) {
	return NULL;
}

/**
 * \brief	Deallocates virtual memory
 * \fn		Vo	mfr(Vo* p, Msz n)
 * \param	p 
 * \param	n 
 * \return	Vo
 */
Vo	mfr(Vo* p, Msz n) {
	if (p) {
		brk( (Vo*)((_Ptr)p-n) );
	}
	return_void;
}