#ifndef TYPES_H
#define TYPES_H

/* Include data model information*/
#include <wl/DATA/DAMO.h>
#include <wl/DATA/LANG.h>
#include <wl/core/error.h>

#if		defined(LG_C)	/* Follows ISO C standard */

#if LG_C >= VR_C99

#ifndef TYPE__BOOL
#define TYPE__BOOL		1
#endif


#ifndef TYPE_LONG_LONG
#define TYPE_LONG_LONG	1
#endif

#endif	/* LG_C >= VR_C99 */

#ifndef TYPE_VOID
#define TYPE_VOID		1
#endif

#ifndef TYPE_BOOL
#define TYPE_BOOL		0
#endif

#ifndef TYPE__BOOL
#define TYPE__BOOL		0
#endif

#ifndef TYPE_LONG_LONG
#define TYPE_LONG_LONG	0
#endif

#elif	defined(LG_CPP)	/* Follows ISO C++ standard */

#if LG_CPP >= VR_CPP11
#ifndef TYPE_LONG_LONG
#define TYPE_LONG_LONG	1
#endif
#endif

#ifndef TYPE_VOID
#define TYPE_VOID		1
#endif

#ifndef TYPE__BOOL
#define TYPE__BOOL		0
#endif

#ifndef TYPE_BOOL
#define TYPE_BOOL		1
#endif

#ifndef TYPE_LONG_LONG
#define TYPE_LONG_LONG	0
#endif

#else					/* Follows another standard */

#ifndef TYPE_VOID
#define TYPE_VOID		0
#endif

#ifndef TYPE_BOOL
#define TYPE_BOOL		0
#endif

#ifndef TYPE__BOOL
#define TYPE__BOOL		0
#endif

#ifndef TYPE_LONG_LONG
#define TYPE_LONG_LONG	0
#endif

#endif

/* Fixed-size numeric types */
#ifndef NO_FIXED_TYPES

#if	DATA_MODEL == DM_LP32
typedef char				i8,		I8;
typedef short				i16,	I16;
typedef long				i32,	I32;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned long		u32,	U32;
#elif	(DATA_MODEL == DM_ILP32) && \
		(DATA_MODEL == DM_LLP64)
typedef char				i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
#elif	DATA_MODEL == DM_LP64
typedef char				i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef long				i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef unsigned long		u64,	U64;
#elif	DATA_MODEL == DM_ILP64
typedef char				i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef int					i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef unsigned int		u64,	U64;
#elif	DATA_MODEL == DM_SILP64
typedef char				i8,		I8;
typedef short				i16,	I16;
typedef short				i32,	I32;
typedef short				i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned short		u32,	U32;
typedef unsigned short		u64,	U64;
#else
typedef char				i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef long				i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef unsigned long		u64,	U64;
#endif

#endif /* Fixed-size numeric types */

#if DEF_VOID == 1
typedef void				vo, VO;
#else
WARN("Void type is not supported.")
typedef char				vo, VO;
#endif

#if		DEF_BOOL == 1
typedef bool				bl, BL;
#elif	DEF__BOOL == 1
typedef _Bool				bl, BL;
#else
typedef char				bl, BL;
#endif

#if		DEF_LONG_LONG == 1

#if		DATA_MODEL < DM_LP64
typedef long long			i64, I64;
typedef unsigned long long	u64, U64;
#endif

#endif

#endif