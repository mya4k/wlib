#ifndef WC_MATHF_H
#define WC_MATHF_H

/* Numeric types */
#include <wc/core/types.h>
/* Trigonometry */
#include <wc/geo/trig.h>

extern const F32 _ef;
extern const F32 emf;
extern const F32 grf;
extern const F32 pif;
extern const F32 tauf;

extern const F64 _e;
extern const F64 em;
extern const F64 gr;
extern const F64 pi;
extern const F64 tau;

/* Absolute */
#define absolute abd
extern F32 abf	(F32 x);
extern F64 abd	(F64 x);

/* Hypotenuse */
#define hypotenuse hy
#define hyd hy
extern F32 hyf(F32 a, F32 b);
extern F64 hy(F64 a, F64 b);

/* Logarithms */
#define logf	lgf
#define log		lgd
extern F32 lgf	(F32 x, F32 z);
extern F64 lgd	(F64 x, F64 z);

/* Power function */
#define powerf	pwf
#define power	pwd
extern F32 pwf	(F32 x, F32 y);
extern F64 pwd	(F64 x, F64 y);

/* Nth root function */
#define rootf	rtf
#define root	rtd
extern F32 rtf	(F32 y, F32 z);
extern F64 rtd	(F64 y, F64 z);

#endif