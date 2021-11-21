#include <wc/array.h>



#if !defined(WL_MAL_IMPLIMENTED) || !defined(mal)
#	include <stdlib.h>
#	define mal malloc
#endif



/**
 * \brief	
 * \fn		static void _af1(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b 
 * \param	c 
 * \param	func wl_Af value
 */
static void _af1(
	const void* restrict const	a,
	const void* restrict const	b,
	const void* restrict const	c,
	const Af					func
) {
	switch (func) {
	case WL_AF_NT: *((U8*)a) = ~*((U8*)a); break;

	case WL_AF_AN: *((U8*)a) &= *((U8*)b); break;
	case WL_AF_OR: *((U8*)a) |= *((U8*)b); break;
	case WL_AF_XR: *((U8*)a) ^= *((U8*)b); break;
	case WL_AF_NN: *((U8*)a) = ~(*((U8*)a) & *((U8*)b)); break;
	case WL_AF_NR: *((U8*)a) = ~(*((U8*)a) | *((U8*)b)); break;
	case WL_AF_NX: *((U8*)a) = ~(*((U8*)a) ^ *((U8*)b)); break;
	
	case WL_AF_NOA: *((U8*)a) = *((U8*)b); break;
	case WL_AF_ANA: *((U8*)a) = *((U8*)b) & *((U8*)c); break;
	case WL_AF_ORA: *((U8*)a) = *((U8*)b) | *((U8*)c); break;
	case WL_AF_XRA: *((U8*)a) = *((U8*)b) ^ *((U8*)c); break;
	case WL_AF_NNA: *((U8*)a) = ~(*((U8*)b) & *((U8*)c)); break;
	case WL_AF_NRA: *((U8*)a) = ~(*((U8*)b) | *((U8*)c)); break;
	case WL_AF_NXA: *((U8*)a) = ~(*((U8*)b) ^ *((U8*)c)); break;

	default: break;
	}
}

/**
 * \brief	
 * \fn		static void _af2(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b 
 * \param	c 
 * \param	func wl_Af value
 */
static void _af2(
	const void* restrict const	a,
	const void* restrict const	b,
	const void* restrict const	c,
	const Af					func
) {
	switch (func) {
	case WL_AF_NT: *((U16*)a) = ~*((U16*)a); break;

	case WL_AF_AN: *((U16*)a) &= *((U16*)b); break;
	case WL_AF_OR: *((U16*)a) |= *((U16*)b); break;
	case WL_AF_XR: *((U16*)a) ^= *((U16*)b); break;
	case WL_AF_NN: *((U16*)a) = ~(*((U16*)a) & *((U16*)b)); break;
	case WL_AF_NR: *((U16*)a) = ~(*((U16*)a) | *((U16*)b)); break;
	case WL_AF_NX: *((U16*)a) = ~(*((U16*)a) ^ *((U16*)b)); break;
	case WL_AF_NOA: *((U16*)a) = *((U16*)b); break;

	case WL_AF_ANA: *((U16*)a) = *((U16*)b) & *((U16*)c); break;
	case WL_AF_ORA: *((U16*)a) = *((U16*)b) | *((U16*)c); break;
	case WL_AF_XRA: *((U16*)a) = *((U16*)b) ^ *((U16*)c); break;
	case WL_AF_NNA: *((U16*)a) = ~(*((U16*)b) & *((U16*)c)); break;
	case WL_AF_NRA: *((U16*)a) = ~(*((U16*)b) | *((U16*)c)); break;
	case WL_AF_NXA: *((U16*)a) = ~(*((U16*)b) ^ *((U16*)c)); break;

	default: break;
	}
}

/**
 * \brief	
 * \fn		static void _af4(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b 
 * \param	c 
 * \param	func wl_Af value
 */
