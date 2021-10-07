<head>
<style>
  #ASCII th, td {
    text-align: center;
  }
</style>
</head>

# WLib Documentation

Welcome to WLib Documentation main page! Here you can learn how to use our libraries and read in detail how every global identifier works.

# Requirements

If you want to use our library to write your own code, your compiler should comply with next basic requirements:
- ANSI C / ISO C / ISO C++ (all of any revision) standard support (while there are efforts to support K&R C compilers, like `pcc`, however, you are on your own);

# 1. Types

Header `<types.h>` defines:
- fixed-size integer types (`U8`, `U16`, `U32`, `U64`, `I8`, `I16`, `I32`, `I64`),
- alias types (`Ch`, `Fl`, `Db`, `Ld`),
- C/C++ backwards compatibility types (`Vo`, `Bl`),
- special types (`Pt`, `IMax`, `UMax`),
- type width macros (`CHB`, `SHB`, `INB`, `LOB`, `LLB`, `I8B`, `I16B`, `I32B`, `I64B`, `PTB`, `IMB`),
- type limits macros (`CHN`, `SHN`, `INN`, `LON`, `LLN`, `I8N`, `I16N`, `I32N`, `I64N`, `CHX`, `SHX`, `INX`, `LOX`, `LLX`, `I8X`, `I16X`, `I32X`, `I64X`).

## 1.1. Fixed-size integer types

```c
typedef /* type */ wl_i8,	wl_I8;
typedef /* type */ wl_i16,	wl_I16;
typedef /* type */ wl_i32,	wl_I32;
typedef /* type */ wl_i64,	wl_I64;
typedef /* type */ wl_u8,	wl_U8;
typedef /* type */ wl_u16,	wl_U16;
typedef /* type */ wl_u32,	wl_U32;
typedef /* type */ wl_u64,	wl_U64;
```

A fixed-size integer type means an integer type, which width stays constant across different system. There are 8 distinct fixed-size integer types. 

Since basic C types (`char`, `short`, `int`, `long`, etc.) widths are not specified in the ISO C standard, it was left for compilers to decide their sizes on their own. The sizes of basic C types are different depending on your Operating System, CPU Architecture, Compiler options, etc. However, rather handily, there a several common data models that majority of systems design their C types according to; the `<sys/damo.h>` is responsible for correctly using system information to define a data model (the `DATA_MODEL` macro). The implementation of fixed-size integer types shall be done through those data models (unless there is a better replacement for this model, in which case let us know). 

`WL_USE_STDINT` macro can be defined with any non-zero value at build time, to signal WLib to implement its fixed-size integer types through `<stdint.h>`'s definitions of fixed-size integer types rather than the method described above.

A table for integer type reference. Size describes how many bits the library tries to define for the type. The next columns lists unsigned types, separated by a comma, that correspond to the optimal size. The third column does the same as the previous but for singed integer. Other columns show the actual size for the data model.

<table>
<thead>
  <tr>
    <th rowspan="3">Size</th>
    <th rowspan="3">Unsigned</th>
    <th rowspan="3">Signed</th>
    <th colspan="5">Data model</th>
  </tr>
  <tr>
    <th colspan="2">LP32, ILP32</th>
    <th rowspan="2">LP64, LLP64</th>
    <th rowspan="2">ILP64</th>
    <th rowspan="2">SILP64</th>
  </tr>
  <tr>
    <th>&lt;C99 / &lt;C++11</th>
    <th>&ge;C99 / &ge;C++11</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>8</td>
    <td><code>U8</code>, <code>u8</code></td>
    <td><code>I8</code>, <code>i8</code></td>
    <td>8</td>
    <td>8</td>
    <td>8</td>
    <td>8</td>
    <td>8</td>
  </tr>
    <tr>
    <td>16</td>
    <td><code>U16</code>, <code>u16</code></td>
    <td><code>I16</code>, <code>i16</code></td>
    <td>16</td>
    <td>16</td>
    <td>16</td>
    <td>16</td>
    <td>64</td>
  </tr>
  <tr>
    <td>32</td>
    <td><code>U32</code>, <code>u32</code></td>
    <td><code>I32</code>, <code>i32</code></td>
    <td>32</td>
    <td>32</td>
    <td>32</td>
    <td>64</td>
    <td>64</td>
  </tr>
  <tr>
    <td>64</td>
    <td><code>U64</code>, <code>u64</code></td>
    <td><code>I64</code>, <code>i64</code></td>
    <td>32</td>
    <td>32/64&ast;</td>
    <td>64</td>
    <td>64</td>
    <td>64</td>
  </tr>
