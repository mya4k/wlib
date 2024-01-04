#############
# Variables #
#############

# Path to the default C compiler
cc = /bin/cc $(flags)
# Path to Clang compiler
clang = /bin/clang $(flags)
# Path to GCC
gcc = /bin/gcc $(flags) $(fa)
# Path to TCC
tcc = /bin/tcc
# Path to CC65
cc65 = /bin/cc65
# Default flags
flags = -Wall -Wextra -Iinc -c $(F) -Werror -DWL_PREFIX=0 -Wdouble-promotion -Wformat=2 -Wnull-dereference -Wswitch-default -Wswitch-enum -Wunused-parameter -Wuninitialized -Wstrict-overflow=5 -Walloca -Wfloat-equal -Wunused-macros -Wcast-qual -Wwrite-strings -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wno-openmp -Wpacked -Wpadded -Wredundant-decls -Wnested-externs -Winline -Wint-in-bool-context -Winvalid-pch -Winvalid-utf8 -Wvariadic-macros 
# Flags for elf-i386 freestanding systems
fs86 = $(cc) -march=i386 -m32 -nostdlib -ffreestanding
# Analyzer flags
fa = -fanalyzer -Wno-analyzer-too-complex -Wno-analyzer-possible-null-argument -fipa-pure-const -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=format -Wsuggest-attribute=cold -Wsuggest-attribute=malloc -fstrict-flex-arrays=3 -Wstrict-flex-arrays -Wabi=2 -Wformat-overflow -Wformat-signedness -Winit-self -Wsync-nand -Wstringop-overflow=4 -Walloc-zero -Warith-conversion -Wattribute-alias=2 -Wbidi-chars=any -Wduplicated-branches -Wduplicated-cond -Wtrampolines -Wunsafe-loop-optimizations -Wbad-function-cast -Wjump-misses-init -Wlogical-op -Wopenacc-parallelism -Wopenmp-simd -Wpacked-not-aligned -Wvector-operation-performance -Wunsuffixed-float-constants -Wno-analyzer-malloc-leak
# Pedantic flags
pedantic = -pedantic-errors -Wpedantic



#############
# Direction	#
#############

# Create object directory
dirobj:
	mkdir -p obj/
# Create library directory
dirlib:
	mkdir -p lib/

################################################################################
# Compilation targets
#
# You need to provide the defintion of $(F), where you must specify the input
# files and may as well append additional compiler options
################################################################################

# Compile (ISO C compliency)
cmp_in:
	$(ccx) $(pedantic) -DWL_LIBC=0 -std=c90 -Wno-attributes
	$(ccx) $(pedantic) -DWL_LIBC=0 -std=iso9899:199409 -Wno-attributes
	$(ccx) $(pedantic) -DWL_LIBC=0 -std=c99  
	$(ccx) $(pedantic) -DWL_LIBC=0 -std=c11 
	$(ccx) $(pedantic) -DWL_LIBC=0 -std=c17 
	$(ccx) $(pedantic) -DWL_LIBC=0 -std=c2x
# Compile (GNU version compliency)
cmp_gn:
	$(ccx) -DWL_LIBC=0 -std=gnu90 -Wno-attributes
	$(ccx) -DWL_LIBC=0 -std=gnu99
	$(ccx) -DWL_LIBC=0 -std=gnu11
	$(ccx) -DWL_LIBC=0 -std=gnu17
	$(ccx) -DWL_LIBC=0 -std=gnu2x
cmp_is:
	$(ccx) $(pedantic) -DWL_LIBC=1 -std=c90 -Wno-attributes
	$(ccx) $(pedantic) -DWL_LIBC=1 -std=iso9899:199409 -Wno-attributes
	$(ccx) $(pedantic) -DWL_LIBC=1 -std=c99 
	$(ccx) $(pedantic) -DWL_LIBC=1 -std=c11 
	$(ccx) $(pedantic) -DWL_LIBC=1 -std=c17 
	$(ccx) $(pedantic) -DWL_LIBC=1 -std=c2x
# Compile (GNU version compliency)
cmp_gs:
	$(ccx) -DWL_LIBC=1 -std=gnu90 -Wno-attributes
	$(ccx) -DWL_LIBC=1 -std=gnu99
	$(ccx) -DWL_LIBC=1 -std=gnu11
	$(ccx) -DWL_LIBC=1 -std=gnu17
	$(ccx) -DWL_LIBC=1 -std=gnu2x
cmp_i:
	make cmp_in
	make cmp_is
cmp_g:
	make cmp_gn
	make cmp_gs
cmpgi:
	make cmp_i ccx="$(gcc)"
cmpgg:
	make cmp_g ccx="$(gcc)"
cmpci:
	make cmp_i ccx="$(clang)"
cmpcg:
	make cmp_g ccx="$(clang)"
cmp86:
	make cmp_g ccx="$(fs86)"
# Compile with CC65
cmp65:
	cc65 -v -t c64 -Iinc -DWL_PREFIX=0 -D__STDC__ -o /dev/null $(F)
# Compile with TCC
cmpt:
	tcc -Iinc -o /dev/null -c $(F) -Wall -Werror -Wunsupported -Wwrite-strings
# Compile with All
cmp: cmpgi cmpgg cmpci cmpcg cmp86 cmp65 cmpt
# Compile for assembly analysis
asm: dirobj
	BASE = `basename $(F) | sed 's/\.c//'`
	$(cc) -std=c2x -Iinc -S $(F) -o asm/$(BASE).s -Ofast -g -fverbose-asm -masm=intel



##########
# Extras #
##########

# Macro dump
macro:
	$(cc) -E $(F) -dM -Iinc -std=c90 -Wall -Wextra -pedantic-errors -Wpedantic

	
.DEFAULT:


ca:
	for FILE in `echo src/array/*.c`; \
	do \
		make cmp F="$$FILE -o /dev/null"; \
	done || exit 1


oa: dirobj
	for FILE in `echo src/array/*.c`; \
	do \
		export _FILE=$$FILE; \
		$(ccx) -Iinc -Ofast -c $$FILE -o obj/array/`basename $$_FILE .c`.o; \
	done || exit 1
oa86g:
	make oa cc="$(86gcc)" F="-DWL_LIBC=0 -fno-pie"


# $(cc) -O2 -c src/array/axxl.c -o obj/axxl.o
.PHONY: lib
wlib lib:
	ar -rc lib/libwa.a obj/array/*.o
wlib86g lib86g:
	make lib cc="$(86gcc)"

	

# carray carr cwca:
# 	for file in src/array/*; do make compile F=$$file; done
# oarray oarr owca: dirobj
# 	for file in src/array/*; do $(cc) $(flags) -O2 -c $$file -o obj/array/`basename $$file | sed 's/\.c/\.o/'`; done
# oarrayd oarrd owcad: dirobj
# 	for file in src/array/*; do $(cc) $(flags) -O0 -c $$file -o obj/array/`basename $$file | sed 's/\.c/\.o/'` -g; done
# arrayd arrd wcad array_debug arr_debug wca_debug: owcad dirlib
# 	ar -rc lib/libwca.a obj/array/*
# array arr wca: owca dirlib
# 	ar -rc lib/libwca.a obj/array/*
clean clear:
	find . -name "*.o" -type f -delete
	find . -name "*.s" -type f -delete

array wca:

testa:
	/bin/cc -Iinc -lwa -Llib -DWL_LIBC=0 
# -o test/array.o
