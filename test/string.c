


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





typedef char* wl_Str;





typedef wl_u16 wl_Sl, wl_Lens;
 extern wl_Sl wl_sl(const char* str);


extern wl_U32 wl_s2u (const char* str, wl_u8 flags);
 wl_Sl wl_sl(const char* restrict const str) {
  const char* a = str;
  for (; *a; a++);
  return a-str;
 }
wl_U32 wl_s2u(const char* restrict const str, const wl_u8 flags) {
 wl_U32 r = 0;

 switch (flags&0x3) {

  case 2: {

   const wl_Sl s = wl_sl(str);
   wl_Sl i;

   for (i = 0; i<=s && (str[i]&0xFE) == '0'; i++) {
    r *= 2;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case 3: {

   const wl_Sl s = wl_sl(str);
   wl_Sl i;

   for (i = 0; i<=s && str[i]>='0' && str[i]<='7'; i++) {
    r *= 8;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case 0:
  default: {

   const wl_Sl s = wl_sl(str);
   wl_Sl i;

   for (i = 0; i<=s && ((str[i]) >= '0' && (str[i]) <= '9'); i++) {
    r *= 10;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }

  case 1: {

   const wl_Sl s = wl_sl(str);
   wl_Sl i;

   for (i = 0; i<=s && str[i]>='0' && str[i]<='F'; i++) {
    r *= 16;
    r += ( (str[i]) + 62*((wl_U8)(str[i])==' ') - 32*((wl_U8)(str[i])==127) + 96*((wl_U8)(str[i])<' ') + 29*((wl_U8)(str[i])<'0'&&(wl_U8)(str[i])>=' ') - 48*((wl_U8)(str[i])<':'&&(wl_U8)(str[i])>='0') + 19*((wl_U8)(str[i])<'A'&&(wl_U8)(str[i])>=':') - 55*((wl_U8)(str[i])<'['&&(wl_U8)(str[i])>='A') - 7 *((wl_U8)(str[i])<'a'&&(wl_U8)(str[i])>='[') - 61*((wl_U8)(str[i])<'{'&&(wl_U8)(str[i])>='a') - 33*((wl_U8)(str[i])<127&&(wl_U8)(str[i])>='{') );
   }
   break;
  }
 }
 return r;
}
