#ifndef WC_POINT_H
#define WC_POINT_H

#include <wc/core/type.h>
#include <wc/core/types.h>

#define Point(_DIM, _TYPE) Point##_DIM##_TYPE;

/* Point 1D */
_QUICKTYPE1(pt1b,	U8),	Point1b,	Point1U8;
_QUICKTYPE1(pt1w,	U16),	Point1w,	Point1U16;
_QUICKTYPE1(pt1u,	U32),	Point1u,	Point1U32;
_QUICKTYPE1(pt1q,	U64),	Point1q,	Point1U64;

_QUICKTYPE1(pt1c,	I8),	Point1c,	Point1I8;
_QUICKTYPE1(pt1h,	I16),	Point1h,	Point1I16;
_QUICKTYPE1(pt1,	I32),	Point1,		Point1I32,	pt1i,	Point1i;
_QUICKTYPE1(pt1l,	I64),	Point1l,	Point1I64;

_QUICKTYPE1(pt1f,	F32),	Point1f,	Point1F32;
_QUICKTYPE1(pt1d,	F64),	Point1d,	Point1F64;

/* Point 2D */
_QUICKTYPE2(pt2b,	U8),	Point2b,	Point2U8;
_QUICKTYPE2(pt2w,	U16),	Point2w,	Point2U16;
_QUICKTYPE2(pt2u,	U32),	Point2u,	Point2U32;
_QUICKTYPE2(pt2q,	U64),	Point2q,	Point2U64;

_QUICKTYPE2(pt2c,	I8),	Point2c,	Point2I8;
_QUICKTYPE2(pt2h,	I16),	Point2h,	Point2I16;
_QUICKTYPE2(pt2,	I32),	Point2,		Point2I32,	pt2i,	Point2i;
_QUICKTYPE2(pt2l,	I64),	Point2l,	Point2I64;

_QUICKTYPE2(pt2f,	F32),	Point2f,	Point2F32;
_QUICKTYPE2(pt2d,	F64),	Point2d,	Point2F64;

/* Point 3D */
_QUICKTYPE3(pt3b,	U8),	Point3b,	Point3U8;
_QUICKTYPE3(pt3w,	U16),	Point3w,	Point3U16;
_QUICKTYPE3(pt3u,	U32),	Point3u,	Point3U32;
_QUICKTYPE3(pt3q,	U64),	Point3q,	Point3U64;

_QUICKTYPE3(pt3c,	I8),	Point3c,	Point3I8;
_QUICKTYPE3(pt3h,	I16),	Point3h,	Point3I16;
_QUICKTYPE3(pt3,	I32),	Point3,		Point3I32, pt3i, Point3i;
_QUICKTYPE3(pt3l,	I64),	Point3l,	Point3I64;

_QUICKTYPE3(pt3f,	F32),	Point3f,	Point3F32;
_QUICKTYPE3(pt3d,	F64),	Point3d,	Point3F64;

#endif