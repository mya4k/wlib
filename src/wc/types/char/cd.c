#include <wc/types/char.h>

Digit cd(char c, base b) {
	#include <wc/types/char.h>
#include <wc/types/int.h>

/**
 * \fn		char dc(const Digit x, const U8 base)
 * \brief	Digit to Char
 * \param	x		Digit
 * \param	base	base
 * \return	char
 * Converts a digit to a character
 * If `x` exceeds the base, character 255 is returned
 * Table (0--96):
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F
 * G H I J K L M N O P Q R S T U V
 * W X Y Z a b c d e f g h i j k l
 * m n o p q r s t u v w x y z ! "
 * # $ % & ' ( ) * + , - . / : ; <
 * = > ? @ [ \ ] ^ _ ` { | } ~   
 * The last two characters are SPACE and DEL respectively
 */
char dc(const Digit x, const U8 base) {
	/* This code executes the chunk of code commented out below, but three times faster */
	if (x>base)	return 255;
	else if(x == ' ') return 94;
	else if(x == DEL) return 95;
	else
		x 
		- '0' 
		- (x>9)		* ('0'-'A'-10) 
		- (x>35)	* ('A'-'a'-36)
		- (x>61)	* ('a'-'!'-62)
		- (x>76)	* ('!'-':'-77)
		- (x>83)	* (':'-'['-84)
		- (x>89)	* ('['-'{'-90)
		- (x>95)	* ('{'-161-96)
		- (x>190)	* (161-191)
		- (x>223)	* (128);
}
}