<!--   <tr>
    <td>64</td>
    <td><code>UMax</code>, <code>umax</code></td>
    <td><code>IMax</code>, <code>iMax</code></td>
    <td>32</td>
    <td>32/64&ast;</td>
    <td>64</td>
    <td>64</td>
    <td>64</td>
  </tr> -->
</tbody>
</table>

&ast; &mdash; While the `long long int` type has been introduced in ISO C 1999, which is at least 64-bits long, it is unknown whether LP32 and ILP32 data models' `long long int` type is at least 64 or 32 bits and may vary from system to system. Regardless, WLib tries to defined it as `long long int` anyway, when compiler with ISO C99 standard or newer.

## 1.2. Special types

```c
typedef /* type */ wl_IMax,	wl_imax;
typedef /* type */ wl_UMax,	wl_umax;
typedef /* type */ wl_Pt,   wl_pt;
```

There are 3 additional useful types defined in `<types.h>`: `Pt`, `IMax` and `UMax`

### Pointer type

`Pt` or `pt` &mdash; the pointer type. An integer type large enough to hold the reference to an object. This is intended to be used for casting the pointer value into an arithmetic type for pointer arithmetic. 

For example, take the next piece of code. In order to use arithmetic operations using pointers, we would need to convert then into an arithmetical type. After calculations, we would probably want the result value to be converted back into a pointer value.

```c
void* foo(void* p) {
	return (void*)((Pt)p+1);
}
```

`WL_USE_STDINT` macro can be defined with any non-zero value at build time, to signal WLib to implement its fixed-size integer types through `<stdint.h>`'s definitions rather than using data models.

### Maximal-width types

`IMax` or `imax` is a type for the largest available signed basic integer C type (usually 64-bits)

`UMax` or `umax` is a type for the largest avalible unsigned basic integer C type (usually 64-bits)

## 1.3. Compatibility types

```c
typedef /* type */	Vo, vo;
typedef /* type */	Bl, bl;
```

`void` type has been added by the ANSI C standard (which means it may not have been supported by pre-standard compilers), WLib defines `Vo` and `vo` types. However, in the implementation of any WLib identifier or a function (except the definition of `Vo` and `vo` types themselves) use of `void` type as-is is allowed, even interchangeably; therefore, `Vo` and `vo` types are mostly viewed as aliases.

While `_Bool` type has only been introduced ten years later with an ISO C 1999 revision. `Bl` or `bl` type ensures to use of the type will not generate any error or warnings and will act as a boolean type for the most part for compilers set to comply with a standard revision prior to `_Bool`'s debut. More specifically `Bl` is defined as the smallest available data type (any 8-bit type), where any non-zero value is considered true and false otherwise. In C++ the default boolean type is `bool`, not `_Bool`, therefore, `Bl` and `bl` are also defined accordingly to the language used.

## 1.4. Alias types

```c
typedef char		Ch, ch;
typedef double		Db, db;
typedef float		Fl, fl;
typedef long double	Ld, ld;
```

`Ch` and `ch` are aliases for `char` type.

`Fl` and `fl` are aliases for `float` type.

`Db` and `db` are aliases for `double` type.

`Ld` and `ld` are aliases for `long double` type.

### 1.5. Type width macros

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

## 1.6. Type width macros

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

# 2. Character manipulation &lt;char.h&gt;

