#####################################################################################
# This is a file used for automatically creating objects files from source files.	#
#####################################################################################

# if it ain't broken don't fix it
## it's broken, how we fix it?
### fixed

# Version 1
#[ ! -d "obj/wc/$1" ] && mkdir -p obj/wc/$1
#[ ! -d "lib/wc/`echo $1 | cut -d / -f 1`" ] && mkdir -p lib/wc/`echo $1 | cut -d / -f 1`
#ls src/wc/$1/*.c | while read F; do gcc -Wall -Wextra -Wno-overflow -Wno-char-subscripts -Werror -fmax-errors=1 -I inc -o obj/`echo $F | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o -c $F; done
#ar -rc lib/wc/$1.l obj/wc/$1/*.o
#ar -t lib/wc/$1.l

# Version 2
#E=`find src/wc/$1/* -type d | tr '\n' ' '`
#mkdir -p obj/wc/$1 `echo $E | sed 's/src/obj/g'`
#find src/wc/$1/* -name *.c | while read F; do gcc -c $F -o obj/`echo $F | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o -Iinc -Wall -Wextra -Werror; done

# Version 3.0
#if [[ $2 == "NULL" ]]
#then $2 = inc
#fi
#
#if [[ $1 == "NULL" ]]
#then	
#	E=`find src/* -type d | tr '\n' ' '`
#	mkdir -p obj `echo $E | sed 's/src/obj/g'`
#	find src/* -name *.c | while read F; do gcc -c $F -o obj/`echo $F | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o -I$2 -Wall -Wextra -Werror; done
#else
#	E=`find src/$1/* -type d | tr '\n' ' '`
#	mkdir -p obj/$1 `echo $E | sed 's/src/obj/g'`
#	find src/$1/* -name *.c | while read F; do gcc -c $F -o obj/`echo $F | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o -I$2 -Wall -Wextra -Werror; done
#
#fi

# Version 3.1
#E=`find $2/* -type d | tr '\n' ' '`
#mkdir -p $3 `echo $E | sed "s:$2:$3:g"`
#find $2/* -name *.c | while read F; do $1 -c $F -o $3`echo $F | sed "s:$2::g" | cut -d . -f 1 -`.o -I$4 -Wall -Wextra -Werror; done

# Version 3.2
E=`find $2/* -type d | tr '\n' ' '`
mkdir -p $3 `echo $E | sed "s:$2:$3:g"`
find $2/* -name '*.c' | while read F; do $1 -c $F -o $3`echo $F | sed "s:$2::g" | cut -d . -f 1 -`.o ; done