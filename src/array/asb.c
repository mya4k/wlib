#include <wl/array.h>
#include <wl/math.h>



#	if UMB>=64
		/* Value of `UMax`, where all individual bytes are `0x01` */
#		define _LOW		0x0101010101010101
		/* Value of `UMax`, where all individual bytes are `0x80` */
#		define _HIGH	0x8080808080808080
#	else
		/* Value of `UMax`, where all individual bytes are `0x01` */
#		define _LOW		0x01010101
		/* Value of `UMax`, where all individual bytes are `0x08` */
#		define _HIGH	0x80808080
#	endif

/* Whether there's a byte that has a value of `0x00` */
#define _HASZERO(X)		(((X)-_LOW) & ~(X) & _HIGH)
#define _HASZERO8(X)	(((X)-((U8l)_LOW)) & ~(X) & ((U8l)_HIGH))
#define _HASZERO16(X)	(((X)-((U16l)_LOW)) & ~(X) & ((U16l)_HIGH))
#define _HASZERO32(X)	(((X)-((U32l)_LOW)) & ~(X) & ((U32l)_HIGH))



static inline const char* _asbsw(
	const	char* restrict	haystack,
	const	U32				len,
	const	char			byte
) {
	int a;

#	if UMB >= 64
		if (unlikely(len & 4)) {
			a = __builtin_clz(_HASZERO32((*(U32l*)haystack)^byte)) / CHB;
			if (unlikely(a < 4)) return (char*)((Pt)haystack + a);
			haystack += 4;
		}
#	endif
	if (unlikely(len & 2)) {
		a = __builtin_clz(_HASZERO16((*(U16l*)haystack)^byte)) / CHB;
		if (unlikely(a < 2)) return (char*)((Pt)haystack + a);
		haystack += 2;
	}
	if (unlikely(len & 1)) {
		/* This is faster than using `_HASZERO` and other stuff */
		if (unlikely(*haystack == byte)) return haystack;
		haystack += 1;
	}

	return NULL;
}



/* Array Search Byte */
const char* _asb(
	const	char* restrict	haystack,
			U32				len,
	const	char			byte
) {
	/* If we are allowed to use functions in `<string.h>`, just call this 
	function through its macro, which will make a call to a libc function. */
#	if WL_C_STRING
		return asb(haystack,len,byte);
#	else
		register Pt a;
		/* If the size of the haystack is less than wordsize, use subword byte search */
		if (unlikely(len > sizeof(UMax))) {
			/* Search till alignment of the haystack */
#			define BYTES_TILL_ALIGNED (sizeof(UMax)-(Pt)haystack%sizeof(UMax))
			a = (Pt)_asbsw(haystack, BYTES_TILL_ALIGNED, byte);
			if (unlikely(a)) return (const char*)a;
			len -= BYTES_TILL_ALIGNED;
			haystack += BYTES_TILL_ALIGNED;
			/* Search words for byte */
			while (len >= sizeof(UMax)) {
				a = __builtin_clz(_HASZERO((*(UMax*)haystack)^byte)) / CHB;
				if (unlikely(a)) return (const char*)((Pt)haystack + a);
				len -= sizeof(UMax);
				haystack += sizeof(UMax);
			}
		}

		/* Search the remaining bits */
		a = (Pt)_asbsw(haystack,len,byte);
		if (unlikely(a)) return (const char*)a;

		/* If not found */
		return NULL;
#	endif
}
