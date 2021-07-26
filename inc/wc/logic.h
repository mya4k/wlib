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
#	define	AND		WL_AND
#	define	ANDL	WL_ANDL
#	define	NAND	WL_NAND
#	define	NANDL	WL_NANDL
#	define	NOR		WL_NOR
#	define	NORL	WL_NORL
#	define	NXOR	WL_NXOR
#	define	NXORL	WL_NXORL
#	define	NO		WL_NO
#	define	NOL		WL_NOL
#	define	NOT		WL_NOT
#	define	NOTL	WL_NOTL
#	define	OR		WL_OR
#	define	ORL		WL_ORL
#	define	XOR		WL_XOR
#	define	XORL	WL_XORL
#endif

#ifndef REGION_BITWISE
#	define	WL_NO(A)		(A)
#	define	WL_NOT(A)		(~(A))
#	define	WL_AND(A,B)		((A)&(B))
#	define	WL_NAND(A,B)	(~((A)&(B)))
#	define	WL_OR(A,B)		((A)|(B))
#	define	WL_NOR(A,B)		(~((A)|(B)))
#	define	WL_XOR(A,B)		((A)^(B))
#	define	WL_NXOR(A,B)	(~((A)^(B)))
#	define	WL_SHL(A,B)		((A)<<(B))
#	define	WL_SHR(A,B)		(((A)>>(B))&(wl_IMax))
#endif

#ifndef REGION_LOGICAL
#	define	WL_NOL(A)		(!!(A))
#	define	WL_NOTL(A)		(!(A))
#	define	WL_ANDL(A,B)	((A)&&(B))
#	define	WL_NANDL(A,B)	(!((A)&&(B)))
#	define	WL_ORL(A,B)		((A)||(B))
#	define	WL_NORL(A,B)	(!((A)||(B)))
#	define	WL_XORL(A,B)	(!!(!!(A)&&!!(B)))
#	define	WL_NXORL(A,B)	(!!(A)&&!!(B))
#endif

#ifndef REGION_BITWISE_ASSIGNMENT
#	define	WL_NOA(A)		(A)	/* No point in assignment*/
#	define	WL_NOTA(A)		((A)=~(A))
#	define	WL_ANDA(A,B)	((A)&=(B))
#	define	WL_NANDA(A,B)	((A)=~((A)&(B)))
#	define	WL_ORA(A,B)		((A)|=(B))
#	define	WL_NORA(A,B)	((A)=~((A)|(B)))
#	define	WL_XORA(A,B)	((A)^=(B))
#	define	WL_NXORA(A,B)	((A)=~((A)^(B)))
#endif

#ifndef REGION_LOGICAL_ASSIGNMENT
#	define	WL_NOLA(A)		((A)=!!(A))
#	define	WL_NOTLA(A)		((A)=!(A))
#	define	WL_ANDLA(A,B)	((A)=(A)&&(B))
#	define	WL_NANDLA(A,B)	((A)=!((A)&&(B)))
#	define	WL_ORLA(A,B)	((A)=(A)||(B))
#	define	WL_NORLA(A,B)	((A)=!((A)||(B)))
#	define	WL_XORLA(A,B)	((A)=!!(!!(A)&&!!(B)))
#	define	WL_NXORLA(A,B)	((A)=!!(A)&&!!(B))
#endif

#ifndef REGION_ARITHMETIC
#	define	WL_SAL(A,B)		((A)<<(B))
#	define	WL_SAR(A,B)		((A)>>(B))
#endif

#endif