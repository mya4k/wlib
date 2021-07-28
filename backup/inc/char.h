/**
 * \file char.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Macro for special characters and functions for character manipulation
 * \version 0.1
 * \date 2021-06-29
 * Content:
 * 	Macros:		WL_NUL, WL_SOH, WL_STX, WL_ETX, WL_EOT, 
 * 				WL_ENQ, WL_ACK, WL_BEL, WL_BS, WL_HT, 
 * 				WL_LF, WL_VT, WL_FF, WL_CR, WL_SO, WL_SI, 
 * 				WL_DLE, WL_DC1, WL_DC2, WL_DC3, WL_DC4, 
 * 				WL_NAK, WL_SYN, WL_ETB, WL_CAN, WL_EM, 
 * 				WL_SUB, WL_ESC, WL_FS, WL_GS, WL_RS, WL_US,
 * 				WL_DEL, wl_lens
 *	Typedefs:	wl_StrSize
 * 	Functions:	wl_lens
 * 
 */


#ifndef WC_CHAR_H
#define WC_CHAR_H



#include <wc/types.h>	/* Types */
#include <wc/core.h>	/* C & C++ compatibility */



/*--- Convinient aliases --------------------------------*/
#ifndef NO_SHORT_NAMES
#	define NUL		WL_NUL
#	define SOH		WL_SOH
#	define STX		WL_STX
#	define ETX		WL_ETX
#	define EOT		WL_EOT
#	define ENQ		WL_ENQ
#	define ACK		WL_ACK
#	define BEL		WL_BEL
#	define BS		WL_BS
#	define HT		WL_HT
#	define LF		WL_LF
#	define VT		WL_VT
#	define FF		WL_FF
#	define CR		WL_CR
#	define SO		WL_SO
#	define SI		WL_SI
#	define DLE		WL_DLE
#	define DC1		WL_DC1
#	define DC2		WL_DC2
#	define DC3		WL_DC3
#	define DC4		WL_DC4
#	define NAK		WL_NAK
#	define SYN		WL_SYN
#	define ETB		WL_ETB
#	define CAN		WL_CAN
#	define EM		WL_EM
#	define SUB		WL_SUB
#	define ESC		WL_ESC
#	define FS		WL_FS
#	define GS		WL_GS
#	define RS		WL_RS
#	define US		WL_US
#	define DEL		WL_DEL
#	define cilc		wl_cilc
#	define cius		wl_cius
#	define cic		wl_cic
#	define cid		wl_cid
#	define cis		wl_cis
#	define ciw		wl_ciw
#	define cie		wl_cie
#	define cia		wl_cia
#	define cil		wl_cil
#	define c2l		wl_c2l
#	define c2u		wl_c2u
#	define c2d		wl_c2d
#	define StrSize	wl_StrSize
#	define lens		wl_lens
#endif



/*--- Control characters --------------------------------*/
/**
 * \def		WL_NUL
 * \brief	Null (x00)
 */
#define WL_NUL	'\000'

/**
 * \def		WL_SOH
 * \brief	Start of Heading (x01)
 */
#define WL_SOH	'\001'

/**
 * \def		WL_STX
 * \brief	Start of Text (x02)
 */
#define WL_STX	'\002'

/**
 * \def		WL_ETX
 * \brief	End of Text (x03)
 */
#define WL_ETX	'\003'

/**
 * \def		WL_EOT
 * \brief	End of Transmission (x04)
 */
#define WL_EOT	'\004'

/**
 * \def		WL_ENQ
 * \brief	Enquiry (x05)
 */
#define WL_ENQ	'\005'

/**
 * \def		WL_ACK
 * \brief	Acknowledge (x06)
 */
#define WL_ACK	'\006'

/**
 * \def		WL_BEL
 * \brief	Bell (x07)
 */
#define WL_BEL	'\007'

/**
 * \def		WL_BS
 * \brief	Backspace (x08)
 */
#define WL_BS	'\010'

/**
 * \def		WL_HT
 * \brief	Horizontattention textal Tabulation (x09)
 */
#define WL_HT	'\011'

/**
 * \def		WL_LF
 * \brief	New Line (x0A)
 */
#define WL_LF	'\012'

/**
 * \def		WL_VT
 * \brief	Vertical Tabulation (x0B)
 */
#define WL_VT	'\013'

/**
 * \def		WL_FF
 * \brief	Form Feed (x0C)
 */
#define WL_FF	'\014'

/**
 * \def		WL_CR
 * \brief	Carriage Return (x0D)
 */
#define WL_CR	'\015'

/**
 * \def		WL_SO
 * \brief	Shift Out (x0E)
 */
#define WL_SO	'\016'

/**
 * \def		WL_SI
 * \brief	Shift In (x0F)
 */
#define WL_SI	'\017'

/**
 * \def		WL_DLE
 * \brief	Data Link Escape (x10)
 */
#define WL_DLE	'\020'

/**
 * \def		WL_DC1
 * \brief	Device Control 1 (x11)
 */
#define WL_DC1	'\021'

/**
 * \def		WL_DC2
 * \brief	Device Control 2 (x12)
 */
#define WL_DC2	'\021'

/**
 * \def		WL_DC3
 * \brief	Device Control 3 (x13)
 */
