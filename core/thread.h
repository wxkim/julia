#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "core.h"
#include "../display/color.h"
#include "../display/buffer.h"
#include "../inc/julia.h"

#define MAX_THREADS 64

void launch_rendering_threads(int num_threads, thread_arg_t* thread_args);
frame_dimensions_t* frame_delegation(int num_threads, int width, int height);

#endif
