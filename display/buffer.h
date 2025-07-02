#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>

void buffer_set(int w, int h);
void buffer_init(int x, int y, uint8_t r, uint8_t g, uint8_t b);
uint8_t *buffer_pixels(void);
void buffer_free(void);


#endif