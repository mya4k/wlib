#ifndef WL_ARRAY_H
#define WL_ARRAY_H



#include <wc/core.h>
#include <wc/types.h>



#if !WL_PREFIX
	#define aan					wl_aan
	#define ann					wl_ann
	#define ano					wl_ano
	#define anr					wl_anr
	#define ant					wl_ant
	#define anx					wl_anx
	#define aor					wl_aor
	#define axr					wl_axr
	#define aand				wl_aand
	#define anand				wl_anand
	#define anor				wl_anor
	#define anot				wl_anot
	#define anxor				wl_anxor
	#define axor				wl_axor
	#define aanl				wl_aanl
	#define annl				wl_annl
	#define anol				wl_anol
	#define anrl				wl_anrl
	#define antl				wl_antl
	#define anxl				wl_anxl
	#define aorl				wl_aorl
	#define axrl				wl_axrl
	#define aandl				wl_aandl
	#define anandl				wl_anandl
	#define anorl				wl_anorl
	#define anotl				wl_anotl
	#define anxorl				wl_anxorl
	#define axorl				wl_axorl
	#define asb					wl_asb
	#define asa					wl_asa
	#define arb					wl_arb
	#define ara					wl_ara
	#define _asb				wl__asb
	#define _asa				wl__asa
	#define _arb				wl__arb
	#define _ara				wl__ara
	#define findb				wl_findb
	#define find				wl_find
	#define replaceb			wl_replaceb
	#define replace				wl_replace
	#define asb1				wl_asb1
	#define asb9				wl_asb9
	#define asbo				wl_asbo
	#define asbo9				wl_asbo9
	#define asbc				wl_asbc
	#define asbn				wl_asbn
	#define asb9n				wl_asb9n
	#define asbon				wl_asbon
	#define asbo9n				wl_asbo9n
	#define asa1				wl_asa1
	#define asa9				wl_asa9
	#define asao				wl_asao
	#define asao9				wl_asao9
	#define asac				wl_asac
	#define asan				wl_asan
	#define asa9n				wl_asa9n
	#define asaon				wl_asaon
	#define asao9n				wl_asao9n
	#define arb1				wl_arb1
	#define arb9				wl_arb9
	#define arba				wl_arba
	#define arbn				wl_arbn
	#define arb9n				wl_arb9n
	#define arb1c				wl_arb1c
	#define arb9c				wl_arb9c
	#define arbac				wl_arbac
	#define arbnc				wl_arbnc
	#define arb9nc				wl_arb9nc
	#define asa1				wl_asa1
	#define asa9				wl_asa9
	#define asaa				wl_asaa
	#define asan				wl_asan
	#define asa9n				wl_asa9n
	#define asa1c				wl_asa1c
	#define asa9c				wl_asa9c
	#define asaac				wl_asaac
	#define asanc				wl_asanc
	#define asa9nc				wl_asa9nc
	#define _Af					wl__Af
	#define Asf					wl_Asf
	#define Arf					wl_Arf
	#define FindFlags			wl_FindFlags
	#define ReplaceFlags		wl_ReplaceFlags
	#define _AF_NO				WL__AF_NO
	#define _AF_AN				WL__AF_AN
	#define _AF_OR				WL__AF_OR
	#define _AF_XR				WL__AF_XR
	#define _AF_NT				WL__AF_NT
	#define _AF_NN				WL__AF_NN
	#define _AF_NR				WL__AF_NR
	#define _AF_NX				WL__AF_NX
	#define AS_FR				WL_AS_FR
	#define AS_PT				WL_AS_PT
	#define AS_LS				WL_AS_LS
	#define AS_OF				WL_AS_OF
	#define AS_CO				WL_AS_CO
	#define AS_NG				WL_AS_NG
	#define FIND_FIRST			WL_FIND_FIRST
	#define FIND_POINTER		WL_FIND_POINTER
	#define FIND_LAST			WL_FIND_LAST
	#define FIND_OFFSET			WL_FIND_OFFSET
	#define FIND_COUNT			WL_FIND_COUNT
	#define FIND_NEGATIVE		WL_FIND_NEGATIVE
	#define AR_FR				WL_AR_FR
	#define AR_LS				WL_AR_LS
	#define AR_AC				WL_AR_AC
	#define AR_AL				WL_AR_AL
	#define AR_NG				WL_AR_NG
	#define REPLACE_FIRST		WL_REPLACE_FIRST
	#define REPLACE_LAST		WL_REPLACE_LAST
	#define REPLACE_ALLCHAR		WL_REPLACE_ALLCHAR
	#define REPLACE_ALL			WL_REPLACE_ALL
	#define REPLACE_NEGATIVE	WL_REPLACE_NEGATIVE
	#define _afa				wl__afa
	#define _afb				wl__afb
