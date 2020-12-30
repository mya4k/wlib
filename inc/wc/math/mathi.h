#ifndef WC_MATHI_H
#define WC_MATHI_H



/* Includes */
#include <wc/core.h>	/* Compatibility */
#include <wc/types.h>	/* Numeric types */



/* Declaration */
C_DECL_BEGIN
/* Absolute */
#define ab	abi					/* (I32) Absolute		*/
extern I32	abi(I32 x);			/* (I32) Absolute		*/
extern I64	abl(I64 x);			/* (I64) Absolute		*/

/* Factorial */
#define fc	fcu					/* (U32) Factorial		*/
#define fci fcu					/* (U32) Factorial		*/
#define fcl	fcq					/* (U64) Factorial		*/
extern U32	fcu(U8	x);			/* (U32) Factorial		*/
extern U64	fcq(U8	x);			/* (U64) Factorial		*/

/* Logarithms */
#define lg	lgu					/* (U32) Logarithm		*/
#define lgi	lgu					/* (U32) Logarithm		*/
#define lgl	lgq					/* (U64) Logarithm		*/
extern U16	lgu(U8	x, U32	y);	/* (U32) Logarithm		*/
extern U32	lgq(U8	x, U64	y);	/* (U64) Logarithm		*/

/* Power */
#define pw	pwi					/* (U32) Power			*/
extern U32	pwu(U16	x, U8	y);	/* (U32) Power			*/
extern U64	pwq(U32	x, U8	y);	/* (U64) Power			*/
extern I32	pwi(U16	x, U8	y);	/* (I32) Power			*/
extern I64	pwl(U32	x, U8	y);	/* (I64) Power			*/

/* Root */
#define rt	rtu					/* (U32) Square Root	*/
#define rti rtu					/* (U32) Square Root	*/
#define rtl	rtq					/* (U64) Square Root	*/
#define sr	rtu					/* (U32) Square Root	*/
#define sri	rtu					/* (U32) Square Root	*/
#define srl rtq					/* (U64) Square Root	*/
#define sru	rtu					/* (U32) Square Root	*/
#define srq rtq					/* (U64) Square Root	*/
extern U16	rtu(U32 z);			/* (U32) Square Root	*/
extern U32	rtq(U64	z);			/* (U64) Square Root	*/

/* Sign */
#define sg	sgi
extern I8	sgi(I32 x);			/* (I32) Sign			*/
extern I8	sgl(I32 x);			/* (I32) Sign			*/
C_DECL_END

#endif