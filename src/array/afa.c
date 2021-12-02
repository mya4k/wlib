#include <wc/array.h>



#if !defined(WL_MAL_IMPLIMENTED) || !defined(mal)
#	include <stdlib.h>
#	define mal malloc
#endif



/* Shortcut for properly assigning selected bits of the value, where `m` is the
 * bitmask, where the value of the bit determines if it is going to be assigned
 * from `b` to `a`
 */
#if WL_OPTIMIZE_MEMORY >= 1
#	define _ASV(a,b)	\
		((a) = ((b)&(((UMax)1<<size) - 1)) + ((a)&(UMX>>size<<size))))
#else
#	define _ASV(a,b) 						\
		const UMax m = ((UMax)1<<size) - 1;	\
		((a) = ((b)&m) + ((a)&~m))
#endif
/* Abbreviation for `sizeof(UMax)` */
#define SM	(sizeof(UMax))
/* Pointer add assignment */
#define PADA(a,b) (a = (const void*)((Pt)a+(Pt)b))

#define AFATEMP(_ASVARG_A, _ASVARG_B)						\
	for (; size >= SM; PADA(a,SM), PADA(b,SM), size -= SM)	\
		(_ASVARG_A) = (_ASVARG_B);							\
	if (size<<=3) {											\
		_ASV((_ASVARG_A), (_ASVARG_B));						\
	}

#define AFAHEAD1					\
	if (size&&b) {					\
		const char* a;				\
		if (!_a) _a = mal(size);	\
		a = _a;

#define AFAHEAD2					\
	if (size&&b&&c) {				\
		const char* a;				\
		if (!_a) _a = mal(size);	\
		a = _a;

#define AFAFOOT	\
	}			\
	return _a;

#define AFADEF1(NAME, _ASVARG_A, _ASVARG_B)	\
	AFADECL1(NAME) {						\
		AFAHEAD1							\
		AFATEMP( (_ASVARG_A), (_ASVARG_B))	\
		AFAFOOT								\
	}

#define AFADEF2(NAME, _ASVARG_A, _ASVARG_B)	\
	AFADECL2(NAME) {						\
		AFAHEAD2							\
		AFATEMP( (_ASVARG_A), (_ASVARG_B))	\
		AFAFOOT								\
	}



#if WL_OPTIMIZE_SPEED == 2
	AFADEF1(ano, *((UMax*)a), *((UMax*)b))
	AFADEF1(ant, *((UMax*)a), ~*((UMax*)b))
	AFADEF2(aan, *((UMax*)a), *((UMax*)b) & *((UMax*)c))
	AFADEF2(aor, *((UMax*)a), *((UMax*)b) | *((UMax*)c))
	AFADEF2(axr, *((UMax*)a), *((UMax*)b) ^ *((UMax*)c))
	AFADEF2(ann, *((UMax*)a), ~(*((UMax*)b) & *((UMax*)c)))
	AFADEF2(anr, *((UMax*)a), ~(*((UMax*)b) | *((UMax*)c)))
	AFADEF2(anx, *((UMax*)a), ~(*((UMax*)b) ^ *((UMax*)c)))

	/* This function exists here as a failsafe, 
	 * YOU SHOULD NOT USE THIS FUNCTION IF SPEED IS YOUR PRIORITY 
	 */
	const void* afa(const void* _a, const void* b, const void* c, const	Af func, As size) {
		switch (func) {
			case WL_AF_NOA: return ano(_a, b, size);
			case WL_AF_NTA: return ant(_a, b, size);
			case WL_AF_ANA: return aan(_a, b, c, size);
			case WL_AF_ORA: return aor(_a, b, c, size);
			case WL_AF_XRA: return axr(_a, b, c, size);
			case WL_AF_NNA: return ann(_a, b, c, size);
			case WL_AF_NRA: return anr(_a, b, c, size);
			case WL_AF_NXA: return anx(_a, b, c, size);
			default: return NULL;
		}
	}
#else
	const void* afa(const void* _a, const void* b, const void* c, const	Af func, As size) {
		AFAHEAD1
		/* Method in a nutshell:
		 * 1.	Treat values in chunks of SM bytes
		 * 2.	When there are less than SM bytes remaining, 
		 * 		use selected assignment macro `_ASV`
		 * Notes:
		 * `size<<=3` -- convertion from bytes to bits for `m` shifts
		 * `m` is a bitmask for selected assignment `_ASV`. See the 
		 * comment above `_ASV` for more information.
		 */

		 /* All function require `b` != NULL, otherwise, no action will 
		 * performed 
		 */
		/* Those functions that require `c`, will only be done if `c` is 
		 * not NULL 
		 */
		if (c)	switch (func) {
			/* aan() -- Array bitwise AND */
			case WL_AF_ANA: AFATEMP(*((UMax*)a), *((UMax*)b) & *((UMax*)c)) break;
			/* aor() -- Array bitwise OR */
			case WL_AF_ORA: AFATEMP(*((UMax*)a), *((UMax*)b) | *((UMax*)c)) break;
			/* axr() -- Array bitwise XOR */
			case WL_AF_XRA: AFATEMP(*((UMax*)a), *((UMax*)b) ^ *((UMax*)c)) break;
			/* ann() -- Array bitwise NAND */
			case WL_AF_NNA: AFATEMP(*((UMax*)a), ~(*((UMax*)b) & *((UMax*)c))) break;
			/* anr() -- Array bitwise NOR */
			case WL_AF_NRA: AFATEMP(*((UMax*)a), ~(*((UMax*)b) | *((UMax*)c))) break;
			/* anx() -- Array bitwise NXOR */
			case WL_AF_NXA: AFATEMP(*((UMax*)a), ~(*((UMax*)b) ^ *((UMax*)c))) break;
			default: break;
		}
		else 	switch (func) {
			/* aas() -- Array assignment */
			case WL_AF_NOA: AFATEMP(*((UMax*)a), *((UMax*)b)) break;
			/* ant() -- Array bitwise NOT */
			case WL_AF_NTA: AFATEMP(*((UMax*)a), ~*((UMax*)b)) break;
			default: break;
		}
		AFAFOOT
	}
#endif
