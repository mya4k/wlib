#include <wl/math.h>
#include <wl/variadic.h>

#define _smaux(X)\
	U##X smau##X(U8 count, const U##X* restrict const addends) {\
		U##X s = 0;\
		\
		while (count) {\
			s += addends[count--];\
		}\
	\
		return s;\
	}

#define _smvux(X)\
	U##X smvu##X(U8 count, ...) {\
		Va va;\
		U##X s = 0;\
		\
		vi(va, count);\
		\
		while (count) {\
			s += vn(va, U##X);\
			count--;\
		}\
		\
		return s;\
	}

_smaux(8);
_smaux(16);
_smaux(32);
_smaux(64);
/* _smvux(8);
_smvux(16); */
_smvux(32);
_smvux(64);
