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
| Size              | Unsigned     | Signed       | LP32, ILP32 | LP64, LLP64 | ILP64 | SILP64 |
|:------------------|:------------:|:------------:|:-----------:|:-----------:|:-----:|:------:|
| optimally 8 bit   | `U8`, `u8`   | `I8`, `i8`   | 8           | 8           | 8     | 8      |
| optimally 16 bit  | `U16`, `u16` | `I16`, `i16` | 16          | 16          | 16    | 64     |
| optimally 32 bit  | `U32`, `u32` | `I32`, `i32` | 32          | 32          | 64    | 64     |
| optimally 64 bit  | `U64`, `u64` | `I64`, `i64` | 64?         | 64          | 64    | 64     |
? -- While the `long long int` type has been introduced in ISO C 1999, which is at least 64-bits long, it is unknown whether LP32 and ILP32 data models' `long long int` type is at least 64 or 32 bits and may vary from system to system. Regardless, WLib tries to defined it as `long long int` anyway, when compiler with ISO C99 standard or newer.

### 2.2. Fixed-size floating-point types
### 2.3. Other types
### 2.4. Sizes
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
