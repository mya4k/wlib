#ifndef WC_BIT_H
#define WC_BIT_H

#include <wc/types.h>

typedef I8	Bt
typedef I16	Wd
typedef I32	Dw
typedef I64 Qw

/* No operation / Buffer gate */
extern Bt	nob	(Bt	x);
extern Wd	now	(Wd	x);
extern Dw	no	(Dw	x);
extern Qw	noq	(Qw	x);

/* NOT gate */
extern Bt	ntb	(Bt	x);
extern Wd	ntw	(Wd	x);
extern Dw	nt	(Dw	x);
extern Qw	ntq	(Qw	x);

/* AND gate */
extern Bt	anb	(Bt	x, Bt	y);
extern Wd	anw	(Wd	x, Wd	y);
extern Dw	an	(Dw	x, Dw	y);
extern Qw	anq	(Qw	x, Qw	y);

/* OR gate */
extern Bt	orb	(Bt	x, Bt	y);
extern Wd	orw	(Wd	x, Wd	y);
extern Dw	or	(Dw	x, Dw	y);
extern Qw	orq	(Qw	x, Qw	y);

/* NAND gate */
extern Bt	nnb	(Bt	x, Bt	y);
extern Wd	nnw	(Wd	x, Wd	y);
extern Dw	nn	(Dw	x, Dw	y);
extern Qw	nnq	(Qw	x, Qw	y);

/* NOR gate */
extern Bt	nrb	(Bt	x, Bt	y);
extern Wd	nrw	(Wd	x, Wd	y);
extern Dw	nr	(Dw	x, Dw	y);
extern Qw	nrq	(Qw	x, Qw	y);

/* XOR gate */
extern Bt	xrb	(Bt	x, Bt	y);
extern Wd	xrw	(Wd	x, Wd	y);
extern Dw	xr	(Dw	x, Dw	y);
extern Qw	xrq	(Qw	x, Qw	y);

/* XNOR gate */
extern Bt	xnb	(Bt	x, Bt	y);
extern Wd	xnw	(Wd	x, Wd	y);
extern Dw	xn	(Dw	x, Dw	y);
extern Qw	xnq	(Qw	x, Qw	y);

/* Logical shift left */
extern Bt	slb	(Bt x, Bt n);
extern Wd	slw	(Wd x, Bt n);
extern Dw	sl	(Dw x, Bt n);
extern Qw	slq	(Qw x, Bt n);

/* Logical shift right */
extern I32	sr	(I32 x, U8 n);
extern I32	srl	(I32 x, U8 n);

/* Arithmetic shift left */
inline extern I32	sal	(I32 x, U8 n);
inline extern I32	sall	(I32 x, U8 n);

/* Arithmetic shift right */
#define sa sar
inline extern I32	sar	(I32 x, U8 n);
inline extern I32	sarl	(I32 x, U8 n);

/* Rotate bits left */
inline extern I32	rl	(I32 x, U8 n);
inline extern I64	rll	(I64 x, U8 n);

/* Rotate bits right */
extern I32	rr	(I32 x, U8 n);
extern I64	rrl	(I64 x, U8 n);

#endif