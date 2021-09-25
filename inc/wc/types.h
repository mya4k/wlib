/**
 * \file types.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Fixed-size & fundamental data types, their size and limits
 * \version 1.0
 * \date 2021-06-30
 * \attention This is spaghetti code, you have been warned
 * Content:
 * 	Macros:	WL_CHB, WL_SHB, WL_INB, WL_LOB, WL_PTB, WL_I8B,
 *  		WL_I8N, WL_I8X, WL_I16B, WL_I16N, WL_I16X,
 * 			WL_I32B, WL_I32N, WL_I32X, WL_I64B, WL_I64N, 
 * 			WL_I64X, WL_U8N, WL_U8X, WL_U16N, WL_U16X, 
 * 			WL_U32N, WL_U32X, WL_U64N, WL_U64X, WL_IMB,
 * 			WL_IMN, WL_IMX, WL_UMN, WL_UMX
 * 	Types:	wl_ch, wl_Ch, wl_vo, wl_Vo, wl_bl, wl_Bl, 
 * 			wl_i8, wl_u8, wl_i16, wl_u16, wl_i32, wl_u32,
 * 			wl_i64, wl_u64, wl_I8, wl_U8, wl_I16, wl_U16,
 * 			wl_I32, wl_U32, wl_I64, wl_U64, wl_IMax,
 * 			wl_imax, wl_UMax, wl_umax, wl__Ptr
 * 
 */
#ifndef WC_TYPES_H
#define WC_TYPES_H

/* Include data model information*/
#include <wc/sys/damo.h>
#include <wc/sys/lang.h>



#ifndef NO_SHORT_NAMES
#define _Ptr	wl__Ptr
#define Bl		wl_Bl
#define CHB		WL_CHB
#define Ch		wl_Ch
#define I8		wl_I8
#define I8B 	WL_I8B
#define I8N 	WL_I8N
#define I8X		WL_I8X
#define I16		wl_I16
#define I16B	WL_I16B
#define I16N 	WL_I16N
#define I16X 	WL_I16X
#define I32		wl_I32
#define I32B	WL_I32B
#define I32N 	WL_I32N
#define I32X 	WL_I32X
#define I64		wl_I64u
#define I64B	WL_I64B
#define I64N 	WL_I64N
#define I64X 	WL_I64X
#define IMN		WL_UMN
#define IMX		WL_UMX
#define U8		wl_U8
#define U8B 	WL_U8B
#define U8N 	WL_U8N
#define U8X		WL_U8X
#define U16		wl_U16
#define U16B	WL_U16B
#define U16N 	WL_U16N
#define U16X 	WL_U16X
#define U32		wl_U32
#define U32B	WL_U32B
#define U32N 	WL_U32N
#define U32X 	WL_U32X
#define U64		wl_U64
#define U64B	WL_U64B
#define U64N 	WL_U64N
#define U64X 	WL_U64X
#define UMN		WL_UMN
#define UMX		WL_UMX
#define IMB		WL_IMB
#define INB		WL_INB
#define LOB 	WL_LOB
#define PTB 	WL_PTB
#define SHB 	WL_SHB
#define Vo		wl_Vo
#define bl		wl_bl
#define ch		wl_ch
#define i8		wl_i8
#define i16		wl_i16
#define i32		wl_i32
#define i64		wl_i64
#define IMax	wl_IMax
#define imax	wl_imax
#define u64		wl_u64
#define u8		wl_u8
#define u16		wl_u16
#define u32		wl_u32
#define UMax	wl_UMax
#define umax	wl_umax
#define vo		wl_vo
#define PTM		WL_PTM
#define PTX		WL_PTX
#define F32		wl_F32
#define F64		wl_F64
#define f32		wl_f32
#define f64		wl_f64
#endif



#if !defined(DATA_MODEL)
#define DATA_MODEL DM_NULL
#endif

#if		defined(LG_C)	/* Follows ISO C standard */

#if LG_C >= VR_C99

#ifndef DEF__BOOL
#define DEF__BOOL		1
#endif


#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	1
#endif

#endif	/* LG_C >= VR_C99 */

#ifndef DEF_VOID
#define DEF_VOID		1
#endif

#ifndef DEF_BOOL
#define DEF_BOOL		0
#endif

#ifndef DEF__BOOL
#define DEF__BOOL		0
#endif

#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	0
#endif

#elif	defined(LG_CPP)	/* Follows ISO C++ standard */

#if LG_CPP >= VR_CPP11
#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	1
#endif
#endif

#ifndef DEF_VOID
#define DEF_VOID		1
#endif

#ifndef DEF__BOOL
#define DEF__BOOL		0
#endif

#ifndef DEF_BOOL
#define DEF_BOOL		1
#endif

#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	0
#endif

#else					/* Follows another standard */

#ifndef DEF_VOID
#define DEF_VOID		0
#endif

#ifndef DEF_BOOL
#define DEF_BOOL		0
#endif

