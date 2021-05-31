#include <wc/types.h>
#include <wc/types/char.h>

/**
 * @brief	String search
 * @fn		const u8 ss(const char* str, const char* find)
 * 
 * @param str 	String, where the search will happen
 * @param find	Character to find in `str`
 * @return const u8
 * 
 * Searches 
 */
u8 ss(const char* str, const char* find) {
	const u8 p = cs(str, find[0], 0);
	const u8 s = sl(find);
	
	if (p) {
		for ( u8 i = 1; i < s; i++)
			if (str[p+i] != find[i]) return SS_NOT_FOUND;
		return p;
	}

	return SS_NOT_FOUND;
}