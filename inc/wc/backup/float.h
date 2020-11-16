#ifndef WC_FLOAT_H
#define WC_FLOAT_H



#include <wc/core/types.h>


#define ROUND_UP	0
#define ROUND_DOWN	1
#define ROUND_KEEP	2

#ifndef ROUND_METHOD
#define ROUND_METHOD ROUND_UP
#endif



typedef BL	_Sgf;	/* Sign of F32 */
typedef I8	_Exf;	/* Exponent of F32 */
typedef I32	_Mtf;	/* Mantissa of F32 */
typedef BL	_Sgd;	/* Sign of F64 */
typedef I16	_Exd;	/* Exponent of F64 */
typedef I64	_Mtd;	/* Mantissa of F64 */

/* Integer Part & Fractioncal Part of F32 */
typedef struct _Dpf { 
	F32 i;	/* Integer Part */
	F32 f;	/* Fractioncal Part */
} _Dpf;

/* Integer Part & Fractioncal Part of F64 */
typedef struct _Dpd { 
	F64 i;	/* Integer Part */
	F64 f;	/* Fractioncal Part */
} _Dpd;

typedef struct _Rqf {
	F32 r;	/* Remainder */
	F32 q;	/* Quotient */
} _Rqf;

typedef struct _Rqd {
	F64 r;	/* Remainder */
	F64 q;	/* Quotient */
} _Rqd;



extern _Exf	f32e	(F32	x);					/* Finds the Exponent of F32 */
extern _Mtf	f32m	(F32	x);					/* Finds the Mantissa of F32 */
extern F32	f32n	(_Sgf	s, _Exf	e, _Mtf	m); /* Constructs F32 */
extern _Sgf	f32s	(F32	x);					/* Finds the Sign of F32 */

extern _Exd	f64e	(F32	x);					/* Finds the Exponent of F64 */
extern _Mtd	f64m	(F32	x);					/* Finds the Mantissa of F64 */
extern F64	f64n	(_Sgd	s, _Exd	e, _Mtd	m); /* Constructs F64 */
extern _Sgd	f64s	(F32	x);					/* Finds the Sign of F64 */


extern _Dpf dpf		(F32	x);					/* Divides F32 to Integer Part & Fractioncal Part */
extern _Dpd dpd		(F32	x);					/* Divides F64 to Integer Part & Fractioncal Part */


extern F32	clf		(F32	x);					/* F32 Ceil */
extern F32	flf		(F32	x);					/* F32 Floor */
extern F32	rof		(F32	x);					/* F32 Round */
extern F32	trf		(F32	x);					/* F32 Truncate */

extern F64	cld		(F64	x);					/* F64 Ceil */
extern F64	fld		(F64	x);					/* F64 Floor */
extern F64	rod		(F64	x);					/* F64 Round */
extern F64	trd		(F64	x);					/* F64 Truncate */


extern F32	mdf		(F32	x, F32	y);			/* F32 Modulo */
extern F64	mdd		(F64	x, F64	y);			/* F64 Modulo */

#endif