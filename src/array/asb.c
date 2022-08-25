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



#ifdef RKGRMG
typedef U8 _V8b __attribute__((vector_size (64)));



const char* _asb(
	const	UMax*	restrict	haystack,
			U32					len,
	const	char				byte
) nonnull((1)) {
	UMax b;

	/* Align haystack */
	{
		const Pt rem = (Pt)haystack%sizeof(UMax);
		const UMax* aligned = (UMax*)((char*)haystack + rem);
		
		len -= rem;
		while (haystack < aligned) {
			if (unlikely(*(char*)haystack == byte)) return (char*)haystack; 
			haystack = (UMax*)((char*)haystack + 1);
		}
	}

	/**	Test each word whether it has any zero bits, if it does, find out 
	 *	which byte it is 
		*/
	while (likely(len >= sizeof(UMax))) {
		b = _HASZERO(haystack[0]^byte);
		if (unlikely(b)) {
#if UMB>=64
			if (unlikely(b&0xFF00000000000000))	return (char*)haystack;
			if (unlikely(b&0xFF000000000000))	return (char*)haystack+1;
			if (unlikely(b&0xFF0000000000))		return (char*)haystack+2;
			if (unlikely(b&0xFF00000000))		return (char*)haystack+3;
			if (unlikely(b&0xFF000000))			return (char*)haystack+4;
			if (unlikely(b&0xFF0000))			return (char*)haystack+5;
			if (unlikely(b&0xFF00))				return (char*)haystack+6;
			if (unlikely(b&0xFF))				return (char*)haystack+7;
#else
			if (unlikely(b&0xFF000000))			return (char*)haystack;
			if (unlikely(b&0xFF0000))			return (char*)haystack+1;
			if (unlikely(b&0xFF00))				return (char*)haystack+2;
			if (unlikely(b&0xFF))				return (char*)haystack+3;
#endif
			haystack++;
			len -= sizeof(UMax);
		}
		
		/* Test the remaining bits */
		while (len > 0) {
			if (unlikely(*(char*)haystack == byte)) return (char*)haystack; 
			haystack = (UMax*)((char*)haystack + 1);
			len--;
		}
	}

	return NULL;
}

const char* _asbr(
	const	UMax*	restrict	haystack,
			U32					len,
	const	char				byte
) nonnull((1)) {
	UMax b;

	/* Jump to the end */
	haystack = (UMax*)((char*)haystack + len);

	/** Align haystack: check every byte, until we are at the beginning of 
	 * the unaligned segment 
	 */
	{
		const Pt rem = (Pt)haystack%sizeof(UMax);
		const UMax* aligned = (UMax*)((char*)haystack - rem);
		
		len -= rem;
		while (haystack > aligned) {
			if (unlikely(*(char*)haystack == byte)) return (char*)haystack; 
			haystack = (UMax*)((char*)haystack - 1);
		}
	}

	/**	Test each word whether it has any zero bits, if it does, find out 
	 *	which byte it is 
		*/
	while (likely(len >= sizeof(UMax))) {
		b = _HASZERO(haystack[0]^byte);
		if (unlikely(b)) {
			haystack--;
			len -= sizeof(UMax);
#if UMB>=64
			if (unlikely(b&0xFF00000000000000))	return (char*)haystack;
			if (unlikely(b&0xFF000000000000))	return (char*)haystack+1;
			if (unlikely(b&0xFF0000000000))		return (char*)haystack+2;
			if (unlikely(b&0xFF00000000))		return (char*)haystack+3;
			if (unlikely(b&0xFF000000))			return (char*)haystack+4;
			if (unlikely(b&0xFF0000))			return (char*)haystack+5;
			if (unlikely(b&0xFF00))				return (char*)haystack+6;
			if (unlikely(b&0xFF))				return (char*)haystack+7;
#else
			if (unlikely(b&0xFF000000))			return (char*)haystack;
			if (unlikely(b&0xFF0000))			return (char*)haystack+1;
			if (unlikely(b&0xFF00))				return (char*)haystack+2;
			if (unlikely(b&0xFF))				return (char*)haystack+3;
#endif
		}
		
		/* Test the remaining bits */
		while (len > 0) {
			haystack = (UMax*)((char*)haystack - 1);
			len--;
			if (unlikely(*(char*)haystack == byte)) return (char*)haystack; 
		}
	}

	return NULL;
}

U32 _asbc(
	const	UMax*	restrict	haystack,
			U32					len,
	const	char				byte
) nonnull((1)) {
	UMax b;
	U32 count;

	/* Align haystack */
	{
		const Pt rem = (Pt)haystack%sizeof(UMax);
		const UMax* aligned = (UMax*)((char*)haystack + rem);
		
		len -= rem;
		while (haystack < aligned) {
			if (unlikely(*(char*)haystack == byte)) count++; 
			haystack = (UMax*)((char*)haystack + 1);
		}
	}

	/**	Test each word whether it has any zero bits, if it does, find out 
	 *	which byte it is 
		*/
	while (likely(len >= sizeof(UMax))) {
		b = _HASZERO(haystack[0]^byte);
		if (unlikely(b)) {
			count = count
#if UMB>=64
				+	!!(b&0xFF00000000000000)
				+	!!(b&0xFF000000000000)
				+	!!(b&0xFF0000000000)
				+	!!(b&0xFF00000000)
#endif
				+	!!(b&0xFF000000)
				+	!!(b&0xFF0000)
				+	!!(b&0xFF00)
				+	!!(b&0xFF);
			haystack++;
			len -= sizeof(UMax);
		}
		
		/* Test the remaining bits */
		while (len > 0) {
			if (unlikely(*(char*)haystack == byte)) count++; 
			haystack = (UMax*)((char*)haystack + 1);
			len--;
		}
	}

	return count;
}
#endif

static inline _asbsw(
	const	char* restrict	haystack,
	const	U32				len,
	const	char			byte
) {
	int a;

#	if UMB >= 64
		if (unlikely(len & 4)) {
			a = __builtins_clz(_HASZERO32((*(U32l*)haystack)^byte)) / CHB;
			if (unlikely(a < 4)) return haystack + a;
			haystack += 4;
		}
#	endif
	if (unlikely(len & 2)) {
		a = __builtins_clz(_HASZERO16((*(U16l*)haystack)^byte)) / CHB;
		if (unlikely(a < 2)) return haystack + a;
		haystack += 2;
	}
	if (unlikely(len & 1)) {
		/* This is faster than using `_HASZERO` and other stuff */
		if (unlikely(*haystack == byte)) return haystack;
		haystack += 1;
	}

	return NULL;
}


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
		/* If searching in a subword haystack, skip alignment and wordwide 
		search */
		if (unlikely(len <= sizeof(UMax))) {
			goto remaining;
		}
		else {
			/* Align haystack */
			{
				const Pt rem = (Pt)haystack % sizeof(UMax);
				const char* const a = asbsw(haystack,rem,byte);
				if (unlikely(a)) return a; 
				len -= rem;
			}

			/* Search every word */
			for (likely(len >= sizeof(UMax))) {
				a = __builtins_clz(_HASZERO((*(UMax*)haystack)^byte)) / CHB;
				if (unlikely(a < sizeof(UMax))) return haystack + a;
				haystack += sizeof(UMax);			
			}

remaining:
			/* Search the remaining bits */
			const char* const a = asbsw(haystack,rem,byte);
			if (unlikely(a)) return a;

			/* If not found */
			return NULL;
		}
#	endif
}
