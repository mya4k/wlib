#include <wl/types.h>
#include <wl/bit.h>
#include <wl/core.h>

typedef UMax Gen;

enum SearchFlags {
	SF_HAYSTACK_WORD,
	SF_HAYSTACK_CHARARRAY,
	SF_HAYSTACK_STRING,
	SF_HAYSTACK_ARRAY,
	
	SF_NEEDLE_BIT,
	SF_NEEDLE_CHAR,
	SF_NEEDLE_WORD,
	SF_NEEDLE_CHARARRAY,
	SF_NEEDLE_STRING,
	SF_NEEDLE_REGEX,
	SF_NEEDLE_ARRAY,

	SF_RETURN_FIRST,	/* Position of the first occurrence */
	SF_RETURN_LAST,		/* Position of the last occurrence */
	SF_RETURN_INDEX,	/* Position of the specified ordinal occurrence */
	SF_RETURN_COUNT,	/* Number of occurrences */
	SF_RETURN_ALL,		/* Array with positions of all occurrences */

	SF_REPLACE_FIRST,
	SF_REPLACE_LAST,
	SF_REPLACE_INDEX,
	SF_REPLACE_ALL
};

/**
 * \brief 	Search Word for Bit First
 * \def		swbf(haystack, bits, needle)
 * \param	haystack	Haystack Bitstring
 * \param	bits		Size of haystack in bits
 * \param	needle		Needle Bit
 * \return	Ordinal bit number of occurrence
 * 
 * \warning	Returns `U8X` if needle wasn't found
 */
#define swbf(haystack, bits, needle)	\
	clz(likely(needle) ? (haystack) : (~haystack)) - (UMB-bits)

/**
 * \brief 	Search Word for Bit Last
 * \def		swbl(haystack, bits, needle)
 * \param	haystack	Haystack Bitstring
 * \param	bits		Size of haystack in bits
 * \param	needle		Needle Bit
 * \return	Ordinal bit number of occurrence
 *  
 * \warning	Returns `U8X` if needle wasn't found
 */
#define swbl(haystack, bits, needle)	\
	ctz(likely(needle) ? (haystack) : (~haystack)) - (UMB-bits)

/**
 * \brief 	Search Word for Bit Count
 * \def		swbl(haystack, bits, needle)
 * \param	haystack	Haystack Bitstring
 * \param	bits		Size of haystack in bits
 * \param	needle		Needle Bit
 * \return	Number of occurrences
 */
#define swbl(haystack, bits, needle)	\
	pop(likely(needle) ? (haystack) : (~haystack)) - (UMB-bits)  

/**
 * \brief 	Search Word for Word First
 * \def		vsbf(haystack, bits, needle)
 * \param	haystack	Haystack Bitstring
 * \param	bits		Size of haystack in bits
 * \param	needle		Needle Bit
 * \return	Ordinal bit number of occurrence
 * 
 * \warning	Returns `U8X` if needle wasn't found
 */
U8 swf(UMax haystack, I8 bitsh, const UMax needle, const U8 bitsn) {
	register U8 index;	/* Storage for bsbf return */

	while (bitsh >= bitsn) {
		/* Use bsbf to find the first bit of needle */
		index = bsbf(haystack, bitsh, needle>>(bitsn-1));
		bitsh -= index;
		haystack <<= index;
		if_unlikely(haystack )
		if_unlikely(haystack >> (UMB-(bitsh+needle)) & ((1<<bitsn) - 1))
 
		/* Test at occurrence for equality with neelde */
		if_unlikely ( ( haystack>>( UMB-(bitsn+needle) ) & (1<<bitsn)-1 ) == needle )
			return index;
		/* Shift the searched area away */
		haystack <<= index++;
		bitsh -= index;
	}

	/* Nothing found */
	return U8X;
}

Gen search(Gen haystack, Gen needle, U8 flags) {
	if (SF_HAYSTACK_VALUE) {
		if (SF_NEEDLE_BIT) {
			if (needle)	
				return clz(haystack);
			else
				return clz(~haystack);
		}
	}
	else if (SF_HAYSTACK_BYTEARRAY) {
		if (SF_NEEDLE_BIT) {
			if (needle)	
				return clz(haystack);
			else
				return clz(~haystack);
		}
	}
}
