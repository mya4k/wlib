#include <wl/array.h>



/* Array shift left subword */
#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
const char* _aslsw(
	char* restrict	_arr,
	U32				rem,
	U8f				by
) {
#if		UMB >= 64
	if (rem&4) {
		*(U32*)_arr <<= by;
		*(U32*)_arr = (*(U32*)_arr & ~(((U32)1<<by)-1)) | *(_arr+=4);
	}
#endif
	if (rem&2) {
		*(U16*)_arr <<= by;
		*(U16*)_arr = (*(U16*)_arr & ~(((U16)1<<by)-1)) | *(_arr+=2);
	}
	if (rem) {
		*_arr <<= by;
		*_arr = (*_arr & ~(((U8)1<<by)-1)) | *(_arr++);
	}
	return _arr;
}

/* Array shift left */
void _asl(
	const	char* restrict const	arr,
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
	{
		const char* _arr = arr;
		U32			_len = len;
		/* Bit shift until alignment */
		_arr = _aslsw(_arr, sizeof(UMax) - (Pt)arr % sizeof(UMax), by);
		/* Bit shift words */
		for (; _len >= 2*sizeof(UMax); _len -= sizeof(UMax)) {
			*(U64*)arr << by;
			*(U64*)_arr = *(U64*)_arr & ~(((U64)1<<by)-1) | *(_arr+=sizeof(UMax));
		}
		/* To avoid overflow, last cycle of the loop will not try to access the
		 next word */
		*(U64*)arr << by;
		/* Bit shift remaining bytes*/
		_aslsw(_arr, _len, by);
	}

	/* Then shift bytes */
	ano(arr+bytes, len-bytes, arr);

	/* Fill the gap with zeros */
	aflv(arr+len-bytes, bytes, (UMax)0, sizeof(UMax));
}
