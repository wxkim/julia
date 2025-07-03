#include "thread.h"

extern pixel_t *buffer;

static void* multithreaded_rendering(void* args) {
    thread_arg_t* t = (thread_arg_t*)(args);
    frame_dimensions_t* f = &t->frame_dimensions;

    for (uint32_t y = f->ybound_begin; y < f->ybound_end; ++y) {
        for (uint32_t x = f->xbound_begin; x < f->xbound_end; ++x) {
            // TODO MULTITHREADED RENDERING LOGIC

        }

    }
}



void launch_rendering_threads(int num_threads, thread_arg_t* thread_args) {
    pthread_t threads[max_thread_count];

    for (int i = 0; i < num_threads; ++i) {
        if(pthread_create(&threads[i], NULL, multithreaded_rendering, &thread_args[i]) != 0) {
            LOG("Failed to create thread. Halting execution...");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_threads; ++i) pthread_join(threads[i], NULL);
}

frame_dimensions_t* frame_delegation(int num_threads, int width, int height) {
    frame_dimensions_t* regions = malloc(sizeof(frame_dimensions_t) * num_threads);

    if(!regions) {
        LOG("Failed to allocate memory. Halting execution...");
        exit(EXIT_FAILURE);
    }

    uint32_t rows_per_thread = height / num_threads;
    uint32_t remainder = height % num_threads;

    uint32_t current_y = 0;

    for (int i = 0; i < num_threads; ++i) {
        uint32_t current_height = rows_per_thread + (i < remainder ? 1 : 0);

        regions[i] = (frame_dimensions_t) {
            xbound_begin = 0,
            ybound_begin = current_y,
            xbound_end = width,
            ybound_end = current_y + this_height,
            img_width = width,
            img_height = height
        }

        current_y += current_height;
    }

    return regions;
}