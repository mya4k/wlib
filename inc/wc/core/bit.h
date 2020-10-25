#ifndef WC_BIT_H
#define WC_BIT_H

#include <wc/core/types.h>

/* Logical shift left */
inline I32 sl	(I32 x, U8 n);
inline I64 sll	(I32 x, U8 n);

/* Logical shift right */
inline I32 sr	(I32 x, U8 n);
inline I32 srl	(I32 x, U8 n);

/* Arithmetic shift left */
inline I32 sal	(I32 x, U8 n);
inline I32 sall	(I32 x, U8 n);

/* Arithmetic shift right */
#define sa sar
inline I32 sar	(I32 x, U8 n);
inline I32 sarl	(I32 x, U8 n);

/* Rotate bits left */
inline I32 rl	(I32 x, U8 n);
inline I64 rll	(I64 x, U8 n);

/* Rotate bits right */
I32 rr	(I32 x, U8 n);
I64 rrl	(I64 x, U8 n);

#endif