# This is where building happens

lsobj = $(shell find obj/* -name *.o | tr '\n' ' ')
crobj = $(shell ./lib.sh  )
libdirx = lib

debug:
	$(call crobj)
	ar -rc $(libdirx)/libwc.a $(call lsobj)
#wos:
#	mkdir -p
#	$(call crobj,.)
#	ar -rc $(libdirx)/li