Character manipulation library is contained in a single header, <char.h>, and provides macros for using control characters by their short names (`EOF`), for checking the set of a chacater (letter, digit, symbol, etc), converting characters from one set to another (from lowercase to uppercase).

<table id="ASCII">
  <thead>
    <tr>
      <th ></th>
      <th >00</th>
      <th >01</th>
      <th >02</th>
      <th >03</th>
      <th >04</th>
      <th >05</th>
      <th >06</th>
      <th >07</th>
      <th >08</th>
      <th >09</th>
      <th >0A</th>
      <th >0B</th>
      <th >0C</th>
      <th >0D</th>
      <th >0E</th>
      <th >0F</th>
      <th ></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th ><b>00</b></th>
      <td >&#9216;</td>
      <td >&#9217;</td>
      <td >&#9218;</td>
      <td >&#9219;</td>
      <td >&#9220;</td>
      <td >&#9221;</td>
      <td >&#9223;</td>
      <td >&#9224;</td>
      <td >&#9225;</td>
      <td >&#9226;</td>
      <td >&#9227;</td>
      <td >&#9228;</td>
      <td >&#9229;</td>
      <td >&#9230;</td>
      <td >&#9231;</td>
      <td >&#9232;</td>
      <th ><b>0F</b></th>
    </tr>
    <tr>
      <th ><b>10</b></th>
      <td >&#9233;</td>
      <td >&#9234;</td>
      <td >&#9235;</td>
      <td >&#9236;</td>
      <td >&#9237;</td>
      <td >&#9238;</td>
      <td >&#9239;</td>
      <td >&#9240;</td>
      <td >&#9241;</td>
      <td >&#9242;</td>
      <td >&#9243;</td>
      <td >&#9244;</td>
      <td >&#9245;</td>
      <td >&#9246;</td>
      <td >&#9247;</td>
      <td >&#9248;</td>
      <th ><b>1F</b></th>
    </tr>
    <tr>
      <th ><b>20</b></th>
      <td >&#9251;</td>
      <td >!</td>
      <td >&quot;</td>
      <td >&num;</td>
      <td >$</td>
      <td >%</td>
      <td >&amp;</td>
      <td >&#39;</td>
      <td >(</td>
      <td >)</td>
      <td >&ast;</td>
      <td >+</td>
      <td >,</td>
      <td >-</td>
      <td >.</td>
      <td >/</td>
      <th ><b>2F</b></th>
    </tr>
    <tr>
      <th ><b>30</b></th>
      <td >0</td>
      <td >1</td>
      <td >2</td>
      <td >3</td>
      <td >4</td>
      <td >5</td>
      <td >6</td>
      <td >7</td>
      <td >8</td>
      <td >9</td>
      <td >:</td>
      <td >;</td>
      <td >&lt;</td>
      <td >=</td>
      <td >&gt;</td>
      <td >?</td>
      <th ><b>3F</b></th>
    </tr>
    <tr>
      <th ><b>40</b></th>
      <td >@</td>
      <td >A</td>
      <td >B</td>
      <td >C</td>
      <td >D</td>
      <td >E</td>
      <td >F</td>
      <td >G</td>
      <td >H</td>
      <td >I</td>
      <td >J</td>
      <td >K</td>
      <td >L</td>
      <td >M</td>
      <td >N</td>
      <td >O</td>
      <th ><b>4F</b></th>
    </tr>
    <tr>
      <th ><b>50</b></th>
      <td >P</td>
      <td >Q</td>
      <td >R</td>
      <td >S</td>
      <td >T</td>
      <td >U</td>
      <td >V</td>
      <td >W</td>
      <td >X</td>
      <td >Y</td>
      <td >Z</td>
      <td >[</td>
      <td >\</td>
      <td >]</td>
      <td >^</td>
      <td >_</td>
      <th ><b>5F</b></th>
    </tr>
    <tr>
      <th ><b>60</b></th>
      <td >&grave;</td>
      <td >a</td>
      <td >b</td>
      <td >c</td>
      <td >d</td>
      <td >e</td>
      <td >f</td>
      <td >g</td>
      <td >h</td>
      <td >i</td>
      <td >j</td>
      <td >k</td>
      <td >l</td>
      <td >m</td>
      <td >n</td>
      <td >o</td>
      <th ><b>6F</b></th>
    </tr>
    <tr>
      <th ><b>70</b></th>
      <td >p</td>
      <td >q</td>
      <td >r</td>
      <td >s</td>
      <td >t</td>
      <td >u</td>
      <td >v</td>
      <td >w</td>
      <td >x</td>
      <td >y</td>
      <td >z</td>
      <td >{</td>
      <td >&vert;</td>
      <td >}</td>
      <td >~</td>
      <td >␡</td>
      <th ><b>7F</b></th>
    </tr>
  </tbody>
  <thead>
    <tr>
      <th ></th>
      <th >F0</th>
      <th >F1</th>
      <th >F2</th>
      <th >F3</th>
      <th >F4</th>
      <th >F5</th>
      <th >F6</th>
      <th >F7</th>
      <th >F8</th>
      <th >F9</th>
      <th >FA</th>
      <th >FB</th>
      <th >FC</th>
      <th >FD</th>
      <th >FE</th>
      <th >FF</th>
      <th ></th>
    </tr>
  </thead>
