#ifndef ARCH_H
#define ARCH_H

/* Alpha */
#if !defined(AR_ALPHA)	&&(	\
	defined(__alpha__)	||	\
	defined(__alpha)	||	\
	defined(_M_ALPHA)		\
)
#if		defined(__alpha_ev4__)
#define AR_ALPHA 4
#elif	defined(__alpha_ev5__)
#define AR_ALPHA 5
#elif	defined(__alpha_ev6__)
#define AR_ALPHA 6
#endif
#endif /* Alpha */

/* AMD64 */
#if !defined(AR_AMD64) && ( defined(__amd64__) || defined(_M_AMD64) )
#define AR_AMD64
#endif /* AMD64 */

/* ARM */
#if !defined(AR_ARM)			&&(	\
	defined(__arm__)			||	\
	defined(__TARGET_ARCH_ARM)	||	\
	defined(_ARM)				||	\
	defined(_M_ARM)				||	\
	defined(__arm)					\
) 

#define ARM_2	20
#define ARM_3	30
#define ARM_4T	41
#define ARM_5	50
#define ARM_5T	51
#define ARM_6	60
#define ARM_6T2	61
#define ARM_7	70

#if		defined(__ARM_ARCH_2__)
#define AR_ARM ARM_2
#elif	defined(__ARM_ARCH_3__)
#define AR_ARM ARM_3
#elif	defined(__ARM_ARCH_4T__)
#define AR_ARM ARM_4T
#elif	defined(__ARM_ARCH_5__) || (_M_ARM == 50)
#define AR_ARM ARM_5
#elif	defined(__ARM_ARCH_5T__)
#define AR_ARM ARM_5T
#elif	defined(__ARM_ARCH_6__) || (_M_ARM == 60)
#define AR_ARM ARM_6
#elif	defined(__ARM_ARCH_6T2__)
#define AR_ARM ARM_6T2
#elif	defined(__ARM_ARCH_7__) || (_M_ARM == 70)
#define AR_ARM ARM_7
#else	
#define AR_ARM 0
#endif

#endif /* ARM */

/* ARM64 */
#if !defined(AR_ARM64) && defined(__aarch64__)
#define
#endif /* ARM64 */

/* Blackfin */
#if !defined(AR_BFIN) && defined(__bfin)
#define AR_BFIN
#endif /* Blackfin */

/* Convex */
#if !defined(AR_CONVEX) && defined(__convex__)
#if		defined(__convex_c1__)
#define AR_CONVEX 1
#elif	defined(__convex_c2__)
#define AR_CONVEX 2
#elif	defined(__convex_c3__)
#define AR_CONVEX 3
#elif	defined(__convex_c32__)
#define AR_CONVEX 32
#elif	defined(__convex_c34__)
#define AR_CONVEX 34
#elif	defined(__convex_c38__)
#define AR_CONVEX 38
#else
#define AR_CONVEX 0
#endif
#endif /* Convex */

/* Epiphany */
#if !defined(AR_EPIPHANY) && defined(__epiphany__)
#define AR_EPIPHANY
#endif /* Epiphany */

/* HP/PA RISC */
#if !defined(AR_HPPA) && defined(__hppa)
#if		defined(_PA_RISC1_0)
#define AR_HPPA	10
#elif	defined(_PA_RISC1_1)
#define AR_HPPA 11
#elif	defined(_PA_RISC2_0)
#define AR_HPPA 20
#else
#define AR_HPPA 0
#endif
#endif /* HP/PA RISC */

/* Intel x86 */
#if !defined(AR_I86)		&&(	\
	defined(__i386)			||	\
	defined(i386)			||	\
	defined(_M_I86)			||	\
	defined(_M_IX86)		||	\
	defined(__X86__)		||	\
	defined(_X86_)			||	\
	defined(__THW_INTEL__)	||	\
	defined(__I86__)		||	\
	defined(__INTEL__)		||	\
	defined(__386)				\
)
#if		defined(__I86__)
#define	AR_I86 __I86__
#elif	defined(__i386__) || (_M_IX86 == 300)
#define AR_I86 3
#elif	defined(__i486__) || (_M_IX86 == 400)
#define AR_I86 4
#elif	defined(__i586__) || (_M_IX86 == 500)
#define AR_I86 5
#elif	defined(__i686__) || (_M_IX86 == 600)
#define AR_I86 6
#else
#define AR_I86 0
#endif
#endif /* Intel x86 */

/* Intel Itanium (IA-64) */
#if	!defined(AR_IA64)		&&(	\
	defined(__ia64__)		||	\
	defined(__ia64)			||	\
	defined(_M_IA64)		||	\
	defined(__itanium__)		\
)
#define AR_IA64
#endif /* Intel Itanium (IA-64) */

