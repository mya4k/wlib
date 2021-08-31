/**
 * \file	array.c
 * \author	Wispy (wspvlv@gmail.com)
 * \brief	Array manipulation functions
 * \version	0.1
 * \date	2021-07-28
 * 
 * 
 */
#include <wc/array.h>
#include <wc/memory.h>



/**	\fn		ADEF1(aas, NO)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\brief	Assigns `s` bytes of objects of array A to array R
 *	\return	The array of object that are assigned
 */
ADEF1(wl_aas, NO);

/**	\fn		ADEF1(ant, NOT)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\brief	Performes bitwise NOT to the operand A to `s` bytes and assignes
			the result in array R
 *	\return	The array of object that have been inverted
 */
ADEF1(wl_ant, NOT);

/**	\fn		ADEF2(aan, AND)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
  *	\param	b	the operand B
 *	\brief	Performes bitwise AND to the operand A and B to `s` bytes and assignes
			the result in array R
 *	\return	The array of object that have been conjuncted
 */
ADEF2(wl_aan, AND);

/**	\fn		ADEF2(aor, OR)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise OR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been disjuncted
 */
ADEF2(wl_aor, OR);

/**	\fn		ADEF2(axr, XOR)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise XOR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been exclusively disjuncted
 */
ADEF2(wl_axr, XOR);

/**	\fn		ADEF2(ann, NAND)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
  *	\param	b	the operand B
 *	\brief	Performes bitwise NAND to the operand A and B to `s` bytes and assignes
			the result in array R
 *	\return	The array of object that have been conjuncted and inversed
 */
ADEF2(wl_ann, NAND);

/**	\fn		ADEF2(anr, NOR)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise NOR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been disjuncted and inversed
 */
ADEF2(wl_anr, NOR);

/**	\fn		ADEF2(anx, NXOR)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise NXOR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been exclusively disjuncted and inversed
 */
ADEF2(wl_anx, NXOR);

/**
 * \brief	Array equals
 * \fn		wl_aeq(register wl_U8 s, register wl_VO*	a, register wl_VO* b)
 * \param	s	Size of arrays
 * \param	a	Array A
 * \param	b	Array B
 * \return	wl_Bl 
 */
wl_Bl	wl_aeq(	register const wl_U8	s,
				register const wl_Vo*	a,
				register const wl_Vo*	b	) {
	if (!a) a = wl_mal(s);

	register const wl_U8 d = s/8;
	register const wl_U8 m = s%8;
	register wl_U8 i = 0;

	for (; i < d; i++)
		if (((wl_U64*)a)[i] != ((wl_U64*)b)[i]) return 0;
	
	i = s;

	if (m&0b100) {
		i-=4;
		if (*(wl_U32*)(a+i) != *(wl_U32*)(b+i)) return 0;
	}

	if (m&0b010) {
		i-=2;
		if (*(wl_U16*)(a+i) != *(wl_U16*)(b+i)) return 0;
	}

	if (m&0b001) {
		i--;
		if (*(wl_U8*)(a+i) != *(wl_U8*)(b+i)) return 0;
	}

	return 1;
}

/**	\fn		VO* afl(register 8 sa, register VO* a, register U8 sb, register VO* b)
 *	\param	sa	size of the array A in bytes
 *	\param	a	the array A
 *	\param	sb	size of the array B in bytes
 *	\param	b	the array B
 *	\brief	Takes two arrays and their sizes. Fills the array A with as many
 *			instances of array B as the size of array A can handle.
 *	\return	The array A
 *
 *	Method:
 *		-#	If \e a = NULL, then the array of size \e sa will be allocated
 *		-#	If \e b = NULL and \e sb = 0, then array will be filled with zeros
 *		-#	If \e sb = 0, the function does nothing and returns NULL
 *		-#	Declares a variable \e i, this is be the pointer offset
 *		-#	Assignes array \e b to array \e a offsetted by \e i, and incriments
 *			\e i by \e sb. This step is repeated until less than sb bytes are
 *			left untreated
 *		-#	Assignes the remaining part of array \e a with whatever piece of 
 *			array \e b fits
 *	\sa	wl_aas
 *	\sa wl_mal
 */
