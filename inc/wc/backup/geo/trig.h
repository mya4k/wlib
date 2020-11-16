#ifndef WC_TRIG_H
#define WC_TRIG_H

#include <wc/core/types.h>

/* Trigonometric functions */
#define tgf		tanf
#define tg		tan
#define ctgf	cotf
#define ctg		cot
#define tghf	tnhf
#define tgh		tnh
#define ctghf	cthf
#define ctgh	cth
#define atgf	atnf
#define atg		atn
#define actgf	actf
#define actg	act
#define atghf	atnhf
#define atgh	atnh
#define actghf	acthf
#define actgh	acth

extern F32 sinf(F32 x);
extern F64 sin(F64 x);
extern F32 cosf(F32 x);
extern F64 cos(F64 x);
extern F32 tanf(F32 x);
extern F64 tan(F64 x);
extern F32 cotf(F32 x);
extern F64 cot(F64 x);

extern F32 snhf(F32 x);
extern F64 snh(F64 x);
extern F32 cshf(F32 x);
extern F64 csh(F64 x);
extern F32 tnhf(F32 x);
extern F64 tnh(F64 x);
extern F32 cthf(F32 x);
extern F64 cth(F64 x);

extern F32 asnf(F32 x);
extern F64 asn(F64 x);
extern F32 acsf(F32 x);
extern F64 acs(F64 x);
extern F32 atnf(F32 x);
extern F64 atn(F64 x);
extern F32 actf(F32 x);
extern F64 act(F64 x);

extern F32 asnhf(F32 x);
extern F64 asnh(F64 x);
extern F32 acshf(F32 x);
extern F64 acsh(F64 x);
extern F32 atnhf(F32 x);
extern F64 atnh(F64 x);
extern F32 acthf(F32 x);
extern F64 acth(F64 x);

#endif