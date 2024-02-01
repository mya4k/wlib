/**
 * \file array.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Array module
 * \version 0.1
 * \date 2022-08-19
 * 
 * Array module provides functions operating on arrays.
 * \note An array here refer to an object of a defined size, storing a continuous collection of bytes, unless stated otherwise 
 * 
 * Types of operations:
 * -	array coping (acp)
 * -	bitwise operations (aor)
 * -	logical operations (aorl)
 * -	array filling
 * -	byte search
 * -	array search 
 */



#ifndef WL_ARRAY_H
#define WL_ARRAY_H	1



#include <wl/types.h>
#include <wl/core.h>



#if !WL_CONF_PREFIX
#	if WL_C_VA_MACRO
#		define ano(arr,len,...)				wl_ano(arr,len,__VA_ARGS__)
#		define aan(arr1,arr2,len,...)		wl_aan(arr1,arr2,len,__VA_ARGS__)
#		define aor(arr1,arr2,len,...)		wl_aor(arr1,arr2,len,__VA_ARGS__)
#		define axr(arr1,arr2,len,...)		wl_axr(arr1,arr2,len,__VA_ARGS__)
#		define ant(arr,len,...)				wl_ant(arr,len,__VA_ARGS__)
#		define ann(arr1,arr2,len,...)		wl_ann(arr1,arr2,len,__VA_ARGS__)
#		define anr(arr1,arr2,len,...)		wl_anr(arr1,arr2,len,__VA_ARGS__)
#		define anx(arr1,arr2,len,...)		wl_anx(arr1,arr2,len,__VA_ARGS__)
#		define afl(dst,ldst,src,...)		wl_afl(dst,ldst,src,__VA_ARGS__)
#	else
#		define ano(arr,len,res)				wl_ano(arr,len,res)
#		define aan(arr1,arr2,len,res)		wl_aan(arr1,arr2,len,res)
#		define aor(arr1,arr2,len,res)		wl_aor(arr1,arr2,len,res)
#		define axr(arr1,arr2,len,res)		wl_axr(arr1,arr2,len,res)
#		define ant(arr,len,res)				wl_ant(arr,len,res)
#		define ann(arr1,arr2,len,res)		wl_ann(arr1,arr2,len,res)
#		define anr(arr1,arr2,len,res)		wl_anr(arr1,arr2,len,res)
#		define anx(arr1,arr2,len,res)		wl_anx(arr1,arr2,len,res)
#		define afl(dst,ldst,src,lsrc)		wl_afl(dst,ldst,src,lsrc)
#	endif

#	define asl(arr,len,by)					wl_asl(arr,len,by)
#	define asr(arr,len,by)					wl_asr(arr,len,by)

#	define anol(arr,len)					wl_anol(arr,len)
#	define aanl(arr1,arr2,len)				wl_aanl(arr1,arr2,len)
#	define aorl(arr1,arr2,len)				wl_aorl(arr1,arr2,len)
#	define axrl(arr1,arr2,len)				wl_axrl(arr1,arr2,len)
#	define antl(arr,len)					wl_antl(arr,len)
#	define annl(arr1,arr2,len)				wl_annl(arr1,arr2,len)
#	define anrl(arr1,arr2,len)				wl_anrl(arr1,arr2,len)
#	define anxl(arr1,arr2,len)				wl_anxl(arr1,arr2,len)
#	define aeq(arr1,arr2,len)				wl_aeq(arr1,arr2,len)
#	define anq(arr1,arr2,len)				wl_anq(arr1,arr2,len)
#	define act(src,off,len,slice)			wl_act(src,off,len,slice)
#	define asb(haystack,len,byte)			wl_asb(haystack,len,byte)
#	define asbr(haystack,len,byte)			wl_asbr(haystack,len,byte)
#	define asbc(haystack,len,byte)			wl_asbc(haystack,len,byte)
#	define asa(haystack,needle,lenh,lenn)	wl_asa(haystack,needle,lenh,lenn)
#	define asar								wl_asar
#	define asac								wl_asac
#	define arb(haystack,len,needle,rep) 	wl_arb(haystack,len,needle,rep)
#	define ara(src,ndl,rep,lens,lenn,lenr)	wl_ara(src,ndl,rep,lens,lenn,lenr)
#	define acp(src,len,dst)					wl_acp(src,len,dst)
#	define amv(src,len,dst)					wl_amv(src,len,dst)
/* #	define amg(srcs,lens,count,dst)			wl_amg(srcs,lens,count,dst) */

#	define _ano			wl__ano
#	define _ant			wl__ant
#	define _aan			wl__aan
#	define _aor			wl__aor
#	define _axr			wl__axr
#	define _ann			wl__ann
#	define _anr			wl__anr
#	define _anx			wl__anx
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
#	define _amv			wl__amv
#	define _anq			wl__anq

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
 * \warning If two objects overlap, object \a arr will be overwritten in the 
 * proccess
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_STRING_H
#	include <string.h>
#	include <wl/memory.h>

