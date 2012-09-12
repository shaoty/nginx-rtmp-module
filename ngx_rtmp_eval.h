/*
 * Copyright (c) 2012 Roman Arutyunyan
 */


#ifndef _NGX_RTMP_EVAL_H_INCLUDED_
#define _NGX_RTMP_EVAL_H_INCLUDED_

#include "ngx_rtmp.h"


typedef struct ngx_rtmp_eval_s ngx_rtmp_eval_t;


typedef void (* ngx_rtmp_eval_pt)(ngx_rtmp_session_t *s, ngx_rtmp_eval_t *e,
                                  ngx_str_t *ret);


struct ngx_rtmp_eval_s {
    ngx_str_t               name;
    ngx_rtmp_eval_pt        handler;
    ngx_uint_t              offset;
};


#define ngx_rtmp_null_eval  { ngx_null_string, NULL, 0 }


/* standard session eval variables */
extern ngx_rtmp_eval_t      ngx_rtmp_eval_session[];


ngx_int_t ngx_rtmp_eval(ngx_rtmp_session_t *s, ngx_str_t *in,
          ngx_rtmp_eval_t *e, ngx_str_t *out);


#endif /* _NGX_RTMP_EVAL_H_INCLUDED_ */
