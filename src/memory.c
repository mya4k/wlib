#define NOT_YET_IMPLIMENTED 1

#if NOT_YET_IMPLIMENTED != 1

/**
 * \file	memory.c
 * \author	Wispy (wspvlv@gmail.com)
 * \brief	Memory allocation
 * \version	0.1
 * \date	2021-07-28
 */
#include <wc/core.h>
#include <wc/types.h>



#ifndef REGION_MOVE_TO_MEMORY_H
#	define MSize	wl_MSize
	typedef U32		wl_MSize;
#endif



/**
 * \brief	Size classes
 * \var		const U16 _size_classes[]
 */
const U16 _size_classes[] = {
	1, 2, 3, 4, 5, 6, 7, 8,
	9, 10, 12, 15,
	18, 20, 25, 31,
	36, 42, 50, 63,
	72, 84, 102, 127,
	146, 170, 204, 255,
	292, 340, 409, 511,
	584, 682, 818, 1023,
	1169, 1364, 1637, 2047,
	2340, 2730, 3276, 4095,
	4680, 5460, 6552, 8191,
};



/**
 * \brief	Size to class
 * \fn		static inline int _s2c(wl_MSize n)
 * \param	n	size
 * \return	int	 Size class of \a n
 */
static inline int _s2c(wl_MSize n)
{
	n = (n+3)>>4;
	if (n<10) return n;
	int i = (28-a_clz_32(n++))*4 + 8;
	if (n>_size_classes[i+1])	i+=2;
	if (n>_size_classes[i])		i++;
	return i;
}



/**
 * \brief	Dynamic memory allocator
 * \fn		Vo* wl_mal(MSize s)
 * \param	s	Size in bytes
 * \return	Vo* Pointer to then newly allocated space, NULL on failure
 */
Vo* wl_mal(MSize s) {
	if (s) {
		int c = _s2c(s);
		
	}
	/* If s = 0, nothing to allocate */
	else return NULL;
}

#endif