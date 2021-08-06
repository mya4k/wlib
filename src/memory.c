#include <sys/mman.h>	/* `mmap`			*/
#include <wc/types.h>	/* types			*/
#include <wc/void.h>	/* `return_void`	*/
#include <wc/memory.h>	/*  				*/
#include <unistd.h>		/* sysconf & sbrk	*/
#include <wc/bool.h>	/* TRUE & FALSE		*/



#ifndef REGION_MACROS
#	define MAL_SMALL_REQUEST	0xFF
#	define MMAP_THRESHOLD		0x100000
#	define DEV_ZERO				(int)-1
#	define ROUND2PAGESIZE(n)	((n/pagesize + (_Bool)(n%pagesize)) * pagesize)

#	if PTB == 32
#		define PTR2NEXT_2_PTR(i)	(((MChunk*)(i))->ptr2next < (_Ptr)(i) ? ((MChunk*)(i))->ptr2next & I32N : ((MChunk*)(i))->ptr2next | ((_Ptr)heap&I32N))
#	else
#		define PTR2NEXT_2_PTR(i)	(((MChunk*)(i))->ptr2next < (_Ptr)(i) ? ((MChunk*)(i))->ptr2next & I64N : ((MChunk*)(i))->ptr2next | ((_Ptr)heap&I64N))
#	endif
#endif



#ifndef REGION_TYPES
/**
 * \brief 
 * 
 */
typedef struct MChunk {
	_Ptr	allocated:1;		/* Wether the chunk is allocated */
#ifdef MCHUNK_USE_SIZE
	_Ptr	size:(PTB-1);		/* Size */
#else
	_Ptr	ptr2next:(PTB-1);	/* Pointer to the next chunk */
#endif
	/* The rest is data */
} MChunk;
#endif



#ifndef REGION_VARS
static Vo* heap = NULL;		/* Start of the heap */
static long pagesize = 0;	/* Page size */
#endif



/**
 * \brief	Prepare program for dynamic memory allocation
 * \fn		static Vo _minit()
 * \return	Vo 
 */
static Vo _minit() {
	/* Get the start of the heap */
	heap = sbrk(0);
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
Vo* mal(Msz size) {
start:
	/* Check if ready for dynamic allocation */ 
	if (heap) {
		/* If request has size */
		if (size) {
			/* When allocating memory chunks we also need space for MChunk struct */
			size += sizeof(MChunk);
			/* If normal size */
			if (size < MMAP_THRESHOLD) {
				Vo* heapEnd = sbrk(0);	/**< End of the heap */
				_Ptr sum = 0;	/* Here will be stored summed size of all consequent free chunks */
				_Ptr chunk = 0;	/* Pointer to the first chunk of a group of free chunks */
				_Ptr _ptr2next;
				/* Try finding a group of consequent unallocated MChunk big enough for us */
				for (	
					/* Pointer to current MChunk, starts at the beggining of the heap */
					Vo* i = heap;
					/* Will check all chunks until the end of the heap */
					i < heapEnd;
					/* Move to next chuck if no suitable chunk was found */
					i = (Vo*)_ptr2next
				) {
					_ptr2next = PTR2NEXT_2_PTR(i);
					/*  */
					if (sum < size) {
						/* If the chunk allocated, reset the sum pointer and keep looking*/
						if (((MChunk*)i)->allocated) sum = 0;
						/**/
						else {
							sum += _ptr2next - (_Ptr)i;
							chunk = _ptr2next;
						}
					}
					else {
						heapEnd = ((MChunk*)chunk)->ptr2next;
						goto end;
					};
				}

				/* If no suitable space was found, allocate more memory */
				chunk = sbrk(0);
				heapEnd = sbrk(ROUND2PAGESIZE(size));
end:			sum = chunk + size;
				/*
				 * Create a new memory chunk by slicing a bigger one
				 */
				/* Store the end of the chunk for later */
				/* Set out new chunk as allocated */
				((MChunk*)chunk)->allocated = TRUE;
				/* The pointer is to the next chunk is the pointer to the remaining area of the bigger chunk */
				((MChunk*)chunk)->ptr2next = sum;
				/* The remaining space is turned into another chunk that is unallocated */
				((MChunk*)sum)->allocated = FALSE;
				((MChunk*)sum)->ptr2next = heapEnd;
				return chunk - sizeof(MChunk);
			}

			/* If size is too big, allocate using mmap */
			else {
				return mmap(	(void*)0,
								ROUND2PAGESIZE(size + sizeof(MChunk)), 
								PROT_READ | PROT_WRITE,
								MAP_PRIVATE | MAP_ANONYMOUS,
								DEV_ZERO,
								0										);
			}
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
Vo	mfr(Vo* p) {
	if (p) {
		if (p >= heap && p <= sbrk(0)) {
			((MChunk*)p)->allocated = FALSE;
		}
		else munmap(p, PTR2NEXT_2_PTR(p)-(_Ptr)p);
	}
	return_void;
}