/* Motorola MC68000 */
#if !defined(AR_M68K)	&&( \
	defined(__m68k__)	||	\
	defined(M68000)		||	\
	defined(__MC68K__) 		\
)
#if		defined(__mc68000__)
#define AR_M68K 68000
#elif	defined(__mc68010__)
#define AR_M68K 68010
#elif	defined(__mc68020__)
#define AR_M68K 68020
#elif	defined(__mc68030__)
#define AR_M68K 68030
#elif	defined(__mc68040__)
#define AR_M68K 68040
#elif	defined(__mc68060__)
#define AR_M68K 68060
#else	/* defined(__mc68060__) */
#define AR_M68K
#endif	/* defined(__mc68060__) */
#endif	/* Motorola MC68000 */

/* MIPS */
#if !defined(AR_MIPS)	&&(	\
	defined(__mips)		||	\
	defined(__MIPS__)		\
)
#if		defined(_MIPS_ISA_MIPS1) || defined(_R3000)
#define AR_MIPS 1
#elif	defined(_MIPS_ISA_MIPS2) || defined(__MIPS_ISA2__)
#define AR_MIPS 2
#elif	defined(_MIPS_ISA_MIPS3) || defined(__MIPS_ISA3__)
#define AR_MIPS 3
#elif	defined(_MIPS_ISA_MIPS4) || defined(__MIPS_ISA4__)
#define AR_MIPS 4
#endif 
#endif /* MIPS */

/* PowerPC */
#if !defined(AR_PPC)			&&(	\
	defined(_ARCH_PPC)			||	\
	defined(_M_PPC)				||	\
	defined(__PPCGECKO__)		||	\
	defined(__PPCBROADWAY__)	||	\
	defined(_XENON)				||	\
	defined(__ppc)					\
)
#if		defined(_ARCH_440)
#define AR_PPC 440
#elif 	defined(_ARCH_450)
#define AR_PPC 450
#elif 	defined(_ARCH_601) || defined(__ppc601__)
#define AR_PPC 601
#elif 	defined(_ARCH_603) || defined(__ppc603__)
#define AR_PPC 603
#elif 	defined(_ARCH_604) || defined(__ppc604__)
#define AR_PPC 604
#elif 	defined(_M_PPC)
#define AR_PPC _M_PPC
#else
#define	AR_PPC 0
#endif
#endif /* PowerPC */

/* Pyramid 9810 */
#if !defined(AR_PYR) && defined(pyr)
#define AR_PYR
#endif /* Pyramid 9810 */

/* RS/6000 */
#if !defined(AR_RS6000)		&&(	\
	defined(__THW_RS6000)	||	\
	defined(_IBMR2)			||	\
	defined(_POWER)			||	\
	defined(_ARCH_PWR)		||	\
	defined(_ARCH_PWR2)		||	\
	defined(_ARCH_PWR3)		||	\
	defined(_ARCH_PWR4)			\
)
#define AR_RS6000
#endif /* RS/6000 */

/* SPARC */
#if !defined(AR_SPARC)		&&(	\
	defined(__sparc__)		||	\
	defined(__sparc)			\
)
#if		defined(__sparc_v8__) || defined(__sparcv8)
#define AR_RS6000 8
#elif	defined(__sparc_v9__) || defined(__sparcv9)
#define AR_RS6000 9
#else
#define AR_RS6000 0
#endif
#endif /* SPARC */

/* SuperH */
#if !defined(AR_SH) && defined(__sh__)
#if		defined(__sh1__)
#define AR_SH 1
#elif	defined(__sh2__)
#define AR_SH 2
#elif	defined(__sh3__)
#define AR_SH 3
#elif	defined(__SH4__)
#define AR_SH 4
#elif	defined(__SH5__)
#define AR_SH 5
#else
#define AR_SH 0
#endif
#endif /* SuperH */

/* SystemZ */
#if !defined(AR_Z)		&&(	\
	defined(__370__)	||	\
	defined(__s390__)	||	\
	defined(__s390x__)	||	\
	defined(__zarch__)	||	\
	defined(__SYSC_ZARCH__)	\
)
#define AR_Z
#endif /* SystemZ */

/* Template
#if !defined(AR_) && defined()
#define
#endif
#if !defined(AR_)	&&(	\
	defined()		||	\
	defined()			\
)
#define
#endif
*/

/* Is 32-bit architecture */
#if	!defined(AR_BIT)					&&(	\
	defined(AR_ARM)						||	\
	defined(AR_BFIN)					||	\
	defined(AP_HPPA) && (AP_HPPA < 20)	||	\
	defined(AR_I86)						||	\
	defined(AR_M68K)					||	\
	AR_MIPS < 3							||	\
	AR_PPC < 620						||	\
	AR_SPARC < 9						||	\
	AR_SH < 5								\
)
#define AR_BIT 32
#endif /* Is 32-bit architecture */

/* Is 64-bit architecture */
#if !defined(AR_BIT)	&&(	\
	defined(AR_ALPHA)					||	\
	defined(AR_AMD64)					||	\
	defined(AR_ARM64)					||	\
	defined(AP_HPPA) && (AP_HPPA < 20)	||	\
	defined(AR_IA64)					||	\
	AR_MIPS >= 3						||	\
	AR_PPC >= 620						||	\
	AR_SPARC >= 9						||	\
	AR_SH >= 5								\
)
#define AR_BIT 64
#endif /* Is 64-bit architecture */

#endif
