#ifndef TYPES_H
#define TYPES_H

#include <wl/DATA/DAMO.h>
#include <wl/DATA/LANG.h>

// Wispy says trans rights!

#define NULL	0
#define FALSE	0
#define TRUE	1

#ifndef FIXED_INT
#define FIXED_INT TRUE
#endif	// FIXED_INT

// Void and Character types
typedef void			VO;
typedef char			CH;

// Boolean type
#if (defined(LG_C) && (LG_C >= VR_C99)) || defined(LG_CPP)
typedef _Bool			BL;
#else	// Boolean type
typedef char			BL;
#endif	// Boolean type

// Integer types
#if (FIXED_INT == FALSE) || (DATA_MODEL == DM_NULL)
typedef signed char		I8;
typedef short			I16;
typedef int				I32;
typedef long			I64;

typedef unsigned char	U8;
typedef unsigned short	U16;
typedef unsigned int	U32;
typedef unsigned long	U64;
#endif	// Integer types

// Floating-point types
typedef float			F32;
typedef double			F64;

#endif