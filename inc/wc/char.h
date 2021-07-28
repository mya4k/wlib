/**
 * \file char.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Macro for special characters and functions for character manipulation
 * \version 0.1
 * \date 2021-07-27
 * Content:
 * 	Macros:		WL_NUL, WL_SOH, WL_STX, WL_ETX, WL_EOT, 
 * 				WL_ENQ, WL_ACK, WL_BEL, WL_BS, WL_HT, 
 * 				WL_LF, WL_VT, WL_FF, WL_CR, WL_SO, WL_SI, 
 * 				WL_DLE, WL_DC1, WL_DC2, WL_DC3, WL_DC4, 
 * 				WL_NAK, WL_SYN, WL_ETB, WL_CAN, WL_EM, 
 * 				WL_SUB, WL_ESC, WL_FS, WL_GS, WL_RS, WL_US,
 * 				WL_DEL, wl_lens
 *	Typedefs:	wl_Lens
 * 	Functions:	wl_lens
 * 
 */
#ifndef WC_CHAR_H
#define WC_CHAR_H



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
#	define Lens		wl_Lens
#	define lens		wl_lens
#endif



#ifndef REGION_CONTROL_CHARS
/**
 * \def		WL_NUL
 * \brief	Null (x00)
 */
#	define WL_NUL	'\000'
/**
 * \def		WL_SOH
 * \brief	Start of Heading (x01)
 */
#	define WL_SOH	'\001'
/**
 * \def		WL_STX
 * \brief	Start of Text (x02)
 */
#	define WL_STX	'\002'
/**
 * \def		WL_ETX
 * \brief	End of Text (x03)
 */
#	define WL_ETX	'\003'
/**
 * \def		WL_EOT
 * \brief	End of Transmission (x04)
 */
#	define WL_EOT	'\004'
/**
 * \def		WL_ENQ
 * \brief	Enquiry (x05)
 */
#	define WL_ENQ	'\005'
/**
 * \def		WL_ACK
 * \brief	Acknowledge (x06)
 */
#	define WL_ACK	'\006'
/**
 * \def		WL_BEL
 * \brief	Bell (x07)
 */
#	define WL_BEL	'\007'
/**
 * \def		WL_BS
 * \brief	Backspace (x08)
 */
#	define WL_BS	'\010'
/**
 * \def		WL_HT
 * \brief	Horizontattention textal Tabulation (x09)
 */
#	define WL_HT	'\011'
/**
 * \def		WL_LF
 * \brief	New Line (x0A)
 */
#	define WL_LF	'\012'
/**
 * \def		WL_VT
 * \brief	Vertical Tabulation (x0B)
 */
#	define WL_VT	'\013'
/**
 * \def		WL_FF
 * \brief	Form Feed (x0C)
 */
#	define WL_FF	'\014'
/**
 * \def		WL_CR
 * \brief	Carriage Return (x0D)
 */
#	define WL_CR	'\015'
/**
 * \def		WL_SO
 * \brief	Shift Out (x0E)
 */
#	define WL_SO	'\016'
/**
 * \def		WL_SI
 * \brief	Shift In (x0F)
 */
#	define WL_SI	'\017'
/**
 * \def		WL_DLE
 * \brief	Data Link Escape (x10)
 */
#	define WL_DLE	'\020'
/**
 * \def		WL_DC1
 * \brief	Device Control 1 (x11)
 */
#	define WL_DC1	'\021'
/**
 * \def		WL_DC2
 * \brief	Device Control 2 (x12)
 */
#	define WL_DC2	'\021'
/**
 * \def		WL_DC3
 * \brief	Device Control 3 (x13)
 */
#	define WL_DC3	'\021'
/**
 * \def		WL_DC4
 * \brief	Device Control 4 (x14)
 */
#	define WL_DC4	'\021'
/**
 * \def		WL_NAK
 * \brief	Negative Acknowledge (x15)
 */
#	define WL_NAK	'\025'
/**
 * \def		WL_SYN
 * \brief	Synchronous Idle (x16)
 */
#	define WL_SYN	'\026'
/**
 * \def		WL_ETB
 * \brief	End of Transmission Block (x17)
 */
#	define WL_ETB	'\027'
/**
 * \def		WL_CAN
 * \brief	Cancel (x18)
 */
#	define WL_CAN	'\030'
/**
 * \def		WL_EM
 * \brief	End of Medium (x19)
 */
#	define WL_EM	'\031'
/**
 * \def		WL_SUB
 * \brief	Substitute (x1A)
 */
#	define WL_SUB	'\032'
/**
 * \def		WL_ESC
 * \brief	Escape (x1B)
 */
#	define WL_ESC	'\033'
/**
 * \def		WL_FS
 * \brief	File Separator (x1C)
 */
#	define WL_FS	'\034'
/**
 * \def		WL_GS
 * \brief	Group Separator (x1D)
 */
#	define WL_GS	'\035'
/**
 * \def		WL_RS
 * \brief	Record Separator (x1E)
 */
#	define WL_RS	'\036'
/**
 * \def		WL_US
 * \brief	Unit Separator (x1F)
 */
#	define WL_US	'\037'
/**
 * \def		WL_DEL
 * \brief	Delete (x7F)
 */
#	define WL_DEL	'\177'
#endif

#ifndef REGION_CHAR
/**
 * \brief	Is Lowercase Character
 * \def		wl_cilc(a)
 * \param	a	character
 * \return	True, if character is a lowercase letter, false, otherwise
 */
#	define wl_cilc(a) ((a) >= 'a' && (a) <= 'z')					/* Is Lowercase Character	*/
/**
 * \brief	Is Uppercase Character
 * \def		wl_ciuc(a)
 * \param	a	character
 * \return	True, if character is an uppercase letter, false otherwise
 */
