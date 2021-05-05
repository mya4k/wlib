lsobj = $(shell find obj/wc/$(1)/* -name *.o | tr '\n' ' ')
crobj = $(shell bin/lib.sh $(1))
libdirx = /usr/lib

inp_test:
	echo obj/`echo "src/wc/math/mathi/pwl.c" | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o

core: # core = io + mathi
	mkdir -p $(libdirx)
	$(call crobj,io)
	$(call crobj,math/mathi)
	sudo ar -rc $(libdirx)/libwc.a $(call lsobj,io)$(call lsobj,math/mathi)

types:
	mkdir -p $(libdirx)
	$(call crobj,types)
	sudo ar -rc $(libdirx)/libwct.a $(call lsobj,types)

clean:
	rm -r obj
	sudo rm $(libdirx)/libwc.a $(libdirx)/libwct.a