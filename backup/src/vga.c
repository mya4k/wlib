#include <wc/vga.h>
#include <wc/char.h>



/**
 * \var		VGABuffer
 * \brief	VGA Buffer
 */
Ven* VGABuffer;
/**
 * \var		VGARow
 * \brief	VGA Row Coordinate
 */
/**
 * \var		VGAColumb
 * \brief	VGA Column Coordinate
 */
Venp VGARow, VGAColumn;



/**
 * \fn		voc
 * \brief	VGA Output Character
 */
void voc(register char chr, register Vgac color) {
			if (chr == '\n') VGARow++;
	else	if (chr == '\r') VGAColumn = 0;
	else {
		vpat( ven(chr,color), VGAColumn, VGARow );
		if (++VGAColumn == VGA_WIDTH) {
			VGAColumn = 0;
			if (++VGARow == VGA_HEIGHT)
				VGARow = 0;
		}
	}
}

/**
 * \fn		vos
 * \brief	VGA Output String
 * Basically outputs a character string length times
 */
void vos(register char* str, register Vgac color) {
	for (Vbfs i = 0; i < lens(str); i++)
		voc(str[i], color);
}