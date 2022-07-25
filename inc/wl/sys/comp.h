#ifndef WL_SYS_COMP_H
#define WL_SYS_COMP_H



#define WL_CM_MSVC			1	/* Microsoft Visual C++ */
#define WL_CM_CLANG			2	/* Clang */
#define WL_CM_GCC			3	/* GCC */
#define WL_CM_MINGW			4	/* MinGW */
#define WL_CM_OTHER			-1



#ifndef WL_CM
#	if		defined(_MSC_VER)
#		define WL_CM WL_CM_MSVC
#	elif	defined(__clang__)
#		define WL_CM WL_CM_CLANG
#		define WL_CLANG_ATTR	1
#	elif	defined(__GNUC__)
#		define WL_CM WL_CM_GCC
#		define WL_GNU_ATTR		1
#	elif	defined(__MINGW32__) ||\
			defined(__MINGW64__)
#		define WL_CM WL_CM_MINGW
#		define WL_MINGW_ATTR	1
#	else
#		define WL_CM WL_CM_OTHER	
#	endif
#endif

#if WL_CM==WL_CM_GCC || WL_CM==WL_CM_CLANG || WL_CM==WL_CM_MINGW
#define WL_GCCLIKE	1
#endif



#endif
