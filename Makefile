# This is where building happens
wlib = /home/wispy/prj/wlib
inc = $(wlib)/inc
gcc = gcc
lsobj = $(shell find $(wlib)/obj/* -name *.o | tr '\n' ' ')
crobj = $(shell $(wlib)/lib.sh $(gcc) $(wlib)/src $(wlib)/obj $(inc))
libdirx = lib
libdir = /usr/lib/

debug:
	$(call crobj)
	ar -rc $(libdirx)/libwc.a $(call lsobj)
inst:
	sudo mv $(libdirx)/libwc.a $(libdir)
#wos:
#	mkdir -p
#	$(call crobj,.)
#	ar -rc $(libdirx)/li