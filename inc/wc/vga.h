#ifndef WC_VGA_H
#define WC_VGA_H



#include <wc/types.h>



#ifndef NO_LONG_NAMES
#	define VGADefineEntry	ven
#	define VGAPositionEntry	vpat
#endif



#define VGA_WIDTH	80
#define VGA_HEIGHT	25
/**
 * \def		ven(ch, color)
 * \brief	VGA entry definition
 * \arg		ch		An ASCII character
 * \arg		color	
 */
#define ven(c,color)	(Ven)( c | (color<<8) )
/**
 * \def		vpat(entry, x, y)
 * \brief	Position a VGA entry at
 */
#define vpat(entry,x,y)	( VGABuffer[y*VGA_WIDTH+x] = entry )


/**
 * \typedef	Ven
 * \typedef VGAEntry
 * \brief 	VGA Entry type
 */
typedef u16 Ven, VGAEntry;
/**
 * \typedef	Venp
 * \typedef	VGAEntryPosition
 * \brief 	VGA Entry position type
 */
typedef u8	Venp, VGAEntryPosition;
/**
 * \typedef Vbfs
 * \typedef VGABufferSize
 * \brief	VGA Buffer Size
 */
typedef u8	Vbfs, VGABufferSize;


/**
 * \enum	Vgac
 * \typedef Vgac
 * \typedef VGAColor
 * \brief	VGA 16-color palette
 */
typedef enum Vgac {
	VGAC_BLACK = 0,
	VGAC_BLUE = 1,
	VGAC_GREEN = 2,
	VGAC_CYAN = 3,
	VGAC_RED = 4,
	VGAC_MAGENTA = 5,
	VGAC_BROWN = 6,
	VGAC_LIGHT_GREY = 7,
	VGAC_DARK_GREY = 8,
	VGAC_LIGHT_BLUE = 9,
	VGAC_LIGHT_GREEN = 10,
	VGAC_LIGHT_CYAN = 11,
	VGAC_LIGHT_RED = 12,
	VGAC_LIGHT_MAGENTA = 13,
	VGAC_LIGHT_BROWN = 14,
	VGAC_WHITE = 15,
} Vgac, VGAColor;



extern Ven* VGABuffer;
extern Venp VGARow, VGAColumn;



extern void voc(register char	chr, register Vgac color);
extern void vos(register char*	str, register Vgac color);



#endif