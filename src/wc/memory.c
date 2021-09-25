/**
 * \file	memory.c
 * \author	Wispy (wspvlv@gmail.com)
 * \brief	Dynamic memory allocation interface for Unix-like systems
 * \version 0.1
 * \date	2021-08-07
 * 
 * This is a very minimalistic 
 */
#include <wc/sys/osys.h>
#ifdef OS_UNIXLIKE



#include <sys/mman.h>	/* `mmap`			*/
#include <sys/param.h>	/* `BSD` if exists	*/
#include <wc/types.h>	/* types			*/
#include <wc/void.h>	/* `return_void`	*/
#include <wc/memory.h>	/*  				*/
#include <unistd.h>		/* sysconf & sbrk	*/
#include <wc/bool.h>	/* TRUE & FALSE		*/



/* Allow allocating with mmap */
#if defined(BSD) && BSD <= 199006
#define USE_MMAP FALSE
#else
#define USE_MMAP TRUE
#endif

/* Allow allocating with sbrk */
#if _BSD_SOURCE || _SVID_SOURCE || 											\
	(_XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED) &&	\
    !(_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) || !USE_MMAP ||	\
	__GNUC__
#define USE_BRK	TRUE
#else
#define USE_BRK FALSE
#endif


#ifndef REGION_MACROS
#	define MAL_SMALL_REQUEST	0xFF
#	define MMAP_THRESHOLD		0x100000
#	define ROUND2PAGESIZE(n)	((n/pagesize + (_Bool)(n%pagesize)) * pagesize)

#	ifndef MAP_ANONYMOUS
#		define MAP_ANONYMOUS 0
#	endif
#endif



#ifndef REGION_VARS
static Vo*	heap = NULL;	/* Start of the heap */
static long	pagesize = 0;	/* Page size */
static int	dev_zero = -1;	/* File descriptor for /dev/zero */
#endif



/**
 * \brief	Prepare program for dynamic memory allocation
 * \fn		static Vo _minit()
 * \return	Vo 
 */
static Vo _minit() {
#if USE_BRK
	/* Get the start of the heap */
	heap = sbrk(0);
#endif
	/* Get the page size */
	pagesize = sysconf(_SC_PAGESIZE);
}



/**
 * \brief	Allocates vitrual memory
 * \fn		Vo* mal(Msz size)
 * \param	size	bytes to allocate
 * \return	Vo*
 * \attention Requires `_minit()`
 * 
 */
Vo* wl_mal(Msz size) {
start:
	/* Check if ready for dynamic allocation */ 
	if (pagesize) {
		/* If request has size */
		if (size) {
			/* When allocating memory chunks we also need space for MChunk 
			 * struct 
			 */
			size += sizeof(MChunk);
#			if USE_BRK == TRUE
			/* If normal size */
			if (size < MMAP_THRESHOLD) {
				Vo* heapEnd = sbrk(0);	/**< End of the heap */
				/* Here will be stored summed size of all consequent free 
				 * chunks 
				 */
				_Ptr sum = 0;	
				/* Pointer to the first chunk of a group of free chunks */
				_Ptr chunk = 0;
				_Ptr _ptr2next;
				/* Try finding a group of consequent unallocated MChunk big 
				 * enough for us 
				 */
				for (	
					/* Pointer to current MChunk, starts at the beggining of 
					 * the heap 
					 */
					Vo* i = heap;
					/* Will check all chunks until the end of the heap */
					i < heapEnd;
					/* Move to next chuck if no suitable chunk was found */
					i = (Vo*)_ptr2next
				) {
					_ptr2next = PTR2NEXT_2_PTR(i);
					/*  */
					if (sum < size) {
						/* If the chunk allocated, reset the sum pointer and 
						 * keep looking 
						 */
						if (((MChunk*)i)->allocated) sum = 0;
						/**/
						else {
							sum += _ptr2next - (_Ptr)i;
							chunk = _ptr2next;
						}
					}
					else {
						heapEnd = (Vo*)PTR2NEXT_2_PTR(chunk);
						goto end;
					};
				}

				/* If no suitable space was found, allocate more memory */
				chunk = (_Ptr)sbrk(0);
				sbrk(ROUND2PAGESIZE(size));
				heapEnd = sbrk(0);

end:			sum = chunk + size;
				/*
				 * Create a new memory chunk by slicing a bigger one
				 */
				/* Store the end of the chunk for later */
				/* Set out new chunk as allocated */
				((MChunk*)chunk)->allocated = TRUE;
				/* The pointer is to the next chunk is the pointer to the 
				 * remaining area of the bigger chunk 
				 */
				((MChunk*)chunk)->ptr2next = sum;
				/* The remaining space is turned into another chunk that is 
				 * unallocated 
				 */
				((MChunk*)sum)->allocated = FALSE;
				((MChunk*)sum)->ptr2next = (_Ptr)heapEnd;

				return (Vo*)(chunk + sizeof(MChunk));
			}
			/* If size is too big, allocate using mmap */
			else {
				return mmap(	(void*)0,
								ROUND2PAGESIZE(size + sizeof(MChunk)), 
								PROT_READ | PROT_WRITE,
								MAP_PRIVATE | MAP_ANONYMOUS,
								dev_zero,
								0										);
			}
#			else
			return mmap(	(void*)0,
							ROUND2PAGESIZE(size + sizeof(MChunk)), 
							PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANONYMOUS,
							dev_zero,
							0										);
#			endif
		}
		/* If size = 0 */
		else return NULL;
	}
	/* Otherwise, prepare the program and start over this function call */ 
	else {
		_minit();
		goto start;
	}
}

/**
 * \brief	Deallocates virtual memory
 * \fn		Vo	mfr(Vo* p, Msz n)
 * \param	p 
 * \return	Vo
 */
Vo	wl_mfr(Vo* p) {
	if (p) {
#		if USE_BRK
		if (p >= heap && p <= sbrk(0)) {
			((MChunk*)((_Ptr)p-sizeof(MChunk)))->allocated = FALSE;
		}
		else munmap(p, PTR2NEXT_2_PTR(p)-(_Ptr)p);
#		else
		munmap(p, PTR2NEXT_2_PTR(p)-(_Ptr)p);
#		endif
	}
	return_void;
}

/**
 * \brief	Size of an allocated memory segment
 * \fn		Msz wl__sizeofmem(Vo* ptr)
 * \param	ptr 
 * \return	Msz 
 */
Msz wl__sizeofmem(Vo* ptr) {
	_Ptr m = (_Ptr)MCHUNKOF(ptr);
	return PTR2NEXT_2_PTR(m) - m - sizeof(wl_MChunk);
}



#endif
