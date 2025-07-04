#include "thread.h"


// #include "../core/core.h"
// #include "../display/color.h"
// #include "../display/buffer.h"
// #include "../core/thread.h"
#include "../inc/julia.h"

static void* multithreaded_rendering(void* args) {
    thread_arg_t* t = (thread_arg_t*)(args);

    frame_dimensions_t* f = &t->frame_dimensions;

    t->fractal_type_fn(f, t->framebuffer, t->max_iter);

    return NULL;
}

void launch_rendering_threads(int num_threads, thread_arg_t* thread_args) {
    pthread_t threads[MAX_THREADS];

    if(num_threads > MAX_THREADS) 
        error_warning("High thread count! \n");

    for (int i = 0; i < num_threads; ++i) {
        if(pthread_create(&threads[i], NULL, multithreaded_rendering, &thread_args[i]) != 0) {
            error_fatal("Failed to create thread. SIGKILL triggered. \n");
        }
    }

    for (int i = 0; i < num_threads; ++i) pthread_join(threads[i], NULL);
}

frame_dimensions_t* frame_delegation(int num_threads, int width, int height) {
    frame_dimensions_t* regions = malloc(sizeof(frame_dimensions_t) * num_threads);

    if(!regions) {
        error_fatal("Failed to allocate memory. SIGKILL triggered. \n");
    }

    uint32_t rows_per_thread = height / num_threads;
    uint32_t remainder = height % num_threads;

    uint32_t current_y = 0;

    for (int i = 0; i < num_threads; ++i) {
        uint32_t current_height = rows_per_thread + ((uint32_t) i < (uint32_t) remainder ? 1 : 0);

        regions[i] = (frame_dimensions_t) {
            .xbound_begin = 0,
            .ybound_begin = current_y,
            .xbound_end = width,
            .ybound_end = current_y + current_height,
            .img_width = width,
            .img_height = height
        };

        current_y += current_height;
    }

    return regions;
}