#include <wc/types.h>



/* Macros */
#define RHO			1.57079637050628662109375F	/* (F32) Pho constant (quarter-turn)*/



/* Definitions */
extern F32 snf(F32 x);



/* (F32) Cosine	*/
F32 csf(F32	x) {
	/* cos(x) = sin(x+rho) */
	return snf(x + RHO);
}