<head>
<style>
  #ASCII th, #ASCII td {
    text-align: center;
  }
  .ASCII-control {
    font-size: 1.5em;
    background-color: #EEF;
  }
  .ASCII-lowercase {
    background-color: #EFE;
  }
  .ASCII-uppercase {
    background-color: #FEE;
  }
  .ASCII-digit {
    background-color: #FEF;
  }
  .ASCII-symbol {
    background-color: #FFE;
  }
  .ASCII-whitespace {
    color: #800;
  }
</style>
</head>

[toc]

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

# 2. Character manipulation \<char.h\>;

Character manipulation library is contained in a single header, <char.h>, and provides macros for using control characters by their short names (`ACK`), for checking the set of a chacater (letter, digit, symbol, etc), converting characters from one set to another (from lowercase to uppercase).

Below is the table of ASCII character set. 

- Characters belonging to the Control Character Set are inside blue cells (x00&mdash;x1F and x7F);
- Characters belonging to the Symbol Character Set are inside yellow cells (x20&mdash;x2F and x3A&mdash;x40 and x5B&mdash;x60 and x7B&mdash;x7E);
- Characters belonging to the Digit Character Set are inside pink/magenta cells (x30&mdash;x39);
- Characters belonging to the Uppercase Character Set are inside red cells (x41&mdash;x5A);
- Characters belonging to the Lowercase Character Set are inside green cells (x61&mdash;x7A);
- Characters belonging to the Whitespace Character Set are in red color (x09&mdash;x0D);
- The Letter Character Set is a combined set of the Uppercase Character Set and the Lowercase Character Set;
- The Alphaneumeric Character Set is a combined set of the Letter Character Set and the Digit Character Set;
- The Extended ASCII Character Set is any character beyond the order number 127 (x7F) or ␡ character.

