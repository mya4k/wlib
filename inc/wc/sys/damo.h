#ifndef DAMO_H
#define DAMO_H

#include <wc/sys/arch.h>
#include <wc/sys/comp.h>
#include <wc/sys/osys.h>

/* Data model "NULL" assumes that
	* char		is 8-bit
	* short		is 16-bit
	* int		is 32-bit
	* long		is 64-bit
	* long long	is at least 64-bit
	* pointers	are at least 64-bit
	*/
#define DM_NULL		0
#define DM_LP32		1
#define DM_ILP32	2
#define DM_LLP64	3
#define DM_LP64		4
#define DM_ILP64	5
#define DM_SILP64	6

/* Automatic data model definition */
#if !defined(DATA_MODEL)

/* LP32 */
#if defined(OS_WIN16)
#define DATA_MODEL DM_LP32

/* ILP32 */
#elif	defined(_ILP32)		||	\
		defined(__ILP32__)	||	\
		(AR_BIT == 64) 		&&( \
			defined(OS_WIN32)	||	\
			defined(OS_UNIX)	||	\
			defined(OS_LINUX)	||	\
			defined(OS_MAC) 		\
		)
#define DATA_MODEL DM_ILP32

/* LLP64 */
#elif	defined(OS_WIN64)						&&	\
		(defined(AR_I86) || defined(AR_IA64))	&&	\
		defined(CM_MSC)							||	\
		defined(CM_MINGW)
#define DATA_MODEL DM_LLP64

/* LP64 */
#elif	defined(_LP64)		||	\
		defined(__LP64__)	||	\
		defined(OS_UNIX)	||	\
		defined(OS_SUN)		||	\
		defined(OS_LINUX)	||	\
		defined(OS_BSD)		||	\
		defined(OS_MAC)		||	\
		defined(OS_ZOS)		||	\
		defined(OS_CYGWIN)
#define DATA_MODEL DM_LP64

/* ILP64 */
#elif	(AR_BIT == 64) 		&&(	\
			defined(OS_UNIX)	||	\
			defined(OS_LINUX)	||	\
			defined(OS_MAC))
		)
#define DATA_MODEL DM_ILP64

/* SILP64 */
#elif defined(OS_UNICOS)
#define DATA_MODEL DM_SILP64

/* Otherwise data model is undefined */
#else 
#define DATA_MODEL DM_NULL

#endif

#endif /* Automatic data model definition */

#endif