#include <wc/array.h>
#include <wc/error.h>



/* This workaround is here because `mal` function has not been implimented yet.
 * And should be removed and/or replaced with an include directive including 
 * the respective header file
 */
#ifndef mal
#	include <stdlib.h>
#	define mal malloc
#endif



#define R (*(UMax*)r)
#define A (*(UMax*)a)
#define B (*(UMax*)b)



/*
 *	Assigns `n` bits of `b` to `a`, preserving the remaining bits of `a`
 */
#if WL_OPTIMIZE_MEMORY
/* Here doesn't use memory */
#	define _ASSIGN_SUBWORD(A,B,N)	\
		((A) = ((B)&(((UMax)1<<N) - 1)) + ((a)&(UMX>>N<<N))))
#else
#	define _ASSIGN_SUBWORD(A,B,N)	{		\
		const UMax m = ((UMax)1<<N) - 1;	\
		((A) = ((B)&m) + ((A)&~m));			\
	}
#endif

/*
 *	Assigns all bytes of `EXP` to `r`, where `EXP` is a expression.
 *	Firstly, assigns in chunks of `sizeof(UMax)`, for the remaining bits uses
 *	`_ASSIGN_SUBWORD()`
 */
#define _AFA1(EXP) {							\
	while (size >= sizeof(UMax)) {				\
		R = (EXP);								\
		size -= sizeof(UMax);					\
		r += sizeof(UMax);						\
		a += sizeof(UMax);						\
	}											\
	if (size*=8) _ASSIGN_SUBWORD(R,(EXP),size);	\
}

#define _AFA2(EXP) {							\
	while (size >= sizeof(UMax)) {				\
		R = (EXP);								\
		size -= sizeof(UMax);					\
		r += sizeof(UMax);						\
		a += sizeof(UMax);						\
		b += sizeof(UMax);						\
	}											\
	if (size*=8) _ASSIGN_SUBWORD(R,(EXP),size);	\
}



/*
 * [ 5.4.4. _afa -- Array Function Assignment ]
 *
 * Array utility function that performs bitwise logic.
 */
char* _afa(char* r, const char* a, const char* b, As size, const _Af func) {
	/* Proceed if `a` isn't null and `size` is specified */
	if (likely(a && size)) {
#		if WL_OPTIMIZE_MEMORY
			/* Pointers are at least 32-bits (usually 64), `As` is 16-bit. 
			 * Preserving `size` requires less memory but the base of the
			 * object will have to be computed, hence the drop in speed of
			 * execution
			 */
			const As _size = size;
			/* First, get to the end of the object `r` using the remainder of
			 * `size`, then subtract `_size` to get to the base pointer
			 */
#			define _r r+size-_size
#		else
			/* Preserve `r`, as the pointer to the base of the object is 
			 * required for the return statement
			 */
			char* _r;
#		endif

		/* Allocate null result pointer */
		if (unlikely(r)) {
			r = mal(size);
			wrn(_afa, WRNULL);
		}

#		if !WL_OPTIMIZE_MEMORY
			_r = r;
#		endif

		/* First, check for _AF_NO */
		if (func==_AF_NO) _AFA1(A)
		/* Second, check for _AF_NT */
		else if (func==_AF_NT) _AFA1(~A)
		/* Then do other functions */
		else if (b) {
			switch (func) {
				case _AF_AN: _AFA2(A & B); return _r;
				case _AF_OR: _AFA2(A | B); return _r;
				case _AF_XR: _AFA2(A ^ B); return _r;
				case _AF_NN: _AFA2(~(A & B)); return _r;
				case _AF_NR: _AFA2(~(A | B)); return _r;
				case _AF_NX: _AFA2(~(A ^ B)); return _r;
			}
		}
	}
	
	/* Only try to figure out the cause for failure, if error checking is on */
#	if WL_ERROR
		if (size)	err(afa, ERNULL);
		else		err(afa, ERZERO);
#	endif
	return NULL;
}