#	if WL_C_VA_MACRO
#		define wl_ano(arr, len, ...)	\
		memcpy(	\
			(unlikely(__VA_ARGS__+0)\
			? (void*)(__VA_ARGS__+0)\
			: wl_mal(len)), (const char*)(arr), (len))
#	else
#		define wl_ano(arr, len, res)	\
		memcpy(	\
			(unlikely(res)\
			? (void*)(res)\
			: wl_mal(len)), (const char*)(arr), (len))
#	endif
#else	/* WL_STRING_H */
#	if WL_C_VA_MACRO
#		define wl_ano(arr, len, ...)	\
	wl__ano((char*)(arr), (len), (char*)(__VA_ARGS__+0))
#	else
#		define wl_ano(arr, len, res)	\
	wl__ano((char*)(arr), (len), (char*)(res))
#	endif
#endif	/* WL_STRING_H */

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
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with 
 * \a res
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
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned 
 * a pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with 
 * \a res
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
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned 
 * a pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with 
 * \a res
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
 * \warning If two objects overlap, object \a arr will be overwritten in the 
 * proccess
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_ant(arr, len, ...)	\
		wl__ant((char*)(arr), (len), (char*)(__VA_ARGS__+0))
#else
#	define wl_ant(arr, len, res)	\
		wl__ant((char*)(arr), (len), (char*)(res))
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
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned 
 * a pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with 
 * \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_ann(arr1, arr2, len, ...)	\
		wl__ann((char*)(arr1), (char*)(arr2), (len), (char*)(__VA_ARGS__+0))
#else
#	define wl_ann(arr1, arr2, len, res)	\
		wl__ann((char*)(arr), (char*)(arr2), (len), (char*)(res))
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
 * \note If \a res is a null pointer or omitted (C99), \a res will be assigned 
 * a pointer to freshly allocated object of \a len bytes.
 * 
 * \note \a len is interpreted as \e U32
 * 
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with 
 * \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_anr(arr1, arr2, len, ...)	\
		wl__anr((char*)(arr1), (char*)(arr2), (len), (char*)(__VA_ARGS__+0))
#else
#	define wl_anr(arr1, arr2, len, res)	\
		wl__anr((char*)(arr), (char*)(arr2), (len), (char*)(res))
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
 * \warning Behavior is undefined if either \a arr1 or \a arr2 overlap with 
 * \a res
 * 
 * \todo Integrate \a res null pointer handling into the expansion of the 
 * macro, rather than the function definition.
 */
#if WL_C_VA_MACRO
#	define wl_anx(arr1, arr2, len, ...)	\
		wl__anx((char*)(arr1), (char*)(arr2), (len), (char*)(__VA_ARGS__+0))
#else
#	define wl_anx(arr1, arr2, len, res)	\
		wl__anx((char*)(arr), (char*)(arr2), (len), (char*)(res))
#endif

/**
 * \brief	Array Shift Left
 * 
 * \def		asl(arr, len, by)
 * \arg		arr		Array to shift
 * \arg		len		Array size
 * \arg		by		Shift degree in bits
 * \return	void*	Address of \a arr
 * 
 * Logical left shift of \a arr of size \a len by \a by bits
 * 
 * Visualization:
 * \code 
 * *arr <<= by
 * \endcode
 */
#define	wl_asl(arr, len, by)	\
		(wl__asl((char*)(arr), (len), (by)))

/**
 * \brief	Array Shift Right
 * 
 * \def		asr(arr, len, by)
 * \arg		arr		Array to shift
 * \arg		len		Array size
 * \arg		by		Shift degree in bits
 * \return	void*	Address of \a arr
 * 
 * Logical right shift of \a arr of size \a len by \a by bits
 * 
 * Visualization:
 * \code 
 * *arr >>= by
 * \endcode
 */
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
 * \def		aanl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if both array are not filled with 0
 * 
 * Visualization:
 * \code 
 * return (*arr1)&&(*arr2)
 * \endcode
 */
#define wl_aanl(arr1, arr2, len) (				\
	wl__anol((char*)(arr1), (len)) 				\
	? ( wl__anol((char*)(arr2), (len)) ? 1 : 0) \
	: 0 )
/**
 * \brief	Array OR Logical
 * \def		aorl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if any array is not filled with 0
 * 
 * Visualization:
 * \code 
 * return (*arr1)||(*arr2)
 * \endcode
 */
#define wl_aorl(arr1, arr2, len) (				\
	wl__anol((char*)(arr1), (len)) 				\
	? 1  										\
	: (wl__anol((char*)(arr2), (len)) ? 1 : 0) )
