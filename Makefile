cc = /bin/gcc
flags = -Wall -Wextra -Iinc -c $(F) -o /dev/null
clang = /bin/clang $(flags)
gcc = /bin/gcc $(flags)

dirobj:
	mkdir -p obj/
dirlib:
	mkdir -p lib/

# Compile with Clang (ISO)
cmpci:
	$(clang) -pedantic-errors -Wpedantic -std=c90  
	$(clang) -pedantic-errors -Wpedantic -std=iso9899:199409 
	$(clang) -pedantic-errors -Wpedantic -std=c99 
	$(clang) -pedantic-errors -Wpedantic -std=c11 
	$(clang) -pedantic-errors -Wpedantic -std=c17 
	$(clang) -pedantic-errors -Wpedantic -std=c2x 
# Compile with Clang (GNU)
cmpcg:
	$(clang) -std=gnu90 
	$(clang) -std=gnu99 
	$(clang) -std=gnu11 
	$(clang) -std=gnu17 
	$(clang) -std=gnu2x
# Compile with Clang (All)
cmpc: cmpci cmpcg
# Compile with GCC (ISO)
cmpgi:
	$(gcc) -pedantic-errors -Wpedantic -std=c90 
	$(gcc) -pedantic-errors -Wpedantic -std=iso9899:199409 
	$(gcc) -pedantic-errors -Wpedantic -std=c99 
	$(gcc) -pedantic-errors -Wpedantic -std=c11 
	$(gcc) -pedantic-errors -Wpedantic -std=c17 
	$(gcc) -pedantic-errors -Wpedantic -std=c2x 
# Compile with GCC (GNU)
cmpgg:
	$(gcc) -std=gnu90 
	$(gcc) -std=gnu99 
	$(gcc) -std=gnu11 
	$(gcc) -std=gnu17 
	$(gcc) -std=gnu2x
# Compile with GCC (All)
cmpg: cmpgi cmpgg
# Compile with all compilers
compile comp cmp: cmpc cmpg
# Compile with all compiler (for headers)
compile_header cmph: cmpgg cmpcg
# Compilation time statistics
cmpt:
	$(gcc) -pedantic-errors -Wpedantic -ftime-report
# Compilation time statistics (for headers)
cmpth:
	$(gcc) -ftime-report

carray carr cwca:
	for file in src/array/*; do make compile F=$$file; done
oarray oarr owca: dirobj
	for file in src/array/*; do $(cc) $(flags) -O2 -c $$file -o obj/array/`basename $$file | sed 's/\.c/\.o/'`; done
oarrayd oarrd owcad: dirobj
	for file in src/array/*; do $(cc) $(flags) -O0 -c $$file -o obj/array/`basename $$file | sed 's/\.c/\.o/'` -g; done
arrayd arrd wcad array_debug arr_debug wca_debug: owcad dirlib
	ar -rc lib/libwca.a obj/array/*
array arr wca: owca dirlib
	ar -rc lib/libwca.a obj/array/*
clean clear:
	find . -name "*.o" -type f -delete
	find . -name "*.s" -type f -delete

array wca:
