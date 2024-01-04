#include <wl/array.h>



#define NO(X)	(X)
#define NT(X)	(~(X))
#define AN(X,Y)	((X)&(Y))
#define OR(X,Y)	((X)|(Y))
#define XR(X,Y)	((X)^(Y))
#define NN(X,Y)	(~((X)&(Y)))
#define NR(X,Y)	(~((X)|(Y)))
#define NX(X,Y)	(~((X)^(Y)))

#if WL_OPTIMIZE != WL_OPTIMIZE_MEMORY_EXTRA
#	define T_AXXSW1(NAME,FUNC)											\
		inline_unless_opt_size static void _##NAME##sw(						\
			char* restrict arr, const U32 len, char* restrict res		\
		) {																\
			register const UMax m = ((UMax)1<<(CHB*len)) - 1;			\
			*(UMax*)res = FUNC((*(UMax*)arr)&m) + ((*(UMax*)res)&(~m));	\
		}
#else	/* WL_OPTIMIZE != WL_OPTIMIZE_MEMORY_EXTRA */
#	define T_AXXSW1(NAME,FUNC)												\
		inline_unless_opt_size static void _##NAME##sw(							\
			char* restrict arr, const U32 len, char* restrict res			\
		) {																	\
			((*(UMax*)res) = FUNC((*(UMax*)arr)&(((UMax)1<<(CHB*len)) - 1))	\
			+ ((*(UMax*)res)&(UMX>>(CHB*len)<<(CHB*len)))));					\
		}
#endif	/* WL_OPTIMIZE != WL_OPTIMIZE_MEMORY_EXTRA */

#define T_AXXSW2(NAME,FUNC)											\
	inline_unless_opt_size static void _##NAME##sw(						\
		char* restrict arr1,char* restrict arr2,					\
		const U32 len, char* restrict res							\
	) {																\
		register const UMax m = ((UMax)1<<(CHB*len)) - 1;			\
		*(UMax*)res = FUNC(((*(UMax*)arr1)&m),((*(UMax*)arr2)&m))	\
		+ ((*(UMax*)res)&(~m));										\
	}


#if UMB > 32
#	define T_AXXSWS1(NAME,FUNC)											\
		inline_unless_opt_size static void _##NAME##sws(					\
			char* restrict arr, const U32 len, char* restrict res		\
		) {																\
			if (unlikely(len&4)) {										\
				*(U32l*)res = FUNC(*(U32l*)arr);						\
				res += 4; arr += 4;										\
			}															\
			if (unlikely(len&2)) {										\
				*(U16l*)res = FUNC(*(U16l*)arr);						\
				res += 2; arr += 2;										\
			}															\
			if (unlikely(len)) {										\
				*res = FUNC(*arr);										\
				res++; arr++;											\
			}															\
		}

#	define T_AXXSWS2(NAME,FUNC)										\
		inline_unless_opt_size static void _##NAME##sws(				\
			char* restrict arr1, char* restrict arr2, 				\
			const U32 len, char* restrict res						\
		) {															\
			if (unlikely(len&4)) {									\
				*(U32l*)res = FUNC(*(U32l*)arr1, *(U32l*)arr2);		\
				res += 4; arr1 += 4; arr2 += 4;						\
			}														\
			if (unlikely(len&2)) {									\
				*(U16l*)res = FUNC(*(U16l*)arr1, *(U16l*)arr2);		\
				res += 2; arr1 += 2; arr2 += 2;						\
			}														\
			if (unlikely(len)) {									\
				*res = FUNC(*arr1, *arr2);							\
				res++; arr1++; arr2++;								\
			}														\
		}
#else	/* UMB > 32 */
#	define T_AXXSWS1(NAME,FUNC)											\
		inline_unless_opt_size static void _##NAME##sws(					\
			char* restrict arr, const U32 len, char* restrict res		\
		) {																\
			if (unlikely(len&2)) {										\
				*(U16l*)res = FUNC(*(U16l*)arr);						\
				res += 2; arr += 2;										\
			}															\
			if (unlikely(len)) {										\
				*res = FUNC(*arr);										\
				res++; arr++;											\
			}															\
		}

