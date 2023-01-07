/**
 * \file array.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Array manipulation functions
 * \version 0.1
 * \date 2022-08-19
 * 
 * This header provides functions:
 * 	- copy data
 * 	- perform binary operations on data
 * 	- perform logical operation on data
 * 	- search for a specific byte or data in memory
 * 	- replace occurrences of byte or data in memory
 * 	- fill memory with data
 */



#ifndef WL_ARRAY_H
#define WL_ARRAY_H	1



#include <wl/types.h>
#include <wl/core.h>



#if !WL_CONF_PREFIX
#	define ano			wl_ano
#	define aan			wl_aan
#	define aor			wl_aor
#	define axr			wl_axr
#	define ant			wl_ant
#	define ann			wl_ann
#	define anr			wl_anr
#	define anx			wl_anx
#	define anol			wl_anol
#	define aanl			wl_aanl
#	define aorl			wl_aorl
#	define axrl			wl_axrl
#	define antl			wl_antl
#	define annl			wl_annl
#	define anrl			wl_anrl
#	define anxl			wl_anxl
#	define aeq			wl_aeq
#	define anq			wl_anq
#	define afl			wl_afl
#	define asb			wl_asb
#	define asbr			wl_asbr
#	define asbc			wl_asbc
#	define asa			wl_asa
#	define asar			wl_asar
#	define asac			wl_asac

#	define _ano			wl__ano
#	define _aan			wl__aan
#	define _aor			wl__aor
#	define _axr			wl__axr
#	define _anol		wl__anol
#	define _aanl		wl__aanl
#	define _aorl		wl__aorl
#	define _asb			wl__asb
#	define _asbr		wl__asbr
#	define _asbc		wl__asbc
#	define afla			wl_afla
#	define aflv			wl_aflv

#endif



