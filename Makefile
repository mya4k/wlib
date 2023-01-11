cc = /bin/gcc 
flags = -Wall -Wextra -Iinc -c $(F) -Werror
clang = /bin/clang $(flags)
gcc = /bin/gcc $(flags) # -fanalyzer -Wanalyzer-too-complex

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

# Compile with Clang (ISO)
cmpci:
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c90
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=iso9899:199409 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c99 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c11 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c17 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c2x 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c90
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=iso9899:199409 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c99 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c11 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c17 
	$(clang) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c2x 
# Compile with Clang (GNU)
cmpcg:
	$(clang) -std=gnu90 -DWL_FIXED=0
	$(clang) -std=gnu99 -DWL_FIXED=0
	$(clang) -std=gnu11 -DWL_FIXED=0
	$(clang) -std=gnu17 -DWL_FIXED=0
	$(clang) -std=gnu2x -DWL_FIXED=0
	$(clang) -std=gnu90 -DWL_FIXED=1
	$(clang) -std=gnu99 -DWL_FIXED=1
	$(clang) -std=gnu11 -DWL_FIXED=1
	$(clang) -std=gnu17 -DWL_FIXED=1
	$(clang) -std=gnu2x -DWL_FIXED=1
# Compile with Clang (All)
cmpc: cmpci cmpcg
# Compile with GCC (ISO)
cmpgi:
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c90 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=iso9899:199409 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c99 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c11 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c17 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=0 -std=c2x 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c90 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=iso9899:199409 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c99 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c11 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c17 
	$(gcc) -pedantic-errors -Wpedantic -DWL_FIXED=1 -std=c2x 
# Compile with GCC (GNU)
cmpgg:
	$(gcc) -std=gnu90 -DWL_FIXED=0
	$(gcc) -std=gnu99 -DWL_FIXED=0
	$(gcc) -std=gnu11 -DWL_FIXED=0
	$(gcc) -std=gnu17 -DWL_FIXED=0
	$(gcc) -std=gnu2x -DWL_FIXED=0
	$(gcc) -std=gnu90 -DWL_FIXED=1
	$(gcc) -std=gnu99 -DWL_FIXED=1
	$(gcc) -std=gnu11 -DWL_FIXED=1
	$(gcc) -std=gnu17 -DWL_FIXED=1
	$(gcc) -std=gnu2x -DWL_FIXED=1
cmp65:
	cc65 -Iinc -D__STDC__ -o /dev/null $(F)
cmpt:
	tcc -Iinc -o /dev/null -c $(F) -Wall -Werror -Wunsupported -Wwrite-strings
# Compile with GCC (All)
cmpg: cmpgi cmpgg
# Compile with all compilers
compile comp cmp: cmpc cmpg cmp65 cmpt
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


carray carr:
	make cmp F="src/array/axx.c"
	make cmp F="src/array/axxl.c"
oarray oarr: dirobj
	$(cc) -Iinc -O2 -c src/array/axx.c -o obj/axx.o
# $(cc) -O2 -c src/array/axxl.c -o obj/axxl.o
wlib lib: oarray dirlib
	ar -rc lib/libwca.a obj/axx.o obj/axxl.o

	

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
