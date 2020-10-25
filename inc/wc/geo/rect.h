#ifndef WC_RECT_H
#define WC_RECT_H

#include <wc/core/type.h>
#include <wc/core/types.h>

/* Rect 2D
	 * x: x position
	 * y: y position
	 * l: length
	 * w: width
 */ 

_TYPE4(rcb,	U8,		x, y, l, w), Rectb,	RectU8;
_TYPE4(rcw,	U16,	x, y, l, w), Rectw,	RectU16;
_TYPE4(rcu,	U32,	x, y, l, w), Rectu,	RectU32;
_TYPE4(rcq,	U64,	x, y, l, w), Rectq,	RectU64;

_TYPE4(rcc,	U8,		x, y, l, w), Rectc,	RectU8;
_TYPE4(rch,	U16,	x, y, l, w), Recth,	RectU16;
_TYPE4(rc,	U32,	x, y, l, w), Rect,	RectU32, rci, Recti;
_TYPE4(rcl,	U64,	x, y, l, w), Rectl,	RectU64;

_TYPE4(rcf,	F32,	x, y, l, w), Rectf,	RectF32;
_TYPE4(rcd,	F64,	x, y, l, w), Rectd,	RectF64;

#endif