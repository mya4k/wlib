#ifndef OSYS_H
#define OSYS_H

/* AIX */
#if !defined(OS_AIX) && defined(_AIX)
#if defined(_AIX3) || defined(_AIX32)
#define OS_AIX 32
#elif defined(_AIX41)
#define OS_AIX 41
#elif defined(_AIX43)
#define OS_AIX 43
#else
#define OS_AIX 00
#endif
#endif /* AIX */

/* Android */
#if !defined(OS_ANDROID) && defined(__ANDROID__)
#include <android/api-level.h>
#if defined(__ANDROID_API__)
#define OS_ANDROID __ANDROID_API__
#else
#define OS_ANDROID 0
#endif
#endif /* Android */

/* Amdahl UTS */
#if !defined(OS_UTS) && defined(UTS)
#define OS_UTS
#endif /* Amdahl UTS */

/* AmigaOS */
#if !defined(OS_AMIGA) && defined(AMIGA)
#define OS_AMIGA
#endif

/* Apollo Domain/OS */
#if !defined(OS_APOLLO) && defined(apollo)
#define OS_APOLLO
#endif /* Apollo Domain/OS */

/* BeOS */
#if !defined(OS_BEOS) && defined(__BEOS__)
#define OS_BEOS
#endif /* BeOS */

/* Blue Gene */
#if !defined(OS_BG) && defined(__bg__)
#define OS_BG
#endif /* Blue Gene */

/* Blue Gene/Q */
#if !defined(OS_BGQ) && defined(__bgq__)
#define OS_BGQ
#endif /* Blue Gene */

/* BSD Environment */
#if !defined(OS_BSD) && defined(BSD)
#if	defined(BSD4_4)
#define OS_BSD 199306
#else
#define OS_BSD BSD
#endif
#endif /* BSD Environment */

/* BSD/OS */
#if !defined(OS_BSDI) && defined(__bsdi__)
#define OS_BSDI
#endif /* BSD/OS */

/* ConvexOS */
#if !defined(OS_CONVEX) && defined(__convex__)
#define OS_CONVEX
#endif /* ConvexOS */

/* Cygwin Environment */
#if !defined(OS_CYGWIN) && defined(__CYGWIN__)
#define OS_CYGWIN
#endif /* Cygwin Environment */

/* DG/UX */
#if !defined(OS_DGUX) && defined(DGUX)
#define OS_DGUX
#endif /* DG/UX */

/* DragonFly */
#if !defined(OS_DFLY) && defined(__DragonFly__) && !defined(__FreeBSD__)
#define OS_DFLY
#endif /* DragonFly */

/* DYNIX/ptx */
#if !defined(OS_PTX) && defined(_SEQUENT_)
#define OS_PTX
#endif /* DYNIX/ptx */

/* eCos */
#if !defined(OS_ECOS) && defined(__ECOS)
#define OS_ECOS
#endif /* eCos */

/* EMX Environment */
#if !defined(OS_EMX) && defined(__EMX__)
#define OS_EMX
#endif /* EMX Environment */

/* FreeBSD */
#if !defined(OS_FREEBSD) && defined(__FreeBSD__)
#ifdef __FreeBSD_version
#define OS_FREEBSD __FreeBSD_version
#endif
#endif /* FreeBSD */

/* GNU */
#if !defined(OS_GNU) && defined(__gnu_hurd__)
#define OS_GNU
#endif /* GNU */

/* GNU/kFreeBSD */
#if !defined(OS_GNU_BSD) && defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#define OS_GNU_BSD
#endif /* GNU/kFreeBSD */

/* GNU/Linux */
#if !defined(OS_GNU_LINUX) && defined(__gnu_linux__)
#define OS_GNU_LINUX
#endif /* GNU/Linux */

/* HI-UX MPP */
#if !defined(OS_HIUXMPP) && defined(__hiuxmpp)
#define OS_HIUXMPP
#endif /* HI-UX MPP */

/* HP-UX */
#if !defined(OS_HPUX) && defined(hpux)
#define OS_HPUX
#endif /* HP-UX */

/* IBM OS/400 */
#if !defined(OS_400) && defined(__OS400__)
#define OS_400
#endif /* IBM OS/400 */

