/**
 * \file make.c
 * \author Wispy (wspvlv@gmail.com)
 * \brief Make program specifically for WLib, because GNU Make makes me go insane
 * \version 0.1
 * \date 2024-01-06
 * 
 * 
 */
#include <wl/core.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "src/math/sm.c"
#include "src/array/amg.c"
#include "src/string/sl.c"



char cc[] = "/bin/cc ";
char cflags[] = "-Og -g -c ";
char flags[] = "-Iinc ";
char warns[] = "-WNSObject-attribute -Wabi=2 -Wabsolute-value -Waddress -Waddress-of-packed-member -Waggregate-return -Waggressive-loop-optimizations -Walloc-zero -Walloca -Wanalyzer-allocation-size -Wanalyzer-deref-before-check -Wanalyzer-double-fclose -Wanalyzer-double-free -Wanalyzer-exposure-through-output-file -Wanalyzer-exposure-through-uninit-copy -Wanalyzer-fd-access-mode-mismatch -Wanalyzer-fd-double-close -Wanalyzer-fd-leak -Wanalyzer-fd-phase-mismatch -Wanalyzer-fd-type-mismatch -Wanalyzer-fd-use-after-close -Wanalyzer-fd-use-without-check -Wanalyzer-file-leak -Wanalyzer-free-of-non-heap -Wanalyzer-imprecise-fp-arithmetic -Wanalyzer-infinite-recursion -Wanalyzer-jump-through-null -Wanalyzer-malloc-leak -Wanalyzer-mismatching-deallocation -Wanalyzer-null-argument -Wanalyzer-null-dereference -Wanalyzer-out-of-bounds -Wanalyzer-possible-null-argument -Wanalyzer-possible-null-dereference -Wanalyzer-putenv-of-auto-var -Wanalyzer-shift-count-negative -Wanalyzer-shift-count-overflow -Wanalyzer-stale-setjmp-buffer -Wanalyzer-tainted-allocation-size -Wanalyzer-tainted-array-index -Wanalyzer-tainted-assertion -Wanalyzer-tainted-divisor -Wanalyzer-tainted-offset -Wanalyzer-tainted-size -Wanalyzer-too-complex -Wanalyzer-unsafe-call-within-signal-handler -Wanalyzer-use-after-free -Wanalyzer-use-of-pointer-in-stale-stack-frame -Wanalyzer-use-of-uninitialized-value -Wanalyzer-va-arg-type-mismatch -Wanalyzer-va-list-exhausted -Wanalyzer-va-list-leak -Wanalyzer-va-list-use-after-va-end -Wanalyzer-write-to-const -Wanalyzer-write-to-string-literal -Warith-conversion -Warray-compare -Wattribute-warning -Wattributes -Wbad-function-cast -Wbool-compare -Wbool-operation -Wbuiltin-declaration-mismatch -Wbuiltin-macro-redefined -Wc++-compat -Wcannot-profile -Wcast-align -Wcast-align=strict -Wcast-function-type -Wcast-qual -Wchar-subscripts -Wclobbered -Wcomment -Wcomplain-wrong-lang -Wconversion -Wcoverage-invalid-line-number -Wcoverage-mismatch -Wcpp -Wdangling-else -Wdate-time -Wdeprecated -Wdeprecated-declarations -Wdesignated-init -Wdisabled-optimization -Wdiscarded-array-qualifiers -Wdiscarded-qualifiers -Wdiv-by-zero -Wdouble-promotion -Wduplicate-decl-specifier -Wduplicated-branches -Wduplicated-cond -Wempty-body -Wendif-labels -Wenum-conversion -Wenum-int-mismatch -Wexpansion-to-defined -Wextra -Wfloat-conversion -Wfloat-equal -Wformat-contains-nul -Wformat-diag -Wformat-extra-args -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat-y2k -Wformat-zero-length -Wframe-address -Wfree-nonheap-object -Whsa -Wif-not-aligned -Wignored-attributes -Wignored-qualifiers -Wimplicit -Wincompatible-pointer-types -Winfinite-recursion -Winit-self -Winline -Wint-conversion -Wint-in-bool-context -Wint-to-pointer-cast -Winvalid-memory-model -Winvalid-pch -Winvalid-utf8 -Wjump-misses-init -Wlogical-not-parentheses -Wlogical-op -Wlto-type-mismatch -Wmaybe-uninitialized -Wmemset-elt-size -Wmemset-transposed-args -Wmisleading-indentation -Wmismatched-dealloc -Wmissing-attributes -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-include-dirs -Wmissing-parameter-type -Wmissing-profile -Wmissing-prototypes -Wmultichar -Wmultistatement-macros -Wnested-externs -Wnonnull -Wnonnull-compare -Wnull-dereference -Wodr -Wold-style-declaration -Wopenacc-parallelism -Wopenmp-simd -Woverflow -Woverlength-strings -Woverride-init -Woverride-init-side-effects -Wpacked -Wpacked-not-aligned -Wpadded -Wparentheses -Wpedantic -Wpointer-arith -Wpointer-compare -Wpointer-sign -Wpointer-to-int-cast -Wpragmas -Wprio-ctor-dtor -Wpsabi -Wredundant-decls -Wrestrict -Wreturn-local-addr -Wscalar-storage-order -Wsequence-point -Wshadow -Wshadow=compatible-local -Wshadow=local -Wshift-count-negative -Wshift-count-overflow -Wsign-compare -Wsign-conversion -Wsizeof-array-argument -Wsizeof-array-div -Wsizeof-pointer-div -Wsizeof-pointer-memaccess -Wstack-protector -Wstrict-flex-arrays -Wstrict-prototypes -Wstring-compare -Wstringop-overread -Wstringop-truncation -Wsuggest-attribute=cold -Wsuggest-attribute=const -Wsuggest-attribute=format -Wsuggest-attribute=malloc -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wsuggest-final-methods -Wsuggest-final-types -Wswitch -Wswitch-bool -Wswitch-default -Wswitch-enum -Wswitch-outside-range -Wswitch-unreachable -Wsync-nand -Wsystem-headers -Wtautological-compare -Wtraditional -Wtraditional-conversion -Wtrampolines -Wtrigraphs -Wtrivial-auto-var-init -Wtsan -Wtype-limits -Wundef -Wunicode -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunsafe-loop-optimizations -Wunsuffixed-float-constants -Wunused -Wunused-but-set-parameter -Wunused-but-set-variable -Wunused-function -Wunused-label -Wunused-local-typedefs -Wunused-macros -Wunused-result -Wunused-value -Wunused-variable -Wuse-after-free -Wvarargs -Wvariadic-macros -Wvector-operation-performance -Wvla-parameter -Wvolatile-register-var -Wwrite-strings -Wxor-used-as-pow -Wzero-length-bounds -Wformat ";



/**
 * \brief	WLib Make Program
 * 
 * Flags:
 * - `c` &mdash; Compile file without saving the output
 * - `o` &mdash; Compile file saving the output
 * - `l` &mdash; 
 */
int main(int argc, char* argv[]) {
	if_likely(argc > 0) {
		switch (argv[1][0]) {
			case 'c':
				char* file = &argv[1][1];
				const U32	fileSize = wl_sl(file),
							ccSize = wl_sl(cc),
							cflagsSize = wl_sl(cflags),
							flagsSize = wl_sl(flags),
							warnsSize = wl_sl(warns);
				
				const char* args = amg(
					vaa(char*, cc, flags, warns, cflags, file), 
					vaa(U32, ccSize, flagsSize, warnsSize, cflagsSize, fileSize+1), 
				5, NULL);
				puts(args);
				execlp("sh", "sh", "-c", args, NULL);
			default:
		}
	}

	return 0; 
}


#ifdef gay

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
					execlp("sh", "sh", "-c", eargs, NULL);
					printf("%s\n", eargs);
					free(eargs);
				default:
			}
		break;
		default:
	}
}

#endif