#ifndef DEF__BOOL
#define DEF__BOOL		0
#endif

#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	0
#endif
#endif



/* Fixed-size integer types */
typedef char				wl_ch, wl_Ch;

#ifndef NO_FIXED_TYPES

/* From C99 there's <stdint.h> header which defines fixed-size types */
#if	(LG_C >= VR_C99) && defined(USE_STDLIB)
#include <stdint.h>
typedef int8_t				wl_i8,		wl_I8;
typedef int16_t				wl_i16,		wl_I16;
typedef int32_t				wl_i32,		wl_I32;
typedef int64_t				wl_i64,		wl_I64;
typedef uint8_t				wl_u8,		wl_U8;
typedef uint16_t			wl_u16,		wl_U16;
typedef uint32_t			wl_u32,		wl_U32;
typedef uint64_t			wl_u64,		wl_U64;
typedef uintptr_t			wl__Ptr;	/* Pointer type (experimental)	*/
typedef intmax_t			wl_imax,	wl_IMax;
typedef uintmax_t			wl_umax,	wl_UMax;
#endif

#if	DATA_MODEL == DM_LP32

#if	!defined(USE_STDLIB)
typedef signed char			wl_i8,		wl_I8;
typedef short				wl_i16,		wl_I16;
typedef long				wl_i32,		wl_I32;
typedef unsigned char		wl_u8,		wl_U8;
typedef unsigned short		wl_u16,		wl_U16;
typedef unsigned long		wl_u32,		wl_U32;
typedef wl_U32				wl__Ptr;	/* Pointer type (experimental)	*/
#endif

#define WL_CHB	8
#define WL_SHB	16
#define WL_INB	16
#define WL_LOB	32
#define WL_PTB	32							/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_ILP32

#if	!defined(USE_STDLIB)
typedef signed char			wl_i8,	wl_I8;
typedef short				wl_i16,	wl_I16;
typedef int					wl_i32,	wl_I32;
typedef unsigned char		wl_u8,	wl_U8;
typedef unsigned short		wl_u16,	wl_U16;
typedef unsigned int		wl_u32,	wl_U32;
typedef wl_U32					wl__Ptr;	/* Pointer type (experimental)	*/

#endif

#define WL_CHB	8
#define WL_SHB	16
#define WL_INB	32
#define WL_LOB	32
#define WL_PTB	32							/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_LLP64

#if	!defined(USE_STDLIB)
typedef signed char			wl_i8,	wl_I8;
typedef short				wl_i16,	wl_I16;
typedef int					wl_i32,	wl_I32;
typedef unsigned char		wl_u8,	wl_U8;
typedef unsigned short		wl_u16,	wl_U16;
typedef unsigned int		wl_u32,	wl_U32;
typedef wl_U64					wl__Ptr;	/* Pointer type (experimental) */
#endif

#define WL_CHB	8
#define WL_SHB	16
#define WL_INB	32
#define WL_PTB	64							/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_LP64

#if	!defined(USE_STDLIB)
typedef signed char			wl_i8,		wl_I8;
typedef short				wl_i16,		wl_I16;
typedef int					wl_i32,		wl_I32;
typedef long				wl_i64,		wl_I64;
typedef unsigned char		wl_u8,		wl_U8;
typedef unsigned short		wl_u16,		wl_U16;
typedef unsigned int		wl_u32,		wl_U32;
typedef unsigned long		wl_u64,		wl_U64;
typedef wl_U64				wl__Ptr;	/* Pointer type (experimental) */
typedef wl_U64				wl_imax,	wl_IMax;
typedef wl_U64				wl_umax,	wl_UMax;
#endif

#define WL_CHB	8
#define WL_SHB	16
#define WL_INB	32
#define WL_LOB	64
#define WL_PTB	64							/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_ILP64

#if	!defined(USE_STDLIB)
typedef signed char			wl_i8,		wl_I8;
typedef short				wl_i16,		wl_I16;
typedef int					wl_i32,		wl_I32;
typedef int					wl_i64,		wl_I64;
typedef unsigned char		wl_u8,		wl_U8;
typedef unsigned short		wl_u16,		wl_U16;
typedef unsigned int		wl_u32,		wl_U32;
typedef unsigned int		wl_u64,		wl_U64;
typedef wl_U64				wl__Ptr;	/* Pointer type (experimental) */
typedef wl_U64				wl_imax,	wl_IMax;
typedef wl_U64				wl_umax,	wl_UMax;
#endif

#define WL_CHB	8
#define WL_SHB	16
#define WL_INB	64
#define WL_LOB	64
#define WL_PTB	64							/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_SILP64

