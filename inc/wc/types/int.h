/**
 * @file		types/int.h
 * @author		Wispy
 * @brief		Numeric properties operations
 * @version		0.1
 * @date		2021-04-11
 * @copyright	Wispy (c) 2021
 */
#ifndef WC_INT_H
#define WC_INT_H

#include <wc/types.h>

#undef	digitToChar
#define digitToChar		dc
#undef	digitCount
#define	digitCount		dcu
#undef	digitGet
#define	digitGet		dgu
#undef	digitSet
#define digitSet		dsu
#undef	U32ToString		
#define U32ToString		uS
#undef	I32ToString		
#define I32ToString		iS
#undef	U64ToString		
#define U64ToString		qS
#undef	I64ToString			
#define I64ToString		lS

/**
 * @typedef	Dg
 * @brief	Digit type
 * Digits are intended to hold a single digit
 */
/**
 * @typedef	Digit
 * @brief	Digit type
 * Digits are intended to hold a single digit
 */
typedef U8 Dg, Digit;

/**
 * \fn		char dc(const Digit x, const U8 base)
 * \brief	Digit to Char
 * \param	x		Digit
 * \param	base	base
 * \return	char
 * Converts a number into a character representation of a digit
 * If `x` exceeds the base, DEL character is returned
 * Table (0--96):
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F
 * G H I J K L M N O P Q R S T U V
 * W X Y Z a b c d e f g h i j k l
 * m n o p q r s t u v w x y z ! "
 * # $ % & ' ( ) * + , - . / : ; <
 * = > ? @ [ \ ] ^ _ ` { | } ~   
 * The last two characters are SPACE and DEL respectively
 */
char dc(const Digit x, const U8 base);

/**
 * @fn			U8 dcu(const U32 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcu(const U32 x, const U8 base);

/**
 * @fn			U8 dcq(const U64 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcq(const U64 x, const U8 base);

/**
 * @fn			U8 dci(const U32 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dci(const U32 x, const U8 base);

/**
 * @fn			U8 dcl(const U64 x, const U8 base)
 * @brief 		Counts digits in base
 * @param x		The number
 * @param base 	The base
 * @return U8	
 */
U8 dcl(const U64 x, const U8 base);

/**
 * @fn			Digit dgu(const U32 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgu(const U32 x, const U8 n, const U8 base);

/**
 * @fn			Digit dgq(const U64 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgq(const U64 x, const U8 n, const U8 base);

/**
 * @fn			Digit dgi(const I32 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgi(const I32 x, const U8 n, const U8 base);

/**
 * @fn			Digit dgl(const I64 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgl(const I64 x, const U8 n, const U8 base);

/* U32 to string */
char* uS(U32	x, ch* str, const U8 flags);
/* U64 to string */
char* qS(U64	x, ch* str, const U8 flags);
/* I32 to string */
char* iS(I32	x, ch* str, const U8 flags);
/* I64 to string */
char* lS(I64	x, ch* str, const U8 flags);

#endif