/**
 * \brief	Array XOR Logical
 * \def		axrl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if one array initalized with 0 and the other one is not
 * 
 * Visualization:
 * \code 
 * return (!!*arr1) ^ (!!*arr2)
 * \endcode
 */
#define wl_axrl(arr1, arr2, len)\
	(wl_anol((arr1), (len)) != wl_anol((arr2), (len)))
/**
 * \brief	Array NOT Logical
 * \def		antl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * Returns TRUE, if all data of the array is set to 0
 * 
 * Visualization:
 * \code 
 * return !*arr
 * \endcode
 */
#define wl_antl(arr, len)			(!wl_anol((arr), (len)))
/**
 * \brief	Array NAND Logical
 * \def		annl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * Returns TRUE, if either of the arrays is filled with 0
 * 
 * Visualization:
 * \code 
 * return !(*arr1 && *arr2)
 * \endcode
 */
#define wl_annl(arr1, arr2, len)	(anol((arr1),(len)) && anol((arr2),(len)))
/**
 * \brief	Array NOR Logical
 * \def		anrl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if both  arrays are filled with 0
 * 
 * Visualization:
 * \code 
 * return !(*arr1 || *arr2)
 * \endcode
 */
#define wl_anrl(arr1, arr2, len)	(!wl_aorl((arr1), (arr2), (len)))
/**
 * \brief	Array NXOR Logical
 * \def		anxl(arr1, arr2, len)
 * \arg		arr1	First array operand
 * \arg		arr2	Second array operand
 * \arg		len		Length of the operands in bytes
 * \return	Bl
 * 
 * Returns TRUE, if both arrays are true or false
 * 
 * Visualization:
 * \code 
 * return !((!!*arr) ^ (!!*arr))
 * \endcode
 */
#define wl_anxl(arr1, arr2, len)\
	(wl_anol((arr1), (len)) == wl_anol((arr2), (len)))

/**
 * \brief	Array Not Equal 
 * 
 * \def		anq(arr1,arr2,len)
 * \arg		arr1	Array 1
 * \arg		arr2	Array 2
 * \arg		len		Size of both arrays
 * \return	Bl		True, if not equal
 * 
 * If the value of two objects are not equal, return true
 * 
 * Visualization:
 * ```
 * *arr1 != *arr2
 * ```
 */
#define wl_anq(arr1,arr2,len)	\
	(wl__anq((char*)(arr1), (char*)(arr2), (len)))

/**
 * \brief	Array Equal 
 * 
 * \def		aeq(arr1,arr2,len)
 * \arg		arr1	Array 1
 * \arg		arr2	Array 2
 * \arg		len		Size of both arrays
 * \return	Bl		True, if equal
 * 
 * If the value of two objects are equal, return true
 * 
 * Visualization:
 * ```
 * *arr1 == *arr2
 * ```
 */
#define wl_aeq(arr1,arr2,len)	(!wl_anq((arr1), (arr2), (len)))

/**
 * \brief	Array Cut
 * \def		act(arr,off,len,slice)
 * \param	arr		The source array
 * \param	off 	Offset of \a arr
 * \param	len		Length of the slice
 * \param	slice	Pointer to where slice will be stored
 * 
 * Cuts off a \a len byte slice from the source array starting after \a off 
 * bytes from base of the source array. The slice is stored at \a slice.
 */
#define wl_act(arr,off,len,slice)	(wl_ano((arr)+(off), (len), (slice)))

/**
 * \brief	Array Fill
 * \def		afl(dst, ldst, src, lsrc)
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
 * \def		asb(haystack, len, byte)
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
 * \def		asbr(haystack, len, byte)
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
 * \def		asbc(haystack, len, byte)
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

/**
 * \brief	Array Search Array
 * \def		asa(haystack, needle, lenh, lenn)
 * \param	haystack	Pointer to haystack array
 * \param	needle		Pointer to needle array
 * \param	lenh		Size of haystack array
 * \param	lenn		Size of needle array
 * \return	
 */
#	define wl_asa(haystack, needle, lenh, lenn) \
	((void*)wl__asa((char*)(haystack), (char*)(needle), (lenh), (lenn)))

#	define wl_arb(haystack, len, needle, rep)	\
	((void*)wl__arb((char*)(haystack), (len), (needle), (rep)))

#	define wl_ara(src, ndl, rep, lens, lenn, lenr) \
	((src) = (void*)wl__ara((char*)(src), (char*)(ndl), (char*)(rep), (lens), (lenn), (lenr)))

#	define wl_acp(src, len, dst)	wl_ano((src), (len), (dst))
#	define wl_amv(src, len, dst)	wl__amv((char*)(src), (len), (char*)(dst));



