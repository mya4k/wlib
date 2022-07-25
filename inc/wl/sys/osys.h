#ifndef WL_SYS_OSYS_H
#define WL_SYS_OSYS_H



#define WL_OS_UNKNOWN				0
#define WL_OS_AIX					1	/* AIX */
#define WL_OS_IBM_AIX				1
#define WL_OS_ANDROID				2	/* Android */
#define WL_OS_UTS					3	/* Amdahl UTS */
#define WL_OS_AMIGAOS				4	/* AmigaOS */
#define WL_OS_AMIGA					4
#define WL_OS_AEGIS					5	/* Apollo AEGIS */
#define WL_OS_APOLLO				6	/* Apollo Domain/OS */
#define WL_OS_DOMAIN				6
#define WL_OS_DOMAIN_OS				6
#define WL_OS_BEOS					7	/* BeOS */
#define WL_OS_BLUE_GENE				8	/* Blue Gene */
#define WL_OS_BG					8
#define WL_OS_BSD					9	/* BSD and decendants */
#define WL_OS_EMX					10	/* EMX Environment */
#define WL_OS_CONVEX				11	/* ConvexOS */
#define WL_OS_CONVEXOS				11
#define WL_OS_CONVEX_OS				11
#define WL_OS_CYGWIN				12	/* Cygwin */
#define WL_OS_DGUX					13	/* DG/UX */
#define WL_OS_DG_UX					13
#define WL_OS_DYNIX					14	/* DYNIX/ptr */
#define WL_OS_DYNIX_PTX				14
#define WL_OS_DYNIXPTX				14
#define WL_OS_ECOS					15	/* eCOS */
#define WL_OS_GNU					16	/* GNU/Hurd */
#define WL_OS_GNUHURD				16
#define WS_OS_GNU_HURD				16
#define WL_OS_HURD					16
#define WL_OS_HI_UX_MPP				17	/* HI-UX MPP */
#define WL_OS_HIUX_MPP				17
#define WL_OS_HI_UX					17
#define WL_OS_HIUX					17
#define WL_OS_HP_UX					18	/* HP-UX */
#define WL_OS_HPUX					18
#define WL_OS_OS400					19	/* IBM OS/400*/
#define WL_OS_400					19
#define WL_OS_IBM_OS400				19
#define WL_OS_IBM_I5_OS				19
#define WL_OS_IBM_I5OS				19
#define WL_OS_I5_OS					19
#define WL_OS_IBM_I5OS				19
#define WL_OS_I5					19
#define WL_OS_IBMI					19
#define WL_OS_IBM_I					19
#define WL_OS_INTEGRITY				20	/* INTEGRITY */
#define WL_OS_INTERIX				21	/* Interix */
#define WL_OS_IRIX					22	/* IRIX */
#define WL_OS_SGI					22
#define WL_OS_LINUX					23	/* Linux kernel*/
#define WL_OS_LYNXOS				24	/* LynxOS */
#define WL_OS_LYNXOS_RTOS			24
#define WL_OS_LYNX					24
#define WL_OS_MACOS					25	/* MacOS */
#define WL_OS_MAC					25
#define WL_OS_MACINTOSH				25
#define WL_OS_OS_9					26	/* OS-9 */
#define WL_OS_OS9					26
#define WL_OS_9						26
#define WL_OS_MINIX					27	/* MINIX */
#define WL_OS_MORPHOS				28	/* MorphOS */
#define WL_OS_MORPH					28
#define WL_OS_MPE					29	/* MPE/iX */
#define WL_OS_MPE_XL				29
#define WL_OS_MPE_IX				29
#define WL_OS_MPEXL					29
#define WL_OS_MPEIX					29
#define WL_OS_MSDOS					30	/* MS-DOS */
#define WL_OS_MS_DOS				30
#define WL_OS_NONSTOP				31	/* NonStop */
#define WL_OS_TANDEM				31
#define WL_OS_NUCLEUS				32	/* Nucleus RTOS */
#define WL_OS_NUCLEUS_RTOS			32
#define WL_OS_OS2					33	/* OS/2 */
#define WL_OS_OS_2					33
#define WL_OS_2						33
#define WL_OS_PALMOS				34	/* PalmOS */
#define WL_OS_PALM_OS				34
#define WL_OS_PALM					34
#define WL_OS_GARNET_OS				34
#define WL_OS_GARNETOS				34
#define WL_OS_GARNET				34
#define WL_OS_PLAN9					35	/* Plan9 */
#define WL_OS_PLAN_9				35
#define WL_OS_P9					35
#define WL_OS_9P					35
#define WL_OS_DC_OSX				36	/* DC/OSx */
#define WL_OS_DCOSX					36
#define WL_OS_PYR					36
#define WL_OS_QNX					37	/* QNX */
#define WL_OS_SINIX					38	/* SIMIX */
#define WL_OS_OPENSERVER			39	/* OpenServer */
#define WL_OS_OPEN_SERVER			39
#define WL_OS_XINUOUS_OPENSERVER	39
#define WL_OS_XINUOUS_OPEN_SERVER	39
#define WL_OS_SCO					39
#define WL_OS_SCO_UNIX				39
#define WL_OS_SCO_ODT				39
#define WL_OS_SCO_OPEN_DESKTOP		39
#define WL_OS_SCO_OPENDESKTOP		39
#define WL_OS_XENIX					39
#define WL_OS_SOLARIS				40	/* Solaris */
#define WL_OS_SUNOS					40
#define WL_OS_SUN_OS				40
#define WL_OS_SUN					40
#define WL_OS_SUN_UNIX				40
#define WL_OS_STRATUS_VOS			41	/* Stratus VOS */
#define WL_OS_STRATUS_V				41
#define WL_OS_VOS					41
#define WL_OS_V						41
#define WL_OS_SYLLABLE				42	/* Syllable */
#define WL_OS_SYMBIAN				43	/* Symbian OS */
#define WL_OS_TRU64					44	/* Tru64 (OSF/1) */
#define WL_OS_OSF					44
#define WL_OS_OSF1					44
#define WL_OS_OSF_1					44
#define WL_OS_DEC_OSF1				44
#define WL_OS_DEC_OSF_1				44
#define WL_OS_DEC_OSF1_AXP			44
#define WL_OS_DEC_OSF_1_AXP			44
#define WL_OS_DIGITAL_UNIX			44
#define WL_OS_ULTRIX				45	/* ULTRIX */
#define WL_OS_UNICOS				46	/* UNICOS */
#define WL_OS_UNICOS_MP				47	/* UNICOS/mp */
#define WL_OS_UNIX					48	/* UNIX */
#define WL_OS_UNIXWARE				49	/* UnixWare */
#define WL_OS_UWIN					50	/* U/Win */
#define WL_OS_U_WIN					50
#define WL_OS_VMS					51	/* OpenVMS */
#define WL_OS_OPENVMS				51
#define WL_OS_VXWORKS				52	/* VXWorks */
#define WL_OS_WINDOWS				53	/* Windows */
#define WL_OS_WIN					53
#define WL_OS_WINDOWS_CE			54	/* Windows CE */
#define WL_OS_WIN_CE				54
#define WL_OS_WINDOWS_WCE			54
#define WL_OS_WIN_WCE				54
#define WL_OS_WINDU					55	/* Wind/U */
#define WL_OS_WIND_U				55
#define WL_OS_Z_OS					56	/* z/OS */
#define WL_OS_Z						56
#define WL_OS_ZOS					56




