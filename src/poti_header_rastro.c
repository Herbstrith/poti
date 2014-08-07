/* Do not edit. File generated by rastro. */

#include "poti_header_rastro.h"

/* Rastro function implementation for 'ssisssss' */
void rst_event_ssisssss_ptr(rst_buffer_t *ptr, u_int16_t type, const char* s0, const char* s1, u_int32_t i0, const char* s2, const char* s3, const char* s4, const char* s5, const char* s6)
{
  rst_startevent(ptr, type<<18|0x7111);
  RST_PUT(ptr, u_int32_t, 0x21111000);
  RST_PUT(ptr, u_int32_t, i0);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  RST_PUT_STR(ptr, s3);
  RST_PUT_STR(ptr, s4);
  RST_PUT_STR(ptr, s5);
  RST_PUT_STR(ptr, s6);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ssisssss' - fortran support */
void rst_event_ssisssss_f_( int16_t *type, const char* s0, const char* s1, int32_t* i0, const char* s2, const char* s3, const char* s4, const char* s5, const char* s6)
{
  rst_event_ssisssss ((u_int16_t)* type,  s0,  s1, (u_int32_t)* i0,  s2,  s3,  s4,  s5,  s6);
}

void rst_init_f_(int64_t *id1, int64_t *id2)
{
  rst_init((u_int64_t)* id1, (u_int64_t)* id2);
}
void rst_finalize_f_ ()
{
  rst_finalize();
}
