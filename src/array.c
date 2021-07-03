#include <wc/array.h>

/**	\fn		ADEF1(aas, NO)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\brief	Assigns `s` bytes of objects of array A to array R
 *	\return	The array of object that are assigned
 */
ADEF1(aas, NO);

/**	\fn		ADEF1(ant, NT)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\brief	Performes bitwise NOT to the operand A to `s` bytes and assignes
			the result in array R
 *	\return	The array of object that have been inverted
 */
ADEF1(ant, NT);

/**	\fn		ADEF2(aan, AN)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
  *	\param	b	the operand B
 *	\brief	Performes bitwise AND to the operand A and B to `s` bytes and assignes
			the result in array R
 *	\return	The array of object that have been conjuncted
 */
ADEF2(aan, AN);

/**	\fn		ADEF2(aor, OR)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise OR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been disjuncted
 */
ADEF2(aor, OR);

/**	\fn		ADEF2(axr, XR)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise XOR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been exclusively disjuncted
 */
ADEF2(axr, XR);

/**	\fn		ADEF2(ann, NN)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
  *	\param	b	the operand B
 *	\brief	Performes bitwise NAND to the operand A and B to `s` bytes and assignes
			the result in array R
 *	\return	The array of object that have been conjuncted and inversed
 */
ADEF2(ann, NN);

/**	\fn		ADEF2(anr, NR)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise NOR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been disjuncted and inversed
 */
ADEF2(anr, NR);

/**	\fn		ADEF2(anx, NX)
 *	\param	s	size of the operands in bytes
 *	\param	r	the array where the result is stored
 *	\param	a	the operand A
 *	\param	b	the operand B
 *	\brief	Performes bitwise NXOR to the operand A and B to `s` bytes and assignes
 *			the result in array R
 *	\return	The array of object that have been exclusively disjuncted and inversed
 */
