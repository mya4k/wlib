#ifndef WC_SYS_COMP_H
#define WC_SYS_COMP_H



#define WC_CM_MSVC			1	/* Microsoft Visual C++ */
#define WC_CM_CLANG			2	/* Clang */
#define WC_CM_GCC			3	/* GCC */
#define WC_CM_MINGW			4	/* MinGW */



#ifndef WC_CM
#	if		defined(_MSC_VER)
#		define WC_CM WC_CM_MSVC
#	elif	defined(__clang__)
#		define WC_CM WC_CM_CLANG
#	elif	defined(__GNUC__)
#		define WC_CM WC_CM_GCC
#	elif	defined(__MINGW32__) ||\
			defined(__MINGW64__)
#		define WC_CM WC_CM_MINGW
#	endif
#endif



#endif
