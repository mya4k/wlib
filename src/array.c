#include <wc/array.h>



#ifndef NO_SHORT_NAME
#	define Af wl_Af
#endif

typedef enum wl_Af {
	WL_AF_NO = 0,
	WL_AF_AN = 1,
	WL_AF_OR = 2,
	WL_AF_XR = 3,
	WL_AF_NT = 4,
	WL_AF_NN = 5,
	WL_AF_NR = 6,
	WL_AF_NX = 7
} wl_Af;



/**
 * \brief Array Assign
 * 
 * \param a 
 * \param b 
 * \param size 
 * \return void* 
 */
void* aas(
	const void* restrict a,
	const void* restrict const b,
	const As size,
	const Af func
) {
	/* 1. Create a variable that will keep the pointer increment value. */
	As i = 0;

#	ifndef WL_AAS_SIMPLE
#		if IMB >= 64
			/* 2. The widest type is 8 bytes. Apply FUNC to every 8 bytes of 
			 * `a` and `b`, until there are less than 8 bytes left in the array
			 * `a` or `b`.
			 */
			for (; i < size&-8; i+=8) _af28(a,b);

			/* 3. If there are less than 8 bytes remaining, we can apply FUNC 
			 * on them in 3 steps.
			 * 	-	if more than or equal 2 bytes remaining, apply FUNC to 2
			 * 		bytes;
			 * 	-	after previous step, if more than 2 bytes remaining, apply
			 * 		FUNC to 2 bytes;
			 * 	-	after previous step, if there's a byte remaining, apply 
			 * 		FUNC to the last byte;
			 */
			if (size&4) { _af24(a,b); i+=4; }
			if (size&2) { _af22(a,b); i+=2; }
			if (size&1) { _af21(a,b); i+=1; }
#		else
			/* 2. The widest type is 4 bytes. Apply FUNC to every 4 bytes of 
			 * `a` and `b`, until there are less than 4 bytes left in the array
			 * `a` or `b`.
			 */
			for (; i < size&-4; i+=4) _af24(a,b);

			/* 3. If there are less than 4 bytes remaining, we can apply FUNC 
			 * on them in 2 steps.
			 * 	-	after previous step, if more than or equal 2 bytes 
			 * 		remaining, apply FUNC to 2 bytes;
			 * 	-	after previous step, if there's a byte remaining, apply 
			 * 		FUNC to the last byte;
			 */
			if (size&2) { _af22(a,b); i+=2; }
			if (size&1) { _af21(a,b); i+=1; }
#		endif
#	else
		/* 2. Apply FUNC to every byte of `a` and `b` */
		for (; i < size; i++) _af21(a,b);
#	endif
		return a;
}