<table id="ASCII">
  <thead>
    <tr>
      <th></th>
      <th>00</th>
      <th>01</th>
      <th>02</th>
      <th>03</th>
      <th>04</th>
      <th>05</th>
      <th>06</th>
      <th>07</th>
      <th>08</th>
      <th>09</th>
      <th>0A</th>
      <th>0B</th>
      <th>0C</th>
      <th>0D</th>
      <th>0E</th>
      <th>0F</th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th><b>00</b></th>
      <td class="ASCII-control">&#9216;</td>
      <td class="ASCII-control">&#9217;</td>
      <td class="ASCII-control">&#9218;</td>
      <td class="ASCII-control">&#9219;</td>
      <td class="ASCII-control">&#9220;</td>
      <td class="ASCII-control">&#9221;</td>
      <td class="ASCII-control">&#9222;</td>
      <td class="ASCII-control">&#9223;</td>
      <td class="ASCII-control">&#9224;</td>
      <td class="ASCII-control ASCII-whitespace">&#9225;</td>
      <td class="ASCII-control ASCII-whitespace">&#9226;</td>
      <td class="ASCII-control ASCII-whitespace">&#9227;</td>
      <td class="ASCII-control ASCII-whitespace">&#9228;</td>
      <td class="ASCII-control ASCII-whitespace">&#9229;</td>
      <td class="ASCII-control">&#9230;</td>
      <td class="ASCII-control">&#9231;</td>
      <th><b>0F</b></th>
    </tr>
    <tr>
      <th><b>10</b></th>
      <td class="ASCII-control">&#9232;</td>
      <td class="ASCII-control">&#9233;</td>
      <td class="ASCII-control">&#9234;</td>
      <td class="ASCII-control">&#9235;</td>
      <td class="ASCII-control">&#9236;</td>
      <td class="ASCII-control">&#9237;</td>
      <td class="ASCII-control">&#9238;</td>
      <td class="ASCII-control">&#9239;</td>
      <td class="ASCII-control">&#9240;</td>
      <td class="ASCII-control">&#9241;</td>
      <td class="ASCII-control">&#9242;</td>
      <td class="ASCII-control">&#9243;</td>
      <td class="ASCII-control">&#9244;</td>
      <td class="ASCII-control">&#9245;</td>
      <td class="ASCII-control">&#9246;</td>
      <td class="ASCII-control">&#9247;</td>
      <th><b>1F</b></th>
    </tr>
    <tr>
      <th><b>20</b></th>
      <td class="ASCII-symbol">&#9251;</td>
      <td class="ASCII-symbol">!</td>
      <td class="ASCII-symbol">&quot;</td>
      <td class="ASCII-symbol">&num;</td>
      <td class="ASCII-symbol">$</td>
      <td class="ASCII-symbol">%</td>
      <td class="ASCII-symbol">&amp;</td>
      <td class="ASCII-symbol">&#39;</td>
      <td class="ASCII-symbol">(</td>
      <td class="ASCII-symbol">)</td>
      <td class="ASCII-symbol">&ast;</td>
      <td class="ASCII-symbol">+</td>
      <td class="ASCII-symbol">,</td>
      <td class="ASCII-symbol">-</td>
      <td class="ASCII-symbol">.</td>
      <td class="ASCII-symbol">/</td>
      <th><b>2F</b></th>
    </tr>
    <tr>
      <th><b>30</b></th>
      <td class="ASCII-digit">0</td>
      <td class="ASCII-digit">1</td>
      <td class="ASCII-digit">2</td>
      <td class="ASCII-digit">3</td>
      <td class="ASCII-digit">4</td>
      <td class="ASCII-digit">5</td>
      <td class="ASCII-digit">6</td>
      <td class="ASCII-digit">7</td>
      <td class="ASCII-digit">8</td>
      <td class="ASCII-digit">9</td>
      <td class="ASCII-symbol">:</td>
      <td class="ASCII-symbol">;</td>
      <td class="ASCII-symbol">&lt;</td>
      <td class="ASCII-symbol">=</td>
      <td class="ASCII-symbol">&gt;</td>
      <td class="ASCII-symbol">?</td>
      <th><b>3F</b></th>
    </tr>
    <tr>
      <th><b>40</b></th>
      <td class="ASCII-symbol">@</td>
      <td class="ASCII-uppercase">A</td>
      <td class="ASCII-uppercase">B</td>
      <td class="ASCII-uppercase">C</td>
      <td class="ASCII-uppercase">D</td>
      <td class="ASCII-uppercase">E</td>
      <td class="ASCII-uppercase">F</td>
      <td class="ASCII-uppercase">G</td>
      <td class="ASCII-uppercase">H</td>
      <td class="ASCII-uppercase">I</td>
      <td class="ASCII-uppercase">J</td>
      <td class="ASCII-uppercase">K</td>
      <td class="ASCII-uppercase">L</td>
      <td class="ASCII-uppercase">M</td>
      <td class="ASCII-uppercase">N</td>
      <td class="ASCII-uppercase">O</td>
      <th><b>4F</b></th>
    </tr>
    <tr>
      <th><b>50</b></th>
      <td class="ASCII-uppercase">P</td>
      <td class="ASCII-uppercase">Q</td>
      <td class="ASCII-uppercase">R</td>
      <td class="ASCII-uppercase">S</td>
      <td class="ASCII-uppercase">T</td>
      <td class="ASCII-uppercase">U</td>
      <td class="ASCII-uppercase">V</td>
      <td class="ASCII-uppercase">W</td>
      <td class="ASCII-uppercase">X</td>
      <td class="ASCII-uppercase">Y</td>
      <td class="ASCII-uppercase">Z</td>
      <td class="ASCII-symbol">[</td>
      <td class="ASCII-symbol">\</td>
      <td class="ASCII-symbol">]</td>
      <td class="ASCII-symbol">^</td>
      <td class="ASCII-symbol">_</td>
      <th><b>5F</b></th>
    </tr>
    <tr>
      <th><b>60</b></th>
      <td class="ASCII-symbol">&grave;</td>
      <td class="ASCII-lowercase">a</td>
      <td class="ASCII-lowercase">b</td>
      <td class="ASCII-lowercase">c</td>
      <td class="ASCII-lowercase">d</td>
      <td class="ASCII-lowercase">e</td>
      <td class="ASCII-lowercase">f</td>
      <td class="ASCII-lowercase">g</td>
      <td class="ASCII-lowercase">h</td>
      <td class="ASCII-lowercase">i</td>
      <td class="ASCII-lowercase">j</td>
      <td class="ASCII-lowercase">k</td>
      <td class="ASCII-lowercase">l</td>
      <td class="ASCII-lowercase">m</td>
      <td class="ASCII-lowercase">n</td>
      <td class="ASCII-lowercase">o</td>
      <th><b>6F</b></th>
    </tr>
    <tr>
      <th><b>70</b></th>
      <td class="ASCII-lowercase">p</td>
      <td class="ASCII-lowercase">q</td>
      <td class="ASCII-lowercase">r</td>
      <td class="ASCII-lowercase">s</td>
      <td class="ASCII-lowercase">t</td>
      <td class="ASCII-lowercase">u</td>
      <td class="ASCII-lowercase">v</td>
      <td class="ASCII-lowercase">w</td>
      <td class="ASCII-lowercase">x</td>
      <td class="ASCII-lowercase">y</td>
      <td class="ASCII-lowercase">z</td>
      <td class="ASCII-symbol">{</td>
      <td class="ASCII-symbol">&vert;</td>
      <td class="ASCII-symbol">}</td>
      <td class="ASCII-symbol">~</td>
      <td class="ASCII-control">␡</td>
      <th><b>7F</b></th>
    </tr>
  </tbody>
  <thead>
    <tr>
      <th></th>
      <th>F0</th>
      <th>F1</th>
      <th>F2</th>
      <th>F3</th>
      <th>F4</th>
      <th>F5</th>
      <th>F6</th>
      <th>F7</th>
      <th>F8</th>
      <th>F9</th>
      <th>FA</th>
      <th>FB</th>
      <th>FC</th>
      <th>FD</th>
      <th>FE</th>
      <th>FF</th>
      <th></th>
    </tr>
  </thead>
</table>

<table>
  <thead>
    <tr>
      <th colspan="2">Legend</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="background-color:#EEF"></td>
      <td>Control characters</td>
    </tr>
    <tr>
      <td style="background-color:#FFE"></td>
      <td>Symbol characters</td>
    </tr>
    <tr>
      <td style="background-color:#FEF"></td>
      <td>Digit characters</td>
    </tr>
    <tr>
      <td style="background-color:#FEE"></td>
      <td>Uppercase letter characters</td>
    </tr>
    <tr>
      <td style="background-color:#EFE"></td>
      <td>Lowercase letter characters</td>
    </tr>
    <tr>
      <td style="color:#800">A</td>
      <td>Whitespaces</td>
    </tr>
  </tbody>
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Alphanumeric characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Control characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Numeric characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Extended ASCII characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Alphabetic characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Lowercase characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Uppercase characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Symbol characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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
      <td style="text-align:left" colspan="3">Returns <a><a><code>TRUE</code></a></a> if <code>x</code> belongs in the range of <a href="#2-character-manipulation-charh">Whitespace characters</a>, <a><a><code>FALSE</code></a></a> otherwise.
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

```mermaid
graph TD;
  A-->B;
  A-->C;
  B-->D;
  C-->D;
```
