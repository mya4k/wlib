cc = /bin/gcc
flags = -Wall -Wextra -Wpedantic -Iinc
clang = /bin/clang $(flags) -c $(F) -o /dev/null
gcc = /bin/gcc $(flags) -c $(F) -o /dev/null

dirobj:
	mkdir -p obj/
dirlib:
	mkdir -p lib/
compile comp cmp:
	$(clang) -pedantic-errors -Wpedantic -std=c90  
	$(clang) -pedantic-errors -Wpedantic -std=iso9899:199409 
	$(clang) -pedantic-errors -Wpedantic -std=c99 
	$(clang) -pedantic-errors -Wpedantic -std=c11 
	$(clang) -pedantic-errors -Wpedantic -std=c17 
	$(clang) -pedantic-errors -Wpedantic -std=c2x 
	$(clang) -std=gnu90 
	$(clang) -std=gnu99 
	$(clang) -std=gnu11 
	$(clang) -std=gnu17 
	$(clang) -std=gnu2x 
	$(gcc) -pedantic-errors -Wpedantic -std=c90 
	$(gcc) -pedantic-errors -Wpedantic -std=iso9899:199409 
	$(gcc) -pedantic-errors -Wpedantic -std=c99 
	$(gcc) -pedantic-errors -Wpedantic -std=c11 
	$(gcc) -pedantic-errors -Wpedantic -std=c17 
	$(gcc) -pedantic-errors -Wpedantic -std=c2x 
	$(gcc) -std=gnu90 
	$(gcc) -std=gnu99 
	$(gcc) -std=gnu11 
	$(gcc) -std=gnu17 
	$(gcc) -std=gnu2x 
carray carr cwca:
	for file in src/array/*; do make compile F=$$file; done
oarray oarr owca: dirobj
	for file in src/array/*; do $(cc) $(flags) -O2 -c $$file -o obj/array/`basename $$file | sed 's/\.c/\.o/'`; done
array arr wca: owca dirlib
	ar -rc lib/libwca.a obj/array/*
clean clear:
	find . -name "*.o" -type f -delete
	find . -name "*.s" -type f -delete

array wca:
