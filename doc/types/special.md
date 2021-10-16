# 1.2. Special types

```c
typedef /* type */ wl_IMax,	wl_imax;
typedef /* type */ wl_UMax,	wl_umax;
typedef /* type */ wl_Pt,   wl_pt;
```

There are 3 additional useful types defined in `<types.h>`: `Pt`, `IMax` and `UMax`

## Pointer type

`Pt` or `pt` &mdash; the pointer type. An integer type large enough to hold the reference to an object. This is intended to be used for casting the pointer value into an arithmetic type for pointer arithmetic. 

For example, take the next piece of code. In order to use arithmetic operations using pointers, we would need to convert then into an arithmetical type. After calculations, we would probably want the result value to be converted back into a pointer value.

```c
void* foo(void* p) {
	return (void*)((Pt)p+1);
}
```

`WL_USE_STDINT` macro can be defined with any non-zero value at build time, to signal WLib to implement its fixed-size integer types through `<stdint.h>`'s definitions rather than using data models.

## Maximal-width types

`IMax` or `imax` is a type for the largest available signed basic integer C type (usually 64-bits)

`UMax` or `umax` is a type for the largest avalible unsigned basic integer C type (usually 64-bits)
