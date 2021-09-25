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
#	define	AD		WL_AD
#	define	ADA		WL_ADA
#	define	AN		WL_AN
#	define	ANA		WL_ANA
#	define	ANL		WL_ANL
#	define	ANLA	WL_ANLA
#	define	DC		WL_DC
#	define	DV		WL_DV
#	define	DVA		WL_DVA
#	define	EQ		WL_EQ
#	define	GT		WL_GT
#	define	GQ		WL_GQ
#	define	IC		WL_IC
#	define	LT		WL_LT
#	define	LQ		WL_LQ
#	define	MD		WL_MD
#	define	MDA		WL_MDA
#	define	ML		WL_ML
#	define	MLA		WL_MLA
#	define	NN		WL_NN
#	define	NNA		WL_NNA
#	define	NNL		WL_NNL
#	define	NNLA	WL_NNLA
#	define	NG		WL_NG
#	define	NR		WL_NR
#	define	NRA		WL_NRA
#	define	NRL		WL_NRL
#	define	NRLA	WL_NRLA
#	define	NQ		WL_NQ
#	define	NX		WL_NX
#	define	NXL		WL_NXL
#	undef	NO
#	define	NO		WL_NO
#	define	NOA		WL_NOA
#	define	NOL		WL_NOL
#	define	NOLA	WL_NOLA
#	define	NT		WL_NT
#	define	NTL		WL_NTL
#	define	OR		WL_OR
#	define	ORA		WL_ORA
#	define	ORL		WL_ORL
#	define	ORLA	WL_ORLA
#	define	PS		WL_PS
#	define	SAL		WL_SAL
#	define	SALA	WL_SALA
#	define	SAR		WL_SAR
#	define	SARA	WL_SARA
#	define	SHL		WL_SHL
#	define	SHLA	WL_SHLA
#	define	SB		WL_SB
#	define	SBA		WL_SBA
#	define	XR		WL_XR
#	define	XRA		WL_XRA
#	define	XRL		WL_XRL
#	define	XRLA	WL_XRLA
#endif

#ifndef REGION_BITWISE												/************************************/
#	define	WL_NO(A)		(A)										/* Bitwise buffer					*/
#	define	WL_NT(A)		(~(A))									/* Bitwise NOT						*/
#	define	WL_AN(A,B)		((A)&(B))								/* Bitwise AND						*/
#	define	WL_NN(A,B)		(~((A)&(B)))							/* Bitwise NAND						*/
#	define	WL_OR(A,B)		((A)|(B))								/* Bitwise OR						*/
#	define	WL_NR(A,B)		(~((A)|(B)))							/* Bitwise NOR						*/
#	define	WL_XR(A,B)		((A)^(B))								/* Bitwise XOR						*/
#	define	WL_NX(A,B)		(~((A)^(B)))							/* Bitwise NXOR						*/
#	define	WL_SHL(A,B)		((A)<<(B))								/* Bitwise Shift Left				*/
#	define	WL_SHR(A,B)		(((A)>>(B))&(WL_UMX << WL_IMB-(B)))		/* Bitwise Shift Right				*/
																	/************************************/
#	define	WL_NOA(A)		(A)	/* No point in assignment*/			/* Bitwise buffer assignment		*/
#	define	WL_NTA(A)		((A)=~(A))								/* Bitwise NOT assignment			*/
#	define	WL_ANA(A,B)		((A)&=(B))								/* Bitwise AND assignment			*/
#	define	WL_NNA(A,B)		((A)=~((A)&(B)))						/* Bitwise NAND assignment			*/
#	define	WL_ORA(A,B)		((A)|=(B))								/* Bitwise OR assignment			*/
#	define	WL_NRA(A,B)		((A)=~((A)|(B)))						/* Bitwise NOR assignment			*/
#	define	WL_XRA(A,B)		((A)^=(B))								/* Bitwise XOR assignment			*/
#	define	WL_NXA(A,B)		((A)=~((A)^(B)))						/* Bitwise NXOR assignment			*/
#	define	WL_SHLA(A,B)	((A)<<=(B))								/* Bitwise Shift Left assignment	*/
#	define	WL_SHRA(A,B)	((A)=((A)>>(B))&(WL_UMX << WL_IMB-(B)))	/* Bitwise Shift Right assignment	*/
#endif																/************************************/