#	define T_AXXSWS2(NAME,FUNC)										\
		inline_unless_opt_size static void _##NAME##sws(				\
			char* restrict arr1, char* restrict arr2, 				\
			const U32 len, char* restrict res						\
		) {															\
			if (unlikely(len&2)) {									\
				*(U16l*)res = FUNC(*(U16l*)arr1, *(U16l*)arr2);		\
				res += 2; arr1 += 2; arr2 += 2;						\
			}														\
			if (unlikely(len)) {									\
				*res = FUNC(*arr1, *arr2);							\
				res++; arr1++; arr2++;								\
			}														\
		}
#endif	/* UMB > 32 */

#if WL_AUTOVECTOR_LOOPS
#	define T_AXX1(NAME, FUNC) 												\
		const void* _##NAME(												\
			char* restrict arr, U32 len, char* restrict res					\
		) {																	\
			const char* const _res = res;									\
			while (unlikely(len > 0)) {										\
				*res = FUNC(*arr);											\
				len--; res++; arr++;										\
			}																\
			return _res;													\
		}

#	define T_AXX2(NAME, FUNC) 												\
		const void* _##NAME(												\
			char* restrict arr1, char* restrict arr2, 						\
			U32 len, char* restrict res										\
		) {																	\
			const char* const _res = res;									\
			while (unlikely(len > 0)) {										\
				*res = FUNC(*arr1, *arr2);									\
				len--; res++; arr1++; arr2++;								\
			}																\
			return _res;													\
		}
#else
#	define T_AXX1(NAME, FUNC) 												\
		const void* _##NAME(												\
			char* restrict arr, U32 len, char* restrict res					\
		) {																	\
			const char* const _res = res;									\
			if (unlikely(len <= sizeof(UMax))) {							\
				if (likely(len < sizeof(UMax))) {							\
					goto copyrem_##NAME;									\
				}															\
				else *(UMax*)res = FUNC(*(UMax*)arr);						\
			}																\
			else {															\
				{															\
					Pt rem = (Pt)res % sizeof(UMax);						\
					if (unlikely(rem > 0)) {								\
						_##NAME##sw(arr, rem, res);							\
						arr += rem; res += rem; len -= rem;					\
					}														\
				}															\
				while (unlikely(len >= sizeof(UMax))) {						\
					*(UMax*)res = FUNC(*(UMax*)arr);						\
					res += sizeof(UMax);									\
					arr += sizeof(UMax);									\
					len -= sizeof(UMax);									\
				}															\
				copyrem_##NAME:												\
					_##NAME##sws(arr, len, res);							\
			}																\
			return _res;													\
		}

#	define T_AXX2(NAME, FUNC) 												\
		const void* _##NAME(												\
			char* restrict arr1, char* restrict arr2,						\
			U32 len, char* restrict res										\
		) {																	\
			const char* const _res = res;									\
			if (unlikely(len <= sizeof(UMax))) {							\
				if (likely(len < sizeof(UMax))) {							\
					goto copyrem_##NAME;									\
				}															\
				else *(UMax*)res = FUNC(*(UMax*)arr1, (*(UMax*)arr2));		\
			}																\
			else {															\
				{															\
					Pt rem = (Pt)res % sizeof(UMax);						\
					if (unlikely(rem > 0)) {								\
						_##NAME##sw(arr1, arr2, rem, res);					\
						arr1 += rem; arr2 += rem; res += rem; len -= rem;	\
					}														\
				}															\
				while (unlikely(len >= sizeof(UMax))) {						\
					*(UMax*)res = FUNC(*(UMax*)arr1, (*(UMax*)arr2));		\
					res += sizeof(UMax);									\
					arr1 += sizeof(UMax);									\
					arr2 += sizeof(UMax);									\
					len -= sizeof(UMax);									\
				}															\
				copyrem_##NAME:												\
				_##NAME##sws(arr1, arr2, len, res);							\
			}																\
			return _res;													\
		}
#endif

#define T_AXX1ALL(NAME, FUNC)	\
	T_AXXSW1(NAME, FUNC)		\
	T_AXXSWS1(NAME, FUNC)		\
	T_AXX1(NAME, FUNC)

#define T_AXX2ALL(NAME, FUNC)	\
	T_AXXSW2(NAME, FUNC)		\
	T_AXXSWS2(NAME, FUNC)		\
	T_AXX2(NAME, FUNC)

T_AXX1ALL(ano, NO)
T_AXX1ALL(ant, NT)
T_AXX2ALL(aan, AN)
T_AXX2ALL(aor, OR)
T_AXX2ALL(axr, XR)
T_AXX2ALL(ann, NN)
T_AXX2ALL(anr, NR)
T_AXX2ALL(anx, NX)
