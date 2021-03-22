ls src/$1/*.c | while read F; do gcc -Wall -Wextra -Wno-overflow -I inc -o obj/`echo $F | cut -d / -f 1 --complement - | cut -d . -f 1 -`.o -c $F; done
ar -rcs lib/$1.a obj/$1/*.o