/**
 * \brief	Array No Operation (Array copy)
 * 
 * \def		ano(arr, len, ...)
 * \def		ano(arr, len, res)
 * 
 * \arg		arr	Array operand
 * \arg		len	Length of the operand in bytes
 * \arg		res	Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Copies the object of \a len bytes beginning at \a arr into the object of the
 * same size beginning at \a res.   
 * 
 * Visualization:
 * \code 
 * *res = *arr
 * \endcode
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning If two objects overlap, object \a arr will be overwritten in the proccess
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_STRING
#	if WL_C_VA_MACRO
#		define wl_ano(arr, len, ...)	memcpy((__VA_ARGS__+0), (arr), (len))
#	else
#		define wl_ano(arr, len, res)	memcpy((res), (arr), (len))
#	endif
#else
#	if WL_C_VA_MACRO
#		define wl_ano(arr, len, ...)	\
	wl__ano((char*)(arr), (len), (char*)(__VA_ARGS__+0))
#	else
#		define wl_ano(arr, len, res)	\
	wl__ano((char*)(arr), (len), (char*)(res))
#	endif
#endif

/**
 * \brief	Array AND
 * 
 * \def		aan(arr1, arr2, len, ...)
 * \def		aan(arr1, arr2, len, res)
 * 
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operand in bytes
 * \arg		res		Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Performs binary AND on the objects of \a len bytes beginning at \a arr1 and
 * \a arr2, then the resulting object is output to the object of the same size
 * beginning at \a res.
 * 
 * Visualization:
 * \code 
 * *res = *arr1 & *arr2
 * \endcode
 * 
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned a 
 * pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_aan(arr1, arr2, len, ...)										\
	(wl__aan((char*)(arr1), (char*)(arr2), (len),	\
	(char*)(__VA_ARGS__+0)))
#else
#	define wl_aan(arr1, arr2, len, res)										\
	(wl__aan((char*)(arr1), (char*)(arr2), (len),	\
	(char*)(res)))
#endif

/**
 * \brief	Array OR
 * 
 * \def		aor(arr1, arr2, len, ...)
 * \def		aor(arr1, arr2, len, res)
 * 
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operand in bytes
 * \arg		res		Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Performs binary OR on the objects of \a len bytes beginning at \a arr1 and
 * \a arr2, then the resulting object is output to the object of the same size
 * beginning at \a res.
 * 
 * Visualization:
 * \code 
 * *res = *arr1 | *arr2
 * \endcode
 * 
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned a 
 * pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_aor(arr1, arr2, len, ...)										\
	(wl__aor((char*)(arr1), (char*)(arr2), (len),	\
	(char*)(__VA_ARGS__+0)))
#else
#	define wl_aor(arr1, arr2, len, res)										\
	(wl__aor((char*)(arr1), (char*)(arr2), (len),	\
	(char*)(res)))
#endif

/**
 * \brief	Array XOR
 * 
 * \def		axr(arr1, arr2, len, ...)
 * \def		axr(arr1, arr2, len, res)
 * 
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operand in bytes
 * \arg		res		Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Performs binary XOR on the objects of \a len bytes beginning at \a arr1 and
 * \a arr2, then the resulting object is output to the object of the same size
 * beginning at \a res.
 * 
 * Visualization:
 * \code 
 * *res = *arr1 ^ *arr2
 * \endcode
 * 
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned a 
 * pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_axr(arr1, arr2, len, ...)										\
	(wl__axr((char*)(arr1), (char*)(arr2), (len),	\
	(char*)(__VA_ARGS__+0)))
#else
#	define wl_axr(arr1, arr2, len, res)										\
	(wl__axr((char*)(arr1), (char*)(arr2), (len),	\
	(char*)(res)))
#endif

/**
 * \brief	Array NOT
 * 
 * \def		ant(arr, len, ...)
 * \def		ant(arr, len, res)
 * 
 * \arg		arr	Array operand
 * \arg		len	Length of the operand in bytes
 * \arg		res	Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Performs binary NOT on the object of \a len bytes beginning at \a arr, 
 * then the resulting object is output to the object of the same size 
 * beginning at \a res.
 * 
 * Visualization:
 * \code 
 * *res = ~*arr
 * \endcode
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning If two objects overlap, object \a arr will be overwritten in the proccess
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_ant(arr, len, ...)	\
		(!wl_ano((arr), (len), (__VA_ARGS__+0)))
#else
#	define wl_ant(arr, len, res)	\
		(!wl_ano((arr), (len), (res)))
#endif

/**
 * \brief	Array NAND
 * 
 * \def		ann(arr1, arr2, len, ...)
 * \def		ann(arr1, arr2, len, res)
 * 
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operand in bytes
 * \arg		res		Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Performs binary NAND on the objects of \a len bytes beginning at \a arr1 and
 * \a arr2, then the resulting object is output to the object of the same size
 * beginning at \a res.
 * 
 * Visualization:
 * \code 
 * *res = ~(*arr1 & *arr2)
 * \endcode
 * 
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned a 
 * pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_ann(arr1, arr2, len, ...)\
		(!wl_aan((arr1), (arr1), (len), (__VA_ARGS__+0)))
#else
#	define wl_ann(arr1, arr2, len, res)\
		(!wl_aan((arr1), (arr1), (len), (res)))
#endif

/**
 * \brief	Array NOR
 * 
 * \def		anr(arr1, arr2, len, ...)
 * \def		anr(arr1, arr2, len, res)
 * 
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operand in bytes
 * \arg		res		Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Performs binary NOR on the objects of \a len bytes beginning at \a arr1 and
 * \a arr2, then the resulting object is output to the object of the same size
 * beginning at \a res.
 * 
 * Visualization:
 * \code 
 * *res = ~(*arr1 | *arr2)
 * \endcode
 * 
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned a 
 * pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_anr(arr1, arr2, len, ...)\
		(!wl_aor((arr1), (arr1), (len), (__VA_ARGS__+0)))
#else
#	define wl_anr(arr1, arr2, len, res)\
		(!wl_aor((arr1), (arr1), (len), (res)))
#endif

/**
 * \brief	Array NXOR
 * 
 * \def		anx(arr1, arr2, len, ...)
 * \def		anx(arr1, arr2, len, res)
 * 
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operand in bytes
 * \arg		res		Pointer to store the result in (C99 optional)
 * 
 * \return	void*	
 * 
 * Performs binary NXOR on the objects of \a len bytes beginning at \a arr1 and
 * \a arr2, then the resulting object is output to the object of the same size
 * beginning at \a res.
 * 
 * Visualization:
 * \code 
 * *res = ~(*arr1 ^ *arr2)
 * \endcode
 * 
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned
 * a pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_anx(arr1, arr2, len, ...)\
		(!wl_axr((arr1), (arr1), (len), (__VA_ARGS__+0)))
#else
#	define wl_anx(arr1, arr2, len, res)\
		(!wl_axr((arr1), (arr1), (len), (res)))
#endif



/**
 * \brief	Array No Operation Logical
 * 
 * \def		anol(arr, len)
 * 
 * \arg		arr	First array operand
 * \arg		len	Length of the operands in bytes
 * 
 * \return	TRUE, unless the object is filled with only zero bits
 * 
 * The `anol()` function returns the boolean value of the object
 * 
 * Visualization:
 * \code 
 * return !!*arr
 * \endcode
 * 
 * \note \a len is interpreted as \e U32
 */