wl_Vo*	wl_afl(	register wl_U8	sa, 
				register wl_Vo*	a, 
				register wl_U8	sb, 
				register wl_Vo*	b		) {
	if (!a) a = wl_mal(sa);

	if (!sb) {
		if (b) return 0;
		else {
			wl_I64 n = 0;
			b = &n;
			sb = sizeof(n);
		}
	}

	const	wl_U16	d = sa/sb*sb;
			wl_U16	i = 0;

	for (; i<d; i+=sb)
		wl_aas(sb, a+i, b);

	wl_aas(sa-d, a+i, b);

	return a;
}

/**
 * \brief	Array search byte
 * \fn		wl_u8*	wl_asb(register wl_U8* src, register wl_U8 srcSize, register wl_U8 _byte);
 * \param	src		Source array
 * \param	srcSize	Array size
 * \param	_byte	Byte to find
 * \param	flags	Flags
 * \return	wl_u8* 
 * 
 * Searches for the occurance of \p _byte in anywhere in \p src .
 * -	If \c SEARCH_COUNT flag was not set, the function returns true, if any
 * 		occurance was found, false otherwise
 * -	If no flags were provided the algorithm searches for the first \p _byte
 * 		and stores in location in \p srcSize
 * -	If \c SEARCH_RESERVE flag is set, the address of last occurance will be
 *		stored in \p srcSize
 * -	If nothing was found (unless \c SEARCH_COUNT flag is set) \p srcSize
 * 		will be a null pointer
 * -	If \c SEARCH_COUNT flag is set, \p srcSize won't change, but the
 * 		function will return the amount of occurances
 * Regardless of flags used, if any occurance was found the function will
 * return a true (>0) value, and false (0) otherwise
 * \attention Even if \p src is NULL or \p srcSize = 0, function will return
 * true if _byte is 0, otherwise false. (Basically it will try to find _byte 
 * in 0). \p srcSize will never change in this context.
 */
wl_Vopu	wl_asb(	register wl_Vo*	src,
				register wl_U8	srcSize,
				register wl_U8	_byte,
				register wl_U8	flags	) {
	/* If src is not null and the array size is greater than 0 */
	if (src && srcSize) {
		/* If SEARCH_COUNT was set */
		if (flags&SEARCH_COUNT) {
			/* Occurance count accumulator */
			wl__Ptr r = 0;
			/* Search! */
			wl_U8* ilimit = src+srcSize;
			for (wl_U8* i = src; i<ilimit; i++)
				if (*i == _byte)
					/* Yay! We found something! Incriment */
					r++;
			/* When we have searched everything, return the count */
			return (wl_Vopu)r;
		} 
		/* Otherwise */
		else
			/* If SEARCH_REVERSE was set */
			if (flags&SEARCH_REVERSE) {
				register const wl_U8* ilimit = src;
				/* Search! (but we start from the very end) */
				for (register wl_U8* i = src+srcSize; i>ilimit; i -= 1) {
					if (*(char*)i==_byte) {
						return (wl_Vopu)i;
					} 
				}
				return (wl_Vopu)0;
			}
			/* Otherwise */
			else {
				/* Search! */
				register const wl_U8* ilimit = src+srcSize;
				for (register wl_U8* i = src; i<ilimit; i += 1) {
					if (*i==_byte) {
						/* Yay! We found something! Return */
						return (wl_Vopu)i;
					}
				}
				return (wl_Vopu)0;
			}
	}
	/* Otherwise error */
	return (wl_Vopu)(wl__Ptr)!_byte;
}

