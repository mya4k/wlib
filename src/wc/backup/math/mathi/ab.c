/* Absolute function source code */
/* Algorithm of ab(x):
	 * x < 0, -x
	 * x >= 0, x
 */

#include <wc/core/types.h>

#define absolute ab

inline I32 ab	(I32 x) {
	return (x<0) ? -x : x;
}

inline I64 abl	(I64 x) {
	return (x<0) ? -x : x;
} 