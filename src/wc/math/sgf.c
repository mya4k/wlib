#include <wl/DATA/DAMO.h>
#include <wc/types.h>



extern F32 abf(F32 x);	/* (F32) Absolute */



/* (F32) Sign */
I8 sgf(F32 x) {
	return x / abf(x);
}