#include <wc/array.h>
#include <wc/memory.h>



#define _min2(x,y)	((x)<=(y) ? (x) : (y))

/*
 *	Assigns `n` bits of `b` to `a`, preserving the remaining bits of `a`
 */
#if WL_CONF_OPTIMIZE&4 == WL_OPTIMIZE_MEMORY
/* Here doesn't use memory */
#	define _ASSIGN_SUBWORD(arr1,arr2,N)	\
		((arr1) = ((arr2)&(((UMax)1<<N) - 1)) + ((arr1)&(UMX>>N<<N))));
#else
/* Here we use memory, but it's faster */
#	define _ASSIGN_SUBWORD(arr1,arr2,N)	{		\
		const UMax m = ((UMax)1<<N) - 1;		\
		((arr1) = ((arr2)&m) + ((arr1)&~m));	\
	}
#endif

/* Optimal type for `rem` */
#if WL_CONF_OPTIMIZE&4 != WL_CONF_MEMORY
#	define _Rem	Pt
#else	/* WL_CONF_OPTIMIZE&4 != WL_CONF_MEMORY */
#	define _Rem	U8
#endif	/* WL_CONF_OPTIMIZE&4 != WL_CONF_MEMORY */

/*
 *	Assigns all bytes of `EXP` to `r`, where `EXP` is a expression.
 *	Firstly, assigns in chunks of `sizeof(UMax)`, for the remaining bits uses
 *	`_ASSIGN_SUBWORD()`
 * 	Method:
 * 		1.	Copy bytes till next alignment
 * 		2.	Copy bytes one word at a time
 * 		3.	Copy the remaining bytes (less than word bytes)
 */
#define _AFA1(EXP)															\
	if (likely(arr1 != NULL && len > 0)) {									\
		UMax* _res = res;													\
		if (likely(_res == NULL)) _res = mal(len);							\
		if (likely(_res != NULL)) {											\
			if (likely(len > sizeof(UMax))) {								\
				{															\
					const _Rem rem = (Pt)arr1%sizeof(UMax);					\
					if (unlikely(rem>0)) {									\
						_ASSIGN_SUBWORD(*_res, (EXP), CHB*rem);				\
						len -= rem;											\
						_res = (UMax*)((char*)_res + rem);					\
						arr1 = (UMax*)((char*)arr1 + rem);					\
					}														\
				}															\
																			\
				while (len >= sizeof(UMax)) {								\
					*_res = (EXP);											\
					_res++; arr1++; len -= sizeof(UMax);					\
				}															\
																			\
				if (likely(len))	_ASSIGN_SUBWORD(*_res, (EXP), CHB*len);	\
			}																\
			if (unlikely(len == sizeof(UMax))) *_res = (EXP);				\
			_ASSIGN_SUBWORD(*_res, (EXP), CHB*len);							\
			return _res;													\
		}																	\
	}																		\
	return NULL

#define _AFA2(EXP)															\
	if (likely(arr1 != NULL && arr2 != NULL && len > 0)) {					\
		UMax* _res = res;													\
		if (likely(_res == NULL)) _res = mal(len);							\
		if (likely(_res != NULL)) {											\
			if (likely(len > sizeof(UMax))) {								\
				{															\
					const _Rem rem = 										\
					_min2((Pt)arr1%sizeof(UMax), (Pt)arr2%sizeof(UMax));	\
					if (unlikely(rem>0)) {									\
						_ASSIGN_SUBWORD(*_res, (EXP), CHB*rem);				\
						len -= rem;											\
						_res = (UMax*)((char*)_res + rem);					\
						arr1 = (UMax*)((char*)arr1 + rem);					\
						arr2 = (UMax*)((char*)arr2 + rem);					\
					}														\
				}															\
																			\
				while (len >= sizeof(UMax)) {								\
					*_res = (EXP);											\
					_res++; arr1++; arr2++; len -= sizeof(UMax);			\
				}															\
																			\
				if (likely(len))	_ASSIGN_SUBWORD(*_res, (EXP), CHB*len);	\
			}																\
			if (unlikely(len == sizeof(UMax))) *_res = (EXP);				\
			_ASSIGN_SUBWORD(*_res, (EXP), CHB*len);							\
			return _res;													\
		}																	\
	}																		\
	return NULL



const UMax* _ano(
	const	UMax*					arr1,
			U32						len,
			UMax*	restrict const	res
) {
	_AFA1(*arr1);
}

const UMax* _aan(
	const	UMax*					arr1,
	const	UMax*					arr2,
			U32						len,
			UMax*	restrict const	res
) {
	_AFA2(*arr1 & *arr2);
}

const UMax* _aor(
	const	UMax*					arr1,
	const	UMax*					arr2,
			U32						len,
			UMax*	restrict const	res
) {
	_AFA2(*arr1 | *arr2);
}

const UMax* _axr(
	const	UMax*					arr1,
	const	UMax*					arr2,
			U32						len,
			UMax*	restrict const	res
) {
	_AFA2(*arr1 ^ *arr2);
}
