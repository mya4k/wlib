/* Include */
#include <wc/types.h>



/* Declaration */
extern F64 pwd	(F64 x, F64 y);
extern F64 rt2d	(F64 y, F64 z);



/* (F64) N-th Root */
F64 rtd(F64 y, F64 z) {
	return pwd(z, 1.0/y);
}