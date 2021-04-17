[ ! -d "obj/wc/$1" ] && mkdir -p obj/wc/$1
[ ! -d "lib/wc/`echo $1 | cut -d / -f 1`" ] && mkdir -p lib/wc/`echo $1 | cut -d / -f 1`
ls src/wc/$1/*.c | while read F; do gcc -Wall -Wextra -Wno-overflow -Wno-type-limits -Wno-char-subscripts -I inc -o obj/`echo $F | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o -c $F; done
ar -rc lib/wc/$1.l obj/wc/$1/*.o