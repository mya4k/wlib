# About
**WLib** is a configurable standard-independent free fast lightweight open-source and portable powerful general-purpose C programming language library project for software development.

# Documentation
## 0. Introduction
## 1. System information
### 1.1. Architecture
### 1.2. Operating system
### 1.3. Data models
### 1.4. Endianness
### 1.5. Compiler
### 1.6. Language Standard
### 1.7. Standard Version
## 2. Types
### 2.1. Fixed-size integer types
A table for integer type reference. Size describes how many bits the library tries to define for the type. The next columns lists unsigned types, separated by a comma, that correspond to the optimal size. The third columb does the same as the previous but for singed integer. Other columbs show the actual size for the data model.

`UMax` or `umax` is the widest unsigned type support by the system.

`IMax` or `imax` is the widest signed type support by the system.

<table class="table">
<thead>
  <tr>
    <th class="cell" rowspan="3">Size</th>
    <th class="cell" rowspan="3">Unsigned</th>
    <th class="cell" rowspan="3">Signed</th>
    <th class="cell" colspan="5">Data model</th>
  </tr>
  <tr>
    <th class="cell" colspan="2">LP32, ILP32</th>
    <th class="cell" rowspan="2">LP64, LLP64</th>
    <th class="cell" rowspan="2">ILP64</th>
    <th class="cell" rowspan="2">SILP64</th>
  </tr>
  <tr>
    <th class="cell">C99-</th>
    <th class="cell">C99+</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="cell">8</td>
    <td class="cell"><code>U8</code>, <code>u8</code></td>
    <td class="cell"><code>I8</code>, <code>i8</code></td>
    <td class="cell">8</td>
    <td class="cell">8</td>
    <td class="cell">8</td>
    <td class="cell">8</td>
    <td class="cell">8</td>
  </tr>
    <tr>
    <td class="cell">16</td>
    <td class="cell"><code>U16</code>, <code>u16</code></td>
    <td class="cell"><code>I16</code>, <code>i16</code></td>
    <td class="cell">16</td>
    <td class="cell">16</td>
    <td class="cell">16</td>
    <td class="cell">16</td>
    <td class="cell">64</td>
  </tr>
  <tr>
    <td class="cell">32</td>
    <td class="cell"><code>U32</code>, <code>u32</code></td>
    <td class="cell"><code>I32</code>, <code>i32</code></td>
    <td class="cell">32</td>
    <td class="cell">32</td>
    <td class="cell">32</td>
    <td class="cell">64</td>
    <td class="cell">64</td>
  </tr>
  <tr>
    <td class="cell">64</td>
    <td class="cell"><code>U64</code>, <code>u64</code></td>
    <td class="cell"><code>I64</code>, <code>i64</code></td>
    <td class="cell">32</td>
    <td class="cell">32/64*</td>
    <td class="cell">64</td>
    <td class="cell">64</td>
    <td class="cell">64</td>
  </tr>
  <tr>
    <td class="cell">64</td>
    <td class="cell"><code>UMax</code>, <code>umax</code></td>
    <td class="cell"><code>IMax</code>, <code>iMax</code></td>
    <td class="cell">32</td>
    <td class="cell">32/64*</td>
    <td class="cell">64</td>
    <td class="cell">64</td>
    <td class="cell">64</td>
  </tr>
</tbody>
</table>

&ast; &mdash; While the `long long int` type has been introduced in ISO C 1999, which is at least 64-bits long, it is unknown whether LP32 and ILP32 data models' `long long int` type is at least 64 or 32 bits and may vary from system to system. Regardless, WLib tries to defined it as `long long int` anyway, when compiler with ISO C99 standard or newer.

### 2.2. Fixed-size floating-point types
`F32` or `f32` &mdash; a real floating-point type that is at least 32-bits wide.

`F64` or `f64` &mdash; a real floating-point type that is at least 64-bits wide.

### 2.3. Other types
`Vo` or `vo` type is a void type. If `void` type is not provided (K&R C), then it will be defined as the smallest avalibe type (e.g. `char`).

`Bl` or `bl` type is a boolean type. If such is not suported (pre ISO C 1999), then it will be defined as the smallest avalibe type (e.g. `char`).

