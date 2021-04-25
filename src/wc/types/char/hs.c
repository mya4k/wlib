#include <wc/types.h>
#include <wc/types/char.h>
#include <wc/types/array.h>

/**
 * @brief	Hash function
 * @fn		u8 hs(const char* str, const char**	set, const u8 size)
 * 
 * @param str 
 * @param set 
 * @return u8 
 */
u8 hs(const char* str, const char** set, const u8 size) {
	for (u8 i = 0; str && set && i<size; i++)
		if (
				str[0] == set[i][0] 
			&&	aeq(sl(set[i])-2, (const VO*)&str[1], (const VO*)&set[i][1])
		) return i+1;
	return 0;
}