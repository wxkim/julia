#include "buffer.h"

#ifdef _WIN32
    #include <malloc.h>
    #define aligned_malloc(size, align) _aligned_malloc(size, align)
    #define aligned_free(ptr) _aligned_free(ptr)
#else
    #define aligned_malloc(size, align) aligned_alloc(align, ((size + align - 1) / align) * align)
    #define aligned_free(ptr) free(ptr)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

static pixel_t *buffer = NULL;
static int width = 0;
static int height = 0;

void buffer_init(int w, int h) {
    size_t size = sizeof(pixel_t) * w * h;

	buffer = malloc(size);

    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

pixel_t *buffer_pixels(void) {
    return buffer;
}

void buffer_free(void) {
    free(buffer);
}
 
void buffer_set(int x, int y, pixel_t p) {
    buffer[y * width + x] = p;
}