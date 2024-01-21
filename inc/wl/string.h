#ifndef WL__STRING_H
#define WL__STRING_H	1



#include <wl/types.h>



#if !WL_PREFIX
#	define sl		wl_sl
#	define _sl		wl__sl
#endif



#define wl_sl(string) (((char*)(string))[sizeof(string)] ? wl__sl(string) : sizeof(string)-1)



typedef char wl_St[];
/**
 * \brief	Null-terminated String type
 * \typedef	wl_NSt
 * 
 * Data structure storing an array of `char`s
 */
typedef char wl_NSt[];



/* String length */
extern wl_U16 wl__sl(const char* restrict const string);



#endif
