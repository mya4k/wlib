#include <wl/math.h>
#include <wl/variadic.h>


U8 smab(U8 count, const U8* restrict const addends) {
	U8 s = 0;
	
	while (count) {
		s += addends[count--];
	}

	return s;
}

U16 smaw(U8 count, const U16* restrict const addends) {
	U16 s = 0;
	
	while (count) {
		s += addends[count--];
	}

	return s;
}

U32 smau(U8 count, const U32* restrict const addends) {
	U32 s = 0;
	
	while (count) {
		s += addends[count--];
	}

	return s;
}

U64 smaq(U8 count, const U64* restrict const addends) {
	U64 s = 0;
	
	while (count) {
		s += addends[count--];
	}

	return s;
}

U8 smvb(U8 count, ...) {
	Va va;
	U8 s = 0;

	vi(va, count);

	while (count) {
		s += vn(va, U8);
		count--;
	}

	return s;
}

U16 smvw(U8 count, ...) {
	Va va;
	U16 s = 0;

	vi(va, count);

	while (count) {
		s += vn(va, U16);
		count--;
	}

	return s;
}

U32 smvu(U8 count, ...) {
	Va va;
	U32 s = 0;

	vi(va, count);

	while (count) {
		s += vn(va, U32);
		count--;
	}

	return s;
}

U64 smvq(U8 count, ...) {
	Va va;
	U64 s = 0;

	vi(va, count);

	while (count) {
		s += vn(va, U64);
		count--;
	}

	return s;
}