#endif



/* 5.1. Bitwise arithmetic */
#define wl_aan(r,a,b,size)	wl__afa((r),(char*)(a),(char*)(b),(size),WL__AF_AN)
#define wl_aand		wl_aan
#define wl_anand	wl_ann
#define wl_ann(r,a,b,size)	wl__afa((r),(char*)(a),(char*)(b),(size),WL__AF_NN)
#define wl_ano(r,a,size)	wl__afa((r),(char*)(a),WL_NULL,(size),WL__AF_NO)
#define wl_anor		wl_anr
#define wl_anot		wl_ant
#define wl_anr(r,a,b,size)	wl__afa((r),(char*)(a),(char*)(b),(size),WL__AF_NR)
#define wl_ant(r,a,size)	wl__afa((r),(char*)(a),WL_NULL,(size),WL__AF_NT)
#define wl_anx(r,a,b,size)	wl__afa((r),(char*)(a),(char*)(b),(size),WL__AF_NX)
#define wl_anxor	wl_anx
#define wl_aor(r,a,b,size)	wl__afa((r),(char*)(a),(char*)(b),(size),WL__AF_OR)
#define wl_axor		wl_axr
#define wl_axr(r,a,b,size)	wl__afa((r),(char*)(a),(char*)(b),(size),WL__AF_XR)
/* 5.2. Boolean logic */
#define wl_anol(a,s)	wl__afb((char*)(a),WL_NULL,(s),WL__AF_NO)
#define wl_aorl(a,b,s)	wl__afb((char*)(a),(char*)(b),(s),WL__AF_OR)
#define wl_aanl(a,b,s)	wl__afb((char*)(a),(char*)(b),(s),WL__AF_AN)
#define wl_axrl(a,b,s)	wl__afb((char*)(a),(char*)(b),(s),WL__AF_XR)
#define wl_antl(a,s)	wl__afb((char*)(a),WL_NULL,(s),WL__AF_NT)
#define wl_anrl(a,b,s)	wl__afb((char*)(a),(char*)(b),(s),WL__AF_NN)
#define wl_annl(a,b,s)	wl__afb((char*)(a),(char*)(b),(s),WL__AF_NN)
#define wl_anxl(a,b,s)	wl__afb((char*)(a),(char*)(b),(s),WL__AF_NX)
#define wl_aandl	wl_aanl
#define wl_anandl	wl_annl
#define wl_anorl	wl_anrl
#define wl_anotl	wl_antl
#define wl_anxorl	wl_anxl
#define wl_axorl	wl_axrl
/* 5.3.1. `asb` -- Array Search Byte */
#define wl_asb(a,s,b,flags)			wl__asb((char*)(a),(s),(b),(flags))
#define wl_findb	wl_asb
/* 5.3.2. `asa` -- Array Search Array */
#define wl_asa(a,sa,b,sb,flags)		wl__asa((char*)(a),(sa),(char*)(b),(sb),(flags))
#define wl_find		wl_asa
/* 5.3.3. `arb` -- Array Replace Byte */
#define wl_arb(a,sa,b,c,flag)		((a) = wl__arb((char*)(a),(sa),(b),(c),(flag)))
#define wl_replaceb	wl_arb
/* 5.3.4. `ara` -- Array Replace Array */
#define wl_ara(a,sa,b,sb,c,sc,flag) ((a) = wl__ara((char*)(a),(sa),(char*)(b),(sb),(char*)(c),(sc),(flag)))
#define wl_replace	wl_ara
/* Will be added later */
#define wl_asb1(a,s,b)		wl_asb(a,s,b,AS_FR)				/* First */
#define wl_asb9(a,s,b)		wl_asb(a,s,b,AS_LS)				/* Last */
#define wl_asbo(a,s,b)		wl_asb(a,s,b,AS_FR|AS_OF)		/* Offset First */
#define wl_asbo9(a,s,b)		wl_asb(a,s,b,AS_LS|AS_OF)		/* Offset Last */
#define wl_asbc(a,s,b)		wl_asb(a,s,b,AS_CO)				/* Count */
#define wl_asbn(a,s,b)		wl_asb(a,s,b,AS_FR|AS_NG)		/* Negative First */
#define wl_asb9n(a,s,b)		wl_asb(a,s,b,AS_LS|AS_NG)		/* Negative Last */
#define wl_asbon(a,s,b)		wl_asb(a,s,b,AS_FR|AS_OF|AS_NG)	/* Negative Offset First */
#define wl_asbo9n(a,s,b)	wl_asb(a,s,b,AS_LS|AS_OF|AS_NG)	/* Negative Offset Last */

