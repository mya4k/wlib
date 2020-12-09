#include <wc/types.h>

extern F32 pwf(F32 x, F32 y);
extern F64 pwd(F64 x, F64 y);

F32 hyf(F32 x, F32 y) {
	return rtf(2, pw2f());
}