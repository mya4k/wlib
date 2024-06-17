#include <stdio.h>
#include <wl/config.h>


#undef p
#define p(MACRO)\
	printf("%s = %d\n", #MACRO, MACRO)


int main() {
	p(WL_VERSION);
	p(WL_PREFIX);
	p(WL_C);
	p(WL_CPP);
	p(WL_OPTIMIZE);
	p(WL_LIBC);
	p(WL_LIBCPP);
	p(WL_LIMITS_H);
	p(WL_STDLIB_H);
	p(WL_STRING_H);
	p(WL_STDINT_H);
	p(WL__MINGW_MAC_H);
	p(WL_WORDSIZE);
	p(WL_DATAMODEL);
	p(WL_CLANG);
	p(WL_GCC);
	p(WL_MINGW32);
	p(WL_MINGW64);
	p(WL_MINGW);
	p(WL_GNUC);
	p(WL__BOOL);
	p(WL_BOOL);
	p(WL_MIXED);
	p(WL_LONG_LONG);
	p(WL_RESTRICT);
	p(WL_VA_MACRO);
	p(WL_BUILTIN);
	return 0;
}
