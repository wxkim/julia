#ifndef ERROR_H
#define ERROR_H

#pragma once

#ifndef ERROR_H_ALLOWED
    #error "Do not include 'error.h' directly. Include 'core.h' instead."
#endif


#include <string.h>
#include <stdio.h>
#include <unistd.h> 
#include <signal.h>


__attribute__((noreturn)) static inline void error_fatal(const char* msg) {
    if (msg) {
        write(STDERR_FILENO, msg, strlen(msg));
        write(STDERR_FILENO, "\n", 1);
    }

    raise(SIGKILL);
    __builtin_unreachable();
}

__attribute__((noreturn)) static inline void error_terminate(const char* msg) {
    if (msg) {
        write(STDERR_FILENO, msg, strlen(msg));
        write(STDERR_FILENO, "\n", 1);
    }

    raise(SIGTERM);
    __builtin_unreachable();
}

__attribute__((noreturn)) static inline void error_fpe(const char* msg) {
    if (msg) {
        write(STDERR_FILENO, msg, strlen(msg));
        write(STDERR_FILENO, "\n", 1);
    }

    raise(SIGFPE);
    __builtin_unreachable();
}

static inline void error_warning(const char* msg) {
    if (msg) {
        write(STDERR_FILENO, "Warning: ", 9);
        write(STDERR_FILENO, msg, strlen(msg));
        write(STDERR_FILENO, "\n", 1);
    }
}


#endif