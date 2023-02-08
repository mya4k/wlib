cc = /bin/cc
86gcc = /bin/i686-elf-gcc -nostdlib -ffreestanding
flags = -Wall -Wextra -Iinc -c $(F) -Werror -DWL_PREFIX=0
clang = /bin/clang $(flags)
gcc = /bin/gcc $(flags) # -fanalyzer -Wanalyzer-too-complex
ccx = $(cc) $(flags)

dirobj:
	mkdir -p obj/
dirlib:
	mkdir -p lib/

# Macro dump
macro:
	$(cc) -E $(F) -dM -Iinc -std=c90 -Wall -Wextra -pedantic-errors -Wpedantic
# Check for undefined macros
undef:
	$(cc) -c $(F) -Iinc -Wall -Wextra -pedantic-errors -Wpedantic -Wundef

# Compile (ISO)
cmp_i:
	$(ccx) -pedantic-errors -Wpedantic -std=c90 
	$(ccx) -pedantic-errors -Wpedantic -std=iso9899:199409 
	$(ccx) -pedantic-errors -Wpedantic -std=c99 
	$(ccx) -pedantic-errors -Wpedantic -std=c11 
	$(ccx) -pedantic-errors -Wpedantic -std=c17 
	$(ccx) -pedantic-errors -Wpedantic -std=c2x 
# Compile (GNU)
cmp_g:
	$(ccx) -std=gnu90
	$(ccx) -std=gnu99
	$(ccx) -std=gnu11
	$(ccx) -std=gnu17
	$(ccx) -std=gnu2x
# Compile with Clang (ISO)
cmpci:
	make cmp_i cc="/bin/clang"
# Compile with GCC (ISO)
cmpgi:
	make cmp_i cc="/bin/gcc"
# Compile with i686-efi-gcc (ISO)
cmp86i:
	make cmp_i cc="/bin/i686-elf-gcc -DWL_LIBC=0"
# Compile with Clang (GNU)
cmpcg:
	make cmp_g cc="/bin/clang"
# Compile with GCC (GNU)
cmpgg:
	make cmp_g cc="/bin/gcc"
# Compile with i686-efi-gcc (GNU)
cmp86g:
	make cmp_g cc="/bin/i686-elf-gcc -DWL_LIBC=0"
# Compile with GCC (All)
cmpg: cmpgg cmpgi
# Compile with GCC (All)
cmpc: cmpgg cmpgi
# Compile with GCC (All)
cmp86: cmp86g cmp86i 
# Compile with CC65
cmp65:
	cc65 -v -Iinc -D__STDC__ -o /dev/null $(F)
cmpt:
	tcc -Iinc -o /dev/null -c $(F) -Wall -Werror -Wunsupported -Wwrite-strings
# Compile with all compilers
compile comp cmp: cmpci cmpgi cmpci cmp86i cmpcg cmpgg cmpcg cmp86g # cmp65 cmpt
# Compile with all compiler (for headers)
compile_header cmph: cmpgg cmpcg cmpgi cmpci cmp65 cmpt
# Compilation time statistics
cmptm:
	$(gcc) -std=gnu2x -pedantic-errors -Wpedantic -ftime-report
# Compilation time statistics (for headers)
cmpth:
	$(gcc) -std=gnu2x -ftime-report
# Generate assembly
BASE = `basename $(F) | sed 's/\.c//'`
asm:
#	$(cc) -fverbose-asm -Iinc -S $(F) -Ofast -o asm/`basename $(F) | sed 's/\.c/\.s/'` -masm=intel
	$(cc) -std=c2x -Iinc -S $(F) -o asm/$(BASE).s -Ofast -g -fverbose-asm -masm=intel
#	objdump -d -Mintel obj/$(BASE).o -l > asm/$(BASE).s

.PHONY: asm
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
	make oa cc="$(86gcc)" F="-DWL_LIBC=0"


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
