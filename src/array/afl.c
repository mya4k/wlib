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

/* If `lenv` can be duplicated closer to word-size, we do it, to divide the amount of repeated copies.*/
always_inline static void 
_LenvCloserToWordSize(UMax* val, U8* lenv) {
#if UMB >= 64
	if_unlikely(*lenv == 3) {
		/* 3 -> 6 */	*val |= (*val<<24);
		*lenv = 6;
	}
	if_unlikely(*lenv < 5) {
		/* 1 -> 2 */	*val |= (*lenv==1)*(*val<<8);
		/* 2 -> 4 */	*val |= (*lenv==2)*(*val<<16);
		/* 4 -> 8 */	*val |= (*lenv==2)*(*val<<32);
		*lenv = 8;
	}
#else
	if_unlikely(*lenv < 2) {
		/* 1 -> 2 */	*val |= (*lenv==1)*(*val<<8);
		/* 2 -> 4 */	*val |= (*val<<16);
		*lenv = 4;
	}
#endif
}

/* Fill Array when lena is less than lenv */
always_inline static void
_FillRemaining (char* restrict arr, U32 lena, UMax* val, U8 lenv) {
#if UMB >= 64
	if_unlikely(lena&4) {
		*(U32*)arr = *val>>CHB*(lenv-4);
		*val = *(U32*)arr | *val << 4*CHB;	/* Curcular right shift */
		*arr += 4; lena -= 4;
	}
#endif
	if_unlikely(lena&2) {
		*(U16*)arr = *val>>CHB*(lenv-2);
		*val = *(U32*)arr | *val << 2*CHB;	/* Curcular right shift */
		*arr += 2; lena -= 2;
	}
	if_unlikely(lena&1) {
		*arr = *val>>CHB*(lenv-1);
	}
}

/* Fill Array until its pointer is aligned */
always_inline static char*
_FillTillArrAligned (char* restrict arr, U32* lena, UMax* val, U8 lenv) {
	register const Pt rem = (Pt)arr % sizeof(UMax);
	if_unlikely(rem) {
		_FillRemaining(arr, rem, val, lenv);
		*lena -= rem;
		return arr - rem;
	}
	return arr;
}

/* Fill Array until `lena` less than `lenv` */
always_inline static char*
_FillVal(char* restrict arr, U32* lena, UMax* val, U8 lenv) {
#if UMB >= 64
	if_unlikely(lenv!=8) {
		/*	`shift`
			How much we need to shift right to fill `*arr` with the beginning
			of `val`
		*/
		const U8 shift = (2*lenv-8)*CHB;
		const UMax mask = ((UMax)1<<(CHB*lenv))-1;
		while(*lena >= lenv) {
			*(U64*)arr = *val | *val>>shift;
			*val = *(U64*)arr & mask;	/* Curcular right shift */
			*lena -= 5; arr += 5;
		}
	}
	else {
		while(*lena >= 8) {
			*(U64*)arr = *val;
			*lena -= 8; arr += 8;
		}
	}
#else
	if_unlikely(lenv==3) {
		while(*lena >= 3) {
			*(U32*)arr = *val | *val >> 2*CHB;
			*val = *(U64*)arr & 0xFFFFFF;	/* Curcular right shift */
			*lena -= 3; arr += 3;
		}
	}
	else {
		while(*lena >= 4) {
			*(U32*)arr = *val;
			*lena -= 4; arr += 4;
		}
	}
#endif
	return arr;
}


void 
aflv(char* restrict arr, U32 lena, UMax val, U8 lenv) {
	_LenvCloserToWordSize(&val, &lenv);
	arr = _FillTillArrAligned(arr, &lena, &val, lenv);
	arr = _FillVal(arr, &lena, &val, lenv);
	_FillRemaining(arr, lena, &val, lenv);
}

#if rgrgkrjgkr
void aflv(char* restrict arr, U32 lena, UMax val, U8 lenv) {
	if (len)
		/* Duplicate val to fill the word */
		switch (lenv) {
			case 1:
				val |= val<<CHB;
				val |= val<<(2*CHB);
#	if	UMB >= 64
				val |= val<<(4*CHB);
				lenv = 8;
#	else
				lenv = 4;
#	endif
				break;
			case 2:
				val |= val<<(2*CHB);
#	if	UMB >= 64
				val |= val<<(4*CHB);
				lenv = 8;
#	else
				lenv = 4;
#	endif
				break;
#	if UMB >= 64
			case 4:
				val |= val<<(4*CHB);
				lenv = 8;
				break;
#	endif
		}

		/* Align `arr` first */
		{
			Pt rem = sizeof(UMax) - (Pt)arr % sizeof(UMax);
			if (unlikely(rem > 0)) {
				aflvsw(arr, rem, &val, lenv);
				arr += rem; lena -= rem;
			}
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

remaining:
	/* Fill remaining bytes */
	aflvsw(arr, lena, &val, lenv);
}
#endif
