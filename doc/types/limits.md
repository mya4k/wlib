# 1.6. Type limits macros

```c
#define CHN		/* const int */
#define CHX		/* const int */
#define FALSE	/* const int */
#define I16N	/* const int */
#define I16X	/* const int */
#define I32N	/* const int */
#define I32X	/* const int */
#define I64N	/* const int */
#define I64X	/* const int */
#define I8N		/* const int */
#define I8X		/* const int */
#define IMN		/* const int */
#define IMX		/* const int */
#define IMX		/* const int */
#define INN		/* const int */
#define INX		/* const int */
#define LLN		/* const int */
#define LLX		/* const int */
#define LON		/* const int */
#define LOX		/* const int */
#define SCN		/* const int */
#define SCX		/* const int */
#define SHN		/* const int */
#define SHX		/* const int */
#define TRUE	/* const int */
#define U16N	/* const int */
#define U16X	/* const int */
#define U32N	/* const int */
#define U32X	/* const int */
#define U64N	/* const int */
#define U64X	/* const int */
#define U8N		/* const int */
#define U8X		/* const int */
#define UCN		/* const int */
#define UCX		/* const int */
#define UIN		/* const int */
#define UIX		/* const int */
#define ULLN	/* const int */
#define ULLX	/* const int */
#define ULN		/* const int */
#define ULX		/* const int */
#define UMX		/* const int */
#define USN		/* const int */
#define USX		/* const int */
```

In the table below 

| Type               | Minimal value | Maximal value |
|:------------------:|:-------------:|:-------------:|
|`Bl`                |`FALSE`        |`TRUE`         |
|`char`              |`CHN`          |`CHX`          |
|`I8` and `i8`       |`I8N`          |`I8X`          |
|`I16` and `i16`     |`I16N`         |`I16X`         |
|`I32` and `i32`     |`I32N`         |`I32X`         |
|`I64` and `i64`     |`I64N`         |`I64X`         |
|`IMax` and `imax`   |`IMN`          |`IMX`          |
|`int`               |`INN`          |`INX`          |
|`long long`         |`LLN`          |`LLX`          |
|`long`              |`LON`          |`LOX`          |
|`Pt` and `pt`       |`PTN`          |`PTX`          |
|`short`             |`SHN`          |`SHX`          |
|`signed char`       |`SCN`          |`SCX`          |
|`U8` and `u8`       |`U8N`          |`U8X`          |
|`U16` and `u16`     |`U16N`         |`U16X`         |
|`U32` and `u32`     |`U32N`         |`U32X`         |
|`U64` and `u64`     |`U64N`         |`U64X`         |
|`UMax` and `umax`   |`UMN`          |`UMX`          |
|`unsigned char`     |`UCN`          |`UCX`          |
|`unsigned int`      |`UIN`          |`UIX`          |
|`unsigned long long`|`ULLN`         |`ULLX`         |
|`unsigned long`     |`LON`          |`LOX`          |
|`unsigned short`    |`USN`          |`USX`          |
