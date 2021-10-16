# 1.3. Compatibility types

```c
typedef /* type */	Vo, vo;
typedef /* type */	Bl, bl;
```

`void` type has been added by the ANSI C standard (which means it may not have been supported by pre-standard compilers), WLib defines `Vo` and `vo` types. However, in the implementation of any WLib identifier or a function (except the definition of `Vo` and `vo` types themselves) use of `void` type as-is is allowed, even interchangeably; therefore, `Vo` and `vo` types are mostly viewed as aliases.

While `_Bool` type has only been introduced ten years later with an ISO C 1999 revision. `Bl` or `bl` type ensures to use of the type will not generate any error or warnings and will act as a boolean type for the most part for compilers set to comply with a standard revision prior to `_Bool`'s debut. More specifically `Bl` is defined as the smallest available data type (any 8-bit type), where any non-zero value is considered true and false otherwise. In C++ the default boolean type is `bool`, not `_Bool`, therefore, `Bl` and `bl` are also defined accordingly to the language used.
