INC=$(shell find src/wc/* -name *.c | tr '\n' ' ')
lib:
	echo $(INC)