/* INTEGRITY */
#if !defined(OS_INTEGRITY) && defined(__INTEGRITY)
#define OS_INTEGRITY
#endif /* INTEGRITY */

/* Interix Environment */
#if !defined(OS_INTERIX) && defined(__INTERIX)
#define OS_INTERIX
#endif /* Interix Environment */

/* IRIX */
#if !defined(OS_IRIX) && defined(sgi)
#define OS_IRIX
#endif /* IRIX */

/* Linux kernel */
#if !defined(OS_LINUX) && defined(__linux__)
#define OS_LINUX __linux__
#endif

/* LynxOS */
#if !defined(OS_LYNX) && defined(__Lynx__)
#define OS_LYNX
#endif /* LynxOS */

/* MacOS */
#if	!defined(OS_MAC) && \
	(defined(macintosh) || ( defined(_APPLE__) && defined(__MACH__) ))
#define OS_MAC
#endif

/* Microware OS-9 */
#if !defined(OS_9) && defined(__OS9000)
#define OS_9
#endif /* Microware OS-9 */

/* MINIX */
#if !defined(OS_MINIX) && defined(__minix)
#define OS_MINIX
#endif /* MINIX */

/* MorphOS */
#if !defined(OS_MORPHOS) && defined(__MORPHOS__)
#define OS_MORPHOS
#endif /* MorphOS */

/* MPE/iX */
#if !defined(OS_MPEIX) && defined(mpeix)
#define OS_MPEIX
#endif /* MPE/iX */

/* MSDOS */
#if !defined(OS_DOS) && defined(MSDOS)
#define OS_DOS
#endif /* MSDOS */

/* NetBSD */
#if !defined(OS_NETBSD) && defined(__NetBSD__)

#define NETBSD_0_8		800
#define NETBSD_0_9		900
#define NETBSD_1_0		1000
#define NETBSD_1_0A		1001
#define NETBSD_1_2D		1201
#define NETBSD_1_2_1	1210

#if		defined(NetBSD0_8)
#define OS_NETBSD NETBSD_0_8
#elif	defined(NetBSD0_9)
#define OS_NETBSD NETBSD_0_9
#elif	NetBSD1_0 == 1
#define OS_NETBSD NETBSD_1_0
#elif	NetBSD1_0 == 2
#define OS_NETBSD NETBSD_1_0A
#elif	__NetBSD_Version__ == 102040000
#define OS_NETBSD NETBSD_1_2D
#elif	__NetBSD_Version__ == 102000100
#define OS_NETBSD NETBSD_1_2_1
#else
#define OS_NETBSD 0
#endif

#endif /* NetBSD */

/* NonStop */
#if !defined(OS_NONSTOP) && defined(__TANDEM)
#define OS_NONSTOP
#endif /* NonStop */

/* Nucleus RTOS */
#if !defined(OS_NUCLEUS) && defined(__nucleus__)
#define OS_NUCLEUS
#endif /* Nucleus RTOS */

/* OpenBSD */
#if !defined(OS_OPENBSD) && defined(OpenBSD)
#if defined(OpenBSD3_1)
#define OS_OPENBSD 31
#elif defined(OpenBSD3_9)
#define OS_OPENBSD 39
#endif
#endif /* OpenBSD */

/* OS/2 */
#if !defined(OS_2) && defined(OS2)
#define OS_2
#endif /* OS/2 */

/* Palm OS */
#if !defined(OS_PALM) && defined(__palmos__)
#define OS_PALM
#endif /* Palm OS */

/* Plan 9 */
#if !defined(OS_PLAN) && defined(EPLAN9)
#define OS_PLAN
#endif /* Plan 9 */

/* Pyramid DC/OSx */
#if !defined(OS_PYR) && defined(pyr)
#define OS_PYR
#endif /* Pyramid DC/OSx */

/* QNX */
#if !defined(OS_QNX)
#if defined(__QNX__)
#define OS_QNX 400
#elif defined(__QNXNTO__)
#define OS_QNX 600
#elif defined(_NTO_VERSION)
#define OS_QNX _NTO_VERSION
#endif
#endif /* QNX */

