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
#	ifdef WL_C_VA_MACRO
#		define ano(arr,len,...)			wl_ano(arr,len,__VA_ARGS__)
#		define aan(arr1,arr2,len,...)	wl_aan(arr1,arr2,len,__VA_ARGS__)
#		define aor(arr1,arr2,len,...)	wl_aor(arr1,arr2,len,__VA_ARGS__)
#		define axr(arr1,arr2,len,...)	wl_axr(arr1,arr2,len,__VA_ARGS__)
#		define ant(arr,len,...)			wl_ant(arr,len,__VA_ARGS__)
#		define ann(arr1,arr2,len,...)	wl_ann(arr1,arr2,len,__VA_ARGS__)
#		define anr(arr1,arr2,len,...)	wl_anr(arr1,arr2,len,__VA_ARGS__)
#		define anx(arr1,arr2,len,...)	wl_anx(arr1,arr2,len,__VA_ARGS__)
#		define afl(dst,ldst,src,...)	wl_afl(dst,ldst,src,__VA_ARGS__)
#	else
#		define ano(arr,len,res)			wl_ano(arr,len,res)
#		define aan(arr1,arr2,len,res)	wl_aan(arr1,arr2,len,res)
#		define aor(arr1,arr2,len,res)	wl_aor(arr1,arr2,len,res)
#		define axr(arr1,arr2,len,res)	wl_axr(arr1,arr2,len,res)
#		define ant(arr,len,res)			wl_ant(arr,len,res)
#		define ann(arr1,arr2,len,res)	wl_ann(arr1,arr2,len,res)
#		define anr(arr1,arr2,len,res)	wl_anr(arr1,arr2,len,res)
#		define anx(arr1,arr2,len,res)	wl_anx(arr1,arr2,len,res)
#		define afl(dst,ldst,src,lsrc)	wl_afl(dst,ldst,src,lsrc)
#	endif

#	define asl(arr,len,by)			wl_asl(arr,len,by)
#	define asr(arr,len,by)			wl_asr(arr,len,by)

#	define anol(arr,len)			wl_anol(arr,len)
#	define aanl(arr1,arr2,len)		wl_aanl(arr1,arr2,len)
#	define aorl(arr1,arr2,len)		wl_aorl(arr1,arr2,len)
#	define axrl(arr1,arr2,len)		wl_axrl(arr1,arr2,len)
#	define antl(arr,len)			wl_antl(arr,len)
#	define annl(arr1,arr2,len)		wl_annl(arr1,arr2,len)
#	define anrl(arr1,arr2,len)		wl_anrl(arr1,arr2,len)
#	define anxl(arr1,arr2,len)		wl_anxl(arr1,arr2,len)
#	define aeq(arr1,arr2,len)		wl_aeq(arr1,arr2,len)
#	define anq(arr1,arr2,len)		wl_anq(arr1,arr2,len)
#	define act(src,off,len,slice)	wl_act(src,off,len,slice)
#	define asb(haystack,len,byte)	wl_asb(haystack,len,byte)
#	define asbr(haystack,len,byte)	wl_asbr(haystack,len,byte)
#	define asbc(haystack,len,byte)	wl_asbc(haystack,len,byte)
#	define asa(haystack,needle,lenh,lenn)	wl_asa(haystack,needle,lenh,lenn)
#	define asar			wl_asar
#	define asac			wl_asac
#	define arb(haystack,len,needle,rep) wl_arb(haystack,len,needle,rep)
#	define ara(src,ndl,rep,lens,lenn,lenr)	wl_ara(src,ndl,rep,lens,lenn,lenr)

#	define _ano			wl__ano
#	define _aan			wl__aan
#	define _aor			wl__aor
#	define _axr			wl__axr
#	define _asl			wl__asl
#	define _asr			wl__asr
#	define _anol		wl__anol
#	define _aanl		wl__aanl
#	define _aorl		wl__aorl
#	define _asb			wl__asb
#	define _asbr		wl__asbr
#	define _asbc		wl__asbc
#	define _asa			wl__asa
#	define _arb			wl__arb
#	define _ara			wl__ara
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

#define	wl_asl(arr, len, by)	\
		(wl__asl((char*)(arr), (len), (by)))

#define	wl_asr(arr, len, by)	\
		(wl__asr((char*)(arr), (len), (by)))



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
#define wl_aorl(arr1, arr2, len) (				\
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
#define wl_annl(arr1, arr2, len)	(anol((arr1),(len)) && anol((arr2),(len)))
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
	(wl__anq((char*)(arr1), (char*)(arr2), (len)))

