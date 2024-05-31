#include <stdarg.h>

typedef unsigned int U32l;
typedef unsigned long U64l;

#define wl_va_arg(arg, type)\
	(type)_va_arg((_va_list*)&arg)

typedef struct _va_list {
	U32l gp_offset;
	U32l fp_offset;
	U64l overflow_arg_area;
	U64l reg_save_area;
} _va_list;

/* typedef char* _va_list; */

inline static U64l _va_arg(register _va_list* restrict arg) {
	register U64l a;

	if (arg->gp_offset <= 47) {
        a = arg->reg_save_area + arg->gp_offset;
        arg->gp_offset += 8;
	}
	else {
        a = arg->overflow_arg_area;
        arg->overflow_arg_area = a+8;
	}
	
	return *(U64l*)a;
}

/* U32l _va_arg(register _va_list* arg) {
    register U32l a = (U32l)arg;
    arg = (_va_list*)(a+4);
    return *(U32l*)a;
} */

#define _va_start(arg, param)\
    arg = (_va_list)((U32l)&param+1)

#include <stdio.h>

unsigned int sum(unsigned int count, ...) {
    unsigned int r = 0;
    va_list a;
    /* va_start(a, count); */
    /*   lea eax, [ebp+12] # tmp103,
         mov DWORD PTR [ebp-16], eax # MEM[(char * *)&a], tmp103 */
    va_start(a, count);

    while (count > 0) {
        r += wl_va_arg(a, unsigned long);
        count--;
    }

    va_end(a);

    printf("%u ", r);

    return r;
}

unsigned int sym(   unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4, 
                    unsigned char a5, unsigned char a6, unsigned char a7, unsigned char a8,
                    unsigned char a9, unsigned char a10, unsigned char a11, unsigned char a12, 
                    unsigned char a13, unsigned char a14, unsigned char a15, unsigned char a16);

int main() {
    sum(2, 1, 2);
    /* sum(16, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16); */
    return 0;
    /* sym(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16); */
}
