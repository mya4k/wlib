#include <wc/types.h>



/* Definitions */
extern F32 snf(F32 x);
extern F32 csf(F32 x);



/* (F32) Cotangent */
F32 ctf(F32 x) {
	return csf(x) / snf(x);
}