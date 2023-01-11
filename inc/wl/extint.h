#ifndef WL_EXTINT_H
#define WL_EXTINT_H	1



#include <wl/types.h>



#define wl_vc(n)



#if !WL_PREFIX
#	if WL_UMB < 64
#		define U64	wl_U64
#	endif
#	define U128		wl_U128
#	define U256		wl_U256
#	define U512		wl_U512
#	define U1024	wl_U1024
#endif



#if WL_UMB < 64
#	if WL_OPENCL_VECTOR
		typedef wl_U32l __attribute__((ext_vector_size(2)))		wl_U64;
		typedef wl_U32l __attribute__((ext_vector_size(4)))		wl_U128;
		typedef wl_U32l __attribute__((ext_vector_size(8)))		wl_U256;
		typedef wl_U32l __attribute__((ext_vector_size(16)))	wl_U512;
		typedef wl_U32l __attribute__((ext_vector_size(32)))	wl_U1024;
#	elif WL_GCC_VECTOR
		typedef wl_U32l __attribute__((vector_size(8)))			wl_U64;
		typedef wl_U32l __attribute__((vector_size(16))) 		wl_U128;
		typedef wl_U32l __attribute__((vector_size(32))) 		wl_U256;
		typedef wl_U32l __attribute__((vector_size(64))) 		wl_U512;
		typedef wl_U32l __attribute__((vector_size(128)))		wl_U1024;
#	elif WL_NEON_VECTOR
		typedef wl_U32l __attribute__((neon_vector_type(2)))	wl_U64;
		typedef wl_U32l __attribute__((neon_vector_type(4))) 	wl_U128;
		typedef wl_U128 wl_U256[2];
		typedef wl_U128 wl_U512[4];
		typedef wl_U128 wl_U1024[8];
#	else
		typedef wl_U32l wl_U64[2];
		typedef wl_U32l wl_U128[4];
		typedef wl_U32l wl_U256[8];
		typedef wl_U32l wl_U512[16];
		typedef wl_U32l wl_U1024[32];
#	endif
#else
#	if WL_OPENCL_VECTOR
		typedef wl_U64l __attribute__((ext_vector_size(4)))		wl_U128;
		typedef wl_U64l __attribute__((ext_vector_size(8)))		wl_U256;
		typedef wl_U64l __attribute__((ext_vector_size(16)))	wl_U512;
		typedef wl_U64l __attribute__((ext_vector_size(32)))	wl_U1024;
#	elif WL_GCC_VECTOR
		typedef wl_U64l __attribute__((vector_size(16))) 		wl_U128;
		typedef wl_U64l __attribute__((vector_size(32))) 		wl_U256;
		typedef wl_U64l __attribute__((vector_size(64))) 		wl_U512;
		typedef wl_U64l __attribute__((vector_size(128)))		wl_U1024;
#	elif WL_NEON_VECTOR
		typedef wl_U64l __attribute__((neon_vector_type(4)))	wl_U128;
		typedef wl_U128 wl_U256[2];
		typedef wl_U128 wl_U512[4];
		typedef wl_U128 wl_U1024[8];
#	else
		typedef wl_U64l wl_U128[2];
		typedef wl_U64l wl_U256[4];
		typedef wl_U64l wl_U512[8];
		typedef wl_U64l wl_U1024[64];
#	endif
#endif



#endif