#define wl_anol(arr, len)	wl__anol((char*)(arr), (len))
/**
 * \brief	Array AND Logical
 * \def		wl_aanl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if both array are not filled with 0
 */
#define wl_aanl(arr1, arr2, len) (				\
	wl__anol((char*)(arr1), (len)) 				\
	? ( wl__anol((char*)(arr2), (len)) ? 1 : 0) \
	: 0 )
/**
 * \brief	Array OR Logical
 * \def		wl_aorl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if any array is not filled with 0
 */
#define wl_aanl(arr1, arr2, len) (				\
	wl__anol((char*)(arr1), (len)) 				\
	? 1  										\
	: (wl__anol((char*)(arr2), (len)) ? 1 : 0) )
/**
 * \brief	Array XOR Logical
 * \def		wl_axrl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if one array initalized with 0 and the other one is not
 */
#define wl_axrl(arr1, arr2, len)	(wl_anol((arr1), (len)) != wl_anol((arr2), (len)))
/**
 * \brief	Array NOT Logical
 * \def		wl_antl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * Returns TRUE, if all data of the array is set to 0
 */
#define wl_antl(arr, len)			(!wl_anol((arr), (len)))
/**
 * \brief	Array NAND Logical
 * \def		wl_antl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * Returns TRUE, if either of the arrays is filled with 0
 */
#define wl_annl(arr1, arr2, len)	(!wl_aanl((arr1), (arr2), (len)))
/**
 * \brief	Array NAND Logical
 * \def		wl_antl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if both  arrays are filled with 0
 */
#define wl_anrl(arr1, arr2, len)	(!wl_aorl((arr1), (arr2), (len)))
/**
 * \brief	Array XOR Logical
 * \def		wl_axrl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if both arrays are true or false
 */
#define wl_anxl(arr1, arr2, len)\
	(wl_anol((arr1), (len)) == wl_anol((arr2), (len)))


#define wl_anq(arr1,arr2,len)	\
	(wl__anq((wl_UMax*)(arr1), (wl_UMax*)(arr2), (len)))

#define wl_aeq(arr1,arr2,len)	(!wl_anq((arr1), (arr2), (len)))

/**
 * \brief	Array Fill
 * \def		define wl_afl(dst, ldst, src, opt_lsrc)
 * \arg		dst		Array to be filled
 * \arg		ldst	Byte length of `dst`
 * \arg		src		Fill object or pointer to fill object
 * \arg		lsrc	Size of fill object pointed by `src` (optional)
 * \return	Bl
 * 
 * If `lsrc` is 0, the function expects `src` to be the object that will be 
 * repeatedly copied over the length of object pointed to by `dst`.
 * Otherwise, the function expects `src` to be a pointer to the object with
 * length of `lsrc` bytes that will be  repeatedly copied over the length of
 * the object pointed to by `dst`.
 * 
 * If there is not enough space in the object pointed by `dst` remaining to 
 * copy to, only the remaining amount of bytes from `src` object will be 
 * copied.
 */
#if WL_C_VA_MACRO
#	define wl_afl(dst, ldst, src, ...)			\
		(__VA_ARGS__+0)							\
		? afla(dst, ldst, src, (__VA_ARGS__))	\
		: aflv(dst, ldst, src, sizeof(src));
