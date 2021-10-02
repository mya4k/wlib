#ifndef WC_SYS_ARCH_H
#define WC_SYS_ARCH_H



#define WL_AR_UNKNOWN		0
#define WL_AR_DEC_ALPHA 	1	/* DEC Alpha */
#define WL_AR_ALPHA			1
#define WL_AR_ALPHA_AXP		1
#define WL_AR_X86_64		2	/* x86-64 */
#define WL_AR_X8664			2
#define WL_AR_X64			2
#define WL_AR_AMD64			2
#define WL_AR_INTEL64		2
#define WL_AR_IA32E			2
#define WL_AR_IA_32E		2
#define WL_AR_EM64T			2
#define WL_AR_ARM			3	/* ARM */
#define WL_AR_ARM32			3
#define WL_AR_ARM64			4	/* ARM64 */
#define WL_AR_AARCH64		4
#define WL_AR_BLACKFIN		5	/* Blackfin */
#define WL_AR_BFIN			5
#define WL_AR_CONVEX		6	/* Convex */
#define WL_AR_EPIPHANY		7	/* Epiphany */
#define WL_AR_HPPA			8	/* PA-RISC (HP/PA) */
#define WL_AR_HP_PA			8
#define WL_AR_PARISC		8
#define WL_AR_PA_RISC		8
#define WL_AR_IA32			9	/* Intel 32 */
#define WL_AR_IA_32			9
#define WL_AR_X8632			9
#define WL_AR_X86_32		9
#define WL_AR_I386			9
#define WL_AR_I486			9
#define WL_AR_I586			9
#define WL_AR_I686			9
#define WL_AR_IX86			9
#define WL_AR_I86			9
#define WL_AR_INTELX86		9
#define WL_AR_INTEL32		9
#define WL_AR_IA64			10	/* Intel Itanium (IA-64) */
#define WL_AR_IA_64			10
#define WL_AR_ITANIUM		10
#define WL_AR_INTEL_ITANIUM	10
#define WL_AR_M68K			11	/* Motorola 68000 */
#define WL_AR_M68000		11
#define WL_AR_680X0			11
#define WL_AR_68K			11
#define WL_AR_MIPS			12	/* MIPS */
#define WL_AR_POWERPC		13	/* PowerPC */
#define WL_AR_PPC			13
#define WL_AR_PYR			14	/* Pyramid 9810 */
#define WL_AR_PYR_9810		14
#define WL_AR_PYRAMID		14
#define WL_AR_PYRAMID_9810	14
#define WL_AR_RS6000		15	/* IDM RS/6000 */
#define WL_AR_RS_6000		15
#define WL_AR_IBM_RS6000	15
#define WL_AR_IBM_RS_6000	15
#define WL_AR_SPARC			16	/* SPArc */
#define WL_AR_SUPERH		17	/* SuperH */
#define WL_AR_SH			17
#define WL_AR_SYSTEMZ		18	/* SystemZ */
#define WL_AR_SYSTEM_Z		18
#define WL_AR_IBMZ			18
#define WL_AR_IBM_Z			18
#define WL_AR_TMS320		19	/* TMS320 */
#define WL_AR_TI_TMS320		19
#define WL_AR_TI_TMS470		20	/* TMS470 */
#define WL_AR_TI_TMS470		20



#ifndef WL_AR
#	if		defined(__alpha__)		\
		 || defined(__alpha)		\
		 || defined(_M_ALPHA)
#		define WL_AR WL_AR_ALPHA
#	elif	defined(__amd64__)		\
		 || defined(__amd64)		\
		 || defined(__x86_64__)		\
		 || defined(__x86_64)		\
		 || defined(_M_X64)			\
		 || defined(_M_AMD64)
#		define WL_AR WL_AR_X86_64
#	elif	defined(__arm__)		\
		 || defined(__thumb__)		\
		 || defined(_ARM)			\
		 || defined(_M_ARM)			\
		 || defined(_M_ARMT)		\
		 || defined(__arm)
#		define WL_AR WL_AR_ARM
#	elif	defined(__aarch64__)
#		define WL_AR WL_AR_ARM64
#	elif	defined(__bfin)			\
		 || defined(__BFIN__)
#		define WL_AR WL_AR_BFIN
#	elif	defined(__convex__)
#		define WL_AR WL_AR_CONVEX
#	elif	defined(__epiphany__)
#		define WL_AR WL_AR_CONVEX
#	elif	defined(__hppa__)		\
		 || defined(__HPPA__)		\
		 || defined(__hppa)
#		define WL_AR WL_AR_HPPA
#	elif	defined(i386)			\
		 || defined(__i386)			\
		 || defined(__i386__)		\
		 || defined(__IA32__)		\
		 || defined(_M_I86)			\
		 || defined(_M_IX86)		\
		 || defined(__X86__)		\
		 || defined(_X86_)			\
		 || defined(__THW_INTEL__)	\
		 || defined(__I86__)		\
		 || defined(__INTEL__)		\
		 || defined(__386)
#		define WL_AR WL_AR_I386
#	elif	defined(__ia64__)		\
		 || defined(_IA64)			\
		 || defined(__IA64__)		\
		 || defined(__ia64)			\
		 || defined(_M_IA64)		\
		 || defined(__itanium__)
		define WL_AR WL_AR_IA64
#	elif	defined(__m68k__)		\
		 || defined(M68000)			\
		 || defined(__MC68K__)
#		define WL_AR WL_AR_M68K
#	elif	defined(__mips__)		\
		 || defined(mips)			\
		 || defined(__mips)			\
		 || defined(__MIPS__)
#		define WL_AR WL_AR_MIPS
#	elif	defined(__powerpc)		\
		 || defined(__powerpc__)	\
		 || defined(__powerpc64__)	\
		 || defined(__POWERPC__)	\
		 || defined(__ppc__)		\
		 || defined(__ppc64__)		\
		 || defined(__PPC__)		\
		 || defined(__PPC64__)		\
		 || defined(_ARCH_PPC)		\
		 || defined(_ARCH_PPC64)	\
		 || defined(_M_PPC)			\
		 || defined(__PPCGECKO__)	\
		 || defined(__PPCBROADWAY__)\
		 || defined(_XENON)			\
		 || defined(__ppc)
#		define WL_AR WL_AR_POWERPC
#	elif	defined(pyr)
#		define WL_AR WL_AR_PYR
#	elif	defined(__THW_RS6000)	\
		 || defined(_IBMR2	)		\
		 || defined(_POWER	)		\
		 || defined(_ARCH_PWR)		\
		 || defined(_ARCH_PWR2)		\
		 || defined(_ARCH_PWR3)		\
		 || defined(_ARCH_PWR4)
#		define WL_AR WL_AR_RS6000
#	elif	define(__sparc__)		\
		 || define(__sparc)			\
#		define WL_AR WL_AR_SPARC
#	elif	define(__sh__)
#		define WL_AR WL_AR_SH
#	elif	define(__370__)			\
		 || defined(__THW_370__)	\
		 || defined(__s390__)		\
		 || defined(__s390x__)		\
		 || defined(__zarch__)		\
		 || defined(__SYSC_ZARCH__)
#		define WL_AR WL_AR_SYSTEMZ
/* Not sure how to identify TMS320 */
#	elif	define(__TMS470__)
#		define WL_AR WL_AR_TMS470
#	else
#		define WL_AR WL_AR_UNKNOWN
#	endif
#endif



#endif
