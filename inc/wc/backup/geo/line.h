#ifndef WC_LINE_H
#define WC_LINE_H

#include <wc/math/mathg/SQ.h>
#include <wc/core/type.h>
#include <wc/geo/point.h>

#define Line(_DIM, _TYPE) Line##_DIM_##_TYPE

/* Line 1D */
_TYPE2(ln1b, pt1b, A, B), Line1b, Line1U8;
_TYPE2(ln1w, pt1w, A, B), Line1w, Line1U16;
_TYPE2(ln1u, pt1u, A, B), Line1u, Line1U32;
_TYPE2(ln1q, pt1q, A, B), Line1q, Line1U64;

_TYPE2(ln1c, pt1c, A, B), Line1c, Line1I8;
_TYPE2(ln1h, pt1h, A, B), Line1h, Line1I16;
_TYPE2(ln1i, pt1i, A, B), Line1i, Line1I32;
_TYPE2(ln1l, pt1l, A, B), Line1l, Line1I64;

_TYPE2(ln1f, pt1f, A, B), Line1f, Line1F32;
_TYPE2(ln1d, pt1d, A, B), Line1d, Line1F64;

/* Line 2D */
_TYPE2(ln2b, pt2b, A, B), Line2b, Line2U8;
_TYPE2(ln2w, pt2w, A, B), Line2w, Line2U16;
_TYPE2(ln2u, pt2u, A, B), Line2u, Line2U32;
_TYPE2(ln2q, pt2q, A, B), Line2q, Line2U64;

_TYPE2(ln2c, pt2c, A, B), Line2c, Line2I8;
_TYPE2(ln2h, pt2h, A, B), Line2h, Line2I16;
_TYPE2(ln2i, pt2i, A, B), Line2i, Line2I32;
_TYPE2(ln2l, pt2l, A, B), Line2l, Line2I64;

_TYPE2(ln2f, pt2f, A, B), Line2f, Line2F32;
_TYPE2(ln2d, pt2d, A, B), Line2d, Line2F64;

/* Line 3D */
_TYPE2(ln3b, pt3b, A, B), Line3b, Line3U8;
_TYPE2(ln3w, pt3w, A, B), Line3w, Line3U16;
_TYPE2(ln3u, pt3u, A, B), Line3u, Line3U32;
_TYPE2(ln3q, pt3q, A, B), Line3q, Line3U64;

_TYPE2(ln3c, pt3c, A, B), Line3c, Line3I8;
_TYPE2(ln3h, pt3h, A, B), Line3h, Line3I16;
_TYPE2(ln3i, pt3i, A, B), Line3i, Line3I32;
_TYPE2(ln3l, pt3l, A, B), Line3l, Line3I64;

_TYPE2(ln3f, pt3f, A, B), Line3f, Line3F32;
_TYPE2(ln3d, pt3d, A, B), Line3d, Line3F64;

/* Length */
#define le1(_L) _L.B-_L.A
#define le2(_L) srd( SQ(_L.B.x-_L.A.x) + SQ(_L.B.y-_L.A.y) )
#define le3(_L) srd( SQ(_L.B.x-_L.A.x) + SQ(_L.B.y-_L.A.y) + SQ(_L.B.z-_L.A.z) )

#endif