#ifndef REGION_LOGICAL												/************************************/
#	define	WL_NOL(A)		(!!(A))									/* Logic buffer						*/
#	define	WL_NTL(A)		(!(A))									/* Logic NOT						*/
#	define	WL_ANL(A,B)		((A)&&(B))								/* Logic AND						*/
#	define	WL_NNL(A,B)		(!((A)&&(B)))							/* Logic NAND						*/
#	define	WL_ORL(A,B)		((A)||(B))								/* Logic OR							*/
#	define	WL_NRL(A,B)		(!((A)||(B)))							/* Logic NOR						*/
#	define	WL_XRL(A,B)		(!!(!!(A)&&!!(B)))						/* Logic XOR						*/
#	define	WL_NXL(A,B)		(!!(A)&&!!(B))							/* Logic NXOR						*/
																	/************************************/
#	define	WL_NOLA(A)		((A)=!!(A))								/* Logic buffer	assignment			*/
#	define	WL_NTLA(A)		((A)=!(A))								/* Logic NOT assignment	 			*/
#	define	WL_ANLA(A,B)	((A)=(A)&&(B))							/* Logic AND assignment				*/
#	define	WL_NNLA(A,B)	((A)=!((A)&&(B)))						/* Logic NAND assignment			*/
#	define	WL_ORLA(A,B)	((A)=(A)||(B))							/* Logic OR assignment				*/
#	define	WL_NRLA(A,B)	((A)=!((A)||(B)))						/* Logic NOR assignment				*/
#	define	WL_XRLA(A,B)	((A)=!!(!!(A)&&!!(B)))					/* Logic XOR assignment				*/
#	define	WL_NXLA(A,B)	((A)=!!(A)&&!!(B))						/* Logic NXOR assignment			*/
#endif																/************************************/

#ifndef REGION_COMPARASON											/************************************/
#	define	WL_EQ(A,B)		((A)==(B))								/* Equal							*/
#	define	WL_NQ(A,B)		((A)!=(B))								/* Not Equal						*/
#	define	WL_GT(A,B)		((A)>(B))								/* Greater than						*/
#	define	WL_LT(A,B)		((A)<(B))								/* Less than						*/
#	define	WL_GQ(A,B)		((A)>=(B))								/* Greater than	or equal			*/
#	define	WL_LQ(A,B)		((A)<=(B))								/* Less than or equal				*/
#endif																/************************************/

#ifndef REGION_ARITHMETIC											/************************************/
#	define	WL_SAL(A,B)		((A)<<(B))								/* Arithmetic Shift Left			*/
#	define	WL_SAR(A,B)		((A)>>(B))								/* Arithmetic Shift Right			*/
#	define	WL_PS(A)		(+(A))									/* Positivation						*/
#	define	WL_NG(A)		(-(A))									/* Negation							*/
#	define	WL_AD(A,B)		((A)+(B))								/* Addition							*/
#	define	WL_SB(A,B)		((A)-(B))								/* Subtraction						*/
#	define	WL_ML(A,B)		((A)+(B))								/* Multiplication					*/
#	define	WL_DV(A,B)		((A)-(B))								/* Division							*/
#	define	WL_MD(A,B)		((A)%(B))								/* Modulo							*/
																	/************************************/
#	define	WL_SALA(A,B)	((A)<<=(B))								/* Arithmetic Shift Left assignment	*/
#	define	WL_SARA(A,B)	((A)>>=(B))								/* Arithmetic Shift Right assignment*/
#	define	WL_IC(A)		((A)++)									/* Incriment						*/
#	define	WL_DC(A)		((A)--)									/* Decriment						*/
#	define	WL_ADA(A,B)	((A)+=(B))									/* Addition assignment				*/
#	define	WL_SBA(A,B)	((A)-=(B))									/* Subtraction assignment			*/
#	define	WL_MLA(A,B)	((A)+=(B))									/* Multiplication assignment		*/
#	define	WL_DVA(A,B)	((A)-=(B))									/* Division assignment				*/
#	define	WL_MDA(A,B)	((A)%=(B))									/* Modulo	assignment				*/
#endif																/************************************/

#endif