`Ch` or `ch` type is a character or a byte type.

`Pt` &mdash; pointer type. An integer type large enough to hold the reperefernce to an object. This is intended to be used for casting the pointer value into an arithmetic type for pointer arithmetic. For example, take the next piece of code. In order to use arithmetic operations using pointers, we would need to convert then into an arithmetical type. After calculations, we would probably want the result value to be converted back into a pointer value.
```c
void* foo(void* p) {
	return (Vo*)((_Ptr)p+1);
}
```
### 2.4. Sizes
| Type               | Size | Minimal value | Maximal value |
|:------------------:|:----:|:-------------:|:-------------:|
|`char`              |`CHB` |`CHN`          |`CHX`          |
|`signed char`       |`SCB` |`SCN`          |`SCX`          |
|`unsigned char`     |`UCB` |`UCN`          |`UCX`          |
|`short`             |`SHB` |`SHN`          |`SHX`          |
|`unsigned short`    |`USB` |`USN`          |`USX`          |
|`int`               |`INB` |`INN`          |`INX`          |
|`unsigned int`      |`UIB` |`UIN`          |`UIX`          |
|`long`              |`LOB` |`LON`          |`LOX`          |
|`unsigned long`     |`ULB` |`LON`          |`LOX`          |
|`long long`         |`LLB` |`LLN`          |`LLX`          |
|`unsigned long long`|`ULLB`|`ULLN`         |`ULLX`         |
|`Bl`                |`BLB` |`FALSE`        |`TRUE`         |
|`I8` and `i8`       |`I8B` |`I8N`          |`I8X`          |
|`I16` and `i16`     |`I16B`|`I16N`         |`I16X`         |
|`I32` and `i32`     |`I32B`|`I32N`         |`I32X`         |
|`I64` and `i64`     |`I64B`|`I64N`         |`I64X`         |
|`IMax` and `imax`   |`IMB` |`IMN`          |`IMX`          |
|`U8` and `u8`       |`U8B` |`U8N`          |`U8X`          |
|`U16` and `u16`     |`U16B`|`U16N`         |`U16X`         |
|`U32` and `u32`     |`U32B`|`U32N`         |`U32X`         |
|`U64` and `u64`     |`U64B`|`U64N`         |`U64X`         |
|`UMax` and `umax`   |`UMB` |`UMN`          |`UMX`          |
|`Pt`                |`PTB` |`PTN`          |`PTX`          |

### 2.5. Limits
### 2.6. Support check
## 3. Error handling
## 4. Character manipulation
## 5. Mathematics
## 6. Memory management
## 7. Array manipulation
## 8. String manipulation

# Our idea
**Why configurable?**
We believe our tech-savvy users should be able to easily customize and build our library to fit their needs and desires.

**How configurable?**
We know that majority of C programmers already have an implimentation of The Standard C Library hosted on their computers or somewhere else, and if you want to use our library then it would be a smart thing to configure WLib to use functions already implimented by the standard libarary, instead of letting WLib to impliment them on its own. This should save space a little bit. You can also specify the implimentation of which WLib functions will be provided by utilizing Standard Library or WLib

**Why standard-independent?**
We are concerned that some standards like ANSI C or ISO/IEC 9899 appose strict guidelines for library design that limit possible optimization or may add unnessary complexity to the design. WLib is a very flexible library, that can be configured to take up as little as no storage space (excluding header files).

**How is free?**
We distribute this software free of charge and will stay free forever.

**How lightweight?**
As said before, this library be as small as you want. How does that work? Our library cosists of many small modules, and you can install or build any number of them, or none at all, it all depends what you need from our library.

**How open-source?**
The whole source code of our library, where you can find the implimentation of any function, structure, etc., is avalible on [Github](https://www.github.com/wspvlv/wlib) with comment explaining everything. We think that open-source software is a good learning exprience and it's important to know how exactly the software works.

**How portable?**
While our binary releases may not cover every platform, the fact that this project is open-source means you can build this library by yourself to be compatible with your platform. We try our best to make our code portable to work on most hardware and systems. If our library does not seem to support your system and we are not working on it, let us know!

**Powerful**
-- TO BE WRITTEN --

**What is general-purpose?**
-- TO BE WRITTEN --
