#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include "color.h"


void buffer_init(int w, int h) ;
pixel_t *buffer_pixels(void);
void buffer_free(void);

void buffer_set(int x, int y, pixel_t p);

#endif