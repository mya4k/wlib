#ifndef WL_VECTOR_H
#define WL_VECTOR_H 1



#define vector(type, num, name)	Vc(type, num, name)
#define vectorType(name)		vct(name)



/**
 * \brief	Vector Type
 * \def		vct(n)
 * \arg		n	-- Name of the vector, declared using `vc()`
 * 
 * Gets the type of the vector, declared using `vc()`
 * 
 * \see		vc
 */
#define vct(n) wl_Vc_##n



#if WL_OPENCL_VECTOR
#	define vc(type, num, name) \
	typedef type __attribute__((ext_vector_size(num))) vct(n); \
	vct(n) name
#elif WL_GCC_VECTOR
#	define vc(type, num, name) \
	type __attribute__((vector_size(num*sizeof(type)))) name
#elif WL_GCC_BUILTIN || WL_CLANG_BUILTIN
#	define vc(type, num, name) type* name = __builtin_alloca(num*sizeof(type));
#endif



#endif