static void _af4(
	const void* restrict const	a,
	const void* restrict const	b,
	const void* restrict const	c,
	const Af					func
) {
	switch (func) {
	case WL_AF_NT: *((U32*)a) = ~*((U32*)a); break;

	case WL_AF_AN: *((U32*)a) &= *((U32*)b); break;
	case WL_AF_OR: *((U32*)a) |= *((U32*)b); break;
	case WL_AF_XR: *((U32*)a) ^= *((U32*)b); break;
	case WL_AF_NN: *((U32*)a) = ~(*((U32*)a) & *((U32*)b)); break;
	case WL_AF_NR: *((U32*)a) = ~(*((U32*)a) | *((U32*)b)); break;
	case WL_AF_NX: *((U32*)a) = ~(*((U32*)a) ^ *((U32*)b)); break;
	case WL_AF_NOA: *((U32*)a) = *((U32*)b); break;

	case WL_AF_ANA: *((U32*)a) = *((U32*)b) & *((U32*)c); break;
	case WL_AF_ORA: *((U32*)a) = *((U32*)b) | *((U32*)c); break;
	case WL_AF_XRA: *((U32*)a) = *((U32*)b) ^ *((U32*)c); break;
	case WL_AF_NNA: *((U32*)a) = ~(*((U32*)b) & *((U32*)c)); break;
	case WL_AF_NRA: *((U32*)a) = ~(*((U32*)b) | *((U32*)c)); break;
	case WL_AF_NXA: *((U32*)a) = ~(*((U32*)b) ^ *((U32*)c)); break;

	default: break;
	}
}

/**
 * \brief	
 * \fn		static void _af8(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b 
 * \param	c 
 * \param	func wl_Af value
 */
static void _af8(
	const void* restrict const	a,
	const void* restrict const	b,
	const void* restrict const	c,
	const Af					func
) {
	switch (func) {
	case WL_AF_NT: *((U64*)a) = ~*((U64*)a); break;

	case WL_AF_AN: *((U64*)a) &= *((U64*)b); break;
	case WL_AF_OR: *((U64*)a) |= *((U64*)b); break;
	case WL_AF_XR: *((U64*)a) ^= *((U64*)b); break;
	case WL_AF_NN: *((U64*)a) = ~(*((U64*)a) & *((U64*)b)); break;
	case WL_AF_NR: *((U64*)a) = ~(*((U64*)a) | *((U64*)b)); break;
	case WL_AF_NX: *((U64*)a) = ~(*((U64*)a) ^ *((U64*)b)); break;
	case WL_AF_NOA: *((U64*)a) = *((U64*)b); break;

	case WL_AF_ANA: *((U64*)a) = *((U64*)b) & *((U64*)c); break;
	case WL_AF_ORA: *((U64*)a) = *((U64*)b) | *((U64*)c); break;
	case WL_AF_XRA: *((U64*)a) = *((U64*)b) ^ *((U64*)c); break;
	case WL_AF_NNA: *((U64*)a) = ~(*((U64*)b) & *((U64*)c)); break;
	case WL_AF_NRA: *((U64*)a) = ~(*((U64*)b) | *((U64*)c)); break;
	case WL_AF_NXA: *((U64*)a) = ~(*((U64*)b) ^ *((U64*)c)); break;

	default: break;
	}
}

/**
 * \brief	
 * \fn		static void _af1b(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b 
 * \param	func wl_Af value
 */
static Bl _af1b(
	const void* restrict const	a,
	const void* restrict const	b,
	const Af					func
) {
	switch (func) {
	case WL_AF_NOL: return !!*((U8*)a);
	case WL_AF_NTL: return !*((U8*)a);

	case WL_AF_ANL: return *((U8*)a) && *((U8*)b);
	case WL_AF_ORL: return *((U8*)a) || *((U8*)b);
	case WL_AF_XRL: return	(*((U8*)a) && !*((U8*)b)) || 
							(!*((U8*)a) && *((U8*)b));
	case WL_AF_NNL: return !(*((U8*)a) && *((U8*)b));
	case WL_AF_NRL: return !(*((U8*)a) || *((U8*)b));
	case WL_AF_NXL: return	(*((U8*)a) && *((U8*)b)) || 
							(!*((U8*)a) && !*((U8*)b));

	default: return FALSE;
	}
}

