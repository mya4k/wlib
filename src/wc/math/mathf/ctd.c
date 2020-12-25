#include <wc/types.h>



/* Definitions */
extern F64 snd(F64 x);
extern F64 csd(F64 x);



/* (F64) Tangent */
F64 ctd(F64 x) {
	return csd(x) / snd(x);
}