/**
 * \brief 	Array search array
 * \fn		wl_U8* wl_asa(register wl_Vo* src, register wl_U8 srcSize, register wl_Vo* target, register wl_U8 targetSize, register wl_U8 flags)
 * 
 * \param	src			Source array
 * \param	srcSize		Source array size
 * \param	target		Array to find
 * \param	targetSize	target array size
 * \param	flags 		Flags
 * \return	wl_U8*
 * 
 * If \f$(target \neq NULL) \land (targetSize \neq 0)\f$ 
 * Otherwise returns true
 */
wl_Vopu	wl_asa(	register wl_Vo*				src,
				register wl_U8				srcSize,
				register wl_Vo*				target,
				register wl_U8				targetSize,
				register WL_SEARCH_FLAGS	flags		) {
	/* If we're actually searching for anything */
	if (target && targetSize) {
		/* If src is not null and the array size is greater than 0 */
		if (src && srcSize) {
			targetSize--;
			/* If SEARCH_COUNT was set */
			if (flags&SEARCH_COUNT) {
				/* Occurance count accumulator */
				wl__Ptr r = 0;
				/* Search! */
				wl_U8* ilimit = src+srcSize;

				if (targetSize)
					for (wl_U8* i = src; i<ilimit; i++) {
						/* At least one character matches target */
						if (*i == *(wl_U8*)target) {
							if (wl_aeq(targetSize, target+1, i++)) {
								r++;
								i += targetSize;
							}
						}
					}
				else
					for (wl_U8* i = src; i<ilimit; i++)
						/* At least one character matches target */
						if (*i == *(wl_U8*)target) 
							r++;

				/* When we have searched everything, return the count */
				return (wl_Vopu)r;
			}
			/* Otherwise */
		else
			/* If SEARCH_REVERSE was set */
			if (flags&SEARCH_REVERSE) {
				/* Search! */
				register const wl_U8* ilimit = src;
				register const wl_U8 t_1 = targetSize-1;
				for (register wl_U8* i = src+srcSize; i>ilimit; i--) {
					if (*i == *(char*)(target+targetSize)) {
						if (wl_aeq(targetSize, target-t_1, i-=t_1)) {
							return (wl_Vopu)i;
						}
					}
				}
				return (wl_Vopu)0;
			}
			/* Otherwise */
			else {
				/* Search! */
				register const wl_U8* ilimit = src+srcSize;
				for (register wl_U8* i = src; i<ilimit; i++) {
					if (*(char*)i == *(char*)target) {
						if (wl_aeq(targetSize, target+1, i++)) {
							return (wl_Vopu)i;
						}
					}
				}
				return (wl_Vopu)0;
			}
		}
		else return (wl_Vopu)wl_aeq(targetSize, WL_AA0(targetSize), target);
	}
	/* There was nothing to find, so return true */
	return (wl_Vopu)1;
}



#ifdef NOT_IMPLIMENTED_YET
ADEF1B(wl_anol, NOL);	/* Array Logical No Operation */
ADEF1B(wl_antl, NTL);	/* Array Logical NOT */
ADEF2B(wl_aanl, ANL);	/* Array Logical AND */
ADEF2B(wl_aorl, ORL);	/* Array Logical OR */
ADEF2B(wl_axrl, XRL);	/* Array Logical XOR */
ADEF2B(wl_annl, NNL);	/* Array Logical NAND */
ADEF2B(wl_anrl, NRL);	/* Array Logical NOR */
ADEF2B(wl_anxl, NXL);	/* Array Logical NXOR */
ADEF2B(wl_aeq, EQ);		/* Array Equals */
ADEF2B(wl_anq, NQ);		/* Array Not Equals */
ADEF2B(wl_agt, GT);		/* Array Greater Than */
ADEF2B(wl_alt, LT);		/* Array Less Than */
ADEF2B(wl_agq, GQ);		/* Array Greater Than Or Equal */
ADEF2B(wl_alq, LQ);		/* Array Less Than Or Equal */ 
#endif
