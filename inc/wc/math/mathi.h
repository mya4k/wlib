#ifndef WC_MATHI_H
#define WC_MATHI_H

#include <wc/core/types.h>

/* Absolute */
extern I32	ab	(I32 x);
extern I64	abl	(I64 x);

/* Logarithms [lg(x,z) = y] */
#define lgu lg
#define lgq lgl
extern U8	lg	(U16 x, U32 z);
extern U8	lgl	(U32 x, U64 z);

/* Power function [pw(x,y) = z] */
extern I32	pw	(I32 x, I8 y);
extern I64	pwl	(I64 x, I8 y);
extern U32	pwu	(U32 x, U8 y);
extern U64	pwq	(U64 x, U8 y);

/* Nth root function [rt(y,z) = x] */
extern U16	rt	(U8 y, U32 z);
extern U32	rtl	(U8 y, U64 z);

#endif