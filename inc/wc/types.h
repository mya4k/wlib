#ifndef WC_TYPES_H
#define WC_TYPES_H



#include <wc/sys/damo.h>
#include <wc/sys/lang.h>


/*
 * Type support checking
 */
#if		defined(WL_LG_CPP)

#	ifndef WL_TYPE_VOID
#		define WL_TYPE_VOID				1
#	endif	
#	ifndef WL_TYPE_BOOL
#		define WL_TYPE_BOOL				1
#	endif

#	if WL_LG_C>=WL_VR_C11
		/* Long long type support check */
#		ifndef WL_TYPE_LONG_LONG
#			define WL_TYPE_LONG_LONG	1
#		endif
#	endif

#elif	defined(WL_LG_C)

#	if WL_LG_C>=WL_VR_ANSI
		/* Void type support check */
#		ifndef WL_TYPE_VOID
#			define WL_TYPE_VOID			1
#		endif
#	endif

#	if WL_LG_C>=WL_VR_C99
		/* Long long type support check */
#		ifndef WL_TYPE_LONG_LONG
#			define WL_TYPE_LONG_LONG	1
#		endif
		/* _Bool type support check */
#		ifndef WL_TYPE__BOOL
#			define WL_TYPE__BOOL		1
#		endif
#	endif

#endif



/* 1.4. Alias types */
typedef			char				Ch,			ch;
typedef			float				Fl,			fl;
typedef			double				Db,			db;
typedef			long double			Ld,			ld;

/* 1.1 & 1.2
 * "Alternatively, `USE_STDINT` macro can be defined with any non-zero 
 * value ..."
 */
#if defined(WL_USE_STDINT) && (WL_USE_STDINT!=0)
#	include <stdint.h>
	typedef 	int8_t				wl_I8,		wl_i8;
	typedef 	int16_t				wl_I16,		wl_i16;
	typedef 	int32_t				wl_I32,		wl_i32;
	typedef 	int64_t				wl_I64,		wl_i64;
	typedef 	intmax_t			wl_IMax,	wl_imax;
	typedef 	uint8_t				wl_U8,		wl_u8;
	typedef 	uint16_t			wl_U16,		wl_u16;
	typedef 	uint32_t			wl_U32,		wl_u32;
	typedef 	uint64_t			wl_U64,		wl_u64;
	typedef 	uintmax_t			wl_UMax,	wl_umax;
	typedef		uintptr_t			wl_Pt,		wl_Pt;
/* 1.1 Fixed-size integer types */
#else
	/* All data models define char as a byte */
	typedef		signed char			wl_I8,		wl_i8;
	typedef		unsigned char		wl_U8,		wl_u8;

	/* In all data models `short` is 16-bits, except SILP64. On SILP64 there 
	are no 16-bit type, but we will still define it as `short` as it is big
	enough to store 16-bits. */
	typedef		short				wl_I16,		wl_i16;
	typedef 	unsigned short		wl_U16,		wl_u16;

	/* `int` in LP32 is 16-bit, so it does suit us. We will use long instead */
#	if WL_DM == WL_DM_LP32
		typedef	long				wl_I32,		wl_i32;
		typedef	unsigned long		wl_U32,		wl_u32;
#	else
		typedef	int					wl_I32,		wl_i32;
		typedef	unsigned int		wl_U32,		wl_u32;
#	endif

	/* `long` in LP32, LLP64, ILP32 is 32-bit, so it does suit us. We will 
		use `long long` instead, if supported */
	/* 1.2 `UMax` and `IMax` */
#	if	(WL_DM==WL_DM_LP32 || WL_DM==WL_DM_LLP64 || WL_DM == WL_DM_ILP32) \
		&& WL_TYPE_LONG_LONG
		typedef	long long			wl_I64,		wl_i64,	wl_IMax,	wl_imax;
		typedef	unsigned long long	wl_U64,		wl_u64,	wl_UMax,	wl_umax;
#	else
		typedef	long				wl_I64,		wl_i64,	wl_IMax,	wl_imax;
		typedef	unsigned long		wl_U64,		wl_u64,	wl_UMax,	wl_umax;
#	endif

#endif

/* 1.2. Pointer type */
/* Pointer type always has the same width as the widest data type */
typedef 		wl_UMax				wl_Pt, wl_pt;

/* 1.3. Compatibility types */
#if !defined(WL_LG_CPP)		/* If C */
/* Void */
#	if WL_LG_C<=WL_VR_K_R_C	/* K&R C */
		typedef	char				Vo,			vo;
#	else					/* Standard C */
		typedef	void				Vo,			vo;
#	endif
/* Boolean */
#	if WL_TYPE__BOOL		/* C99+ */
		typedef	_Bool				Vo,			vo;
#	else					/* Pre-C99 */
		typedef	char				Vo,			vo;
#	endif
#else						/* If C++ */
	typedef			void				Vo,			vo;
	typedef			bool				Vo,			vo;
#endif



#endif