/* Defined in `array/afl.c` */
extern void wl_afla(
			char* restrict arr1,		wl_U32 len1,
	const	char* restrict arr2, const	wl_U32 len2
) nonnull((1,3));

/* Defined in `array/afl.c` */
extern void wl_aflv(
	char* restrict	arr, wl_U32	lena, 
	wl_UMax			val, wl_U8	lenv
) nonnull((1));

/* Defined in `array/axx.c` */
extern const void* wl__ano(
	char*	restrict	arr, 
	wl_U32				len,
	char*				res
) nonnull((1));

/* Defined in `array/axx.c` */
extern const void* wl__ant(
	char*	restrict	arr, 
	wl_U32				len,
	char*				res
) nonnull((1));

/* Defined in `array/axx.c` */
extern const void* wl__aan(
	char*	restrict	arr1,
	char*	restrict	arr2, 
	wl_U32				len,
	char*				res
) nonnull((1,2));

/* Defined in `array/axx.c` */
extern const void* wl__aor(
	char*	restrict	arr1,
	char*	restrict	arr2, 
	wl_U32				len,
	char*				res
) nonnull((1,2));

/* Defined in `array/axx.c` */
extern const void* wl__axr(
	char*	restrict	arr1,
	char*	restrict	arr2, 
	wl_U32				len,
	char*				res
) nonnull((1,2));

/* Defined in `array/axx.c` */
extern const void* wl__ann(
	char*	restrict	arr1,
	char*	restrict	arr2, 
	wl_U32				len,
	char*				res
) nonnull((1,2));

/* Defined in `array/axx.c` */
extern const void* wl__anr(
	char*	restrict	arr1,
	char*	restrict	arr2, 
	wl_U32				len,
	char*				res
) nonnull((1,2));

/* Defined in `array/axx.c` */
extern const void* wl__anx(
	char*	restrict	arr1,
	char*	restrict	arr2, 
	wl_U32				len,
	char*				res
) nonnull((1,2));

/* Defined in `array/asl.c` */
extern void wl__asl(
			char*	restrict const	arr,
	const	wl_U32					len,
			wl_U32					by
) nonnull((1));

/* Defined in `array/asr.c` */
extern void wl__asr(
			char*	restrict const	arr,
			wl_U32					len,
			wl_U32					by
) nonnull((1));

/* Defined in `array/anol.c` */
extern wl_Bl wl__anol(char* restrict arr1, wl_U32 len) pure nonnull((1));

/* Defined in `array/aanl.c` */
/*extern wl_Bl wl__aanl(
	const wl_UMax* restrict arr1, const wl_UMax* restrict arr2, wl_U32 len
)
nonnull((1,2));*/

/* Defined in `array/aorl.c` */
extern wl_Bl wl__aorl(
	char* restrict arr1, char* restrict arr2, wl_U32 len
) pure nonnull((1,2));

extern wl_Bl wl__anq(
	char* restrict arr1, char* restrict arr2, wl_U32 len
) pure nonnull((1,2));

/* Defined in `array/asb.c` */
extern const char* wl__asb(
	const	char* restrict	haystack,
			wl_U32			len,
	const	char			byte
) nonnull((1));

/* Defined in `array/asb.c` */
extern const char* wl__asbr(
	const	char*	restrict	haystack,
			wl_U32				len,
	const	char				byte
) nonnull((1));

/* Defined in `array/asb.c` */
extern wl_U32 wl__asbc(
	const	char*	restrict	haystack,
			wl_U32				len,
	const	char				byte
) nonnull((1));

/* Defined in `array/asa.c` */
extern const char* wl__asa(
	const	char*	restrict			haystack,
	const	char*	restrict	const	needle,
			wl_U32						lenh,
	const	wl_U32 						lenn
) nonnull((1,2));

/* Defined in `array/arb.c` */
extern void wl__arb(
	const	char*	restrict	const	haystack,
	const	wl_U32						len,
	const	char						byte,
	const	char						rep	
) nonnull((1));

/* Defined in `array/ara.c` */
extern const char* wl__ara(
	const	char*	restrict	const	src,
	const	char*	restrict	const	ndl,
	const	char*	restrict	const	rep,
	const	wl_U32		lens,
	const	wl_U32		lenn,
	const	wl_U32		lenr
) nonnull((1,2,3));

/* Defined in `array/amv.c` */
extern const void* wl__amv(
	const char* restrict const src, 
	const wl_U32 len, 
	char* restrict const dst
) nonnull((1));

/* Defined in `array/amg.c` */
extern char* amga(
	char* _dst,
	const U8 count,
	char** restrict	srcs,
	const U32* restrict const lens
);

extern char* amgv(
	char* _dst,
	const U8 count,
	...
);

#endif