/**
 * \brief	
 * \fn		static void _af2b(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b
 * \param	func wl_Af value
 */
static Bl _af2b(
	const void* restrict const	a,
	const void* restrict const	b,
	const Af					func
) {
	switch (func) {
	case WL_AF_NOL: return !!*((U16*)a);
	case WL_AF_NTL: return !*((U16*)a);

	case WL_AF_ANL: return *((U16*)a) && *((U16*)b);
	case WL_AF_ORL: return *((U16*)a) || *((U16*)b);
	case WL_AF_XRL: return	(*((U16*)a) && !*((U16*)b)) || 
							(!*((U16*)a) && *((U16*)b));
	case WL_AF_NNL: return !(*((U16*)a) && *((U16*)b));
	case WL_AF_NRL: return !(*((U16*)a) || *((U16*)b));
	case WL_AF_NXL: return	(*((U16*)a) && *((U16*)b)) || 
							(!*((U16*)a) && !*((U16*)b));

	default: return FALSE;
	}
}

/**
 * \brief	
 * \fn		static void _af4b(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b 
 * \param	func wl_Af value
 */
static Bl _af4b(
	const void* restrict const	a,
	const void* restrict const	b,
	const Af					func
) {
	switch (func) {
	case WL_AF_NOL: return !!*((U32*)a);
	case WL_AF_NTL: return !*((U32*)a);

	case WL_AF_ANL: return *((U32*)a) && *((U32*)b);
	case WL_AF_ORL: return *((U32*)a) || *((U32*)b);
	case WL_AF_XRL: return	(*((U32*)a) && !*((U32*)b)) || 
							(!*((U32*)a) && *((U32*)b));
	case WL_AF_NNL: return !(*((U32*)a) && *((U32*)b));
	case WL_AF_NRL: return !(*((U32*)a) || *((U32*)b));
	case WL_AF_NXL: return	(*((U32*)a) && *((U32*)b)) || 
							(!*((U32*)a) && !*((U32*)b));

	default: return FALSE;
	}
}

/**
 * \brief	
 * \fn		static void _af8b(
				const void* restrict const a,
				const void* restrict const b,
				const void* restrict const c,
				const Af func
			)
 * \param	a 
 * \param	b
 * \param	func wl_Af value
 */
static Bl _af8b(
	const void* restrict const	a,
	const void* restrict const	b,
	const Af					func
) {
	switch (func) {
	case WL_AF_NOL: return !!*((U64*)a);
	case WL_AF_NTL: return !*((U64*)a);

	case WL_AF_ANL: return *((U64*)a) && *((U64*)b);
	case WL_AF_ORL: return *((U64*)a) || *((U64*)b);
	case WL_AF_XRL: return	(*((U64*)a) && !*((U64*)b)) || 
							(!*((U64*)a) && *((U64*)b));
	case WL_AF_NNL: return !(*((U64*)a) && *((U64*)b));
	case WL_AF_NRL: return !(*((U64*)a) || *((U64*)b));
	case WL_AF_NXL: return	(*((U64*)a) && *((U64*)b)) || 
							(!*((U64*)a) && !*((U64*)b));

	default: return FALSE;
	}
}



/**
 * \brief Array Function Assign
 * 
 * \param a 
 * \param b 
 * \param c
 * \param func
 * \param size 
 * \return const void* 
 */
