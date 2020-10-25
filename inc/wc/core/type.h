#ifndef WC_TYPE_H
#define WC_TYPE_H

#undef _NAME
#undef _TYPE
#undef _TYPE1
#undef _TYPE2
#undef _TYPE3

#define _TYPE1(_NAME, _TYPE, _MEM1) \
	typedef struct _NAME {_TYPE _MEM1;} _NAME
#define _TYPE2(_NAME, _TYPE, _MEM1, _MEM2) \
	typedef struct _NAME {_TYPE _MEM1, y;} _NAME
#define _TYPE3(_NAME, _TYPE, _MEM1, _MEM2, _MEM3) \
	typedef struct _NAME {_TYPE _MEM1, _MEM2, _MEM3;} _NAME
#define _TYPE4(_NAME, _TYPE, _MEM1, _MEM2, _MEM3, _MEM4) \
	typedef struct _NAME {_TYPE _MEM1, _MEM2, _MEM3, _MEM4;} _NAME

#define _QUICKTYPE1(_NAME, _TYPE) typedef _TYPE _NAME
#define _QUICKTYPE2(_NAME, _TYPE) typedef struct _NAME {_TYPE x, y;} _NAME
#define _QUICKTYPE3(_NAME, _TYPE) typedef struct _NAME {_TYPE x, y, z;} _NAME

#endif