</table>


## 2.1. Character checking
### 2.1.1. `cia` &mdash; Character Is Alphanumeric character

```c
#define cia wl_cia
#define wl_cia(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>cia</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>A</b>lphanumeric</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Depends on</b></td>
      <td style="text-align:left" colspan="2"><a href="#215-cil--character-is-letter-character"><code>cil</code></a> , <a href="#213-cid--character-is-digit-character"><code>cid</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Alphanumeric characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.2. `cic` &mdash; Character Is Control character

```c
#define cic wl_cic
#define wl_cic(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>cic</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>C</b>ontrol</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Depends on</b></td>
      <td style="text-align:left" colspan="2"><a><code>DEL</code></a> </td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Control characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.3. `cid` &mdash; Character Is Digit character

```c
#define cid wl_cid
#define wl_cid(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>cid</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>D</b>igit</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3">(No dependencies)</td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Numeric characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.4. `cie` &mdash; Character Is Extended ASCII character

```c
#define cie wl_cie
#define wl_cie(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>cie</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>E</b>xtended ASCII</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3">(No dependencies)</td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Extended ASCII characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.5. `cil` &mdash; Character Is Letter character

```c
#define cil wl_cil
#define wl_cil(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>cil</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>L</b>etter</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Depends on</b></td>
      <td style="text-align:left" colspan="2"><a href="#216-cill--character-is-lowercase-letter-character"><code>cill</code></a> , <a href="#217-ciul--character-is-uppercase-letter-character"><code>ciul</code></a></td>   
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Alphabetic characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.6. `cill` &mdash; Character Is Lowercase Letter character

```c
#define ciul wl_cill
#define wl_cill(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>cill</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>L</b>owercase <b>l</b>etter</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3">(No dependencies)</td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Lowercase characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.7. `ciul` &mdash; Character Is Uppercase Letter character

```c
#define ciul wl_ciul
#define wl_ciul(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>ciul</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>U</b>ppercase <b>l</b>etter</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3">(No dependencies)</td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Lowercase characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.8. `cis` &mdash; Character Is Symbol character

```c
#define cis wl_cis
#define wl_cis(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>cis</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>S</b>ymbol</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3">(No dependencies)</td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Symbol characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

### 2.1.9. `ciw` &mdash; Character Is Whitespace character

