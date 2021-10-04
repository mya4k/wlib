# WLib Documentation

Welcome to WLib Documentation main page! Here you can learn how to use our libraries and read in detail how every global identifier works.

# 1. Types

Header `<types.h>` defines:
- fixed-size integer types (`U8`, `U16`, `U32`, `U64`, `I8`, `I16`, `I32`, `I64`),
- alias types (`Ch`, `Fl`, `Db`, `Ld`),
- C/C++ backwards compatibility types (`Vo`, `Bl`),
- special types (`Pt`, `IMax`, `UMax`),
- type width macros (`CHB`, `SHB`, `INB`, `LOB`, `LLB`, `I8B`, `I16B`, `I32B`, `I64B`, `PTB`, `IMB`),
- type limits macros (`CHN`, `SHN`, `INN`, `LON`, `LLN`, `I8N`, `I16N`, `I32N`, `I64N`, `CHX`, `SHX`, `INX`, `LOX`, `LLX`, `I8X`, `I16X`, `I32X`, `I64X`).

## 1.1 Fixed-size integer types

```c
typedef /* type */	wl_i8,		wl_I8;
typedef /* type */	wl_i16,		wl_I16;
typedef /* type */	wl_i32,		wl_I32;
typedef /* type */	wl_i64,		wl_I64;
typedef /* type */	wl_u8,		wl_U8;
typedef /* type */	wl_u16,		wl_U16;
typedef /* type */	wl_u32,		wl_U32;
typedef /* type */	wl_u64,		wl_U64;
typedef /* type */	wl_imax,	wl_IMax;
typedef /* type */	wl_umax,	wl_UMax;
```

A fixed-size integer type means an integer type, which width stays constant across different system. There are 8 distinct fixed-size integer types. 

Since basic C types (`char`, `short`, `int`, `long`, etc.) widths are not specified in the ISO C standard, it was left for compilers to decide their sizes on their own. The sizes of basic C types are diffirent depending on your Operating System, CPU Architecture, Compiler options, etc. However, rather handily, there a several common data models that majority of systems design their C types according to; the `<sys/damo.h>` is responsible for correctly using system information to define a data model (the `DATA_MODEL` macro). The implimentation of fixed-size integer types shall be done through those data models (unless there is a better replacement for this model, in which case let us know). 

`USE_STDINT` macro can be defined with any non-zero value at build time, to signal WLib to impliment its fixed-size integer types through `<stdint.h>`'s definitions of fixed-size integer types rather than the method described above.

A table for integer type reference. Size describes how many bits the library tries to define for the type. The next columns lists unsigned types, separated by a comma, that correspond to the optimal size. The third columb does the same as the previous but for singed integer. Other columbs show the actual size for the data model.

`UMax` or `umax` is the widest unsigned type support by the system (in many systems it's 64-bit).

`IMax` or `imax` is the widest signed type support by the system (in many systems it's 64-bit).

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
