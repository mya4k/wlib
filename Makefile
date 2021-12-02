gcc = 		/usr/bin/gcc 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h
g++ = 		/usr/bin/g++ 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h
clang = 	/usr/bin/clang 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h
clang++ = 	/usr/bin/clang++	-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h

.PHONY: _test test test_header compile clean asm obj

objdump:
	mkdir -p obj
	objdump -d $(C) > obj/$(shell basename $(C)).dmp
test:
	mkdir -p obj
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
	mkdir -p obj/array
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
	mkdir -p obj
	$(gcc) -pedantic-errors -Wpedantic $(F) -O2
asm:
	$(gcc) -pedantic-errors -Wpedantic -O2 -S $(F)
clean:
	rm -f $(shell find -name "*.gch")
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.s")
	rm -f $(shell find -name "*.a")


carray:
	make compile F="src/array/_anol.c"
	make compile F="src/array/afa.c"
	make compile F="src/array/afl.c"
	make compile F="src/array/asa.c"
	make compile F="src/array/asb.c"
array: carray
	mkdir -p lib
	ar -rc lib/libwca.a obj/array/*
