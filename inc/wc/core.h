#ifndef WL_CORE_H
#define WL_CORE_H



#include <wc/sys/lang.h>
#include <wc/sys/comp.h>



#ifdef WL_LG_CPP
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
#		define C_DECL_END	}
#	endif
#	ifndef ENUM
#		define ENUM(NAME)	enum NAME
#	endif
#endif

/* C99 keywords */
/* #if defined(WL_LG_C) && WL_LG_C < WL_VR_C99 || defined(WL_LG_CPP)
#	ifndef INLINE
#		define INLINE
#	endif
#	ifndef RESTRICT
#		define RESTRICT
#	endif
#else
#	ifndef INLINE
#		define INLINE inline
#	endif
#	ifndef RESTRICT
#		define RESTRICT	restrict
#	endif
#endif */

#if defined(WL_LG_C) && WL_LG_C < WL_VR_C99
/* Inline */
#	undef	inline
#	define	inline
/* Restrict */
#	undef	restrict
#	define	restrict
#elif defined(WL_LG_CPP)
/* Restrict */
#	undef	restrict
#	define	restrict
#endif

#if WL_GCCLIKE
#define likely(cond)	__glibc_likely((long)cond)	
#define unlikely(cond)	__glibc_unlikely((long)cond)
#else
#define likely(cond)	(cond)
#define unlikely(cond)	(cond)
#endif

#if WL_C_ATTR
#	if !defined(nodiscard) && __has_c_attribute(nodiscard)
#	define nodiscard		[[nodiscard]]
#	endif

#	if WL_GNU_ATTR
#		if !defined(nonnull) && __has_c_attribute(gnu::nonnull)
#		define nonnull(...)		[[gnu::nonnull(__VA_ARGS__)]]
#		endif

#		if !defined(returns_nonnull) && __has_c_attribute(gnu::returns_nonnull)
#		define returns_nonnull	[[gnu::returns_nonnull]]
#		endif
#	endif
#endif

#if WL_CPP_ATTR
#	if !defined(nodiscard) && WL_LG_CPP < WL_VR_CPP17
#	define nodiscard		[[nodiscard]]
#	endif

#	if WL_GNU_ATTR
#		if !defined(nonnull)
#		define nonnull(...)		[[gnu::nonnull(__VA_ARGS__)]]
#		endif

#		if !defined(returns_nonnull)
#		define returns_nonnull	[[gnu::returns_nonnull]]
#		endif
#	endif
#endif

#if (WL_GNU_ATTR || WL_CLANG_ATTR || WL_MINGW_ATTR) && !(__STRICT_ANSI__) && defined(__glibc_has_attribute)
#	if !defined(nodiscard) && __glibc_has_attribute(warn_unused_result)
#	define nodiscard		__attribute__((warn_unused_result))
#	endif

#	if !defined(nonnull) && __glibc_has_attribute(warn_unused_result)
#	define nonnull(...)		__attribute__((nonnull(__VA_ARGS__)))
#	endif

#	if !defined(returns_nonnull) && __glibc_has_attribute(warn_unused_result)
#	define returns_nonnull	__attribute__((returns_nonnull))
#	endif
#endif

#	if !defined(nodiscard)
#	define nodiscard
#	endif

#	if !defined(nonnull)
#	define nonnull(X)
#	endif

#	if !defined(returns_nonnull)
#	define returns_nonnull
#	endif



#endif
