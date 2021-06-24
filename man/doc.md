# Input/Output
## Output string
**Name:** wl_out

**Memonics:** Output string

**Synopsis:**	
```c
#define wl_out(STR)
```	

**Param:** `STR` — String to output

**Defined in** io.h

**Description**

Writes the string `STR` into [Standard Output stream](https://en.wikipedia.org/wiki/Standard_streams#Standard_output_(stdout)).

## Input string
| Based on the C library					| Based on System call interfaces	|
| -----------------------------------------	| -------------------------------	|
| **Name:** wl_in																|
| **Memonics:** Input string													|
| **Synopsis:**								| **Synopsis:**
| ```c										| ```c
| #define wl_in(STR, MAXSIZE)				| char*	wl_in	(char* str, size_t maxSize);
| ```										| ```
  

**Synopsis:**				|	**Synopsis:**

```c							```c
#define wl_in(STR, MAXSIZE)		char*	wl_in	(char* str, size_t maxSize);
```								```
**Param:**

`str` — Pointer to the input string

`maxSize` — Maximal input length in bytes

**Declared in** io.h

**Defined in** io.c

**Description**

Reads from [Standard Input stream](https://en.wikipedia.org/wiki/Standard_streams#Standard_input_(stdin)) and stores it into `STR` pointer.
