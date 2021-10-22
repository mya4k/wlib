## 1.5. Type width macros

```c
#define BLB		/* const int */
#define CHB		/* const int */
#define I16B	/* const int */
#define I32B	/* const int */
#define I64B	/* const int */
#define I8B		/* const int */
#define INB		/* const int */
#define LLB		/* const int */
#define LOB		/* const int */
#define SCB		/* const int */
#define SHB		/* const int */
#define U16B	/* const int */
#define U32B	/* const int */
#define U64B	/* const int */
#define U8B		/* const int */
#define UCB		/* const int */
#define UIB		/* const int */
#define ULB		/* const int */
#define ULLB	/* const int */
#define USB		/* const int */
```

Sometimes it is useful to have macros that represent the width of a data type. In the code below a function is defined that takes an agrument of type [`Bl`](#13-compatibility-types), basically a single bit, and shifts this bit to the leftmost binary digit of type U64B. To make this shift you need to know the width of the type.

```c
long foo(Bl a) {
	return a<<(ILB-1);
}
```

| Type               | Width (bits) |
|-------------------:|:------------:|
|`Bl`                |`BLB`         |
|`char`              |`CHB`         | 
|`I8` and `i8`       |`I8B`         |
|`I16` and `i16`     |`I16B`        |
|`I32` and `i32`     |`I32B`        |
|`I64` and `i64`     |`I64B`        |
|`IMax` and `imax`   |`IMB`         |
|`int`               |`INB`         |
|`long long`         |`LLB`         |
|`long`              |`LOB`         |
|`Pt` and `pt`       |`PTB`         |
|`short`             |`SHB`         |
|`signed char`       |`SCB`         |
|`U8` and `u8`       |`U8B`         |
|`U16` and `u16`     |`U16B`        |
|`U32` and `u32`     |`U32B`        |
|`U64` and `u64`     |`U64B`        |
|`UMax` and `umax`   |`UMB`         |
|`unsigned char`     |`UCB`         |
|`unsigned int`      |`UIB`         |
|`unsigned long long`|`ULLB`        |
|`unsigned long`     |`ULB`         |
|`unsigned short`    |`USB`         |
