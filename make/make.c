/**
 * \file make.c
 * \author Wispy (wspvlv@gmail.com)
 * \brief Make program specifically for WLib, because GNU Make makes me go insane
 * \version 0.1
 * \date 2024-01-06
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "src/math/sm.c"
#include "src/array/amg.c"

char cargs[] = "-Wall -Wextra -Iinc -Werror -DWL_PREFIX=0 -Wdouble-promotion -Wformat=2 -Wnull-dereference -Wswitch-default -Wswitch-enum -Wunused-parameter -Wuninitialized -Wstrict-overflow=5 -Walloca -Wfloat-equal -Wunused-macros -Wcast-qual -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wno-openmp -Wpacked -Wpadded -Wredundant-decls -Wnested-externs -Winline -Wint-in-bool-context -Winvalid-pch -Winvalid-utf8 -Wvariadic-macros ";

char aargs[] = "-fanalyzer -Wno-analyzer-too-complex -Wno-analyzer-possible-null-argument -fipa-pure-const -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=format -Wsuggest-attribute=cold -Wsuggest-attribute=malloc -fstrict-flex-arrays=3 -Wstrict-flex-arrays -Wabi=2 -Wformat-overflow -Wformat-signedness -Winit-self -Wsync-nand -Wstringop-overflow=4 -Walloc-zero -Warith-conversion -Wattribute-alias=2 -Wbidi-chars=any -Wduplicated-branches -Wduplicated-cond -Wtrampolines -Wunsafe-loop-optimizations -Wbad-function-cast -Wjump-misses-init -Wlogical-op -Wopenacc-parallelism -Wopenmp-simd -Wpacked-not-aligned -Wvector-operation-performance -Wunsuffixed-float-constants -Wno-analyzer-malloc-leak ";

char files[] = "-c make/make.c";

int main(int argc, char* argv[]) {
	switch(argv[1][0]) {
		case 'o':
			switch(argv[1][1]) {
				case 'a':
					char* _eargs[] = { "gcc ", cargs, aargs, files, "" };
					U32 lens[] = { sizeof("gcc ")-1, sizeof(cargs)-1, sizeof(aargs)-1, sizeof(files)-1, 1 };
					/* printf("%i", smu(lens, 4)); */
					char* eargs = malloc(smu(lens, 5) + 1);
					amg(_eargs, lens, 5, eargs);
					execlp("sh", "sh", "-c", eargs);Q
					printf("%s\n", eargs);
					free(eargs);
				default:
			}
		break;
		default:
	}
}
