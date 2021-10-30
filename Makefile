gcc = /usr/bin/clang -Iinc -Wall -Wextra -Werror -Wfatal-errors
g++ = /usr/bin/clang++ -Iinc -Wall -Wextra -Werror -Wfatal-errors

_test:
	$(gcc) -c $(C) -Wpedantic -std=c90 $(F)
	$(gcc) -c $(C) -Wpedantic -std=iso9899:199409 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c99 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c11 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c17 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c2x $(F)
	$(gcc) -c $(C) -std=gnu90 $(F)
	$(gcc) -c $(C) -std=gnu99 $(F)
	$(gcc) -c $(C) -std=gnu11 $(F)
	$(gcc) -c $(C) -std=gnu17 $(F)
	$(gcc) -c $(C) -std=gnu2x $(F)
	$(g++) -c $(C) -Wpedantic -std=c++98 $(F) 
	$(g++) -c $(C) -Wpedantic -std=c++11 $(F)
	$(g++) -c $(C) -Wpedantic -std=c++14 $(F)
	$(g++) -c $(C) -Wpedantic -std=c++17 $(F)
	$(g++) -c $(C) -Wpedantic -std=c++20 $(F)
	$(g++) -c $(C) -Wpedantic -std=c++23 $(F)
	$(g++) -c $(C) -std=gnu++98 $(F)
	$(g++) -c $(C) -std=gnu++11 $(F)
	$(g++) -c $(C) -std=gnu++14 $(F)
	$(g++) -c $(C) -std=gnu++17 $(F)
	$(g++) -c $(C) -std=gnu++20 $(F)
	$(g++) -c $(C) -std=gnu++23 $(F)
test:
	$(gcc) -c $(C) -Wpedantic -std=c90 $(F)
	$(gcc) -c $(C) -Wpedantic -std=iso9899:199409 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c99 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c11 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c17 $(F)
	$(gcc) -c $(C) -Wpedantic -std=c2x $(F)
	$(gcc) -c $(C) -std=gnu90 $(F)
	$(gcc) -c $(C) -std=gnu99 $(F)
	$(gcc) -c $(C) -std=gnu11 $(F)
	$(gcc) -c $(C) -std=gnu17 $(F)
	$(gcc) -c $(C) -std=gnu2x $(F)
compile:
	make test C="inc/wc/sys/lang.h"
	make test C="inc/wc/sys/arch.h"
	make test C="inc/wc/sys/osys.h"
	make test C="inc/wc/sys/comp.h"
	make test C="inc/wc/sys/damo.h"
	make test C="inc/wc/core.h"
	make test C="inc/wc/types.h"
	make test C="inc/wc/char.h"
	make test C="inc/wc/string.h"

	make test C="src/string.c"
