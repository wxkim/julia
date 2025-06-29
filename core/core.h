#ifndef CORE_H
#define CORE_H

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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ERROR_H_ALLOWED
#include "error.h"

#define LOG(msg) fprintf(stderr,msg)

//#define __SIMD
#ifdef __SIMD 
    #define USE_SIMD 1
#endif


#endif
