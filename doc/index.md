# WLib Documentation
# 0. Introduction
# 1. System information
## 1.1. Architecture
## 1.2. Operating system
## 1.3. Data models
## 1.4. Endianness
## 1.5. Compiler
## 1.6. Language Standard
## 1.7. Standard Version
To be written
# 2. Types &lt;types.h&gt;
## 2.1. Fixed-size integer types
A table for integer type reference. Size describes how many bits the library tries to define for the type. The next columns lists unsigned types, separated by a comma, that correspond to the optimal size. The third columb does the same as the previous but for singed integer. Other columbs show the actual size for the data model.

`UMax` or `umax` is the widest unsigned type support by the system.

`IMax` or `imax` is the widest signed type support by the system.

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
    <td>32/64*</td>
    <td>64</td>
    <td>64</td>
    <td>64</td>
  </tr>
  <tr>
    <td>64</td>
    <td><code>UMax</code>, <code>umax</code></td>
    <td><code>IMax</code>, <code>iMax</code></td>
    <td>32</td>
    <td>32/64*</td>
    <td>64</td>
    <td>64</td>
    <td>64</td>
  </tr>
</tbody>
</table>

&ast; &mdash; While the `long long int` type has been introduced in ISO C 1999, which is at least 64-bits long, it is unknown whether LP32 and ILP32 data models' `long long int` type is at least 64 or 32 bits and may vary from system to system. Regardless, WLib tries to defined it as `long long int` anyway, when compiler with ISO C99 standard or newer.

## 2.2. Fixed-size floating-point types
`F32` or `f32` &mdash; a real floating-point type that is at least 32-bits wide.

`F64` or `f64` &mdash; a real floating-point type that is at least 64-bits wide.

## 2.3. Other types
`Vo` or `vo` type is a void type. If `void` type is not provided (K&R C), then it will be defined as the smallest avalibe type (e.g. `char`).

`Bl` or `bl` type is a boolean type. If such is not suported (pre ISO C 1999), then it will be defined as the smallest avalibe type (e.g. `char`).

`Ch` or `ch` type is a character or a byte type.

`Pt` or `pt` &mdash; the pointer type. An integer type large enough to hold the reperefernce to an object. This is intended to be used for casting the pointer value into an arithmetic type for pointer arithmetic. For example, take the next piece of code. In order to use arithmetic operations using pointers, we would need to convert then into an arithmetical type. After calculations, we would probably want the result value to be converted back into a pointer value.
```c
void* foo(void* p) {
	return (void*)((Pt)p+1);
}
```

### Depricated

`_Ptr` is still preserved for backwards-compatibility. Use `Pt` instead`
## 2.4. Sizes and Limits
Below lies a reference table for type size in bits macros and type limit values macros.

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
|`Pt` and `pt`       |`PTB` |`PTN`          |`PTX`          |
## 2.5. Support check
# 3. Error handling
# 4. Character manipulation &lt;char.h&gt;
## 4.1. Boolean functions
### 4.1.1. `cia` &mdash; Character Is Alphanumeric character
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
      <td style="text-align:left" colspan="2"><a href="#415-cil--character-is-letter-character"><code>cil</code></a> , <a href="#413-cid--character-is-digit-character"><code>cid</code></a></td>
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

### 4.1.2. `cic` &mdash; Character Is Control character
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

### 4.1.3. `cid` &mdash; Character Is Digit character
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

### 4.1.4. `cie` &mdash; Character Is Extended ASCII character
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

### 4.1.5. `cil` &mdash; Character Is Letter character
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
      <td style="text-align:left" colspan="2"><a href="#416-cill--character-is-lowercase-letter-character"><code>cill</code></a> , <a href="#417-ciul--character-is-uppercase-letter-character"><code>ciul</code></a></td>   
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

### 4.1.6. `cill` &mdash; Character Is Lowercase Letter character
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

### 4.1.7. `ciul` &mdash; Character Is Uppercase Letter character
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

### 4.1.8. `cis` &mdash; Character Is Symbol character
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

### 4.1.9. `ciw` &mdash; Character Is Whitespace character
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

## 4.2. Conversation functions

|        | 00    | 01    | 02    | 03    | 04     | 05     | 06    | 07    | 08    | 09                     | 0A    | 0B                    | 0C    | 0D    | 0E     | 0F    |
|:------:|:-----:|:-----:|:-----:|:-----:|:------:|:------:|:-----:|:-----:|:-----:|:----------------------:|:-----:|:---------------------:|:-----:|:------:|:-----:|:-----:|
| **00** | `'0'` | `'1'` | `'2'` | `'3'` | `'4'`  | `'5'`  | `'6'` | `'7'` | `'8'` | `'9'`                  | `'A'` | `'B'`                 | `'C'` | `'D'`  | `'E'` | `'F'` |
| **10** | `'G'` | `'H'` | `'I'` | `'J'` | `'K'`  | `'L'`  | `'M'` | `'N'` | `'O'` | `'P'`                  | `'Q'` | `'R'`                 | `'S'` | `'T'`  | `'U'` | `'V'` |
| **20** | `'W'` | `'X'` | `'Y'` | `'Z'` | `'a'`  | `'b'`  | `'c'` | `'d'` | `'e'` | `'f'`                  | `'g'` | `'h'`                 | `'i'` | `'j'`  | `'k'` | `'l'` |
| **30** | `'m'` | `'n'` | `'o'` | `'p'` | `'q'`  | `'r'`  | `'s'` | `'t'` | `'u'` | `'v'`                  | `'w'` | `'x'`                 | `'y'` | `'z'`  | `'!'` | `'"'` |
| **40** | `'#'` | `'$'` | `'%'` | `'&'` | `'\''` | `'('`  | `')'` | `'*'` | `'+'` | `','`                  | `'-'` | `'.'`                 | `'/'` | `':'`  | `';'` | `'<'` |
| **50** | `'='` | `'>'` | `'?'` | `'@'` | `'['`  | `'\\'` | `']'` | `'^'` | `'_'` | <code>'&grave;'</code> | `'{'` | <code>'&vert;'</code> | `'}'` | `'~'`  | `' '` | `DEL` |

### 4.2.1. `c2d` &mdash; Charater To Digit
```c
#define c2d wl_c2d
#define wl_c2d(a) /* function body */
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
### 4.2.2. `d2c` &mdash; Digit To Charater
## 5. Mathematics
## 6. Memory management
## 7. Array manipulation
## 8. String manipulation