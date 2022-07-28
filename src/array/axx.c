#include <wl/array.h>
#include <wl/memory.h>



#define _min2(x,y)	((x)<=(y) ? (x) : (y))



#define _AFA1_COPY1			\
	if (unlikely(len & 1))	\
	*(U8l*)res = *(U8l*)arr;

#define _AFA1_COPY2							\
	if (unlikely(len & 2)) {				\
		*(U16l*)res = *(U16l*)arr;			\
		len -= 2;							\
		res = (_Afa_U512*)((U16l*)res + 1);	\
		arr = (_Afa_U512*)((U16l*)arr + 1);	\
	}

#define _AFA1_COPY4							\
	if (unlikely(len & 4)) {				\
		*(U32l*)res = *(U32l*)arr;			\
		len -= 4;							\
		res = (_Afa_U512*)((U32l*)res + 1);	\
		arr = (_Afa_U512*)((U32l*)arr + 1);	\
	}

#if WL_CONF_INT64
#	define _AFA1_COPY8							\
		if (unlikely(len & 8)) {				\
			*(U64l*)res = *(U64l*)arr;			\
			len -= 8;							\
			res = (_Afa_U512*)((U64l*)res + 1);	\
			arr = (_Afa_U512*)((U64l*)arr + 1);	\
		}
#else
#	define _AFA1_COPY8														\
		if (unlikely(len & 8)) {											\
			typedef unsigned int __attribute__((vector_size(8))) _Afa_U64;	\
			*(_Afa_U64*)res = *(_Afa_U64*)arr;								\
			len -= 8;														\
			res = (_Afa_U512*)((_Afa_U64*)res + 1);							\
			arr = (_Afa_U512*)((_Afa_U64*)arr + 1);							\
		}
#endif

#define _AFA1_COPY16														\
	if (unlikely(len & 16)) {												\
		typedef unsigned int __attribute__((vector_size(16))) _Afa_U128;	\
		*(_Afa_U128*)res = *(_Afa_U128*)arr;								\
		len -= 16;															\
		res = (_Afa_U512*)((_Afa_U128*)res + 1);							\
		arr = (_Afa_U512*)((_Afa_U128*)arr + 1);							\
	}

#define _AFA1_COPY32														\
	if (unlikely(len & 32)) {												\
		typedef unsigned int __attribute__((vector_size(32))) _Afa_U256;	\
		*(_Afa_U256*)res = *(_Afa_U256*)arr;								\
		len -= 32;															\
		res = (_Afa_U512*)((_Afa_U256*)res + 1);							\
		arr = (_Afa_U512*)((_Afa_U256*)arr + 1);							\
	}

#define _AFA1_COPY64	if (len & 64) *res = *arr;


#define _AFA2_COPY1(OP)								\
	if (unlikely(len & 1))							\
	*(U8l*)res = (*(U8l*)arr1)OP(*(U8l*)arr2);		\

#define _AFA2_COPY2(OP)									\
	if (unlikely(len & 2)) {							\
		*(U16l*)res = (*(U16l*)arr1)OP(*(U16l*)arr2);	\
		len -= 2;										\
		res = (_Afa_U512*)((U16l*)res + 1);				\
		arr1 = (_Afa_U512*)((U16l*)arr1 + 1);			\
		arr2 = (_Afa_U512*)((U16l*)arr2 + 1);			\
	}

#define _AFA2_COPY4(OP)									\
	if (unlikely(len & 4)) {							\
		*(U32l*)res = (*(U32l*)arr1)OP(*(U32l*)arr2);	\
		len -= 4;										\
		res = (_Afa_U512*)((U32l*)res + 1);				\
		arr1 = (_Afa_U512*)((U32l*)arr1 + 1);			\
		arr2 = (_Afa_U512*)((U32l*)arr2 + 1);			\
	}

#if U64LB >= 64
#	define _AFA2_COPY8(OP)									\
		if (unlikely(len & 8)) {							\
			*(U64l*)res = (*(U64l*)arr1)OP(*(U64l*)arr2);	\
			len -= 8;										\
			res = (_Afa_U512*)((U64l*)res + 1);				\
			arr1 = (_Afa_U512*)((U64l*)arr1 + 1);			\
			arr2 = (_Afa_U512*)((U64l*)arr2 + 1);			\
		}
#else
#	define _AFA2_COPY8(OP)													\
		if (unlikely(len & 8)) {											\
			typedef unsigned int __attribute__((vector_size(8))) _Afa_U64;	\
			*(_Afa_U64*)res = (*(_Afa_U64*)arr1)OP(*(_Afa_U64*)arr2);		\
			len -= 8;														\
			res = (_Afa_U512*)((_Afa_U64*)res + 1);							\
			arr1 = (_Afa_U512*)((_Afa_U64*)arr1 + 1);						\
			arr2 = (_Afa_U512*)((_Afa_U64*)arr2 + 1);						\
		}
