#include <stdio.h>

extern unsigned long long fb_[256];

static unsigned long long fb(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n < 128)	return fb_[n];
	if (n <= 255) {
		return fb(n-1) + fb(n-2);
	}
}

int main() {
	FILE* f = fopen("src/wc/fb.c", "a");

	for (int i = 0; i < 160; i++) {
		unsigned long long n = fb(i);
		fprintf(f, "%llu, ", n);
		printf("%u: %llu\n", i, n);
	}

	fclose(f);

	return 0;
}