```c
#define ciw wl_ciw
#define wl_ciw(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>ciw</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>i</b>s <b>W</b>hitespace</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>a</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2"><a><code>TRUE</code></a> or <a><code>FALSE</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3">(No dependencies)</td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a>Whitespace characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
      </td>
    </tr>
  </tbody>
</table>

## 2.2. Convertion functions
### Digit to Character convertion table

| Digit  | **00**| **01**| **02**| **03**| **04** | **05** | **06**| **07**| **08**| **09**                 | **0A**| **0B**                | **0C**| **0D** | **0E**| **0F**|
|:------:|:-----:|:-----:|:-----:|:-----:|:------:|:------:|:-----:|:-----:|:-----:|:----------------------:|:-----:|:---------------------:|:-----:|:------:|:-----:|:-----:|
| **00** | `'0'` | `'1'` | `'2'` | `'3'` | `'4'`  | `'5'`  | `'6'` | `'7'` | `'8'` | `'9'`                  | `'A'` | `'B'`                 | `'C'` | `'D'`  | `'E'` | `'F'` |
| **10** | `'G'` | `'H'` | `'I'` | `'J'` | `'K'`  | `'L'`  | `'M'` | `'N'` | `'O'` | `'P'`                  | `'Q'` | `'R'`                 | `'S'` | `'T'`  | `'U'` | `'V'` |
| **20** | `'W'` | `'X'` | `'Y'` | `'Z'` | `'a'`  | `'b'`  | `'c'` | `'d'` | `'e'` | `'f'`                  | `'g'` | `'h'`                 | `'i'` | `'j'`  | `'k'` | `'l'` |
| **30** | `'m'` | `'n'` | `'o'` | `'p'` | `'q'`  | `'r'`  | `'s'` | `'t'` | `'u'` | `'v'`                  | `'w'` | `'x'`                 | `'y'` | `'z'`  | `'!'` | `'"'` |
| **40** | `'#'` | `'$'` | `'%'` | `'&'` | `'\''` | `'('`  | `')'` | `'*'` | `'+'` | `','`                  | `'-'` | `'.'`                 | `'/'` | `':'`  | `';'` | `'<'` |
| **50** | `'='` | `'>'` | `'?'` | `'@'` | `'['`  | `'\\'` | `']'` | `'^'` | `'_'` | <code>'&grave;'</code> | `'{'` | <code>'&vert;'</code> | `'}'` | `'~'`  | `' '` | `DEL` |

### 2.2.1. `c2d` &mdash; Charater To Digit

```c
#define c2d wl_c2d
#define wl_c2d(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>c2d</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>C</b>haracter <b>to</b> <b>D</b>igit</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>x</i></td>
      <td style="text-align:left">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2">Digit</td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3">(No dependencies)</td>    
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">
        Treats <code>x</code> and return a digit corresponding to <a href="#digit-to-character-convertion-table">Digit To Character convertion table</a>
      </td>
    </tr>
  </tbody>
</table>

### 2.2.2. `d2c` &mdash; Digit To Charater

```c
#define d2c wl_d2c
#define wl_d2c(a) /* function body */
```

<table>
  <tbody>
    <tr>
      <td style="text-align:right"><b>Name</b></td>
      <td style="text-align:left" colspan="2"><code>d2c</code></td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Type</b></td>
      <td style="text-align:left" colspan="2">macro function</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Mnemonics</b></td>
      <td style="text-align:left" colspan="2"><b>D</b>igit <b>to</b> <b>C</b>haracter</td>
    </tr>
      <tr>
      <td style="text-align:right"><b>Parameters</b></td>
      <td style="text-align:left"><i>x</i></td>
      <td style="text-align:left">Digit</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Returns</b></td>
      <td style="text-align:left" colspan="2">Character</td>
    </tr>
    <tr>
      <td style="text-align:right"><b>Depends on</b></td>
      <td style="text-align:left" colspan="2"><a><code>U8</code></a></td>
    </tr>
    <tr>
      <td style="text-align:center" colspan="3"><b>Description</b></td>
    </tr>
    <tr>
      <td style="text-align:left" colspan="3">
        Treats <code>x</code> and return a character corresponding to <a href="#digit-to-character-convertion-table">Digit To Character convertion table</a>
      </td>
    </tr>
  </tbody>
</table>