#endif

#define _AFA2_COPY16(OP)													\
	if (unlikely(len & 16)) {												\
		typedef unsigned int __attribute__((vector_size(16))) _Afa_U128;	\
		*(_Afa_U128*)res = (*(_Afa_U128*)arr1)OP(*(_Afa_U128*)arr2);		\
		len -= 16;															\
		res = (_Afa_U512*)((_Afa_U128*)res + 1);							\
		arr1 = (_Afa_U512*)((_Afa_U128*)arr1 + 1);							\
		arr2 = (_Afa_U512*)((_Afa_U128*)arr2 + 1);							\
	}

#define _AFA2_COPY32(OP)													\
	if (unlikely(len & 32)) {												\
		typedef unsigned int __attribute__((vector_size(32))) _Afa_U256;	\
		*(_Afa_U256*)res = (*(_Afa_U256*)arr1)OP(*(_Afa_U256*)arr2);		\
		len -= 32;															\
		res = (_Afa_U512*)((_Afa_U256*)res + 1);							\
		arr1 = (_Afa_U512*)((_Afa_U256*)arr1 + 1);							\
		arr2 = (_Afa_U512*)((_Afa_U256*)arr2 + 1);							\
	}

#define _AFA2_COPY64(OP)	\
	if (unlikely(len & 64))	*res = (*arr1)OP(*arr2)



/* Copy less than 64 bytes */
#if WL_CONF_OPTIMIZE&4 != WL_CONF_SIZE
	always_inline
#endif 
static void _anosw(
	const _Afa_U512* restrict arr, U32 len, 
	_Afa_U512* restrict res
) {
#if WL_CONF_GCC_VECTOR
	_AFA1_COPY32
	_AFA1_COPY16
	_AFA1_COPY8
#endif
#if UMB >= 64
	_AFA1_COPY4
#endif
	_AFA1_COPY2
	_AFA1_COPY1
}

/* Copy less than 64 bytes but also AND arr1 and arr2 */
#if WL_CONF_OPTIMIZE&4 != WL_CONF_SIZE
	always_inline
#endif
static void _aansw(
	const _Afa_U512* restrict arr1, const _Afa_U512* restrict arr2, U32 len,
	_Afa_U512* restrict res
) {
#if WL_CONF_GCC_VECTOR
	_AFA2_COPY32(&)
	_AFA2_COPY16(&)
	_AFA2_COPY8(&)
#endif
#if UMB >= 64
	_AFA2_COPY4(&)
#endif
	_AFA2_COPY2(&)
	_AFA2_COPY1(&)
}

/* Copy less than 64 bytes but also OR arr1 and arr2 */
#if WL_CONF_OPTIMIZE&4 != WL_CONF_SIZE
	always_inline
#endif
static void _aorsw(
	const _Afa_U512* restrict arr1, const _Afa_U512* restrict arr2, U32 len,
	_Afa_U512* restrict res
) {
#if WL_CONF_GCC_VECTOR
	_AFA2_COPY32(|)
	_AFA2_COPY16(|)
	_AFA2_COPY8(|)
#endif
#if UMB >= 64
	_AFA2_COPY4(|)
#endif
	_AFA2_COPY2(|)
	_AFA2_COPY1(|)
}

/* Copy less than 64 bytes but also XOR arr1 and arr2 */
#if WL_CONF_OPTIMIZE&4 != WL_CONF_SIZE
	always_inline
#endif
static void _axrsw(
	const _Afa_U512* restrict arr1, const _Afa_U512* restrict arr2, U32 len,
	_Afa_U512* restrict res
) {
#if WL_CONF_GCC_VECTOR
	_AFA2_COPY32(^)
	_AFA2_COPY16(^)
	_AFA2_COPY8(^)
#endif
#if UMB >= 64
	_AFA2_COPY4(^)
#endif
	_AFA2_COPY2(^)
	_AFA2_COPY1(^)
}



