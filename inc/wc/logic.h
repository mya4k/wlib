/**
 * \file logic.h
 * \author Wispy (wspvlv@gmail.com)
 * \brief Logic gates
 * \version 0.1
 * \date 2021-07-26
 * 
 * 
 */



#ifndef WC_LOGIC_H
#define WC_LOGIC_H



#include <wc/types.h>



#ifndef NO_SHORT_NAMES
#	define	ADD		WL_ADD
#	define	ADDA	WL_ADDA
#	define	AND		WL_AND
#	define	ANDA	WL_ANDA
#	define	ANDL	WL_ANDL
#	define	ANDLA	WL_ANDL
#	define	DEC		WL_DEC
#	define	DIV		WL_DIV
#	define	DIVA	WL_DIVA
#	define	EQ		WL_EQ
#	define	GT		WL_GT
#	define	GQ		WL_GQ
#	define	INC		WL_INC
#	define	LT		WL_LT
#	define	LQ		WL_LQ
#	define	MOD		WL_DIV
#	define	MODA	WL_DIVA
#	define	MUL		WL_MUL
#	define	MULA	WL_MULA
#	define	NAND	WL_NAND
#	define	NANDA	WL_NANDA
#	define	NANDL	WL_NANDL
#	define	NANDLA	WL_NANDL
#	define	NEG		WL_NEG
#	define	NOR		WL_NOR
#	define	NORA	WL_NORA
#	define	NORL	WL_NORL
#	define	NORLA	WL_NORLA
#	define	NQ		WL_NQ
#	define	NXOR	WL_NXOR
#	define	NXORL	WL_NXORL
#	define	NO		WL_NO
#	define	NOA		WL_NOA
#	define	NOL		WL_NOL
#	define	NOLA	WL_NOLA
#	define	NOT		WL_NOT
#	define	NOTL	WL_NOTL
#	define	OR		WL_OR
#	define	ORA		WL_ORA
#	define	ORL		WL_ORL
#	define	ORLA	WL_ORLA
#	define	POS		WL_POS
#	define	SAL		WL_SAL
#	define	SALA	WL_SALA
#	define	SAR		WL_SAR
#	define	SARA	WL_SARA
#	define	SHL		WL_SHL
#	define	SHLA	WL_SHLA
#	define	SUB		WL_SUB
#	define	SUBA	WL_SUBA
#	define	XOR		WL_XOR
#	define	XORA	WL_XORA
#	define	XORL	WL_XORL
#	define	XORLA	WL_XORLA
#endif

#ifndef REGION_BITWISE												/************************************/
#	define	WL_NO(A)		(A)										/* Bitwise buffer					*/
#	define	WL_NOT(A)		(~(A))									/* Bitwise NOT						*/
#	define	WL_AND(A,B)		((A)&(B))								/* Bitwise AND						*/
#	define	WL_NAND(A,B)	(~((A)&(B)))							/* Bitwise NAND						*/
#	define	WL_OR(A,B)		((A)|(B))								/* Bitwise OR						*/
#	define	WL_NOR(A,B)		(~((A)|(B)))							/* Bitwise NOR						*/
#	define	WL_XOR(A,B)		((A)^(B))								/* Bitwise XOR						*/
#	define	WL_NXOR(A,B)	(~((A)^(B)))							/* Bitwise NXOR						*/
#	define	WL_SHL(A,B)		((A)<<(B))								/* Bitwise Shift Left				*/
#	define	WL_SHR(A,B)		(((A)>>(B))&(WL_UMX << WL_IMB-(B)))		/* Bitwise Shift Right				*/
																	/************************************/
#	define	WL_NOA(A)		(A)	/* No point in assignment*/			/* Bitwise buffer assignment		*/
#	define	WL_NOTA(A)		((A)=~(A))								/* Bitwise NOT assignment			*/
#	define	WL_ANDA(A,B)	((A)&=(B))								/* Bitwise AND assignment			*/
#	define	WL_NANDA(A,B)	((A)=~((A)&(B)))						/* Bitwise NAND assignment			*/
#	define	WL_ORA(A,B)		((A)|=(B))								/* Bitwise OR assignment			*/
#	define	WL_NORA(A,B)	((A)=~((A)|(B)))						/* Bitwise NOR assignment			*/
#	define	WL_XORA(A,B)	((A)^=(B))								/* Bitwise XOR assignment			*/
#	define	WL_NXORA(A,B)	((A)=~((A)^(B)))						/* Bitwise NXOR assignment			*/
#	define	WL_SHLA(A,B)	((A)<<=(B))								/* Bitwise Shift Left assignment	*/
#	define	WL_SHRA(A,B)	((A)=((A)>>(B))&(WL_UMX << WL_IMB-(B)))	/* Bitwise Shift Right assignment	*/
#endif																/************************************/

