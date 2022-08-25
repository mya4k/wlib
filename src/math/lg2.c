#include <wl/math.h>



U8 _lg2q(const U64 z) {
#	if !WL_BUILTIN_CLZ
		return lg2q(z);
#	else
		U64 s = I64LX;
		U64 r = U64B - 1;

		for (; unlikely(s != 0); r--, s>>=1)
			if (unlikely(z&s)) return r;

		return -1;
#	endif
}

U8 _lg2u(const U32 z) {
#	if !WL_BUILTIN_CLZ
		return lg2u(z);
#	else
		U32 s = I32LX;
		U32 r = U32B - 1;

		for (; unlikely(s != 0); r--, s>>=1)
			if (unlikely(z&s)) return r;

		return -1;
#	endif
}

U8 _lg2h(const U16 z) {
#	if !WL_BUILTIN_CLZ
		return lg2h(z);
#	else
		U16 s = I16LX;
		U16 r = U16B - 1;

		for (; unlikely(s != 0); r--, s>>=1)
			if (unlikely(z&s)) return r;

		return -1;
#	endif
}

U8 _lg2b(const U8 z) {
#	if !WL_BUILTIN_CLZ
		return lg2b(z);
#	else
		U8 s = I8LX;
		U8 r = U8B - 1;

		for (; unlikely(s != 0); r--, s>>=1)
			if (unlikely(z&s)) return r;

		return -1;
#	endif
}
