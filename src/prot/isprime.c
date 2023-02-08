#include <wl/types.h>

Bl isprime(U64 n) {
	if (unlikely(n == 0)) return FALSE;
	if (unlikely(n == 1 || n == 2 || n == 3 || n == 5)) return TRUE;

	U8 m = n%6;

	if (unlikely(m == n || m == 1 || m == 5)) {
		for (U64 i = 2; i < n; i++)
			if (n % i == 0) return FALSE;
	}
	else return FALSE;

	return TRUE;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	U8 m = atoi(argv[1]);
	U64 n[m];

	for (U8 h = 0; h < m; h++) {
		n[h] = 0;
	}

	for (U64 i = 2; i <= 1000000; i++) {
		if (unlikely(isprime(i))) {
			n[i%m] += 1;
		}
		if (unlikely(i % 100000 == 0)) {
			system("clear");
			printf("%lu\n", i);
			U8 occup;
			U8 occupmax = 0;
			U32 primes = 0;

			for (U8 j = 0; j < m; j++) {
				occup = printf("%hhu: %lu\n", j, n[j]);
				if (occup > occupmax) occupmax = occup;
				primes += n[j];
			}

			system("clear");
			printf("%lu\n", i);

			for (U8 j = 0; j < m; j++) {
				occup = printf("%hhu: %lu", j, n[j]);

				/* if (n[j] == 0 || primes == 0 || 79-occupmax == 0) {
					printf("%hhu %hh", n[j], )
				} */

				U8 block = n[j] / ( primes / (79-occupmax));
				for (U8 k = occup; k < 80; k++) {
					if (k < occupmax+1) printf(" ");
					else if (block > 0) printf(u8"█");
					else printf(" ");
				}
				printf("\n");
			}
		}
	}

	return 0;
}

/* 
double sus(U8 m) {
	U64 n[m];

	for (U8 h = 0; h < m; h++) {
		n[h] = 0;
	}

	for (U64 i = 2; i <= 10000; i++) {
		if (unlikely(isprime(i))) {
			n[i%m] += 1;
		}
	}

	U8 x = 0;
	for (U8 j = 0; j < m; j++) {
		if (n[j] > 1) x++;
	}

	return x;
}

int main() {
	double min = 1;
	U8 mini;
	double xsus;

	for (U16 i = 1; i < 255; i++) {
		xsus = sus(i) / (double)i;
		if (xsus < min) {
			min = xsus;
			mini = i;
		}
	}

	printf("%g, %hhu", min, mini);
	return 0;
}
 */
