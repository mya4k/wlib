#include <stdio.h>
#include <wl/array.h>
#include <stdlib.h>
#include "src/array/amg.c"
	

int main() {
	char a[] = "Hello World!";
	char* b = malloc(sizeof(a)); 
	ano(a, sizeof(a), b);
	char* c = malloc(7*sizeof(a));

	amg((char*[7]){ a, a, a, a, a, a, "" }, (U32[7]){ sizeof(a)-1, sizeof(a)-1, sizeof(a)-1, sizeof(a)-1, sizeof(a)-1, sizeof(a)-1, 1 }, 7, c);

	printf("%s\n", c);
	return 0;
}
