lsobj = $(shell find obj/wc/$(1)/* -name *.o | tr '\n' ' ')
crobj = $(shell mkdir -p obj/wc/$(1); find src/wc/$(1)/* -name *.c | while read F; do gcc -v -Wall -Wextra -Wno-overflow -Wno-char-subscripts -Werror -fmax-errors=1 -Iinc -o obj/$(shell echo $(F) | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -c $(F); done)
libdirx = lib/unix

inp_test:
	echo obj/`echo "src/wc/math/mathi/pwl.c" | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o
core: # core = io + mathi
	mkdir -p $(libdirx)
	$(call crobj,io)
	$(call crobj,math/mathi)
	ar -rc lib/wc.l $(call lsobj,io) $(call lsobj,math/mathi)
	ar -rc $(libdirx)/libwc.a $(call lsobj,io) $(call lsobj,math/mathi) 
types:
	mkdir -p $(libdirx)
	$(call crobj,types)
	ar -rc lib/wct.l $(call lsobj,types)
	ar -rc $(libdirx)/libwct.a $(call lsobj,types)
all: core types