#ifndef WC_WINDOW_H
#define WC_WINDOW_H

#include <wc/sys/osys.h>

/* Unix-like are only supported for now */
#if defined(OS_UNIXLIKE)
#	include <X11/Xlib.h>
#	define wc(x, y, width, height) \
	XCreateSimpleWindow(XOpenDisplay(0), RootWindow(d, s))
#endif

#endif