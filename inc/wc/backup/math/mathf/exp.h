#ifndef WC_EXP_H
#define WC_EXP_H

#include <wc/core/types.h>

/* Logarithm */
#define logf		lgd			/* F32 Logarithm */
#define log2f		lgbd		/* F32 Binary Logarithm */
#define log10f		lgcd		/* F32 Common Logarithm */
#define logef		lgnd		/* F32 Natural Logarithm */
#define lnf			lgnd		/* F32 Natural Logarithm */
#define log			lgd			/* F64 Logarithm */
#define log2		lgbd		/* F64 Binary Logarithm */
#define log10		lgcd		/* F64 Common Logarithm */
#define loge		lgnd		/* F64 Natural Logarithm */
#define ln			lgnd		/* F64 Natural Logarithm */

extern	F32	lgf	(F32 x, F32 z);	/* F32 Logarithm */
extern	F32 lgbf(F32 z);		/* F32 Binary Logarithm */
extern	F32 lgcf(F32 z);		/* F32 Common Logarithm */
extern	F32 lgnf(F32 z);		/* F32 Natural Logarithm */

extern	F64	lgd	(F64 x, F64 z);	/* F64 Logarithm */
extern	F64 lgbd(F64 z);		/* F64 Binary Logarithm */
extern	F64 lgcd(F64 z);		/* F64 Common Logarithm */
extern	F64 lgnd(F64 z);		/* F64 Natural Logarithm */


/* Power */
#define powerf		pwd			/* F32 Exponentiation */
#define expf		pwd			/* F32 Exponentiation */
#define exp2f		pwbd		/* F32 Binary Exponentiation */
#define exp10f		pwcd		/* F32 Common Exponentiation */
#define expef		pwnd		/* F32 Natural Exponentiation */
#define power		pwd			/* F64 Exponentiation */
#define exp			pwd			/* F64 Exponentiation */
#define exp2		pwbd		/* F64 Binary Exponentiation */
#define exp10		pwcd		/* F64 Common Exponentiation */
#define expe		pwnd		/* F64 Natural Exponentiation */

extern	F32	pwf	(F32 x, F32 y);	/* F32 Exponentiation */
extern	F32	pwbf(F32 y);		/* F32 Binary Exponentiation */
extern	F32	pwcf(F32 y);		/* F32 Common Exponentiation */
extern	F32	pwnf(F32 y);		/* F32 Natural Exponentiation */

extern	F64	pwd	(F64 x, F64 y);	/* F64 Exponentiation */
extern	F64	pwbd(F64 y);		/* F64 Binary Exponentiation */
extern	F64	pwcd(F64 y);		/* F64 Common Exponentiation */
extern	F64	pwnd(F64 y);		/* F64 Natural Exponentiation */


/* Root */
#define rootf		rtd			/* F32 Root */
#define root2f		srtd		/* F32 Square root */
#define root3f		crtd		/* F32 Cube root */
#define sqrtf		srtd		/* F32 Square root */
#define cbrtf		crtd		/* F32 Cube root */
#define root		rtd			/* F64 Root */
#define root2		srtd		/* F64 Square root */
#define root3		crtd		/* F64 Cube root */
#define sqrt		srtd		/* F64 Square root */
#define cbrt		crtd		/* F64 Cube root */

extern	F32	rtf	(F32 y, F32 z);	/* F32 Root */
extern	F32 srtf(F32 z);		/* F32 Square root */
extern	F32 crtf(F32 z);		/* F32 Cube root */

extern	F64	rtd	(F64 y, F64 z);	/* F64 Root */
extern	F64 srtd(F64 z);		/* F64 Square root*/
extern	F64 crtd(F64 z);		/* F64 Cube root */

/* Hypotenuse */
#define hypotenusef	hyf			/* F32 Hypotenuse */
#define hypotenuse	hy			/* F64 Hypotenuse */
#define hyd			hy			/* F64 Hypotenuse */

extern	F32	hyf	(F32 a, F32 b);	/* F64 Hypotenuse */
extern	F64	hy	(F64 a, F64 b);	/* F64 Hypotenuse */

/* Extra */
#if defined(EXP_EXTRA)

/* log(z) with float base as a base */
#define logbf		lfbf
#define logb		lfb
#define lfbd		lfb

extern	F32 lfbf(F32 z);
extern	F64 lfb	(F64 z);


/* Integral part of log(z) with float base as a base */
#define logbif		lbif
#define logbi		lbi
#define lfid		lbi

extern	F32 lfif(F32 z);
extern	F64 lfi	(F64 z);


/* Natural Exponent - 1 */
#define ee1f		pe1f
#define ee1			pe1
#define pe1d		pe1

extern	F32 pe1f(F32 y);
extern	F64 pe1	(F64 y);


/* Float base ^ y * x */
#define eflf		pfmf
#define efl			pfm
#define pfld		pfm
#define efmf		pfmf
#define efm			pfm
#define pfmd		pfm

extern	F32 pfmf(F32 x, I32 y);
extern	F64 pfm	(F64 x, I32 y);
extern	F32 pflf(F32 x, I64 y);
extern	F64 pfl	(F64 x, I64 y);

#endif	/* Extra */