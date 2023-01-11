#include <wl/array.h>



#define _min2(x, y) ((x <= y) ? (x) : (y))



/* Subword Array OR Logical 
 * 
 * Performs OR Logical operation when we need to work on less than word bytes 
 */
Bl _aorlsw(
	const char* restrict arr1,
	const char* restrict arr2,
	const U32 rem
) {
#if UMB >= 64
	if (unlikely(rem&4)) {
		if (unlikely(*(U32*)arr1 || *(U32*)arr2))
			return TRUE;
		arr1 += 4; arr2 += 4;
	}
#endif
	if (unlikely(rem&2)) {
		if (unlikely(*(U16*)arr1 || *(U16*)arr2))
			return TRUE;
		arr1 += 2; arr2 += 2;
	}
	if (unlikely(rem&1)) {
		if (unlikely(*arr1 || *arr2))
			return TRUE;
		arr1++; arr2++;
	}
	return FALSE;
}

/* Array OR Logical */
Bl _aorl(
	const char* restrict arr1,
	const char* restrict arr2,
	U32 len
) {
	/* Align at least one of the pointers */
	/* If neither one of the pointers is aligned */
	if (unlikely((Pt)arr1%sizeof(UMax) && (Pt)arr2%sizeof(UMax))) {
		const Pt rem = _min2((Pt)arr1%sizeof(UMax), (Pt)arr2%sizeof(UMax));
		/* If trueness was found before alignment, return */
		if (unlikely(_aorlsw(arr1,arr2,rem))) return TRUE;
		arr1 += rem; arr2 += rem; len -= rem;
	}

	while (len >= sizeof(UMax)) {
		if (unlikely(*(UMax*)arr1 || *(UMax*)arr2))
			return TRUE;
		arr1 += sizeof(UMax);
		arr2 += sizeof(UMax);
		len -= sizeof(UMax);
	}

	if (unlikely(_aorlsw(arr1,arr2,len))) return TRUE;

	return FALSE;
}
