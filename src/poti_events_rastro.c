/* Do not edit. File generated by rastro. */

#include "poti_events_rastro.h"

/* Rastro function implementation for 'dsss' */
void rst_event_dsss_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, const char* s0, const char* s1, const char* s2)
{
  rst_startevent(ptr, type<<18|0x22111);
  RST_PUT(ptr, double, d0);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'dsss' - fortran support */
void rst_event_dsss_f_( int16_t *type, double* d0, const char* s0, const char* s1, const char* s2)
{
  rst_event_dsss ((u_int16_t)* type, (double)* d0,  s0,  s1,  s2);
}

/* Rastro function implementation for 'dssss' */
void rst_event_dssss_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, const char* s0, const char* s1, const char* s2, const char* s3)
{
  rst_startevent(ptr, type<<18|0x2111);
  RST_PUT(ptr, u_int32_t, 0x21000000);
  RST_PUT(ptr, double, d0);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  RST_PUT_STR(ptr, s3);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'dssss' - fortran support */
void rst_event_dssss_f_( int16_t *type, double* d0, const char* s0, const char* s1, const char* s2, const char* s3)
{
  rst_event_dssss ((u_int16_t)* type, (double)* d0,  s0,  s1,  s2,  s3);
}

/* Rastro function implementation for 'dsssss' */
void rst_event_dsssss_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4)
{
  rst_startevent(ptr, type<<18|0x2111);
  RST_PUT(ptr, u_int32_t, 0x21100000);
  RST_PUT(ptr, double, d0);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  RST_PUT_STR(ptr, s3);
  RST_PUT_STR(ptr, s4);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'dsssss' - fortran support */
void rst_event_dsssss_f_( int16_t *type, double* d0, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4)
{
  rst_event_dsssss ((u_int16_t)* type, (double)* d0,  s0,  s1,  s2,  s3,  s4);
}

/* Rastro function implementation for 'ddssss' */
void rst_event_ddssss_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1, const char* s2, const char* s3)
{
  rst_startevent(ptr, type<<18|0x2211);
  RST_PUT(ptr, u_int32_t, 0x21100000);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  RST_PUT_STR(ptr, s3);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddssss' - fortran support */
void rst_event_ddssss_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1, const char* s2, const char* s3)
{
  rst_event_ddssss ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1,  s2,  s3);
}

/* Rastro function implementation for 'ddss' */
void rst_event_ddss_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1)
{
  rst_startevent(ptr, type<<18|0x22211);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddss' - fortran support */
void rst_event_ddss_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1)
{
  rst_event_ddss ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1);
}

/* Rastro function implementation for 'ddssd' */
void rst_event_ddssd_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1, double d2)
{
  rst_startevent(ptr, type<<18|0x2221);
  RST_PUT(ptr, u_int32_t, 0x21000000);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT(ptr, double, d2);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddssd' - fortran support */
void rst_event_ddssd_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1, double* d2)
{
  rst_event_ddssd ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1, (double)* d2);
}

/* Rastro function implementation for 'ddsss' */
void rst_event_ddsss_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1, const char* s2)
{
  rst_startevent(ptr, type<<18|0x2211);
  RST_PUT(ptr, u_int32_t, 0x21000000);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddsss' - fortran support */
void rst_event_ddsss_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1, const char* s2)
{
  rst_event_ddsss ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1,  s2);
}

/* Rastro function implementation for 'ddsssi' */
void rst_event_ddsssi_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1, const char* s2, u_int32_t i0)
{
  rst_startevent(ptr, type<<18|0x2271);
  RST_PUT(ptr, u_int32_t, 0x21100000);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT(ptr, u_int32_t, i0);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddsssi' - fortran support */
void rst_event_ddsssi_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1, const char* s2, int32_t* i0)
{
  rst_event_ddsssi ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1,  s2, (u_int32_t)* i0);
}

/* Rastro function implementation for 'ddsssss' */
void rst_event_ddsssss_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4)
{
  rst_startevent(ptr, type<<18|0x2211);
  RST_PUT(ptr, u_int32_t, 0x21110000);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  RST_PUT_STR(ptr, s3);
  RST_PUT_STR(ptr, s4);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddsssss' - fortran support */
void rst_event_ddsssss_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4)
{
  rst_event_ddsssss ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1,  s2,  s3,  s4);
}

/* Rastro function implementation for 'ddsssssi' */
void rst_event_ddsssssi_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4, u_int32_t i0)
{
  rst_startevent(ptr, type<<18|0x2271);
  RST_PUT(ptr, u_int32_t, 0x21111000);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT(ptr, u_int32_t, i0);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  RST_PUT_STR(ptr, s3);
  RST_PUT_STR(ptr, s4);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddsssssi' - fortran support */
void rst_event_ddsssssi_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4, int32_t* i0)
{
  rst_event_ddsssssi ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1,  s2,  s3,  s4, (u_int32_t)* i0);
}

/* Rastro function implementation for 'ddsssssii' */
void rst_event_ddsssssii_ptr(rst_buffer_t *ptr, u_int16_t type, double d0, double d1, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4, u_int32_t i0, u_int32_t i1)
{
  rst_startevent(ptr, type<<18|0x2277);
  RST_PUT(ptr, u_int32_t, 0x21111100);
  RST_PUT(ptr, double, d0);
  RST_PUT(ptr, double, d1);
  RST_PUT(ptr, u_int32_t, i0);
  RST_PUT(ptr, u_int32_t, i1);
  RST_PUT_STR(ptr, s0);
  RST_PUT_STR(ptr, s1);
  RST_PUT_STR(ptr, s2);
  RST_PUT_STR(ptr, s3);
  RST_PUT_STR(ptr, s4);
  rst_endevent(ptr);
}
/* Rastro function implementation for 'ddsssssii' - fortran support */
void rst_event_ddsssssii_f_( int16_t *type, double* d0, double* d1, const char* s0, const char* s1, const char* s2, const char* s3, const char* s4, int32_t* i0, int32_t* i1)
{
  rst_event_ddsssssii ((u_int16_t)* type, (double)* d0, (double)* d1,  s0,  s1,  s2,  s3,  s4, (u_int32_t)* i0, (u_int32_t)* i1);
}

void rst_init_f_(int64_t *id1, int64_t *id2)
{
  rst_init((u_int64_t)* id1, (u_int64_t)* id2);
}
void rst_finalize_f_ ()
{
  rst_finalize();
}
