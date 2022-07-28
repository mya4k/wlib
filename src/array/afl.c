#include <wl/array.h>
#include <wl/memory.h>



#define _min2(x,y)	((x)<=(y) ? (x) : (y))

const void* afla(
			char* arr1,			U32 len1,
	const	char* arr2, const	U32 len2
) {
	/* Check for NULLs and zeros */
	if (likely(arr2!=NULL && len1>0 && len2>0)) {
		/* If destination is NULL, it needs to be allocated */
		if (unlikely(arr1 == NULL)) arr1 = mal(len1);
		if (likely(arr1 != NULL)) {	/* `malloc` can fail */
			/* Preserve return value */
			const void* const _arr1 = arr1;
			/* Fill with `arr2` until len1 < len2 */
			while (len1>=len2) {
				/**	`_ano_bare` is the same function as `ano` but it doesn't 
				 *	check its parameters for holding valid values
				 */
				_ano_bare((_Afa_U512*)arr2, len2, (_Afa_U512*)arr1);
				len1 -= len2;
				arr1 = arr1+len2;
			}
			/* Fill `len1` bytes of `arr2` */
			_ano_bare((_Afa_U512*)arr2, len1, (_Afa_U512*)arr1);
			/* Return pointer to destination */
			return _arr1;
		}
	}
	return NULL;
}

#define _FILL64(arr, val)	\
	_FILL32(arr, val);		\
	_FILL32(arr+32/sizeof(UMax), val)
#define _FILL32(arr, val)	\
	_FILL16(arr, val);		\
	_FILL16(arr+16/sizeof(UMax), val)
#define _FILL16(arr, val)	\
	_FILL8(arr, val);		\
	_FILL8(arr+8/sizeof(UMax), val)

#if UMB >= 64
#	define _FILL8(arr, val)	\
	*(arr) = (val)
#else
#	define _FILL8(arr, val)	\
	*(arr) = (val);			\
	*(arr+1) = (val)
#endif

const void* aflv(UMax* arr, U32 lena, UMax val, U32 lenv) {
	/* Check for NULLs and zeros */
	if (likely(lena>0 && lenv>0)) {
		/* If destination is NULL, it needs to be allocated */
		if (unlikely(arr == NULL)) arr = mal(lena);
		/* `lenv` cannot be larger than the largest scalar type */
		if (likely(arr != NULL)) {
			/* Preserve return value */
			const void* const _arr = arr;

			/*	Try making `val` as close to wordsize as possible, so we need
				to make less assignments overall
			 */
			switch (lenv) {
				case 1:
					val |= val<<(CHB);
					lenv += 1;
					break;
				case 2:
					val |= val<<(2*CHB);
					lenv += 2;
					break;
#if	UMB >= 64
				case 4:
					val |= val<<(4*CHB);
					lenv += 4;
					break;
#endif
				default: break;
			}

			while (likely(lena>=64)) {
				_FILL64(arr, val);
				arr += 64/sizeof(UMax);
				lena -= 64;
			}

			/* Fill with `arr2` until len1 < len2 */
			if (unlikely(lena&32)) {
				_FILL32(arr, val);
				arr += 32/sizeof(UMax);
				lena -= 32;
			}
			if (unlikely(lena&16)) {
				_FILL16(arr, val);
				arr += 32/sizeof(UMax);
				lena -= 32;
			}
#if UMB >= 64
			if (unlikely(lena)) { _FILL8(arr, val); }
#else
			if (unlikely(lena&8)) { 
				_FILL8(arr, val); 
				arr += 2;
				lena -= 8;
			}
			if (unlikely(lena)) 
				*arr = val;
#endif

			/* Return pointer to destination */
			return _arr;
		}
	}
	return NULL;
}
