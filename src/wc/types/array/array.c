#include <wc/types/array.h>

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