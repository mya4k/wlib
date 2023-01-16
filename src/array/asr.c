#include <wl/array.h>



/* Array shift right subword */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
char* _asrsw(
	char* restrict	_arr,
	U32				rem,
	U8f				by
) {
	U8f carry0 = 0;

#if		UMB >= 64
	/* This variable is set on systems, where UMax is 32-bit*/
	U8f carry1 = 0;

	if (rem&4) {
		/* Eject bits that will be carried over */
		carry0 = *(U32*)_arr & ~(((U32)1<<by)-1);
		*(U32*)_arr >>= by;
	}
	if (rem&2) {
		carry1 = *(U16*)_arr & ~(((U16)1<<by)-1);
		*(U16*)_arr >>= by;
		*(U16*)_arr |= carry0 << (16-by);
	}
	carry0 = carry1;
#else
	if (rem&2) {
		carry0 = *(U16*)_arr & ~(((U16)1<<by)-1);
		*(U16*)_arr >>= by;
	}
#endif
	if (rem) {
#if	UMB >= 64
		carry1 = *_arr & ~(((U8)1<<by)-1);
#endif
		*_arr >>= by;
		*_arr |= carry0 << (8-by);
	}
	return _arr;
}

/* Array shift right */
void _asr(
			char* restrict const	arr,
	const	U32						len,
			U32						by
) {
	/*	The number of bits to shift by will be stored in two variables:
		-	First holds how many bytes to shift by
		-	Second holds how many bits to shift by
	*/
	const U32 bytes = by / CHB;
	by %= CHB;

	/* Perform bit shifting first */
	if (likely(by > 0)) {
		char* 	_arr = arr;
		U32		_len = len;
		/* Bit shift until alignment */
		_arr = _asrsw(_arr, sizeof(UMax) - (Pt)_arr % sizeof(UMax), by);
		/* Bit shift words */
		{
			U8f carry0 = 0, carry1 = 0;
			for (; _len >= 2*sizeof(UMax); _len -= sizeof(UMax)) {
				/* Preserve carry */
				carry1 = *(UMax*)_arr & ~(((U8)1<<by)-1);
				/* Shift right */
				*(UMax*)_arr >>= by;
				/* Insert previous carry */
				*(UMax*)_arr |= carry0 << (64-by);
				carry0 = carry1;
			}
		}
		/* To avoid overflow, last cycle of the loop will not try to access the
		 next word */
		*(U64*)arr <<= by;
		/* Bit shift remaining bytes*/
		_asrsw(_arr, _len, by);
	}

	/* Then shift bytes */
	ano(arr, len-bytes, arr+bytes);

	/* Fill the gap with zeros */
	aflv(arr, bytes, (UMax)0, sizeof(UMax));
}
