/* <int.h> Functions for  */

#include <wc/core.h>
#include <wc/types.h>



#define digitCount	dci
#define digitCountL	dcl
#define digitGet	dgi
#define digitGetL	dgl
#define digitSet	dsi
#define digitSetL	dsl



C_DECL_BEGIN
/*	Digit count (number, base) */
#define dc dci
extern U8	dcu(U32		x, U16 n);			/* (U32) Digit count (number, base) */
extern U8	dcq(U64		x, U32 n);			/* (U64) Digit count (number, base) */
extern U8	dci(I32		x, U16 n);			/* (I32) Digit count (number, base) */
extern U8	dcl(I64		x, U32 n);			/* (I64) Digit count (number, base) */

/* Get digit (number, base, #digit) */
#define dg dgi
extern U16	dgu(U32		x, U16 n, U8 i);	/* (U32) Get digit (number, base, #digit) */
extern U32	dgq(U64		x, U32 n, U8 i);	/* (U64) Get digit (number, base, #digit) */
extern U16	dgi(I32		x, U16 n, U8 i);	/* (I32) Get digit (number, base, #digit) */
extern U32	dgl(I64		x, U32 n, U8 i);	/* (I64) Get digit (number, base, #digit) */

/* Set digit (number, base, #digit) */
#define ds dsi
extern VO	dsu(U32*	x, U16 n, U8 i);	/* (U32) Set digit (*number, base, #digit) */
extern VO	dsq(U64*	x, U32 n, U8 i);	/* (U64) Set digit (*number, base, #digit) */
extern VO	dsi(I32*	x, U16 n, U8 i);	/* (I32) Set digit (*number, base, #digit) */
extern VO	dsl(I64*	x, U32 n, U8 i);	/* (I64) Set digit (*number, base, #digit) */
C_DECL_END