#	define wl_ciuc(a) ((a) >= 'A' && (a) <= 'Z')					/* Is Uppercase Character	*/
/**
 * \brief	Is Contol Character
 * \def		wl_cic(a)
 * \param	a	character
 * \return	True, if character is a control character, false otherwise
 */
#	define wl_cic(a) ((a) < ' ' || (a) == WL_DEL)					/* Is Contol Character		*/
/**
 * \brief	Is Digit Character
 * \def		wl_cid(a)
 * \param	a	character
 * \return	True, if character is a decimal digit character, false otherwise
 */
#	define wl_cid(a) ((a) >= '0' && (a) <= '9')						/* Is Digit Character		*/
/**
 * \brief	Is Symbol Character
 * \def		wl_cis(a)
 * \param	a	character
 * \return	True, if character is a symbol character, false otherwise
 */
#	define wl_cis(a)												/* Is Symbol Character		*/\
	((a) >= '!' && (a) <= '/' || (a) >= ':' && (a) <= '@' || (a) >= '[' && (a) <= '`' || (a) >= '{' && (a) <= '~')
/**
 * \brief	Is Whitespace Character
 * \def		wl_ciw(a)
 * \param	a	character
 * \return	True, if character is a whitespace character, false otherwise
 */
#	define wl_ciw(a) ((a) >= WL_HT && (a) <= WL_CR || (a) == ' ')	/* Is Whitespace Character	*/
/**
 * \brief	Is Ext. ASCII Character
 * \def		wl_cie(a)
 * \param	a	character
 * \return	True, if character from extended character set, false otherwise
 */
#	define wl_cie(a) ((a) > WL_DEL)									/* Is Ext. ASCII Character	*/
/**
 * \brief	Is Alphanumeric Character
 * \def		wl_cia(a)
 * \param	a	character
 * \return	True, if character is an alphanumeric character, false otherwise
 */
#	define wl_cia(a) (wl_cil(a) || wl_cid(a))						/* Is Alphanumeric Character*/
/**
 * \brief	Is Letter Character
 * \def		wl_cil(a)
 * \param	a	character
 * \return	True, if character is a letter, false otherwise
 */
#	define wl_cil(a) (wl_cilc(a) || wl_ciuc(a))						/* Is Letter Character		*/
/**
 * \brief	Character To Lowercase
 * \def		wl_c2l(a)
 * \param	a	character
 * \return	\a a or its modified value
 * If the character is uppercase, changes its case and returns it, otherwise returns \a
 */
#	define wl_c2l(a) ((a) - wl_ciuc(a)*32)
/**
 * \brief	Character To Uppercase
 * \def		wl_c2u(a)
 * \param	a	character
 * \return	\a a or its modified value
 * If the character is lowercase, changes its case and returns it, otherwise returns \a
 */
#	define wl_c2u(a) ((a) + wl_cilc(a)*32)
/**
 * \def		wl_c2d(chr, base)
 * \brief	char to wl_Digit
 * \param	x		Digit
 * \param	base	base
 * \return	wl_Digit
 * \attention Despite being heavily optimized, it still takes about 30 instructions
 * Converts a charcter representing a digit to a digit
 * If result exceeds the base, character 255 is returned
 * Table (0—95):
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F
 * G H I J K L M N O P Q R S T U V
 * W X Y Z a b c d e f g h i j k l
 * m n o p q r s t u v w x y z ! "
 * # $ % & ' ( ) * + , - . / : ; <
 * = > ? @ [ \ ] ^ _ ` { | } ~   
 *                             ↑ ↑
 *                         SPACE DEL
 */
#define wl_c2d(x) (							\
	(x)	- (94-(x))	*((x)==' ')				\
		- (95-(x))	*((x)==127)				\
		- 32		*((x)<0)				\
		+ 96		*((x)<' '&&(x)>0)		\
		+ 29		*((x)<'0'&&(x)>=' ')	\
		- 48		*((x)<':'&&(x)>='0')	\
		+ 19		*((x)<'A'&&(x)>=':')	\
		- 55		*((x)<'['&&(x)>='A')	\
		- 7			*((x)<'a'&&(x)>='[')	\
		- 61		*((x)<'{'&&(x)>='a')	\
		- 33		*((x)<127&&(x)>='{')	\
)

#endif

#ifndef REGION_STRING
#ifdef USE_STDLIB
#	include <string.h>
#	include <limits.h>

	/**
	 * \brief	Maximal value of wl_Lens
	 * \def		WL_LENS_MAX
	 */
#	define WL_LENS_MAX	SIZE_MAX

	/**
	 * \brief	String length type
	 * \typedef	wl_Lens
	 * Size:	2 bytes (16 bits)
	 */
	typedef size_t	wl_StrSize;

	/**
	 *	\def		wl_lens(STR)
	 *	\brief		String length
	 *	\arg		STR String
	 *	\return 	size_t
	 *	Method:
	 *	strlen(STR)
	 */
#	define wl_lens(STR)	strlen(STR)
#else
#	include <core.h>
	/**
	 * \brief	Maximal value of wl_Lens
	 * \def		WL_LENS_MAX
	 */
#	define WL_LENS_MAX	(wl_StrSize)WL_U16X

	/**
	 * \brief	String length type
	 * \typedef	wl_Lens
	 * Size:	2 bytes (16 bits)
	 */
	typedef wl_U16	wl_Lens;

	EXTERN wl_Lens wl_lens(const char* str);	/* String length */
#endif
#endif

#endif