#define wl_asa1(a,s,b)		wl_asa(a,s,b,AS_FR)				/* First */
#define wl_asa9(a,s,b)		wl_asa(a,s,b,AS_LS)				/* Last */
#define wl_asao(a,s,b)		wl_asa(a,s,b,AS_FR|AS_OF)		/* Offset First */
#define wl_asao9(a,s,b)		wl_asa(a,s,b,AS_LS|AS_OF)		/* Offset Last */
#define wl_asac(a,s,b)		wl_asa(a,s,b,AS_CO)				/* Count */
#define wl_asan(a,s,b)		wl_asa(a,s,b,AS_FR|AS_NG)		/* Negative First */
#define wl_asa9n(a,s,b)		wl_asa(a,s,b,AS_LS|AS_NG)		/* Negative Last */
#define wl_asaon(a,s,b)		wl_asa(a,s,b,AS_FR|AS_OF|AS_NG)	/* Negative Offset First */
#define wl_asao9n(a,s,b)	wl_asa(a,s,b,AS_LS|AS_OF|AS_NG)	/* Negative Offset Last */

#define wl_arb1(a,s,b)		wl_arb(a,s,b,AR_FR)				/* First */
#define wl_arb9(a,s,b)		wl_arb(a,s,b,AR_LS)				/* Last */
#define wl_arba(a,s,b)		wl_arb(a,s,b,AR_AL)				/* All */
#define wl_arbn(a,s,b)		wl_arb(a,s,b,AR_FR|AR_NG)		/* Negative First */
#define wl_arb9n(a,s,b)		wl_arb(a,s,b,AR_LS|AR_NG)		/* Negative Last */
#define wl_arb1c(a,s,b)		wl_arb(a,s,b,AR_FR|AR_AC)		/* Anychar First */
#define wl_arb9c(a,s,b)		wl_arb(a,s,b,AR_LS|AR_AC)		/* Anychar Last */
#define wl_arbac(a,s,b)		wl_arb(a,s,b,AR_AL|AR_AC)		/* Anychar All */
#define wl_arbnc(a,s,b)		wl_arb(a,s,b,AR_FR|AR_NG|AR_AC)	/* Anychar Negative First */
#define wl_arb9nc(a,s,b)	wl_arb(a,s,b,AR_LS|AR_NG|AR_AC)	/* Anychar Negative Last */

