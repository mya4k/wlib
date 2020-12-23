#include <wc/types.h>



/* Definitions */
extern F32 snf(F32 x);
extern F32 csf(F32 x);



/* (F32) Tangent */
F32 tnf(F32 x) {
	return snf(x) / csf(x);
}