#define wl_aeq(arr1,arr2,len)	(!wl_anq((arr1), (arr2), (len)))

/**
 * \brief	Array Cut
 * \def		wl_act(arr,off,len,slice)
 * \param	arr		The source array
 * \param	off 	Offset of \a arr
 * \param	len		Length of the slice
 * \param	slice	Pointer to where slice will be stored
 * 
 * Cuts off a \a len byte slice from the source array starting after \a off bytes from base of the source array. The slice is stored at \a slice.
 */
#define wl_act(arr,off,len,slice)	(wl_ano((arr)+(off), (len), (slice)))

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
		? wl_afla((char*)(dst), (ldst), (char*)(src), (__VA_ARGS__))	\
		: wl_aflv((char*)(dst), (ldst), (src), sizeof(src))
#else
#	define wl_afl(dst, ldst, src, lsrc)		\
		(lsrc)+0								\
		? wl_afla((char*)(dst), (ldst), (char*)(src), (lsrc))		\
		: wl_aflv((char*)(dst), (ldst), (src), sizeof(src))
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
	((void*)wl__asb((char*)(haystack), (len), (byte)))

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
	((void*)wl__asbr((char*)(haystack), (len), (byte)))

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
	(wl__asbc((char*)(haystack), (len), (byte)))

#	define wl_asa(haystack, needle, lenh, lenn) \
	((void*)wl__asa((char*)(haystack), (char*)(needle), (lenh), (lenn)))

#	define wl_arb(haystack, len, needle, rep)	\
	((void*)wl__arb((char*)(haystack), (len), (needle), (rep)))

#	define wl_ara(src, ndl, rep, lens, lenn, lenr) \
	((src) = (void*)wl__ara((char*)(src), (char*)(ndl), (char*)(rep), (lens), (lenn), (lenr)))



/* Defined in `array/afl.c` */
EXTERN void wl_afla(
			char* restrict arr1,		wl_U32 len1,
	const	char* restrict arr2, const	wl_U32 len2
) nonnull((1,2));

/* Defined in `array/afl.c` */
EXTERN void wl_aflv(
	char* restrict	arr, wl_U32	lena, 
	wl_UMax				val, wl_U8	lenv
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

/* Defined in `array/asl.c` */
EXTERN void wl__asl(
	const	char*	restrict const	arr,
			wl_U32					len,
			wl_U32					by
) nonnull((1));

/* Defined in `array/asr.c` */
EXTERN void wl__asr(
			char*	restrict const	arr,
			wl_U32					len,
			wl_U32					by
) nonnull((1));

/* Defined in `array/anol.c` */
EXTERN wl_Bl wl__anol(const char* restrict arr1, wl_U32 len) nonnull((1));

/* Defined in `array/aanl.c` */
/*EXTERN wl_Bl wl__aanl(
	const wl_UMax* restrict arr1, const wl_UMax* restrict arr2, wl_U32 len
)
nonnull((1,2));*/

/* Defined in `array/aorl.c` */
EXTERN wl_Bl wl__aorl(
	const char* restrict arr1, const char* restrict arr2, wl_U32 len
) nonnull((1,2));

EXTERN wl_Bl wl__anq(
	const char* restrict arr1, const char* restrict arr2, wl_U32 len
) nonnull((1,2));

/* Defined in `array/asb.c` */
EXTERN const char* wl__asb(
	const	char* restrict	haystack,
			wl_U32			len,
	const	char			byte
) nonnull((1));

/* Defined in `array/asb.c` */
EXTERN const char* wl__asbr(
	const	char*	restrict	haystack,
			wl_U32				len,
	const	char				byte
) nonnull((1));

/* Defined in `array/asb.c` */
EXTERN wl_U32 wl__asbc(
	const	char*	restrict	haystack,
			wl_U32				len,
	const	char				byte
) nonnull((1));

/* Defined in `array/asa.c` */
EXTERN const char* wl__asa(
	const	char*	restrict			haystack,
	const	char*	restrict	const	needle,
			wl_U32						lenh,
	const	wl_U32 						lenn
) nonnull((1,2));

/* Defined in `array/arb.c` */
EXTERN void wl__arb(
	const	char*	restrict	const	haystack,
	const	wl_U32						len,
	const	char						byte,
	const	char						rep	
) nonnull((1));

/* Defined in `array/ara.c` */
EXTERN const char* wl__ara(
	const	char*	restrict	const	src,
	const	char*	restrict	const	ndl,
	const	char*	restrict	const	rep,
	const	U32		lens,
	const	U32		lenn,
	const	U32		lenr
) nonnull((1,2,3));

#endif
