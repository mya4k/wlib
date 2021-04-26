/********************************
 * Character type operations	*
 * Wispy (c) 2021				*
 ********************************/
#ifndef WC_CHAR_H
#define WC_CHAR_H



#include <wc/core.h>
#include <wc/types.h>
#include <wc/types/int.h>



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

/*--- DEFINED -------------------------------------------*/
#undef	SS_NOT_FOUND
#define SS_NOT_FOUND	255		/* String search failure	*/
#undef	CS_REVERSE	
#define CS_REVERSE		1		/* Search from the end		*/
#undef	S_DEC
#define S_DEC			0b00	/* Decimal					*/
#undef	S_BIN
#define S_BIN			0b01	/* Binary					*/
#undef	S_OCT
#define S_OCT			0b10	/* Octal					*/
#undef	S_HEX
#define S_HEX			0b11	/* Hexadecimal				*/



/*--- Boolean Functions ---------------------------------*/
#define iL(a) (a >= 'a' && a <= 'z')			/* Is Lowercase Character	*/
#define iU(a) (a >= 'A' && a <= 'Z')			/* Is Uppercase Character	*/
#define ic(a) (a < ' ' || a == DEL)				/* Is Contol Character		*/
#define id(a) (a >= '0' && a <= '9')			/* Is Digit Character		*/
#define is(a) 								\	/* Is Symbol Character		*/
	(a >= '!' && a <= '/' || a >= ':' && a <= '@' || a >= '[' && a <= '`' || a >= '{' && a <= '~')
#define iw(a) (a >= HT && a <= CR || a == ' ')	/* Is Whitespace Character	*/
#define ie(a) (a > DEL)							/* Is Ext. ASCII Character	*/
#define ia(a) (il(a) || id(a))					/* Is Alphanumeric Character*/
#define il(a) (iL(a) || iU(a))					/* Is Letter Character		*/



C_DECL_BEGIN
/*--- Essential Functions -------------------------------*/
/* String length */
Dg cd(const unsigned char x, const U8 base);
/* Char search */
U8 cs(register const char* str, register char find, u8 flags);
/* String length */
U8 sl(register const char* str);
/* String search */
u8 ss(const char* str, const char* find);
/* Hash */
U8 hs(const char* str, const char** set, const u8 size);
C_DECL_END



#endif
