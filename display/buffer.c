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

static uint8_t *buffer = NULL;
static int width = 0;
static int height = 0;

void buffer_init(int w, int h) {
    size_t size = 3 * w * h;
	buffer = malloc(size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void buffer_set(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    int index = (y * width + x) * 3;
    buffer[index + 0] = r;
    buffer[index + 1] = g;
    buffer[index + 2] = b;
}

uint8_t *buffer_pixels(void) {
    return buffer;
}

void buffer_free(void) {
    free(buffer);
}
 