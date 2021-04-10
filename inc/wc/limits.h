#ifndef LIMITS_H
#define LIMITS_H

#define	I8B		8
#define	I16B	16
#define	I32B	32

#define I8N		(I8)	-128
#define I16N	(I16)	-32768
#define I32N	(I32)	-2147483648

#define I8X		(I8)	127
#define I16X	(I16)	32767
#define I32X	(I32)	2147483647

#define U8X		(U8)	0
#define U16X	(U16)	0
#define U32X	(U32)	0

#define U8X		(U8)	-1
#define U16X	(U16)	-1
#define U32X	(U32)	-1

#if NO_I64	/* Abnormal behavior */
#define I64B	32
#define I64N	(I64)	-2147483648
#define I64X	(I64)	2147483647
#define U64N	(U64)	0
#define U64X	(U64)	-1
#else		/* Optimal behavior */
#define I64B	64
#define I64N	(I64)	-9223372036854775808
#define I64X	(I64)	9223372036854775807
#define U64N	(U64)	0
#define U64X	(U64)	-1
#endif		/* NO_I64 */

#endif