const void* afa(
	const void* restrict		a,
	const void* restrict const	b,
	const void* restrict const	c,
	const Af					func,
	const As					size
) {
	/* 1. Create a variable that will keep the pointer increment value. */
	As i = 0;

	if (!a) a = mal(size);

#	ifndef WL_AFA_SIMPLE
#		if IMB >= 64
			/* 2. The widest type is 8 bytes. Apply FUNC to every 8 bytes of 
			 * `a` and `b`, until there are less than 8 bytes left in the array
			 * `a` or `b`.
			 */
			for (; i < (size&-8); i+=8) _af8(
				(const void* const)((Pt)a+i),
				(const void* const)((Pt)b+i),
				(const void* const)((Pt)c+i),
				func
			);

			/* 3. If there are less than 8 bytes remaining, we can apply FUNC 
			 * on them in 3 steps.
			 * 	-	if more than or equal 2 bytes remaining, apply FUNC to 2
			 * 		bytes;
			 * 	-	after previous step, if more than 2 bytes remaining, apply
			 * 		FUNC to 2 bytes;
			 * 	-	after previous step, if there's a byte remaining, apply 
			 * 		FUNC to the last byte;
			 */
			if (size&4) { 
				_af4(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					(const void* const)((Pt)c+i),
					func
				); 
				i+=4; 
			}
			if (size&2) { 
				_af2(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					(const void* const)((Pt)c+i),
					func
				); 
				i+=2; 
			}
			if (size&1) { 
				_af1(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					(const void* const)((Pt)c+i),
					func
				); 
				i+=1; 
			}
#		else
			/* 2. The widest type is 4 bytes. Apply FUNC to every 4 bytes of 
			 * `a` and `b`, until there are less than 4 bytes left in the array
			 * `a` or `b`.
			 */
			for (; i < (size&-4); i+=4) _af4(
				(const void* const)((Pt)a+i),
				(const void* const)((Pt)b+i),
				(const void* const)((Pt)c+i),
				func
			);

			/* 3. If there are less than 4 bytes remaining, we can apply FUNC 
			 * on them in 2 steps.
			 * 	-	after previous step, if more than or equal 2 bytes 
			 * 		remaining, apply FUNC to 2 bytes;
			 * 	-	after previous step, if there's a byte remaining, apply 
			 * 		FUNC to the last byte;
			 */
			if (size&2) { 
				_af2(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					(const void* const)((Pt)c+i),
					func
				); 
				i+=2; 
			}
			if (size&1) { 
				_af1(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					(const void* const)((Pt)c+i),
					func
				); 
				i+=1; 
			}
#		endif
#	else
		/* 2. Apply FUNC to every byte of `a` and `b` */
		for (; i < size; i++) _af1(
			(const void* const)((Pt)a+i),
			(const void* const)((Pt)b+i),
			(const void* const)((Pt)c+i),
			func
		);
#	endif
		return a;
}

/**
 * \brief Array Function Boolean
 * \param a 
 * \param b 
 * \param func 
 * \param size 
 * \return Bl 
 */
