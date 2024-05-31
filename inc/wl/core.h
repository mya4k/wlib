#ifndef WL_CORE_H
#define WL_CORE_H



#include <wl/config.h>
#include <wl/types.h>



#if !WL_PREFIX
#	define vaa				wl_vaa
#	define genericSigned	wl_genericSigned
#	define genericUnsigned	wl_genericUnsigned
#	define genericInt		wl_genericInt
#endif



#ifndef __attribute__
#  if !WL_GNUC_PREREQ(2,8)
#    define __attribute__(x)
#  endif
#endif

/**
 * \brief	C++ compatible `extern`
 * \def		extern
 * 
 */
#if WL_CPP
#	define extern	extern "C"
#endif	/* WL_CPP */

/**
 * \brief	C89 compatible `restrict`
 * \def		restrict
 */
#if WL_C < WL_VER_C99
#	define restrict
#endif	/* WL_C < WL_VER_C99 */

/**
 * \brief	C89 compatible `inline`
 * \def		inline
 */
#if WL_C < WL_VER_C99
#	if	WL_GCC
#		define inline	gnu_inline
#	else
#		define inline
#	endif
#endif	/* WL_C < WL_VER_C99 */

/**
 * \brief	C89 compatible forced `inline`
 * \def		always_inline
 */
#undef	always_inline
#	if WL_GCC
#		define always_inline	inline __attribute__((always_inline))
#	else
#		define always_inline	inline
#endif

#ifndef inline_unless_opt_size
#	if WL_OPTIMIZE&3 != WL_OPTIMIZE_SIZE
#		define inline_unless_opt_size always_inline
#	else	/* WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE*/
#		define inline_unless_opt_size
#	endif	/* WL_OPTIMIZE&4 != WL_OPTIMIZE_SIZE*/
#endif

#ifdef __glibc_likely
#define likely(cond)	__glibc_likely((long)(cond))	
#else
#define likely(cond)	(cond)
#endif

#ifdef __glibc_unlikely	
#define unlikely(cond)	__glibc_unlikely((long)(cond))
#else
#define unlikely(cond)	(cond)
#endif

#ifdef __builtin_expect_with_probability
#	define if_probability(cond, probability) if(__builtin_expect_with_probability((long)(cond), 1, (probability)))
#else
#	define if_probability(cond, probability) if(cond)
#endif

#define if_likely(cond)		if(likely(cond))
#define if_unlikely(cond)	if(unlikely(cond))

#if !WL_GCC_ATTRIBUTE && !defined(__attribute__)
#	define __attribute__(X)
#endif

#if !WL_C_ATTRIBUTE && !defined(__has_c_attribute)
#	define __has_c_attribute(X)	0
#endif

#if !WL_CPP_ATTRIBUTE && !defined(__has_cpp_attribute)
#	define __has_cpp_attribute(X)	0
#endif


/*
 *	ATTRIBUTES
 */
#if WL_C_ATTRIBUTE

	/* [[fallthrough]] */
#	if __has_c_attribute(fallthrough)
#		define fallthrough			[[fallthrough]]
#	endif

	/* [[maybe_unused]] */
#	if __has_c_attribute(maybe_unused)
#		define maybe_unused			[[maybe_unused]]
#		define unused				[[maybe_unused]]
#	endif

	/* [[nodiscard]] */
#	if __has_c_attribute(nodiscard)
#		define nodiscard				[[nodiscard]]
#		define warn_unused_result	[[nodiscard]]
#	endif

	/* [[noreturn]] */
#	if __has_c_attribute(noreturn)
#		define noreturn				[[noreturn]]
#	else
#		define noreturn				_Noreturn
#	endif

#elif WL_CPP_ATTRIBUTE

	/* [[fallthrough]] */
#	if __has_cpp_attribute(fallthrough)
#		define fallthrough			[[fallthrough]]
#	endif

	/* [[maybe_unused]] */
#	if __has_cpp_attribute(maybe_unused)
#		define maybe_unused			[[maybe_unused]]
#		define unused				[[maybe_unused]]
#	endif

	/* [[nodiscard]] */
#	if __has_cpp_attribute(nodiscard)
#		define nodiscard				[[nodiscard]]
#		define warn_unused_result	[[nodiscard]]
#	endif

	/* [[noreturn]] */
#	if __has_cpp_attribute(noreturn)
#		define noreturn				[[noreturn]]
#	else
#		define noreturn
#	endif

#else

#	if WL_C >= WL_VER_C11
#		define noreturn				_Noreturn
#	else
#		define noreturn
#		define _Noreturn
#	endif

