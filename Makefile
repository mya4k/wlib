gcc = 		/usr/bin/gcc 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -g -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o
g++ = 		/usr/bin/g++ 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -g -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o
clang = 	/usr/bin/clang 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -g -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o
clang++ = 	/usr/bin/clang++	-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -g -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o


.PHONY: _test test test_header compile clean asm obj

obj:
	mkdir -p obj
	$(gcc) -Wpedantic -O2 -o obj/array.o -c src/array.c $(F)
	$(gcc) -Wpedantic -O2 -o obj/string.o -c src/string.c $(F)
asm:
	mkdir -p asm
	$(gcc) -Wpedantic -O2 -S -o asm/array.s -c src/array.c $(F)
	$(gcc) -Wpedantic -O2 -S -o asm/string.s -c src/string.c $(F)
objdump:
	mkdir -p obj
	objdump -d $(C) > obj/$(shell basename $(C)).dmp
_test:
	$(gcc) -Wpedantic -std=c90 $(F)
	$(gcc) -Wpedantic -std=iso9899:199409 $(F)
	$(gcc) -Wpedantic -std=c99 $(F)
	$(gcc) -Wpedantic -std=c11 $(F)
	$(gcc) -Wpedantic -std=c17 $(F)
	$(gcc) -Wpedantic -std=c2x $(F)
	$(gcc) -std=gnu90 $(F)
	$(gcc) -std=gnu99 $(F)
	$(gcc) -std=gnu11 $(F)
	$(gcc) -std=gnu17 $(F)
	$(gcc) -std=gnu2x $(F)
	$(g++) -Wpedantic -std=c++98 $(F) 
	$(g++) -Wpedantic -std=c++11 $(F)
	$(g++) -Wpedantic -std=c++14 $(F)
	$(g++) -Wpedantic -std=c++17 $(F)
	$(g++) -Wpedantic -std=c++20 $(F)
	$(g++) -Wpedantic -std=c++23 $(F)
	$(g++) -std=gnu++98 $(F)
	$(g++) -std=gnu++11 $(F)
	$(g++) -std=gnu++14 $(F)
	$(g++) -std=gnu++17 $(F)
	$(g++) -std=gnu++20 $(F)
	$(g++) -std=gnu++23 $(F)
test:
	$(clang) -pedantic-errors -Wpedantic -std=c90 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=iso9899:199409 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c99 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c11 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c17 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c2x $(F)
	$(clang) -std=gnu90 $(F)
	$(clang) -std=gnu99 $(F)
	$(clang) -std=gnu11 $(F)
	$(clang) -std=gnu17 $(F)
	$(clang) -std=gnu2x $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c90 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=iso9899:199409 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c99 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c11 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c17 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c2x $(F)
	$(gcc) -std=gnu90 $(F)
	$(gcc) -std=gnu99 $(F)
	$(gcc) -std=gnu11 $(F)
	$(gcc) -std=gnu17 $(F)
	$(gcc) -std=gnu2x $(F)
# /usr/bin/pcc -Iinc
test_header:
	$(clang) -std=c90 $(F)
	$(clang) -std=iso9899:199409 $(F)
	$(clang) -std=c99 $(F)
	$(clang) -std=c11 $(F)
	$(clang) -std=c17 $(F)
	$(clang) -std=c2x $(F)
	$(clang) -std=gnu90 $(F)
	$(clang) -std=gnu99 $(F)
	$(clang) -std=gnu11 $(F)
	$(clang) -std=gnu17 $(F)
	$(clang) -std=gnu2x $(F)
	$(gcc) -std=c90 $(F)
	$(gcc) -std=iso9899:199409 $(F)
	$(gcc) -std=c99 $(F)
	$(gcc) -std=c11 $(F)
	$(gcc) -std=c17 $(F)
	$(gcc) -std=c2x $(F)
	$(gcc) -std=gnu90 $(F)
	$(gcc) -std=gnu99 $(F)
	$(gcc) -std=gnu11 $(F)
	$(gcc) -std=gnu17 $(F)
	$(gcc) -std=gnu2x $(F)
compile:
	for F in `find -name "*.h"`; do make test_header C=$$F; done
	for F in `find -name "*.c"`; do make test C=$$F; done
clean:
	rm -f $(shell find -name "*.gch")
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.s")
	rm -f $(shell find -name "*.a")



carray:
	mkdir -p obj/array
	for F in `find src/array/ -name "*.c"`; do make test C=$$F; done
array: carray
	mkdir -p lib
	ar -rc lib/libwca.a obj/array/*