#else
#	define wl_afl(dst, ldst, src, lsrc)		\
		lsrc+0								\
		? afla(dst, ldst, src, lsrc)		\
		: aflv(dst, ldst, src, sizeof(src));
#endif

/**
 * \brief	Array Search Byte
 * \def		wl_asb(haystack, len, byte)
 * \arg		haystack	Pointer to haystack array
 * \arg		len			Length of haystack array in bytes
 * \arg		byte		Needle byte
 * \return	void*
 * 
 * Searches all bytes in haystack array until the first occurrence of value 
 * `byte` and returns pointer to the byte where it was found. Returns NULL, if
 * there are no bytes with value of `byte`. 
 * 
 * 
 * Returns NULL, if `haystack` is NULL or `len` is 0
 */
#	define wl_asb(haystack, len, byte)	\
	((void*)wl__asb((UMax*)(haystack), (len), (byte)))

/**
 * \brief	Array Search Byte Reverse
 * \def		wl_asbr(haystack, len, byte)
 * \arg		haystack	Pointer to haystack array
 * \arg		len			Length of haystack array in bytes
 * \arg		byte		Needle byte
 * \return	void*
 * 
 * Searches all bytes in haystack array until the last occurrence of value 
 * `byte` and returns pointer to the byte where it was found. Returns NULL, if
 * there are no bytes with value of `byte`. 
 * 
 * Returns NULL, if `haystack` is NULL or `len` is 0
 */
#	define wl_asbr(haystack, len, byte)	\
	((void*)wl__asbr((UMax*)(haystack), (len), (byte)))

/**
 * \brief	Array Search Byte Count
 * \def		wl_asbc(haystack, len, byte)
 * \arg		haystack	Pointer to haystack array
 * \arg		len			Length of haystack array in bytes
 * \arg		byte		Needle byte
 * \return	U32
 * 
 * Searches all bytes in haystack array for occurrences of value `byte` and 
 * returns the amount of occurrences found.
 * 
 * Returns NULL, if `haystack` is NULL or `len` is 0
 */
#	define wl_asbc(haystack, len, byte)	\
	(wl__asbc((UMax*)(haystack), (len), (byte)))



/* Defined in `array/afl.c` */
EXTERN const void* wl_afla(
			char* restrict arr1,		wl_U32 len1,
	const	char* restrict arr2, const	wl_U32 len2
) nonnull((1,2));

/* Defined in `array/afl.c` */
EXTERN const void* wl_aflv(
	wl_UMax* restrict	arr, wl_U32	lena, 
	wl_UMax				val, wl_U32	lenv
) nonnull((1));

/* Defined in `array/axx.c` */
EXTERN const void* wl__ano(
	const	char* restrict	arr, 
			wl_U32					len,
			char* restrict	res
)
nonnull((1));

/* Defined in `array/axx.c` */
EXTERN const void* wl__aan(
	const	char* restrict	arr1, 
	const	char* restrict	arr2, 
			wl_U32					len, 
			char* restrict	res
) nonnull((1,2));

/* Defined in `array/axx.c` */
EXTERN const void* wl__aor(
	const	char* restrict	arr1, 
	const	char* restrict	arr2, 
			wl_U32					len, 
			char* restrict	res
) nonnull((1,2));

/* Defined in `array/axx.c` */
EXTERN const void* wl__axr(
	const	char* restrict	arr1, 
	const	char* restrict	arr2, 
			wl_U32					len, 
			char* restrict	res
) nonnull((1,2));

/* Defined in `array/axxl.c` */
EXTERN wl_Bl wl__anol(const char* restrict arr1, wl_U32 len) nonnull((1));

/* Defined in `array/asb.c` */
EXTERN const char* wl__asb(
	const	UMax*	restrict	haystack,
			U32					len,
	const	char				byte
) nonnull((1));

/* Defined in `array/asb.c` */
EXTERN const char* wl__asbr(
	const	UMax*	restrict	haystack,
			U32					len,
	const	char				byte
) nonnull((1));

/* Defined in `array/asb.c` */
EXTERN wl_U32 wl__asbc(
	const	UMax*	restrict	haystack,
			U32					len,
	const	char				byte
) nonnull((1));


#endif
