/* Include */
#include <wc/types.h>



/* Declaration */
extern F32 pwf	(F32 x, F32 y);
extern F32 rt2f	(F32 y, F32 z);



/* (F32) N-th Root */
F32 rtf	(F32 y, F32 z) {
	return pwf(z, 1.0F/y);
}