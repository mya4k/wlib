#include <wc/types.h>

extern F32 pwf(F32 x, F32 y);
extern F64 pwd(F64 x, F64 y);

F32 rt2f(F32 z) {
	F32 x0 = 0.0F;
	F32 x1 = 1.0F;
	
	for (;;) {
		x0 = x1;
		if (x0==x1) break;
		x1 = (x1-x0) / 2.0F;
	}
	
	return x1;
}

F64 rt2d(F64 z) {
	F64 x0 = 0.0;
	F64 x1 = 1.0;
	
	for (;;) {
		x0 = x1;
		if (x0==x1) break;
		x1 = (x1-x0) / 2.0;
	}
	
	return x1;
}

F32 rtf	(F32 y, F32 z) {
	return pwf(z, 1.0F/y);
}

F64 rtd	(F64 y, F64 z) {
	return pwd(z, 1.0/y);
}