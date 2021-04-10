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