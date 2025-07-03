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
#include <assert.h>

static pixel_t *buffer = NULL;
static int width = 1280;
static int height = 720;

void buffer_init(int w, int h) {
    size_t size = sizeof(pixel_t) * w * h;

	buffer = calloc((size_t)(w*h), sizeof(pixel_t));
    assert(buffer != NULL && "Failed to allocate display buffer");
    width = w;
    height = h;
}

pixel_t *buffer_pixels(void) {
    return buffer;
}

void buffer_free(void) {
    free(buffer);
}
 
void buffer_set(int x, int y, pixel_t p) {
    assert(buffer != NULL);
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    int flipped_y = height - 1 - y;
    buffer[flipped_y * width + x] = p;
}

#ifdef DEBUG

    void buffer_dump_ppm(const char *filename, int width, int height) {
        FILE *fp = fopen(filename, "wb");
        if (!fp) {
            perror("PPM file open failed");
            return;
        }

        fprintf(fp, "P6\n%d %d\n255\n", width, height);

        for (int y = height - 1; y >= 0; y--) {
            fwrite(&buffer_pixels()[y * width], sizeof(pixel_t), width, fp);
        }

        fclose(fp);
    }

#endif