ADEF2(anx, NX);

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
	if (!a) a = mal(NULL, s);

	register const wl_U8 d = s/8;
	register const wl_U8 m = s%8;
	register U16 i = 0;

	for (; i < d; i++)
		if (((wl_U64*)a)[i] != ((wl_U64*)b)[i]) return 0;
	
	i *= 8;

	if (m&0b001) {
		if (((wl_U8*)a)[i] != ((wl_U8*)b)[i]) return 0;
		i++;
	}
	if (m&0b010) {
		if (((wl_U16*)a)[i] != ((wl_U16*)b)[i]) return 0;
		i += 2;
	}
	if (m&0b100)	{
		if (((wl_U16*)a)[i] != ((wl_U16*)b)[i]) return 0;
		i += 4;
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
 *	Method:
 *		-#	If /e a = NULL, then the array of size /e sa will be allocated
 *		-#	If /e b = NULL and /e sb = 0, then array will be filled with zeros
 *		-#	If /e sb = 0, the function does nothing and returns NULL
 *		-#	Declares a variable /e i, this is be the pointer offset
 *		-#	Assignes array /e b to array /e a offsetted by /e i, and incriments
 *			/e i by /e sb. This step is repeated until less than sb bytes are
 *			left untreated
 *		-#	Assignes the remaining part of array /e a with whatever piece of 
 *			array /e b fits
 *	\sa	wl_aas
 *	\sa wl_mal
 */
wl_Vo*	wl_afl(	register wl_U8	sa, 
				register wl_Vo*	a, 
				register wl_U8	sb, 
				register wl_Vo*	b		) {
	if (!a) a = mal(0,sa);

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
		aas(sb, a+i, b);

	aas(sa-d, a+i, b);

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
wl_U8	wl_asb(	register wl_Vo*	src,
				register wl_U8	srcSize,
				register wl_U8	_byte,
				register wl_U8	flags	) {
	/* If src is not null and the array size is greater than 0 */
	if (src && srcSize) {
		/* If SEARCH_COUNT was set */
		if (flags&SEARCH_COUNT) {
			/* Occurance count accumulator */
			wl_U8 r = 0;
			/* Search! */
			for (wl_U8 i = 0; i<srcSize; i++)
				if (*(char*)(src+i) == _byte)
					/* Yay! We found something! Incriment */
					r++;
			/* When we have searched everything, return the count */
			return r;
		} 
		/* Otherwise */
		else
			/* If SEARCH_REVERSE was set */
			if (flags&SEARCH_REVERSE) {
				register const wl_Vo* ilimit = src;
				/* Search! (but we start from the very end) */
				for (register wl_Vo* i = src+srcSize; i<ilimit; i--) {
					if (*(char*)i==_byte) {
						/* Yay! We found something! Return */
						src = i;
						return 1;
					} 
				}
				return 0;
			}
			/* Otherwise */
			else {
				/* Search! */
				register const wl_Vo* ilimit = src+srcSize;
				for (register wl_Vo* i = src; i<ilimit; i++) {
					if (*(char*)i==_byte) {
						/* Yay! We found something! Return */
						src = i;
						return 1;
					} 
				}
				return 0;
			}
	}
	/* Otherwise error */
	return !_byte;
}

/**
 * \brief 	Array search array
 * \fn		wl_U8* wl_asa(register wl_Vo* src, register wl_U8 srcSize, register wl_Vo* target, register wl_U8 targetSize, register wl_U8 flags)
 * \param	src 
 * \param	srcSize 
 * \param	target 
 * \param	targetSize 
 * \param	flags 
 * \return	wl_U8*
 * If \f$ \c (target \neq NULL) \land (targetSize \neq 0) \f$ 
 * Otherwise returns true
 */
wl_U8	wl_asa(	register wl_Vo*	src,
				register wl_U8	srcSize,
				register wl_Vo*	target,
				register wl_U8	targetSize,
				register wl_U8	flags		) {
	/* If we're actually searching for anything */
	if (target && targetSize) {
		/* If src is not null and the array size is greater than 0 */
		if (src && srcSize) {
			targetSize--;
			/* If SEARCH_COUNT was set */
			if (flags&SEARCH_COUNT) {
				/* Occurance count accumulator */
				wl_U8 r = 0;
				/* Search! */
				for (wl_Vo* i = 0; i<src+srcSize; i++) {
					/* At least one character matches target */
					if (*(char*)i == *(char*)target) {
						if (wl_aeq(targetSize, target+1, i++)) {
							r++;
							i += targetSize;
						}
					}
				}
				/* When we have searched everything, return the count */
				return r;
			}
			/* Otherwise */
		else
			/* If SEARCH_REVERSE was set */
			if (flags&SEARCH_REVERSE) {
				/* Search! */
				register const wl_Vo* ilimit = src;
				register const wl_U8 t_1 = targetSize-1;
				for (register wl_Vo* i = src+srcSize; i<ilimit; i--) {
					if (*(char*)i == *(char*)(target+targetSize)) {
						if (wl_aeq(targetSize, target-t_1, i-=t_1)) {
							src = i;
							return 1;
						}
					}
				}
				return 0;
			}
			/* Otherwise */
			else {
				/* Search! */
				register const wl_Vo* ilimit = src+srcSize;
				for (register wl_Vo* i = src; i<ilimit; i++) {
					if (*(char*)i == *(char*)target) {
						if (wl_aeq(targetSize, target+1, i++)) {
							src = i;
							return 1;
						}
					}
				}
				return 0;
			}
		}
		else return wl_aeq(targetSize, WL_AA0(targetSize), target);
	}
	/* There was nothing to find, so return true */
	else return 1;
}



#ifdef NOT_IMPLIMENTED_YET
ADEF1B(anol, NOL);	/* Array Logical No Operation */
ADEF1B(antl, NTL);	/* Array Logical NOT */
ADEF2B(aanl, ANL);	/* Array Logical AND */
ADEF2B(aorl, ORL);	/* Array Logical OR */
ADEF2B(axrl, XRL);	/* Array Logical XOR */
ADEF2B(annl, NNL);	/* Array Logical NAND */
ADEF2B(anrl, NRL);	/* Array Logical NOR */
ADEF2B(anxl, NXL);	/* Array Logical NXOR */
ADEF2B(aeq, EQ);	/* Array Equals */
ADEF2B(anq, NQ);	/* Array Not Equals */
ADEF2B(agt, GT);	/* Array Greater Than */
ADEF2B(alt, LT);	/* Array Less Than */
ADEF2B(agq, GQ);	/* Array Greater Than Or Equal */
ADEF2B(alq, LQ);	/* Array Less Than Or Equal */ 
#endif
