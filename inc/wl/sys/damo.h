#ifndef WL_SYS_DAMO_H
#define WL_SYS_DAMO_H



#include <wl/sys/arch.h>
#include <wl/sys/osys.h>
#include <wl/sys/comp.h>



#define WL_DM_UNKNOWN	0	/* */
#define WL_DM_LP32		1	/* 1/2/2/4/4 */
#define WL_DM_ILP32		2	/* 1/2/4/4/4 */
#define WL_DM_LLP64		3	/* 1/2/4/4/8/8 */
#define WL_DM_LP64		4	/* 1/2/4/8/8/8 */
#define WL_DM_ILP64		5	/* 1/2/8/8/8/8 */
#define WL_DM_SILP64	6	/* 1/8/8/8/8/8 */



/* Check that DATA_MODEL wasn't defined manually */
#ifndef WL_DM

	/* HP aCC, Sun Studio and GNU C defines macros for data model detection */
#	if defined(_ILP32) || defined(__ILP32__)
#		define WL_DM WL_DM_ILP32

	/* HP aCC, Sun Studio and GNU C defines macros for data model detection */
#	elif defined(_LP64) || defined(__LP64__)
#		define WL_DM WL_DM_LP64

	/* Microsoft Windows (x86-64 and IA-64) using Visual C++; and MinGW
	 * (https://en.wikipedia.org/wiki/64-bit_computing#64-bit_data_models)
	 */
#	elif	(WL_OS==WL_OS_WIN) 							\
		&&	(WL_CM==WL_CM_MSVC || WL_CM==WL_CM_MINGW)	\
		&&	(WL_AR==WL_AR_X86_64 || WL_AR==WL_AR_IA_64)
#		define WL_DM WL_DM_LLP64

#	elif	WL_OS==WL_OS_UNICOS
#		define WL_DM WL_DM_SILP64

	/* Most Unix and Unix-like systems; z/OS == LP64
	 * (https://en.wikipedia.org/wiki/64-bit_computing#64-bit_data_models)
	 */
#	elif	(WL_OS_UNIXLIKE==1) || (WL_OS==WL_OS_ZOS)
#		define WL_DM WL_DM_LP64

#	else 
#		define WL_DM WL_DM_UNKNOWN

#	endif
#endif



#endif
