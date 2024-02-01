#ifndef WL_VARIADIC_H
#define WL_VERIADIC_H	1



#if WL_STDARG_H

#if !WL_PREFIX
#	define vi	wl_vi
#	define vn	wl_vn
#	define vq	wl_vq
#endif

#	include <stdarg.h>

/**
 * \brief Variadic Arguments Initialize
 * 
 */
#	define wl_vi(list, preceding)	va_start(list, preceding);
/**
 * \brief Variadic Arguments Access Next
 * 
 */
#	define wl_vn(list, type)		va_arg(list, type);
/**
 * \brief Variadic Arguments Access Quit
 * 
 */
#	define wl_vq(list, type)		va_arg(list, type);
#else
#	error	"Variadic arguments require <stdarg.h>"
#endif



#endif
