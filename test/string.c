


typedef char wl_ch, wl_Ch;
typedef signed char wl_i8, wl_I8;
typedef short wl_i16, wl_I16;
typedef int wl_i32, wl_I32;
typedef long wl_i64, wl_I64;
typedef unsigned char wl_u8, wl_U8;
typedef unsigned short wl_u16, wl_U16;
typedef unsigned int wl_u32, wl_U32;
typedef unsigned long wl_u64, wl_U64;
typedef wl_U64 wl__Ptr;
typedef wl_U64 wl_imax, wl_IMax;
typedef wl_U64 wl_umax, wl_UMax;
typedef void wl_vo, wl_Vo;
typedef _Bool wl_bl, wl_Bl;
typedef float wl_f32, wl_F32;
typedef double wl_f64, wl_F64;






typedef struct wl_MChunk {

 wl__Ptr allocated:1;
 wl__Ptr ptr2next:(64 -1);




} wl_MChunk;
typedef wl__Ptr wl_MSize, wl_Msz;
 extern wl_Vo* wl_mal(wl_Msz n);
 extern wl_Vo wl_mfr(wl_Vo* p);
 extern wl_Msz wl__sizeofmem(wl_Vo* ptr);
typedef wl_Vo* wl_Vopu, wl_vopu, wl_Vopi, wl_vopi;





typedef enum WL_SEARCH_FLAGS {
 WL_SEARCH_NORMAL = (wl_U8)0,
 WL_SEARCH_REVERSE = (wl_U8)1,
 WL_SEARCH_COUNT = (wl_U8)2
} WL_SEARCH_FLAGS;
extern wl_Vo* wl_aas(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a);
extern wl_Vo* wl_anot(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a);
extern wl_Vo* wl_aand(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Vo* wl_aor(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Vo* wl_axor(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Vo* wl_anand(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Vo* wl_anor(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Vo* wl_anxor(const wl_U8 s, wl_Vo* r, wl_Vo* const restrict a, wl_Vo* const restrict b);

extern wl_Bl wl_anol(const wl_U8 s, wl_Vo* const restrict a);
extern wl_Bl wl_anotl(const wl_U8 s, wl_Vo* const restrict a);
extern wl_Bl wl_aandl(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_aorl(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_axorl(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_anandl(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_anorl(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_anxorl(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_aeq(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_aneq(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_agt(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_alt(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_agtq(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);
extern wl_Bl wl_altq(const wl_U8 s, wl_Vo* const restrict a, wl_Vo* const restrict b);

extern wl_Vo* wl_afl( const wl_U8 sa,
        wl_Vo* a,
        wl_U8 sb,
        wl_Vo* b );

extern wl_Vopu wl_asb( const wl_Vo* restrict const src,
      const wl_U8 srcSize,
      const wl_U8 _byte,
      const WL_SEARCH_FLAGS flags );


extern wl_Vopu wl_asa( const wl_Vo* restrict const src,
      const wl_U8 srcSize,
      const wl_Vo* restrict const target,
        wl_U8 targetSize,
      const WL_SEARCH_FLAGS flags );
typedef char* wl_Str;






typedef wl_u16 wl_Sl, wl_Lens;






typedef enum WL_S2_FLAGS {
 WL_S2_DEC = (wl_U8)0,
 WL_S2_HEX = (wl_U8)1,
 WL_S2_BIN = (wl_U8)2,
 WL_S2_OCT = (wl_U8)3
} WL_S2_FLAGS;
 extern wl_Sl wl_sl(const char* restrict const str);


extern wl_U32 wl_s2u(const char* restrict const str, const WL_S2_FLAGS flags);
extern wl_U64 wl_s2q(const char* restrict const str, const WL_S2_FLAGS flags);
extern wl_u8 wl__err;
 wl_Sl wl_sl(const char* restrict const str) {
  const char* a = str;
  for (; *a; a++);
  return a-str;
 }
wl_U32 wl_s2u(const char* restrict const str, const WL_S2_FLAGS flags) {





 wl_U32 r = 0;


 const wl_Sl s = wl_sl(str);
 wl_Sl i = 0;


 switch (flags&0x3) {

  case WL_S2_BIN: {

   if (s > 32) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }


   for (; i<=s && (str[i]&0xFE) == '0'; i++) {
    r *= 2;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case WL_S2_OCT: {

   if (s > 11) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }

   for (; i<=s && str[i]>='0' && str[i]<='7'; i++) {
    r *= 8;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case WL_S2_DEC:
  default: {

   if (s > 10) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }

   for (; i<=s && ((str[i]) >= '0' && (str[i]) <= '9'); i++) {
    r *= 10;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case WL_S2_HEX: {

   if (s > 8) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }

   for (; i<=s && str[i]>='0' && str[i]<='F'; i++) {
    r *= 16;
    r += ( (((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32)) + 62*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))==' ') - 32*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))==127) + 96*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<' ') + 29*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'0'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>=' ') - 48*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<':'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='0') + 19*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'A'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>=':') - 55*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'['&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='A') - 7 *((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'a'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='[') - 61*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'{'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='a') - 33*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<127&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='{') );
   }
   break;
  }
 }

 return r;
}
wl_U64 wl_s2q(const char* restrict const str, const WL_S2_FLAGS flags) {





 wl_U32 r = 0;


 const wl_Sl s = wl_sl(str);
 wl_Sl i = 0;


 switch (flags&0x3) {

  case WL_S2_BIN: {

   if (s > 64) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }


   for (; i<=s && (str[i]&0xFE) == '0'; i++) {
    r *= 2;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case WL_S2_OCT: {

   if (s > 22) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }

   for (; i<=s && str[i]>='0' && str[i]<='7'; i++) {
    r *= 8;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case WL_S2_DEC:
  default: {

   if (s > 20) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }

   for (; i<=s && ((str[i]) >= '0' && (str[i]) <= '9'); i++) {
    r *= 10;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case WL_S2_HEX: {

   if (s > 16) {
    (wl__err = (2));
    return (wl_U32) 0xFFFFFFFF;
   }

   for (; i<=s && str[i]>='0' && str[i]<='F'; i++) {
    r *= 16;
    r += ( (((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32)) + 62*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))==' ') - 32*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))==127) + 96*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<' ') + 29*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'0'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>=' ') - 48*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<':'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='0') + 19*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'A'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>=':') - 55*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'['&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='A') - 7 *((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'a'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='[') - 61*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<'{'&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='a') - 33*((wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))<127&&(wl_U8)(((str[i]) + ((str[i]) >= 'a' && (str[i]) <= 'z')*32))>='{') );
   }
   break;
  }
 }

 return r;
}
