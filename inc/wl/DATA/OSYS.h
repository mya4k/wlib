#ifndef OSYS_H
#define OSYS_H

/* Android */
#if !defined(OS_ANDROID) && defined(__ANDROID__)
#include <android/api-level.h>
#define OS_ANDROID 	__ANDROID_API__
#endif

/* Linux kernel */
#if !defined(OS_LINUX) && defined(__linux__)
#define OS_LINUX __linux__
#endif

/* MacOS */
#if	!defined(OS_MAC) && \
	(defined(macintosh) || ( defined(_APPLE__) && defined(__MACH__) ))
#define OS_MAC
#endif

/* Unix */
#if !defined(OS_UNIX) && defined(__unix__)
#define OS_UNIX
#endif

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

#endif