Bl afb(
	const void* restrict const	a,
	const void* restrict const	b,
	const Af					func,
	const As					size
) {
	/* 1. Create a variable that will keep the pointer increment value. */
	As i = 0;

#	ifndef WL_AFB_SIMPLE
#		if IMB >= 64
			/* 2. The widest type is 8 bytes. Apply FUNC to every 8 bytes of 
			 * `a` and `b`, until there are less than 8 bytes left in the array
			 * `a` or `b`.
			 */
			for (; i < (size&-8); i+=8) 
				if (_af8b(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					func
				)) return FALSE;

			/* 3. If there are less than 8 bytes remaining, we can apply FUNC 
			 * on them in 3 steps.
			 * 	-	if more than or equal 2 bytes remaining, apply FUNC to 2
			 * 		bytes;
			 * 	-	after previous step, if more than 2 bytes remaining, apply
			 * 		FUNC to 2 bytes;
			 * 	-	after previous step, if there's a byte remaining, apply 
			 * 		FUNC to the last byte;
			 */
			if (size&4) { 
				if (_af4b(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					func
				)) return FALSE; 
				i+=4; 
			}
			if (size&2) { 
				if (_af2b(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					func
				)) return FALSE; 
				i+=2; 
			}
			if (size&1) { 
				if (_af1b(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					func
				)) return FALSE; 
				i+=1; 
			}
#		else
			/* 2. The widest type is 4 bytes. Apply FUNC to every 4 bytes of 
			 * `a` and `b`, until there are less than 4 bytes left in the array
			 * `a` or `b`.
			 */
			for (; i < (size&-4); i+=4) 
				if (_af4b(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					func
				)) return FALSE;

			/* 3. If there are less than 4 bytes remaining, we can apply FUNC 
			 * on them in 2 steps.
			 * 	-	after previous step, if more than or equal 2 bytes 
			 * 		remaining, apply FUNC to 2 bytes;
			 * 	-	after previous step, if there's a byte remaining, apply 
			 * 		FUNC to the last byte;
			 */
			if (size&2) { 
				if (_af2b(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					func
				)) return FALSE; 
				i+=2; 
			}
			if (size&1) { 
				if (_af1b(
					(const void* const)((Pt)a+i),
					(const void* const)((Pt)b+i),
					func
				)) return FALSE; 
				i+=1; 
			}
#		endif
#	else
		/* 2. Apply FUNC to every byte of `a` and `b` */
		for (; i < size; i++) 
			if (_af1b(
				(const void* const)((Pt)a+i),
				(const void* const)((Pt)b+i),
				func)
			) return FALSE;
#	endif
		return TRUE;
}

/**
 * \brief Array Fill 
 * \fn	const void* afl(
 *		const void* restrict const a,
 *		const As sa,
 *		const void* restrict const b,
 *		const As sb
 *	)
 * \param a		array to be filled
 * \param sa	size of `*a` in bytes
 * \param b		array to fill with
 * \param sb	size of `*b` in bytes
 * \returns const void*
 * 
 * Repeatedly fills `*a` with `*b`
 * # Rules
 * `a` != `NULL`
 * `b` != `NULL`
 * `sa` > 0
 * # Special case
 * If `sb` = 0, returns `a` but does nothing.
 */
const void* afl(
	const void* restrict const	a,
	const As					sa,
	const void* restrict const	b,
	const As					sb
) {
	/* 1. Check that `a` and `b` are valid pointers, and that `sa` > 0 */
	if (a && b && sa) {
		/* 2. Check that `sb` is more than zero */
		if (sb) {
			const As d = sa-(sa%sb);

			/* 3. Assign `sb` bytes of `*b` to `*a`, until there's less than
			 * `sb` bytes remaining unassigned
			 */
			As i = 0;
			for (i = 0; i<d; i+=sb) aas((Vo*)((Pt)a+i), b, sb);
			
			/* 4. Assign the remaining bytes */
			aas((Vo*)((Pt)a+i), b, sa-d);
		}
		/* If `sb` is zero, do nothing */

		return a;
	}
	/* Otherwise just return NULL */
	return NULL;
}

#if UMB>=64
/* Value of `UMax`, where all individual bytes are `0x01` */
#	define _LOW		0x0101010101010101
/* Value of `UMax`, where all individual bytes are `0x80` */
#	define _HIGH	0x8080808080808080
#else
/* Value of `UMax`, where all individual bytes are `0x01` */
#	define _LOW		0x01010101
/* Value of `UMax`, where all individual bytes are `0x08` */
#	define _HIGH	0x80808080
#endif
/* Whether there's a byte that has a value of `0x00` */
#define _HASZERO(X)  (((X)-_LOW) & ~(X) & _HIGH)
/**
 * \brief 
 * 
 * \param a 
 * \param sa 
 * \param b 
 * \param flags 
 * \return Pt 
 */
