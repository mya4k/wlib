#ifndef WL_CORE_H
#define WL_CORE_H



#include <wl/config.h>



#ifdef WL_CPP
/* Extern compatibility */
#	ifndef EXTERN
#		define EXTERN		extern "C"
#	endif
/* Beginning of a set of external definitions */
#	ifndef C_DECL_BEGIN
#		define C_DECL_BEGIN	EXTERN {
#	endif
/* End of a set of external definitions */
#	ifndef C_DECL_END
#		define C_DECL_END	}
#	endif
#	ifndef ENUM
#		define ENUM(NAME)	enum ENUM_##NAME
#	endif
#else
/* Extern compatibility */
#	ifndef EXTERN
#		define EXTERN		extern
#	endif
/* Beginning of a set of external definitions */
#	ifndef C_DECL_BEGIN
#		define C_DECL_BEGIN
#	endif
/* End of a set of external definitions */
#	ifndef C_DECL_END
#		define C_DECL_END
#	endif
#	ifndef ENUM
#		define ENUM(NAME)	enum NAME
#	endif
#endif

#if defined(WL_C) && WL_C < WL_VER_C99
/* Inline */
#	if WL_GCC
#		undef	inline
#		define	inline
#	else
#		undef	inline
#		define	inline	gnu_inline
#	endif
/* Restrict */
#	undef	restrict
#	define	restrict
#elif defined(WL_CPP)
/* Restrict */
#	undef	restrict
#	define	restrict
#endif

#undef	always_inline
#if WL_GCC
#	define always_inline	inline __attribute__((always_inline))
#else
#	define always_inline	inline
#endif

#if WL_GCCLIKE
#define likely(cond)	__glibc_likely((long)(cond))	
#define unlikely(cond)	__glibc_unlikely((long)(cond))
#else
#define likely(cond)	(cond)
#define unlikely(cond)	(cond)
#endif


/* Some compilers complain about an illegal function call even when the code 
 * should not be compiled
 */
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

#	if WL_CONF_GNU_ATTRIBUTE
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

#if WL_CONF_GNU_ATTRIBUTE
#	define nonnull(X)				[[gnu::nonnull##X##]]
#	define returns_nonnull			[[gnu::returns_nonnull]]
#else
#	define nonnull(X)
#	define returns_nonnull
#endif



#endif