#define wl_asa1(a,s,b)		wl_asa(a,s,b,AR_FR)				/* First */
#define wl_asa9(a,s,b)		wl_asa(a,s,b,AR_LS)				/* Last */
#define wl_asaa(a,s,b)		wl_asa(a,s,b,AR_AL)				/* All */
#define wl_asan(a,s,b)		wl_asa(a,s,b,AR_FR|AR_NG)		/* Negative First */
#define wl_asa9n(a,s,b)		wl_asa(a,s,b,AR_LS|AR_NG)		/* Negative Last */
#define wl_asa1c(a,s,b)		wl_asa(a,s,b,AR_FR|AR_AC)		/* Anychar First */
#define wl_asa9c(a,s,b)		wl_asa(a,s,b,AR_LS|AR_AC)		/* Anychar Last */
#define wl_asaac(a,s,b)		wl_asa(a,s,b,AR_AL|AR_AC)		/* Anychar All */
#define wl_asanc(a,s,b)		wl_asa(a,s,b,AR_FR|AR_NG|AR_AC)	/* Anychar Negative First */
#define wl_asa9nc(a,s,b)	wl_asa(a,s,b,AR_LS|AR_NG|AR_AC)	/* Anychar Negative Last */



/*  */
typedef wl_U16	wl_As, wl_ArraySize;
/* 5.4.1. `_Af` -- Array Function */
typedef wl_U8	wl__Af;
/* 5.4.2. `_Asf` -- Array Search Flags */
typedef wl_U8	wl__Asf;
/* 5.4.3. `_Arf` -- Array Replace Flags */
typedef wl_U8	wl__Arf;



/* 5.4.1. `_Af` -- Array Function */
enum wl__Af {
	WL__AF_NO = 0,
	WL__AF_AN = 1,
	WL__AF_OR = 2,
	WL__AF_XR = 3,
	WL__AF_NT = 4,
	WL__AF_NN = 5,
	WL__AF_NR = 6,
	WL__AF_NX = 7
};
/* 5.4.2. `_Asf` -- Array Search Flags */
enum wl_Asf {
	WL_AS_FR = 0,
	WL_AS_PT = 0,
	WL_AS_LS = 1,
	WL_AS_OF = 2,
	WL_AS_CO = 4,
	WL_AS_NG = 8
};
enum wl_FindFlags {
	WL_FIND_FIRST = 0,
	WL_FIND_POINTER = 0,
	WL_FIND_LAST = 1,
	WL_FIND_OFFSET = 2,
	WL_FIND_COUNT = 4,
	WL_FIND_NEGATIVE = 8
};
/* 5.4.3. `_Arf` -- Array Replace Flags */
enum wl_Arf {
	WL_AR_FR = 0,
	WL_AR_LS = 1,
	WL_AR_AC = 2,
	WL_AR_AL = 4,
	WL_AR_NG = 8
};
enum wl_ReplaceFlags {
	WL_REPLACE_FIRST = 0,
	WL_REPLACE_LAST = 1,
	WL_REPLACE_ALLCHAR = 2,
	WL_REPLACE_ALL = 4,
	WL_REPLACE_NEGATIVE = 8
};



/* 5.3.1. `asb` -- Array Search Byte */
EXTERN wl_Pt wl__asb(
	const char* const restrict	a,	const wl_As s, 
	const char					b, 
	const wl__Asf flags
);
/* 5.3.2. `asa` -- Array Search Array */
EXTERN wl_Pt wl__asa(
	const char* restrict const	a,	const wl_As sa, 
	const char* restrict		b,	const wl_As sb, 
	const wl__Asf flags
);
/* 5.3.3. `arb` -- Array Replace Byte */
EXTERN char* wl__arb(
	const char* restrict const a, const wl_As sa, 
	const char b, 
	const char c, 
	const wl__Asf flag
);
/* 5.3.4. `ara` -- Array Replace Array */
EXTERN char* wl__ara(
	char*						a,	const wl_As sa, 
	const char* restrict const	b,	const wl_As sb,
	const char* restrict const	c,	const wl_As sc,
	const wl__Asf				flag
);
/* 5.4.4. `_afa` -- Array Function Assignment */
EXTERN char* wl__afa(
	char* r, 
	const char* restrict const a, 
	const char* restrict const b, 
	const wl_As size, 
	const wl__Af func
);
/* 5.4.5. `_afb` -- Array Function Boolean */
EXTERN wl_Bl wl__afb(
	const char* restrict const a, 
	const char* restrict const b, 
	const wl_As size, 
	const wl__Af func
);



#endif
