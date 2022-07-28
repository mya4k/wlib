#include <wl/array.h>
#include <wl/memory.h>



/**
 * \brief	Check N bytes of EXP for trueness
 * \def		_ANOL_NBITS(EXP,N)
 * \param	EXP	Expression
 * \param	N	Amount of bytes
 */
#define _ANOL_N(EXP,N)	\
	if (likely(((EXP) & (((UMax)1 << CHB*N)-1)))) return TRUE;

/* Optimal type for `rem` */
#if WL_CONF_OPTIMIZE&4 != WL_CONF_MEMORY
#	define _Rem	Pt
#else	/* WL_CONF_OPTIMIZE&4 != WL_CONF_MEMORY */
#	define _Rem	U8
#endif	/* WL_CONF_OPTIMIZE&4 != WL_CONF_MEMORY */

/* `arr1` have to be non-null and `len` greater than zero */
/* Get how many bytes till the next alignment */
/* Check for trueness in such bytes */
/* Check each word for trueness, until less than word size bytes are 
 * left
 */
/* Check the remaining bits for trueness */
/* Not a single true byte has been discovered */
#define _ANOL(arr1)										\
	if (((Pt)arr1 & len) != 0) {						\
		if (likely(len > sizeof(UMax))) {				\
			{											\
				const _Rem rem = (Pt)arr1%sizeof(UMax);	\
				if (likely(rem>0)) {					\
					_ANOL_N(*arr1,rem)					\
					len -= rem;							\
					arr1 = (UMax*)((char*)arr1 + rem);	\
				}										\
			}											\
			while (likely(len>=sizeof(UMax))) {			\
				if (unlikely(*arr1)) return TRUE;		\
				len -= sizeof(UMax);					\
				arr1++;									\
			}											\
			if (likely(len>0)) _ANOL_N(*arr1,len)		\
		}												\
		if (unlikely(len == sizeof(UMax)))				\
			return *arr1 != 0;							\
		return (*arr1 & (((UMax)1 << CHB*len)-1)) != 0;	\
	}													\
	return FALSE

#define _ANOL2(exp)															\
	if (((Pt)arr1 & (Pt)arr2 & len) != 0)	{								\
		if (likely(len > sizeof(UMax))) {									\
			{																\
				const _Rem rem = 											\
				_min2((Pt)arr1%sizeof(UMax), (Pt)arr2%sizeof(UMax));		\
				if (likely(rem>0)) {										\
					_ANOL_N((exp),rem)										\
					len -= rem;												\
					arr1 = (UMax*)((char*)arr1 + rem);						\
					arr2 = (UMax*)((char*)arr2 + rem);						\
				}															\
			}																\
			while (likely(len>=sizeof(UMax))) {								\
				if (unlikely((exp))) return TRUE;							\
				len -= sizeof(UMax);										\
				arr1++;	arr2++;												\
			}																\
			if (likely(len>0)) _ANOL_N((exp),len)							\
		}																	\
		if (unlikely(len == sizeof(UMax)))									\
			return (exp) != 0;												\
		return ((exp) & (((UMax)1 << CHB*len)-1)) != 0;						\
	}																		\
	return FALSE


/**
 * \brief 
 * 
 * \param arr1 
 * \param len 
 * \return Bl 
 */
Bl _anol(const UMax* restrict arr1, U32 len) {
	_ANOL(arr1);
}

#define _min2(x,y)	((x)<=(y) ? (x) : (y))

Bl _aanl(const UMax* restrict arr1, const UMax* restrict arr2, U32 len) {
	_ANOL2((Pt)arr1&(Pt)arr2);
}

Bl _aorl(const UMax* restrict arr1, const UMax* restrict arr2, U32 len) {
	_ANOL2((Pt)arr1|(Pt)arr2);
}

Bl _anq(const UMax* restrict arr1, const UMax* restrict arr2, U32 len) {
	_ANOL2((Pt)arr1^(Pt)arr2);
}
