#ifndef WC_MATHF_H
#define WC_MATHF_H

#include <wc/types.h>
#include <wc/geo/trig.h>
#include <wc/math/mathf/const.h>
#include <wc/math/mathf/exp.h>

/* Absolute */
#define abs	abd				/* F64 Absolute */

extern F32 abf	(F32 x);	/* F32 Absolute */
extern F64 abd	(F64 x);	/* F64 Absolute */


/* Error function */
#define erff
#define erf
extern F32 eff	(F32 x);	/* F32 Error function */
extern F64 ef	(F64 x);	/* F64 Error function */


/* Gamma function */
extern F32 gmf	(F32 x);	/* F32 Gamma function */
extern F64 gm	(F64 x);	/* F64 Gamma function */


/* Factorial */
extern F32 fcf	(F32 x);
extern F32 pmf	(F32 x);
extern F32 cmf	(F32 x);

extern F64 fcd	(F64 x);
extern F64 pmd	(F64 x);
extern F64 cbd	(F64 x);


/* Fibonacci sequence */
extern F32 fbf	(F32 x);
extern F64 fbd	(F64 x);

#endif