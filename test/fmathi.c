#include <wc/math/mathi.h>

int main() {
    int x, y;
    
    return (
		y ? (
			x ? ({
				if (x==1) return 1;
				if (x==2) return 2 << (y-1);
				if (x==4) return 
				if (y==1) return x;
			}) : 0
		) : 1
	);

// {
// 	if (y)
// 		if (x) {
// 			if (x == 1) return 1;
// 			if (x == 2) return 2 << (y-1);
// 			if (y == 1) return x;
// 			if (y == 2) return x * x;
// 			if (y == 3) return x * x * x;

// 			/* Exponentiation by squaring */
// 			F64 r = 1;

// 			while (y > 1) {
// 				if (y&1) r *= x;
// 				x *= x;
// 				y >>= 1;
// 			}

// 			return r * x;
// 		}
// 		else return 0;
// 	else return 1;
// }
}