#	if WL_GCC_ATTRIBUTE
#		define fallthrough			__attribute__((fallthrough))
#		define maybe_unused			__attribute__((unused))
#		define unused				__attribute__((unused))
#		define nodiscard			__attribute__((warn_unused_result))
#		define warn_unused_result	__attribute__((warn_unused_result))
#	else
#		define fallthrough
#		define maybe_unused
#		define unused
#		define nodiscard
#		define warn_unused_result
#	endif

#endif

#if WL_GCC_ATTRIBUTE
#	if WL_GNU_ATTRIBUTE
#		define nonnull(X)				[[gnu::nonnull##X##]]
#		define returns_nonnull			[[gnu::returns_nonnull]]
#		define pure						[[gnu::pure]]
#	else
#		ifndef nonnull
#			define nonnull(X)				__attribute__((nonnull X))
#		endif

#		ifndef returns_nonnull
#			define returns_nonnull(X)		__attribute__((returns_nonnull X))
#		endif

#		ifndef pure
#			define pure						__attribute__((pure))
#		endif
#	endif
#endif



#if WL_VA_MACRO
#	define	wl_vaa(type, ...)		(type[]){__VA_ARGS__}
#else
/* Not supported */
#endif



#if WL__GENERIC

#	define WL_GENERIC_SIGNED_CHAR\
		signed char:			funcI8
#	define WL_GENERIC_UNSIGNED_CHAR\
		unsigned char:			funcU8

#	define WL_GENERIC_SHORT\
		short:					funcI16
#	define WL_GENERIC_UNSIGNED_SHORT\
		unsigned char:			funcU16	

#	if WL_DATAMODEL == WL_LP32
#		define WL_GENERIC_INT\
			int:				funcI16
#		define WL_GENERIC_UNSIGNED_INT\
			unsigned int:		funcU16
#	else
#		define WL_GENERIC_INT\
			int:				funcI32
#		define WL_GENERIC_UNSIGNED_INT\
			unsigned int:		funcU32
#	endif

#	if WL_DATAMODEL == WL_LP32 || WL_DATAMODEL == WL_ILP32\
	|| WL_DATAMODEL == WL_LLP64
#		define WL_GENERIC_LONG\
			long:				funcI32
#		define WL_GENERIC_UNSIGNED_LONG\
			unsigned long:		funcU32
#	else
#		define WL_GENERIC_LONG\
			long:				funcI64
#		define WL_GENERIC_UNSIGNED_LONG\
			unsigned long:		funcU64
#	endif

#	if WL_LONG_LONG
#		define WL_GENERIC_LONG_LONG\
			long long:	funcI64,
#		define WL_GENERIC_UNSIGNED_LONG_LONG\
			unsigned long long:	funcU64,
#	else	/* WL_LONG_LONG */
#		define WL_GENERIC_SIGNED_LONG_LONG
#		define WL_GENERIC_UNSIGNED_LONG_LONG
#	endif	/* WL_LONG_LONG */

#	define WL_GENERIC_FLOATS\
		float:				funcFloat,\
		double:				funcDouble,\
		long double:		funcLongDouble

#	define WL_GENERIC_SIGNED_BODY\
		WL_GENERIC_LONG_LONG\
		WL_GENERIC_SIGNED_CHAR,\
		WL_GENERIC_SHORT,\
		WL_GENERIC_INT,\
		WL_GENERIC_LONG

#	define WL_GENERIC_UNSIGNED_BODY\
		WL_GENERIC_UNSIGNED_LONG_LONG\
		WL_GENERIC_UNSIGNED_SIGNED_CHAR,\
		WL_GENERIC_UNSIGNED_SHORT,\
		WL_GENERIC_UNSIGNED_INT,\
		WL_GENERIC_UNSIGNED_LONG\

/**
 * \brief	Generic selection for signed integer types
 * \def		genericSigned(control, funcI8, funcI16, funcI32, funcI64)
 */
#	define wl_genericSigned(control, funcI8, funcI16, funcI32, funcI64)\
		_Generic((control), WL_GENERIC_SIGNED_BODY)

/**
 * \brief	Generic selection for unsigned integer types
 * \def		genericSigned(control, funcU8, funcU16, funcU32, funcU64)
 */
#	define wl_genericUnsigned(control, funcU8, funcU16, funcU32, funcU64)\
		_Generic((control), WL_GENERIC_UNSIGNED_BODY)

/**
 * \brief	Generic selection for integer types
 * \def		genericSigned(control, funcI8, funcI16, funcI32, funcI64, funcU8, 
 * 			funcU16, funcU32, funcU64)
 */
