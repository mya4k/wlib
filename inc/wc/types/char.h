/****************************
 * Character type utilities	*
 * Wispy (c) 2021			*
 ****************************/

#ifndef WC_CHAR_H
#define WC_CHAR_H

#include <wc/core.h>
#include <wc/types.h>

/* Control characters */
#undef	NUL
#define	NUL	'\000'
#undef	SOH
#define	SOH	'\001'
#undef	STX
#define	STX	'\002'
#undef	ETX
#define	ETX	'\003'
#undef	EOT
#define	EOT	'\004'
#undef	ENQ
#define	ENQ	'\005'
#undef	ACK
#define	ACK	'\006'
#undef	BEL
#define	BEL	'\007'
#undef	BS
#define	BS	'\010'
#undef	HT
#define	HT	'\011'
#undef	LF
#define	LF	'\012'
#undef	VT
#define	VT	'\013'
#undef	FF
#define	FF	'\014'
#undef	CR
#define	CR	'\015'
#undef	SO
#define	SO	'\016'
#undef	SI
#define	SI	'\017'
#undef	DLE
#define	DLE	'\020'
#undef	DC1
#define	DC1	'\021'
#undef	DC2
#define	DC2	'\022'
#undef	DC3
#define	DC3 '\023'
#undef	DC4
#define	DC4	'\024'
#undef	NAK
#define	NAK	'\025'
#undef	SYN
#define	SYN	'\026'
#undef	ETB
#define	ETB	'\027'
#undef	CAN
#define	CAN	'\030'
#undef	EM
#define	EM	'\031'
#undef	SUB
#define	SUB	'\032'
#undef	ESC
#define	ESC	'\033'
#undef	FS
#define	FS	'\034'
#undef	GS
#define	GS	'\035'
#undef	RS
#define	RS	'\036'
#undef	US
#define	US	'\037'
#undef	DEL
#define	DEL	'\177'



C_DECL_BEGIN
/*--- Boolean Functions ---------------------------------*/
BL iLc(char a);	/* Is Lowercase Character	*/
BL iUc(char a);	/* Is Uppercase Character	*/
BL iac(char a);	/* Is Alphanumeric Character*/
BL icc(char a);	/* Is Contol Character		*/
BL idc(char a);	/* Is Digit Character		*/
BL ilc(char a);	/* Is Letter Character		*/
BL isc(char a);	/* Is Symbol Character		*/
BL iwc(char a);	/* Is Whitespace Character	*/



/*--- Essential Functions -------------------------------*/

/* [String length]
 * Arguments:
 * char*	str	-- String
 * 
 * Description:
 * Calculates the length of a given null-terminated string in characters, 
 * including the NUL character
 * 
 * Method:
 * Let "i" represent the length of the string. Check every character whether 
 * it's NUL, if it's not NUL then "i" increases by 1, otherwise function 
 * returns the value of "i".
 */
U32 sln(char* str);



C_DECL_END

#endif