#if	!defined(USE_STDLIB)
typedef signed char			wl_i8,		wl_I8;
typedef short				wl_i16,		wl_I16;
typedef short				wl_i32,		wl_I32;
typedef short				wl_i64,		wl_I64;
typedef unsigned char		wl_u8,		wl_U8;
typedef unsigned short		wl_u16,		wl_U16;
typedef unsigned short		wl_u32,		wl_U32;
typedef unsigned short		wl_u64,		wl_U64;
typedef wl_U64				wl__Ptr;	/* Pointer type (experimental) */
typedef wl_U64				wl_imax,	wl_IMax;
typedef wl_U64				wl_umax,	wl_UMax;
#endif

#define WL_CHB	8
#define WL_SHB	64
#define WL_INB	64
#define WL_LOB	64
#define WL_PTB	64							/* Pointer size (experimental) */

#else

#if	!defined(USE_STDLIB)
typedef signed char			wl_i8,		wl_I8;
typedef short				wl_i16,		wl_I16;
typedef int					wl_i32,		wl_I32;
typedef long				wl_i64,		wl_I64;
typedef unsigned char		wl_u8,		wl_U8;
typedef unsigned short		wl_u16,		wl_U16;
typedef unsigned int		wl_u32,		wl_U32;
typedef unsigned long		wl_u64,		wl_U64;
typedef wl_U64				wl__Ptr;	/* Pointer type (experimental) */
typedef wl_U64				wl_imax,	wl_IMax;
typedef wl_U64				wl_umax,	wl_UMax;
#endif

#define WL_CHB	8
#define WL_SHB	16
#define WL_INB	32
#define WL_LOB	64
#define WL_PTB	64							/* Pointer size (experimental) */

#endif

#endif /* Fixed-size integer types */


/* Void type */
#if DEF_VOID == 1
typedef void				wl_vo, wl_Vo;
#else
typedef char				wl_vo, wl_Vo;
#endif /* Void type */

/* Boolean type */
#if		DEF_BOOL == 1
typedef bool				wl_bl, wl_Bl;
#elif	DEF__BOOL == 1
typedef _Bool				wl_bl, wl_Bl;
#else
typedef char				wl_bl, wl_Bl;
#endif /* Boolean type */

/* Long long integer type */
#if		DEF_LONG_LONG == 1

#if		(DATA_MODEL == DM_LP32) || (DATA_MODEL == DM_ILP32)
#define NO_I64
typedef long long			wl_i64, 	wl_I64;
typedef unsigned long long	wl_u64, 	wl_U64;
typedef wl_U32				wl_imax,	wl_IMax;
typedef wl_U32				wl_umax,	wl_UMax;
#endif

#else	/* Long long integer type */

#if		(DATA_MODEL == DM_LLP64)
typedef long long			wl_i64, wl_I64;
typedef unsigned long long	wl_u64, wl_U64;
typedef wl_U64				wl_imax,	wl_IMax;
typedef wl_U64				wl_umax,	wl_UMax;
#endif

#endif	/* Long long integer type */

/* Floating point types */
typedef float				wl_f32, wl_F32;
typedef double				wl_f64, wl_F64;

/* Limits and sizes */

#define	WL_I8B	8
#define	WL_I16B	16
#define	WL_I32B	32

#define WL_I8N	(wl_I8)		0x80
#define WL_I16N	(wl_I16)	0x8000
#define WL_I32N	(wl_I32)	0x80000000

#define WL_I8X	(wl_I8)		0x7F
#define WL_I16X	(wl_I16)	0x7FFF
#define WL_I32X	(wl_I32)	0x7FFFFFFF

#define WL_U8N	(wl_U8)		0
#define WL_U16N	(wl_U16)	0
#define WL_U32N	(wl_U32)	0

#define WL_U8X	(wl_U8)		0xFF
#define WL_U16X	(wl_U16)	0xFFFF
#define WL_U32X	(wl_U32)	0xFFFFFFFF

#ifdef NO_I64	/* Abnormal behavior */
#define WL_I64B	32
#define WL_IMB	32
#define WL_I64N	(wl_I64)	0x80000000
#define WL_I64X	(wl_I64)	0x7FFFFFFF
#define WL_IMN	WL_I32N
#define WL_IMX	WL_I32X
#define WL_U64N	(wl_U64)	0
#define WL_U64X	(wl_U64)	0xFFFFFFFF
#define WL_UMN	WL_U32N
#define WL_UMX	WL_U32X
#else		/* Optimal behavior */
#define WL_I64B	64
#define WL_IMB	64
#define WL_I64N	(wl_I64)	0x8000000000000000
#define WL_I64X	(wl_I64)	0x7FFFFFFFFFFFFFFF
#define WL_IMN	WL_I64N
#define WL_IMX	WL_I64X
#define WL_U64N	(wl_U64)	0
#define WL_U64X	(wl_U64)	0xFFFFFFFFFFFFFFFF
#define WL_UMN	WL_U64N
#define WL_UMX	WL_U64X
#endif		/* NO_I64 */

#if WL_PTB == 64
#define WL_PTM	WL_U64N
#define WL_PTX	WL_U64X
#else
#define WL_PTM	WL_U32N
#define WL_PTX	WL_U32X
#endif

#endif
