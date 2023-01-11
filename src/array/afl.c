#include <wl/array.h>
#include <wl/memory.h>



#define _min2(x,y)	((x)<=(y) ? (x) : (y))



/* Array fill array*/
void afla(
			char* arr1,			U32 len1,
	const	char* arr2, const	U32 len2
) {
	/* Fill with `arr2` until len1 < len2 */
	while (len1>=len2) {
		ano(arr2, len2, arr1);
		len1 -= len2;
		arr1 = arr1+len2;
	}
}


#if WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE
	always_inline
#endif
void aflvsw(char* arr, U8 rem, UMax* val, U8 lenv) {
#define _val (*val)
	/* Assuming `lenv` > 4 */
#if UMB >= 64
	if (rem&4) {
		if (lenv > 4) {
			register U8 mlen = (8*(lenv-4));
			*(U32*)arr = _val >> mlen;
			_val = ((UMax)(_val & (((UMax)1<<mlen)-1)) << 32) | *(U32*)arr;
		}
		else /* lenv == 3 */ {
			*(U32*)arr = _val<<8 | _val>>16;
			_val = *(U32*)arr & 0xFFFFFF;
		}
		arr += 4;
	}
#endif
	if (rem&2) {
		register U8 mlen = (8*(lenv-4));
		*(U16*)arr = _val >> mlen;
		_val = ((_val & (((UMax)1<<mlen)-1)) << 16) | *(U16*)arr;
		arr += 2;
	}
	if (rem) {
		register U8 mlen = (8*(lenv-4));
		*arr = _val >> mlen;
		_val = ((_val & (((UMax)1<<mlen)-1)) << 8) | *arr;
		arr++;
	}
}

void aflv(char* restrict arr, U32 lena, UMax val, U8 lenv) {
	/* Duplicate val to fill the word */
	switch (lenv) {
		case 1:
			val |= val<<CHB;
			val |= val<<(2*CHB);
#if	UMB >= 64
			val |= val<<(4*CHB);
			lenv = 8;
#else
			lenv = 4;
#endif
			break;
		case 2:
			val |= val<<(2*CHB);
#if	UMB >= 64
			val |= val<<(4*CHB);
			lenv = 8;
#else
			lenv = 4;
#endif
			break;
#if UMB >= 64
		case 4:
			val |= val<<(4*CHB);
			lenv = 8;
			break;
#endif
	}

	/* Align `arr` first */
	{
		Pt rem = sizeof(UMax) - (Pt)arr % sizeof(UMax);
		aflvsw(arr, rem, &val, lenv);
		arr += rem; lena -= rem;
	}

	/* Fill words */
	if (lenv == sizeof(UMax)) {
		while (lena >= sizeof(UMax)) {
			*(UMax*)arr = val;
			arr += sizeof(UMax); lena -= sizeof(UMax);
		}
	}
	/* Special behavior when `lenv` < wordsize */
#if	UMB >= 64
	else if (lenv == 3) {
		while (lena >= lenv) {
			/* 3 */ *arr = val<<40 | val<<16 | val>>8;
			val = *arr&0xFFFFFFF;
			arr++; lena -= 8;
		}	
	}
	else if (lenv == 5) {
	  	while (lena > lenv) {
			/* 5 */	*arr = val<<24 | val>>16;
			val = *arr&0xFFFFFFFFFF;
			arr++; lena -= 8;
		}
	}
	else if (lenv == 6) {
		while (lena > lenv) {
			/* 6 */ *arr = val<<16 | val>>32;
			val = *arr&0xFFFFFFFFFFFF;
			arr++; lena -= 8;
		}
	}
	else /* if (lenv == 7) */ {		
		while (lena > lenv) {
			/* 7 */ *arr = val<<8 | val>>56;
			val = *arr&0xFFFFFFFFFFFFFF;
			arr++; lena -= 8;
		}	
	}
#else
	else /* if (lenv == 3) */ {
		while (lena >= lenv) {
			*arr = val<<8 | val>>16;
			val = *arr&0xFFFFFF;
			arr++; lena -= 4;
		}
	}
#endif

	/* Fill remaining bytes */
	aflvsw(arr, lena, &val, lenv);
}