Pt asb(
	const void* restrict const	a,
	As							sa,
	const char					b,
	const Asf					flags
) {
	/* If `a` is not NULL and `sa` > 0 */
	if (a && sa) {
		const char* p;
		/* If WL_ASF_COUNT is set */
		if (flags&4) {
			As c = 0;	/* Counter */
			// 	/* Cycles the entire array byte by byte */
			// 	for (i = 0; i < sa; i++)
			// 		/* If the character is a match, increment */
			// 		if (((char*)a)[i] == b)
			// 			c++;
			// 	/* Returns the count */
			// 	return c;
			p = a;
#			if !WL_ASB_SIMPLE
				/* Do match finding until `c` is at the next alignment */
				for (; (Pt)p&(sizeof(UMax)-1) && sa; p++, sa--) {
					if (*(char*)p == b) c++;
				}

				const char m = b*_LOW;
				for ( ; sa>=sizeof(UMax); ) {
					if (_HASZERO(*p^m)) {
						const char* const q = p+8;
						for (; p<q; p++, sa--) {
							if (*p==b) c++;
						}
					}
					else {
						p+=sizeof(UMax);
						sa-=sizeof(UMax);
					}
				}
#			endif
			/* Loops until a match is found or we are at the beggining of 
			 * the array
			 */
			for (; sa && *p != b; p++, sa--);

			return c;
		}

		/* If WL_ASF_REVERSED is set */
		if (flags&1) {
			p = a+sa-1;
#			if !WL_ASB_SIMPLE
				/* Do match finding until `c` is at the previous alignment */
				for (; (Pt)p&(sizeof(UMax)-1) && sa && *(char*)p != b; p--, 
				sa--);
				/* If there still bytes remaining and the next byte isn't a 
				 * match 
				 */
				if (sa && *p != b) {
					const char m = b*_LOW;
					/* Now that `a` is aligned. We check the value of the size
					 * of alignment for the presence of a byte that has a `b`
					 * character. If there isn't one, increment `a` to the 
					 * next alignment, if there is one or more, go to the next
					 * step.
					 */
					for (p-=sizeof(UMax); !_HASZERO(*p^m) && sa>=sizeof(UMax); 
					p-=sizeof(UMax), sa-=sizeof(UMax));
				}
				/* Now we do know that there is a matching byte somewhere in 
				 * this alignment, check each byte in it, if it's a match, 
				 * return.
				 */
#			endif
			/* Loops until a match is found or we are at the beggining of 
			 * the array
			 */
			for (; sa && *p != b; p--, sa--);
		}
		/* Else WL_ASF_NORMAL is set */
		else {
			p = a;
#			if !WL_ASB_SIMPLE
				/* Do match finding until `c` is at the next alignment */
				for (; (Pt)p&(sizeof(UMax)-1) && sa && *(char*)p != b; p++, 
				sa--);
				/* If there still bytes remaining and the next byte isn't a 
				 * match 
				*/
				if (sa && *p != b) {
					const char m = b*_LOW;
					/* Now that `a` is aligned. We check the value of the size
					 * of alignment for the presence of a byte that has a `b`
					 * character. If there isn't one, increment `a` to the 
					 * next alignment, if there is one or more, go to the next
					 * step.
					 */
					for (; !_HASZERO(*p^m) && sa>=sizeof(UMax); 
					p+=sizeof(UMax), sa-=sizeof(UMax));
				}
				/* Now we do know that there is a matching byte somewhere in 
				 * this alignment, check each byte in it, if it's a match, 
				 * return.
				 */
#			endif
			/* Loops until a match is found or we are at the beggining of 
			 * the array
			 */
			for (; sa && *p != b; p++, sa--);
		}

		/* Returns the address where or the offset at which (depending on 
		 * the WL_ASB_PTRDIFF flag) a match was found, or returns NULL if
		 * we looped through the entire array and didn't find any matches
		 */
		return (Pt)p - (Pt)a*!!(flags&2);
	}

	return 0;
}