/* Reliant UNIX */
#if !defined(OS_SINIX) && defined(sinux)
#define OS_SINIX
#endif /* Reliant UNIX */

/* SCO OpenServer */
#if !defined(OS_SCO_DS) && defined(_SCO_DS)
#define OS_SCO_DS 
#endif /* SCO OpenServer */

/* Solaris */
#if !defined(OS_SUN) && defined(sun)
#if defined(__SunOS_5_7)
#define OS_SUN 27
#elif defined(__SunOS_5_8)
#define OS_SUN 80
#endif
#endif /* Solaris */

/* Stratus VOS */
#if !defined(OS_VOS) && defined(__VOS__)
#define OS_VOS __VOS__
#endif /* Stratus VOS */

/* SVR4 Environment */
#if !defined(OS_SVR4) && defined(__sysv__)
#define OS_SVR4
#endif /* SVR4 Environment */

/* Syllable */
#if !defined(OS_SYLLABLE) && defined(__SYLLABLE__)
#define OS_SYLLABLE
#endif /* Syllable */

/* Symbian OS */
#if !defined(OS_SYMBIAN) && defined(__SYMBIAN32__)
#define OS_SYMBIAN
#endif /* Symbian OS */

/* Tru64 (OSF/1) */
#if !defined(OS_OSF) && defined(__osf__)
#define OS_OSF
#endif /* Tru64 (OSF/1) */

/* Ultrix */
#if !defined(OS_ULTRIX) && defined(ultrix)
#define OS_ULTRIX
#endif /* Ultrix */

/* UNICOS */
#if !defined(OS_UNICOS) && defined(_UNICOS)
#define OS_UNICOS _UNICOS
#endif /* UNICOS */

/* UNICOS/mp */
#if !defined(OS_CRAY) && defined(_CRAY)
#define OS_CRAY _CRAY
#endif /* UNICOS/mp */

/* Unix Environment */
#if !defined(OS_UNIX) && defined(__unix__)
#define OS_UNIX
#endif

/* UnixWare */
#if !defined(OS_UNIXWARE) && defined(sco)
#define OS_UNIXWARE
#endif /* UnixWare */

/* U/Win Environment */
#if !defined(OS_UWIN) && defined(_UWIN)
#define OS_UWIN
#endif /* U/Win Environment */

/* VMS */
#if !defined(OS_VMS) && defined(__VMS)
#if defined(__VMS_VER)
#define OS_VMS __VMS_VER
#else
#define OS_VMS
#endif
#endif /* VMS */

/* VxWorks */
#if !defined(OS_VXWORKS) && defined(__VXWORKS__)
#if defined(_WRS_VXWORKS_MAJOR) && defined(_WRS_VXWORKS_MINOR) && defined(_WRS_VXWORKS_MAINT)
#define OS_VXWORKS _WRS_VXWORKS_MAJOR * 100 + _WRS_VXWORKS_MINOR * 10 + _WRS_VXWORKS_MAINT
#else
#define OS_VXWORKS
#endif
#endif /* VxWorks */

/* Windows */
#if !defined(OS_WIN) && ( defined(_WIN16) || defined(_WIN32) )
#define OS_WIN
#endif

/* Windows 16-bit */
#if !defined(OS_WIN16) && defined(_WIN16)
#define OS_WIN16
#endif 

/* Windows 32-bit */
#if !defined(OS_WIN32) && ( defined(_WIN32) || !defined(_WIN64))
#define OS_WIN32
#endif

/* Windows 64-bit */
#if !defined(OS_WIN64) && defined(_WIN64)
#define OS_WIN64
#endif

/* Windows CE */
#if !defined(OS_WCE) && defined(_WIN32_WCE)
#define OS_WCE _WIN32_WCE
#endif /* Windows CE */

/* Wind/U Environment */
#if !defined(OS_WINDU) && defined(_WINDU_SOURCE)
#define OS_WINDU _WINDU_SOURCE
#endif

/* z/OS */
#if !defined(OS_ZOS) && defined(__MVS__)
#define OS_ZOS
#endif
/* z/OS */

/*
#if !defined(OS_) && defined()
#define
#endif
*/

#endif