#	define wl_genericInt(control,\
		funcU8, funcU16, funcU32, funcU64, funcI8, funcI16, funcI32, funcI64\
	) _Generic((control),\
		WL_GENERIC_SIGNED_BODY,\
		WL_GENERIC_UNSIGNED_BODY\
	)

#endif /* WL__GENERIC */

/**
 * \brief	Heap allocate if Null
 * \def		alhIfNull(lvaluePtr, len)
 * \arg		lvaluePtr	Non-constant L-value pointer
 * \arg		len		Bytes to allocate
 * \return	`lvaluePtr` 
 * 
 * Allocate `len` bytes in the heap if `lvaluePtr` pointer is NULL, and 
 * assigns the address of successfully allocated object or NULL on failure.
 */
#define wl_alhIfNull(lvaluePtr, len)\
	(lvaluePtr = likely(lvaluePtr) ? lvaluePtr : alh(len))

/**
 * \brief	Heap allocate if Null Execute
 * \def		alhIfNull(lvaluePtr, len)
 * \arg		lvaluePtr	Non-constant L-value pointer
 * \arg		len		Bytes to allocate
 * \return	void
 * 
 * Same as \sa alhIfNull but will execute code after the macro call, given that
 * the allocation was successful
 * 
 * You may define a scope after the macro call to execute it. After the scope
 * you may also use an else-clause to execute code on allocation failure
 * 
 * \example
```c
	alhIfNullExecute(ptr, 64) {
		printf("Allocation was successful.\n");
	}
	else printf("Allocation failed.\n")
```
 */
#define wl_alhIfNullExec(lvaluePtr, len)\
	if_unlikely(!lvaluePtr)	lvaluePtr = alh(len);\
	if_likely(lvaluePtr)

#if UMB >= 64
#	define funcArrayArrayRemaining\
		switch (len) {\
			case 1:	*dst = (func1); break;\
			case 2: *(U16l*)dst = (func2); break;\
			case 3:\
				*(U16l*)dst = (func2);\
				dst += 2; src += 2;\
				*dst = (func1);\
			break;\
			case 4: *(U32l*)dst = (func4); break;\
			case 5:\
				*(U32l*)dst = (func4);\
				dst += 4; src += 4;\
				*dst = (func1);\
			break;\
			case 6:\
				*(U32l*)dst = (func4);\
				dst += 4; src += 4;\
				*(U16l*)dst = (func2);\
			break;\
			case 7:\
				*(U32l*)dst = (func4);\
				dst += 4; src += 4;\
				*(U16l*)dst = (func2);\
				dst += 2; src += 2;\
				*dst = (func1);\
			default:\
			break;\
		}
#else	/* UMB >= 64 */
#	define funcArrayArrayRemaining\
		switch (len) {\
			case 1:	*dst = (func1); break;\
			case 2: *(U16l*)dst = (func2); break;\
			case 3:\
				*(U16l*)dst = (func2);\
				dst += 2; src += 2;\
				*dst = (func1);\
			default:\
			break;\
		}
#endif	/* UMB >= 64 */

#define wl_funcDeclArrayArray(name, dstType, srcType)\
	dstType* name(dstType* _dst, wl_U32 len, srcType* restrict src)

#if WL_AUTOVECTOR_LOOPS
#	define wl_funcDefArrayArray(\
	name, dstType, srcType, func1, func2, func4, func8\
)\
		funcDeclArrayArray(name, dstType, srcType) {\
			alhIfNullExec(_dst, len) {\
				dstType* dst = _dst;\
				while (len) {\
					*dst = (func1);\
					len--; dst++; src + sizeof(srcType)/sizeof(dstType);\
				}\
			}\
			return _dst;\
		}
#else	/* WL_AUTOVECTOR_LOOPS */
#	define wl_funcDefArrayArray(\
	name, dstType, srcType, func1, func2, func4, func8\
)\
		funcDeclArrayArray(name, dstType, srcType) {\
			alhIfNullExec(_dst, len) {\
				dstType* dst = _dst;\
				if (len > sizeof(UMax)) {\
					{\
						Pt rem = (Pt)dst % sizeof(UMax);\
						if_unlikely(rem) {\
							register const UMax m = wl_b1(CHB*rem) - 1;\
							*(UMax*)dst = (func8)&m + ((*(UMax*)dst)&(~m));\
						}\
					}\
					while (len >= sizeof(UMax)) {\
						*(UMax)dst = (func8);\
						dst += sizeof(UMax);\
						src += sizeof(UMax)*sizeof(srcType)/sizeof(dstType);\
						len -= sizeof(UMax);\
					}\
				}\
				funcArrayArrayRemaining\
			}\
			return _dst;\
		}
#endif	/* WL_AUTOVECTOR_LOOPS */


#endif
