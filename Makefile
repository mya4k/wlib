# This is where building happens
wlib = /home/wispy/prj/wlib
inc = $(wlib)/inc
gcc = gcc
lsobj = $(shell find $(wlib)/obj/* -name '*.o' | tr '\n' ' ')
crobj = $(shell $(wlib)/lib.sh $(gcc) $(wlib)/src $(wlib)/obj $(inc))
libdirx = lib
libdir = /usr/lib/

compile:
	mkdir -p test
#	gcc -c $(C) -Iinc -Wall -Wextra -Werror -Wfatal-errors -std=c90
	gcc -c $(C) -Iinc -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=iso9899:199409
	gcc -c $(C) -Iinc -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=c99
	gcc -c $(C) -Iinc -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=c11
	gcc -c $(C) -Iinc -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=c18
	gcc -c $(C) -Iinc -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=c2x
	gcc -c $(C) -Iinc -Wall -Wextra -Werror -Wfatal-errors -std=gnu90
	gcc -c $(C) -Iinc -Wall -Wextra -Werror -Wfatal-errors -std=gnu99
	gcc -c $(C) -Iinc -Wall -Wextra -Werror -Wfatal-errors -std=gnu11
	gcc -c $(C) -Iinc -Wall -Wextra -Werror -Wfatal-errors -std=gnu18
	gcc -c $(C) -Iinc -Wall -Wextra -Werror -Wfatal-errors -std=gnu2x
	gcc -E $(C) -Iinc -Wall -Wextra -Werror -Wfatal-errors -std=gnu2x | grep -v "#" > test/`basename $(C)`
debug:
	$(call crobj)
	ar -rc $(libdirx)/libwc.a $(call lsobj)
inst:
	sudo mv $(libdirx)/libwc.a $(libdir)



src = src/wc
obj = obj
gcc = gcc -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=gnu2x -Iinc -Ofast
mkdir:
	mkdir -p $(obj)
array: mkdir
	$(gcc) -c $(src)/array.c -o $(obj)/array.o 
string: mkdir
	$(gcc) -c $(src)/string.c -o $(obj)/string.o
memory: mkdir
	$(gcc) -c $(src)/memory.c -o $(obj)/memory.o