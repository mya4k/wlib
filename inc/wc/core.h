/**
 * \file core.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief C & C++ compatibility across standard versions
 * \version 0.1
 * \date 2021-06-29
 * 
 * 
 */
#ifndef WC_CORE_H
#define WC_CORE_H



#include <wc/sys/lang.h>
#include <wc/io.h>



#ifdef LC_CPP
#define EXTERN			extern "C"
#define C_DECL_BEGIN	EXTERN {
#define C_DECL_END		}
#else
#define EXTERN			extern
#define C_DECL_BEGIN
#define C_DECL_END
#endif

#ifndef NULL
#define NULL	((void*)0)
#endif

#ifndef ERR
#define ERR		
#endif


#endif