const _Afa_U512* _ano(
	const _Afa_U512* restrict arr, U32 len, _Afa_U512* restrict res
) {
	/* Allocate destination if \a res is NULL*/
	if (unlikely(res == NULL)) {
		res = mal(len);
	}
#indef WL_C_STRING
	return memcpy(res, arr, len);
#else
	/* Preserve `res` for return */
	const _Afa_U512* const _res = res;
	/* If `len` is smaller than 64 bytes, we won't need to loop */
	if (likely(len <= sizeof(_Afa_U512))) {
		_AFA1_COPY64
		_anosw(arr, len, res);
	}
	else {
		/* Copy bytes until the `arr` pointer is aligned */
		{
			U32 _len = len;
			len = (Pt)arr%sizeof(_Afa_U512);
			_len -= len;
			if (len > 0)
				_anosw(arr, len, res);
			len = _len;
		}

		/* Loop copying 64 bytes, until less than 64 left. */
		while (len > sizeof(_Afa_U512)) {
			*res = *arr;
			res++; arr++; len -= sizeof(_Afa_U512);
		}

		/* Copy the remaining bits */
		_anosw(arr, len, res);
	}
	return _res;
#endif
}

const _Afa_U512* _aan(
	const _Afa_U512* restrict arr1, const _Afa_U512* restrict arr2, U32 len, 
	_Afa_U512* restrict res
) {
	/* Allocate destination if \a res is NULL*/
	if (unlikely(res == NULL)) {
		res = mal(len);
	}
	/* Preserve `res` for return */
	const _Afa_U512* const _res = res;
	/* If `len` is smaller than 64 bytes, we won't need to loop */
	if (likely(len <= sizeof(_Afa_U512))) {
		_AFA2_COPY64(&);
		_aansw(arr1, arr2, len, res);
	}
	else {
		/* Copy bytes until the `arr` pointer is aligned */
		{
			U32 _len = len;
			len = _min2((Pt)arr1%sizeof(_Afa_U512),(Pt)arr2%sizeof(_Afa_U512));
			_len -= len;
			if (len > 0)
				_aansw(arr1, arr2, len, res);
			len = _len;
		}

		/* Loop copying 64 bytes, until less than 64 left. */
		while (len > sizeof(_Afa_U512)) {
			*res = *arr1 & *arr2;
			res++; arr1++; arr2++; len -= sizeof(_Afa_U512);
		}

		/* Copy the remaining bits */
		_aansw(arr1, arr2, len, res);
	}
	return _res;
}

const _Afa_U512* _aor(
	const _Afa_U512* restrict arr1, const _Afa_U512* restrict arr2, U32 len, 
	_Afa_U512* restrict res
) {
	/* Allocate destination if \a res is NULL*/
	if (unlikely(res == NULL)) {
		res = mal(len);
	}
	/* Preserve `res` for return */
	const _Afa_U512* const _res = res;
	/* If `len` is smaller than 64 bytes, we won't need to loop */
	if (likely(len <= sizeof(_Afa_U512))) {
		_AFA2_COPY64(|);
		_aorsw(arr1, arr2, len, res);
	}
	else {
		/* Copy bytes until the `arr` pointer is aligned */
		{
			U32 _len = len;
			len = _min2((Pt)arr1%sizeof(_Afa_U512),(Pt)arr2%sizeof(_Afa_U512));
			_len -= len;
			if (len > 0)
				_aorsw(arr1, arr2, len, res);
			len = _len;
		}

		/* Loop copying 64 bytes, until less than 64 left. */
		while (len > sizeof(_Afa_U512)) {
			*res = *arr1 | *arr2;
			res++; arr1++; arr2++; len -= sizeof(_Afa_U512);
		}

		/* Copy the remaining bits */
		_aorsw(arr1, arr2, len, res);
	}
	return _res;
}

const _Afa_U512* _axr(
	const _Afa_U512* restrict arr1, const _Afa_U512* restrict arr2, U32 len, 
	_Afa_U512* restrict res
) {
	/* Preserve `res` for return */
	const _Afa_U512* const _res = res;
	/* If `len` is smaller than 64 bytes, we won't need to loop */
	if (likely(len <= sizeof(_Afa_U512))) {
		_AFA2_COPY64(^);
		_axrsw(arr1, arr2, len, res);
	}
	else {
		/* Copy bytes until the `arr` pointer is aligned */
		{
			U32 _len = len;
			len = _min2((Pt)arr1%sizeof(_Afa_U512),(Pt)arr2%sizeof(_Afa_U512));
			_len -= len;
			if (len > 0)
				_axrsw(arr1, arr2, len, res);
			len = _len;
		}

		/* Loop copying 64 bytes, until less than 64 left. */
		while (len > sizeof(_Afa_U512)) {
			*res = *arr1 ^ *arr2;
			res++; arr1++; arr2++; len -= sizeof(_Afa_U512);
		}

		/* Copy the remaining bits */
		_axrsw(arr1, arr2, len, res);
	}
	return _res;
}