#ifndef WL_OS
#	if		defined(_AIX)			||\
			defined(__TOS_AIX__)
#		define WL_OS WL_OS_AIX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__ANDROID__)
#		define WL_OS WL_OS_ANDROID
#		define WL_OS_UNIXLIKE 1
#	elif	defined(UTS)
#		define WL_OS WL_OS_UTS
#		define WL_OS_UNIXLIKE 1
#	elif	defined(AMIGA)			||\
			defined(__amigaos__)
#		define WL_OS WL_OS_AMIGAOS
#	elif	defined(aegis)
#		define WL_OS WL_OS_AEGIS
#	elif	defined(apollo)
#		define WL_OS WL_OS_APOLLO
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__BEOS__)
#		define WL_OS WL_OS_BEOS
#	elif	defined(__bg__)			||\
			defined(__THW_BLUEGENE_)
#		define WL_OS WL_OS_BG
#	elif	defined(__FreeBSD__)	|| \
			defined(__NetBSD__)		|| \
			defined(__OpenBSD__)	|| \
			defined(__bsdi__)		|| \
			defined(__DragonFly__)	|| \
			defined(_SYSTYPE_BSD)
#		define WL_OS WL_OS_BSD
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__convex__)
#		define WL_OS WL_OS_CONVEX	
#	elif	defined(__CYGWIN__)
#		define WL_OS WL_OS_CYGWIN	
#		define WL_OS_UNIXLIKE 1
#	elif	defined(DGUX)			|| \
			defined(__DGUX__)		|| \
			defined(__dgux__)
#		define WL_OS WL_OS_DGUX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(_SEQUENT_)		||\
			defined(sequent)
#		define WL_OS WL_OS_DYNIX_PTX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__ECOS)
#		define WL_OS WL_OS_ECOS
#	elif	defined(__EMX__)
#		define WL_OS WL_OS_EMX
#	elif	defined(__GNU__)		||\
			defined(__gnu_hurd__)
