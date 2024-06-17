/* gcc src/prot/bruijn.c -Iinc -Wall -Wextra */
#include <wl/types.h>
#include <stdio.h>
#include <time.h>
#include <wl/bit.h>
#include <wl/core.h>


#define bc(x,y) ((x) & b0(y))
#define bs(x,y)	((x) | b1(y))


U64 debruijn(const U8 k) {
	if (unlikely(k>6)) return U64X;
	
	/* const U8f n = (1<<k); */
	const U8f n1 = (1<<k)-1; /* Length of the sequence divided by 1*/
	/* Usually Bruijn sequence starts with a bitstring of with all zeros 
	proceeded by one and ends with a zero proceeded with a bitstring with all
	ones.
	
		4 = 2^2: (0{01)1}
		8 = 2^3: [0001][0111]
		16 = 2^4: [00001]011010[01111]
	*/
	U64 result = n1 | (U64)1 << (n1-k);
	printf("result: %0llb\n", result);

	if (likely(k>3)) {
		/* Generate a bit table that keeps track of which bitstrings have been
		sequenced. The index of a bit is the bitstring and the value of the
		bit is whether it has been sequenced */
		U64 table = 0;
		const U64 completeTable = (U64)U64X>>(U64B-(n1+1));
		/* Tick off the obvious bitstrings at the beginning and the end */	
		table = 
		bs(table,0) | bs(table,1) | bs(table,n1) | bs(table,(n1>>1));
		printf("table: %0llb\n", table);
		/* Tick off the bitstrings looping from the end to beginning */
		U8f looping = (n1<<1) & (n1);
		while (looping != 0) {
			table = bs(table, looping);
			printf("table: %0llb\n", table);
			looping = (looping<<1) & n1;
		}
		/*  */
		const U8f index0 = n1-k;
		U8f index = index0;
		U8f front = brs(result, index, 4);	/* 0..01..... */
		printf("\tfront: %0hhb\n", front);
		while (table != completeTable) {
			/* U8f end = brs(result, 1, 4); */	/* .....01..1 */
			/* Try next bitstring by appending 0 */
			index--;
			printf("index: %hhi\n", index);
			front = (front<<1) & (n1);
			printf("\tfront: %0hhb\n", front);
			/* If it's already in the table, try appending 1 */
			if (br(table, front)) {
redo:			front |= 1;
				printf("\t\tfront: %0hhb\n", front);
				/* If that's also in the table, backtrack a bit */
				if (br(table, front)) {
					/* Get previous `front` */
					index++;
					printf("index: %hhi\n", index);
					if (index>index0) return U64X;
					front = brs(result,index,4);
					printf("front: %0hhb\n", front);
					table = bc(table, front);
					printf("table: %0llb\n", table);
					goto redo;
				}
			}
			
			table = bs(table, front);
			printf("\ttable: %0llb\n", table);
			printf("\tcomplete: %0llb\n", completeTable);

			result = bc(result, index) | ((UMax)br(front, 0) << index);
			printf("\tresult: %0llb\n", result);
		}
		printf("%0llb\n", table);
	}

	return result;
}



int main() {
	U8f n = 3;
	clock_t t0 = clock();
	U64 b = debruijn(n);
	printf("%f\n", (double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	printf("%0llx\n", b);
	/* for (I8f i = (1<<n)-1; i > 0; i--) {
		printf("%02lld ", brs(b, i, n));
	} */

	const U8f _1sln = 1<<n;

	U8f table[_1sln];

	for (U8f i = 0; i < _1sln; i++) {
		table[(b >> (_1sln-n)) & (1<<n)-1] = i;
		b <<= 1;
	}

	for (U8f i = 0; i < _1sln; i++) {
		printf("%lld, ", table[i]);
	}
	return 0;
}
