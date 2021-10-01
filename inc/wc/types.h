#ifndef WC_TYPES_H
#define WC_TYPES_H



/* 1.1 
 * "Alternatively, `USE_STDINT` macro can be defined with any non-zero 
 * value ... The implimentation of `<types.h>` shall account for this."
 */
#if defined(USE_STDINT) && (USE_STDINT!=0) || 1
#	include <stdint.h>
	typedef int8_t			wl_I8,	wl_i8;
	typedef int16_t			wl_I16,	wl_i16;
	typedef int32_t			wl_I32,	wl_i32;
	typedef int64_t			wl_I64,	wl_i64;
	typedef uint8_t			wl_U8,	wl_u8;
	typedef uint16_t			wl_U16,	wl_u16;
	typedef uint32_t			wl_U32,	wl_u32;
	typedef uint64_t			wl_U64,	wl_u64;
#else
	/* All data models define char as a byte */
	typedef signed char			wl_I8,	wl_i8;
	typedef unsigned char		wl_U8,	wl_u8;
	/* In all data models `short` is 16-bits, except SILP64. On SILP64 there 
	are no 16-bit type, but we will still define it as short as it is big
	enough to store 16-bits.
	*/
	typedef short				wl_I16,	wl_i16;
	typedef unsigned short		wl_U16,	wl_u16;
	/* `int` in LP32 is 16-bit, so it does suit us. We will use long instead */
#	if DATA_MODEL == LP32
		typedef long			wl_I32,	wl_i32;
		typedef unsigned long	wl_U32,	wl_u32;
#	else
		typedef int				wl_I32,	wl_i32;
		typedef unsigned int	wl_U32,	wl_u32;
#	endif
#endif


#endif