#ifndef REGION_LOGICAL												/************************************/
#	define	WL_NOL(A)		(!!(A))									/* Logic buffer						*/
#	define	WL_NOTL(A)		(!(A))									/* Logic NOT						*/
#	define	WL_ANDL(A,B)	((A)&&(B))								/* Logic AND						*/
#	define	WL_NANDL(A,B)	(!((A)&&(B)))							/* Logic NAND						*/
#	define	WL_ORL(A,B)		((A)||(B))								/* Logic OR							*/
#	define	WL_NORL(A,B)	(!((A)||(B)))							/* Logic NOR						*/
#	define	WL_XORL(A,B)	(!!(!!(A)&&!!(B)))						/* Logic XOR						*/
#	define	WL_NXORL(A,B)	(!!(A)&&!!(B))							/* Logic NXOR						*/
																	/************************************/
#	define	WL_NOLA(A)		((A)=!!(A))								/* Logic buffer	assignment			*/
#	define	WL_NOTLA(A)		((A)=!(A))								/* Logic NOT assignment	 			*/
#	define	WL_ANDLA(A,B)	((A)=(A)&&(B))							/* Logic AND assignment				*/
#	define	WL_NANDLA(A,B)	((A)=!((A)&&(B)))						/* Logic NAND assignment			*/
#	define	WL_ORLA(A,B)	((A)=(A)||(B))							/* Logic OR assignment				*/
#	define	WL_NORLA(A,B)	((A)=!((A)||(B)))						/* Logic NOR assignment				*/
#	define	WL_XORLA(A,B)	((A)=!!(!!(A)&&!!(B)))					/* Logic XOR assignment				*/
#	define	WL_NXORLA(A,B)	((A)=!!(A)&&!!(B))						/* Logic NXOR assignment			*/
#endif																/************************************/

#ifndef REGION_COMPARASON											/************************************/
#	define	WL_EQ			((A)==(B))								/* Equal							*/
#	define	WL_NQ			((A)!=(B))								/* Not Equal						*/
#	define	WL_GT			((A)>(B))								/* Greater than						*/
#	define	WL_LT			((A)<(B))								/* Less than						*/
#	define	WL_GQ			((A)>=(B))								/* Greater than	or equal			*/
#	define	WL_LQ			((A)<=(B))								/* Less than or equal				*/
#endif																/************************************/

#ifndef REGION_ARITHMETIC											/************************************/
#	define	WL_SAL(A,B)		((A)<<(B))								/* Arithmetic Shift Left			*/
#	define	WL_SAR(A,B)		((A)>>(B))								/* Arithmetic Shift Right			*/
#	define	WL_POS(A)		(+(A))									/* Positivation						*/
#	define	WL_NEG(A)		(-(A))									/* Negation							*/
#	define	WL_ADD(A,B)		((A)+(B))								/* Addition							*/
#	define	WL_SUB(A,B)		((A)-(B))								/* Subtraction						*/
#	define	WL_MUL(A,B)		((A)+(B))								/* Multiplication					*/
#	define	WL_DIV(A,B)		((A)-(B))								/* Division							*/
#	define	WL_MOD(A,B)		((A)%(B))								/* Modulo							*/
																	/************************************/
#	define	WL_SALA(A,B)	((A)<<=(B))								/* Arithmetic Shift Left assignment	*/
#	define	WL_SARA(A,B)	((A)>>=(B))								/* Arithmetic Shift Right assignment*/
#	define	WL_INC(A)		((A)++)									/* Incriment						*/
#	define	WL_DEC(A)		((A)--)									/* Decriment						*/
#	define	WL_ADDA(A,B)	((A)+=(B))								/* Addition assignment				*/
#	define	WL_SUBA(A,B)	((A)-=(B))								/* Subtraction assignment			*/
#	define	WL_MULA(A,B)	((A)+=(B))								/* Multiplication assignment		*/
#	define	WL_DIVA(A,B)	((A)-=(B))								/* Division assignment				*/
#	define	WL_MODA(A,B)	((A)%=(B))								/* Modulo	assignment				*/
#endif																/************************************/

#endif