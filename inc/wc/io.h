#include <wc/types.h>

/* Convinience macro for _wr: you don't need to think if the pointer of the right type */
#undef	wr
#define	wr(p,d,s) _wr((U32*)p, (U32*)d, s)	/* Write data */

VO _wr(U32* p, U32* d, U32 s);	/* Write data	*/