#		define WL_OS WL_OS_GNU_HURD
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__hiuxmpp)
#		define WL_OS WL_OS_HI_UX_MPP
#		define WL_OS_UNIXLIKE 1
#	elif	defined(_hpux)			||\
			defined(hpux)			||\
			defined(__hpux)
#		define WL_OS WL_OS_HPUX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__OS400__)
#		define WL_OS WL_OS_OS400
#	elif	defined(__INTEGRITY)
#		define WL_OS WL_OS_INTEGRITY
#	elif	defined(__INTERIX)
#		define WL_OS WL_OS_INTERIX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(sgi)			||\
			defined(__sgi)
#		define WL_OS WL_OS_IRIX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(linux)			||\
			defined(__linux)		||\
			defined(__linux__)
#		define WL_OS WL_OS_LINUX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__Lynx__)
#		define WL_OS WL_OS_LYNX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(macintosh)		||\
			defined(Macintosh)		||\
			(defined(__APPLE__) && defined(__MACH__))
#		define WL_OS WL_OS_MAC
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__OS9000)		||\
			defined(_OSK)
#		define WL_OS WL_OS_OS9
#	elif	defined(__minix)
#		define WL_OS WL_OS_MINIX
#	elif	defined(__MORPHOS__)
#		define WL_OS WL_OS_MORPHOS
#	elif	defined(mpeix)			||\
			defined(__mpexl)
#		define WL_OS WL_OS_MPE_IX
#	elif	defined(MSDOS)			||\
			defined(_MSDOS)			||\
			defined(__MSDOS__)
#		define WL_OS WL_OS_MSDOS
#	elif	defined(__TANDEM)
#		define WL_OS WL_OS_NONSTOP
#	elif	defined(__OS2__)		||\
			defined(_OS2)			||\
			defined(OS2)			||\
			defined(__TOS_OS2__)
#		define WL_OS WL_OS_MSDOS
#	elif	defined(__palmos__)
#		define WL_OS WL_OS_PALMOS
#	elif	defined(EPLAN9)
#		define WL_OS WL_OS_PLAN9
#		define WL_OS_UNIXLIKE 1
#	elif	defined(pyr)
#		define WL_OS WL_OS_PYR
#	elif	defined(__QNX__)		||\
			defined(__QNXNTO__)
#		define WL_OS WL_OS_QNX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(M_I386)			||\
			defined(M_XENIX)		||\
			defined(_SCO_DS)
#		define WL_OS WL_OS_OPENSERVER
#		define WL_OS_UNIXLIKE 1
#	elif	defined(sun)			||\
			defined(__sun)
#		define WL_OS WL_OS_SUN
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__SYLLABLE__)
#		define WL_OS WL_OS_SYLLABLE
#	elif	defined(__osf__)		||\
			defined(__osf)
#		define WL_OS WL_OS_TRU64
#	elif	defined(ultrix)			||\
			defined(__ultrix)		||\
			defined(__ultrix__)		||\
			(defined(unix) && defined(vax))
#		define WL_OS WL_OS_ULTRIX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(_UNICOS)
#		define WL_OS WL_OS_UNICOS
#	elif	defined(_CRAY)		 	||\
			defined(__crayx1)
#		define WL_OS WL_OS_UNICOS_MP
#	elif	defined(__unix__)		||\
			defined(__unix)
#		define WL_OS WL_OS_UNIX
#		define WL_OS_UNIXLIKE 1
#	elif	defined(sco)		 	||\
			defined(_UNIXWARE7)
#		define WL_OS WL_OS_UNIXWARE
#		define WL_OS_UNIXLIKE 1
#	elif	defined(_UWIN)
#		define WL_OS WL_OS_UWIN
#		define WL_OS_UNIXLIKE 1
#	elif	defined(__VMS)		 	||\
			defined(VMS)
#		define WL_OS WL_OS_VMS
#	elif	defined(__VXWORKS__)	||\
			defined(__vxworks)
#		define WL_OS WL_OS_VXWORKS
#	elif	defined(_WIN16)			||\
			defined(_WIN32)			||\
			defined(_WIN64)			||\
			defined(__WIN32__)		||\
			defined(__TOS_WIN__)	||\
			defined(__WINDOWS__)
#		define WL_OS WL_OS_WINDOWS
#	elif	defined(_WIN32_WCE)
#		define WL_OS WL_OS_WINDOWS_WCE
#	elif	defined(_WINDU_SOURCE)
#		define WL_OS WL_OS_WINDU
#	elif	defined(__MVS__)		||\
			defined(__HOS_MVS__)	||\
			defined(__TOS_MVS__)
#		define WL_OS WL_OS_ZOS

#	else
#		define WL_OS WL_OS_UNKNOWN
#	endif
#endif



#endif
