#include <wc/array.h>



#if !defined(WL_MAL_IMPLIMENTED) || !defined(mal)
#	include <stdlib.h>
#	define mal malloc
#endif



/* Shortcut for properly assigning selected bits of the value, where `m` is the
 * bitmask, where the value of the bit determines if it is going to be assigned
 * from `b` to `a`
 */
#define _ASV(a,b) ((a) = ((b)&m) + ((a)&~m))
/* Abbreviation for `sizeof(UMax)` */
#define SM	(sizeof(UMax))
/* Pointer add assignment */
#define PADA(a,b) (a = (const void*)((Pt)a+(Pt)b))



const void* afa(const void* _a, const void* b, const void* c, const	Af func, As size) {
	if (size&&b) {
		const char* a;

		if (!_a) _a = mal(size);
		a = _a;

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
		if (b) {
			/* Those functions that require `c`, will only be done if `c` is 
			 * not NULL 
			 */
			if (c)	switch (func) {
				/* aan() -- Array bitwise AND */
				case WL_AF_ANA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), PADA(c,SM), size -= SM)
						*((UMax*)a) = *((UMax*)b) & *((UMax*)c);
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV( *((UMax*)a), *((UMax*)b) & *((UMax*)c));
					}
					break;
				/* aor() -- Array bitwise OR */
				case WL_AF_ORA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), PADA(c,SM), size -= SM)
						*((UMax*)a) = *((UMax*)b) | *((UMax*)c);
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV( *((UMax*)a), *((UMax*)b) | *((UMax*)c));
					}
					break;
				/* axr() -- Array bitwise XOR */
				case WL_AF_XRA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), PADA(c,SM), size -= SM)
						*((UMax*)a) = *((UMax*)b) ^ *((UMax*)c);
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV( *((UMax*)a), *((UMax*)b) ^ *((UMax*)c));
					}
					break;
				/* ann() -- Array bitwise NAND */
				case WL_AF_NNA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), PADA(c,SM), size -= SM)
						*((UMax*)a) = ~(*((UMax*)b) & *((UMax*)c));
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV( *((U64*)a), ~(*((U64*)b) & *((U64*)c)) );
					}
					break;
				/* anr() -- Array bitwise NOR */
				case WL_AF_NRA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), PADA(c,SM), size -= SM)
						*((UMax*)a) = ~(*((UMax*)b) | *((UMax*)c));
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV( *((U64*)a), ~(*((U64*)b) | *((U64*)c)) );
					}
					break;
				/* anx() -- Array bitwise NXOR */
				case WL_AF_NXA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), PADA(c,SM), size -= SM)
						*((UMax*)a) = ~(*((UMax*)b) ^ *((UMax*)c));
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV( *((U64*)a), ~(*((U64*)b) ^ *((U64*)c)) );
					}
					break;
				default: break;
			}
			else 	switch (func) {
				/* aas() -- Array assignment */
				case WL_AF_NOA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), size -= SM)
						*((UMax*)a) = *((UMax*)b);
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV(*((UMax*)a), *((UMax*)b));
					}
					break;
				/* ant() -- Array bitwise NOT */
				case WL_AF_NTA:
					for (; size >= SM; PADA(a,SM), PADA(b,SM), size -= SM)
						*((UMax*)a) = *((UMax*)b);
					if (size<<=3) {
						const UMax m = ((UMax)1<<size) - 1;
						_ASV(*((UMax*)a), *((UMax*)b));
					}
					break;
				default: break;
			}
		}
	}

	return _a;
}
