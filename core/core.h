#ifndef CORE_H
#define CORE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../display/color.h"
#include "../display/buffer.h"


typedef struct {
    uint32_t  xbound_begin,
              ybound_begin,
              xbound_end,
              ybound_end,
              img_width,
              img_height;

} frame_dimensions_t;

typedef void (*fractal_compute_fn_t)(frame_dimensions_t*, pixel_t*, uint32_t);

typedef struct {
    int32_t thread_id;
    uint32_t max_iter;
    frame_dimensions_t frame_dimensions;
    pixel_t *framebuffer;
    fractal_compute_fn_t fractal_type_fn;

} thread_arg_t;


#if defined(_WIN32) || defined(_WIN64)
    #define OS_WINDOWS 1
    #define OS_NAME "Windows"
#else 
    #define OS_UNIX 1
    #define OS_NAME "Unix"
#endif

#if OS_WINDOWS 
    #include <windows.h>
    #include <process.h>
    #define getpid _getpid
    #define OS_PATH '\\'

    #ifndef SIGKILL
        #define SIGKILL SIGABRT
    #endif
#elif OS_UNIX  
    #include <unistd.h>
    #include <signal.h>
    #define OS_PATH '/'
#else
    #error "System: Unix or Windows was not detected."
#endif


#define ERROR_H_ALLOWED
#include "error.h"

#define LOG(msg) fprintf(stderr,msg)

//#define __SIMD
#ifdef __SIMD 
    #define USE_SIMD 1
#endif




#endif
