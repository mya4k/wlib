#include <stdarg.h>
#include <wl/types.h>



#ifndef likely
#	if __GNUC__
#		define likely __glibc_likely
#	else
#		define likely(cond)	(cond)
#	endif
#endif

#ifndef unlikely
#	if __GNUC__
#		define unlikely __glibc_unlikely
#	else
#		define unlikely(cond)	(cond)
#	endif
#endif


#define max(...) {					\
	_Generic()
	I32 max_[] = { __VA_ARGS__ };	\
	maxa(sizeof(max_[])/sizeof(I32));
}

int main() {
	_Generic(
		25,
		I32:	maxa	
	)
	I32 max_[] = { 25, 52 };
	maxa(sizeof(max_)/sizeof(I32), max_);
}



I32 maxv(const U32 count, ...) {
	I32 rmax = WL_I32N; /* Maximal value */
	I32 carg; /* Current arg */
	U32 i;

	va_list arg;
	va_start(arg, count);

	for (i = 0; i < count; i++) {
		carg = va_arg(arg, I32);
		rmax = unlikely(carg>rmax) ? carg : rmax;
	}

	va_end(arg);

	return rmax;
}

I32 maxa(const U32 count, I32 val[]) {
	I32 rmax = WL_I32N;
	
	for (; val<val+count; val++) {
		rmax = unlikely(*val>rmax) ? *val : rmax;
	}

	return rmax;
}