#define WL_DC3	'\021'

/**
 * \def		WL_DC4
 * \brief	Device Control 4 (x14)
 */
#define WL_DC4	'\021'

/**
 * \def		WL_NAK
 * \brief	Negative Acknowledge (x15)
 */
#define WL_NAK	'\025'

/**
 * \def		WL_SYN
 * \brief	Synchronous Idle (x16)
 */
#define WL_SYN	'\026'

/**
 * \def		WL_ETB
 * \brief	End of Transmission Block (x17)
 */
#define WL_ETB	'\027'

/**
 * \def		WL_CAN
 * \brief	Cancel (x18)
 */
#define WL_CAN	'\030'

/**
 * \def		WL_EM
 * \brief	End of Medium (x19)
 */
#define WL_EM	'\031'

/**
 * \def		WL_SUB
 * \brief	Substitute (x1A)
 */
#define WL_SUB	'\032'

/**
 * \def		WL_ESC
 * \brief	Escape (x1B)
 */
#define WL_ESC	'\033'

/**
 * \def		WL_FS
 * \brief	File Separator (x1C)
 */
#define WL_FS	'\034'

/**
 * \def		WL_GS
 * \brief	Group Separator (x1D)
 */
#define WL_GS	'\035'

/**
 * \def		WL_RS
 * \brief	Record Separator (x1E)
 */
#define WL_RS	'\036'

/**
 * \def		WL_US
 * \brief	Unit Separator (x1F)
 */
#define WL_US	'\037'

/**
 * \def		WL_DEL
 * \brief	Delete (x7F)
 */
#define WL_DEL	'\177'



/*--- Macro functions ------------------------------------*/
/**
 * \def		wl_c2d(chr, base)
 * \brief	char to wl_Digit
 * \param	x		Digit
 * \param	base	base
 * \return	wl_Digit
 * \attention Despite being heavily optimized, it still takes about 30 instructions
 * Converts a charcter representing a digit to a digit
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
#define wl_c2d(chr, base)						\
	(chr>base ? 0xFF : (						\
		x==' ' ? 94 : (							\
			x==WL_DEL ? 95 : (					\
				x	- '0'		* ('0'-'A'-10)	\
					- (x>9)		* ('A'-'a'-36)	\
					- (x>61)	* ('a'-'!'-62)	\
					- (x>76)	* ('!'-':'-77)	\
					- (x>83)	* (':'-'['-84)	\
					- (x>89)	* ('['-'{'-90)	\
					- (x>95)	* ('{'-161-96)	\
					- (x>190)	* (161-191)		\
					- (x>223)	* (128)			\
			)									\
		)										\
	))



/*--- Types ---------------------------------------------*/
/**
 * \typedef		wl_StrSize
 * \brief		String size type
 * \attention	8-bits
 */
typedef wl_U8 wl_StrSize;



/*--- Boolean Functions ---------------------------------*/
#define wl_cilc(a) ((a) >= 'a' && (a) <= 'z')					/* Is Lowercase Character	*/
#define wl_ciuc(a) ((a) >= 'A' && (a) <= 'Z')					/* Is Uppercase Character	*/
#define wl_cic(a) ((a) < ' ' || (a) == WL_DEL)					/* Is Contol Character		*/
#define wl_cid(a) ((a) >= '0' && (a) <= '9')					/* Is Digit Character		*/
#define wl_cis(a) 												/* Is Symbol Character		*/	\
	((a) >= '!' && (a) <= '/' || (a) >= ':' && (a) <= '@' || (a) >= '[' && (a) <= '`' || (a) >= '{' && (a) <= '~')
#define wl_ciw(a) ((a) >= WL_HT && (a) <= WL_CR || (a) == ' ')	/* Is Whitespace Character	*/
#define wl_cie(a) ((a) > WL_DEL)								/* Is Ext. ASCII Character	*/
#define wl_cia(a) (wl_cil(a) || wl_cid(a))						/* Is Alphanumeric Character*/
#define wl_cil(a) (wl_cilc(a) || wl_ciuc(a))					/* Is Letter Character		*/
#define wl_c2l(a) ((a) - wl_ciuc(a)*0x20)						/* Character To Lowercase	*/
#define wl_c2u(a) ((a) + wl_cilc(a)*0x20)						/* Character To Uppercase	*/



/*--- Essential Functions -------------------------------*/
#ifdef USE_STDLIB
#	include <string.h>
	/**
	 *	\def		WL_wl_lens(STR)
	 *	\brief		String length
	 *	\arg		STR String
	 *	\return 	size_t
	 *	Method:
	 *	strlen(STR)
	 */
#	define wl_lens(STR)	strlen(STR)
#else
	/**
	 *	\fn			_StrSize wl_lens(const char* str)
	 *	\brief		String length
	 *	\arg		str String
	 *	\return 	_StrSize
	 *	\attention	By default _StrSize is 8-bits, therefore it only supports strings less than 256 characters in length
	 *	Method:
	 *	1. i = 0; (Get a varible)
	 *	2. while (str[i] != CH_NUL) i = i+1; (Check every character and incriment the `i` until the character is null)
	 *	3. return i; (Return the length of the string)
	 */
	EXTERN wl_StrSize	wl_lens	(const char* str);
#endif



#endif