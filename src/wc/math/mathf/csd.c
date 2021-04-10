#include <wc/types.h>



/* Macros */
#define RHO			1.5707963267948965579989817342720925807952880859375	/* (F32) Pho constant (quarter-turn)*/



/* Definitions */
extern F64 snd(F64 x);



/* (F64) Cosine	*/
F64 csd(F64	x) {
	/* cos(x) = sin(x+rho) */
	return snd(x + RHO);
}