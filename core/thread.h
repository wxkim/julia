#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "color.h"
#include "buffer.h"
#include "core.h"

unsigned int max_thread_count = 64;

typedef struct {
    uint32_t  xbound_begin,
              ybound_begin,
              xbound_end,
              ybound_end,
              img_width,
              img_height;

} frame_dimensions_t

typedef struct {
    int32_t thread_id;
    uint32_t max_iter;
    frame_dimensions_t frame_dimensions;
    pixel_t *framebuffer;

} thread_arg_t;

void launch_rendering_threads(int num_threads, thread_arg_t* thread_args);

frame_dimensions_t* frame_delegation(int num_threads, int width, int height);

#endif
