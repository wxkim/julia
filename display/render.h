#ifndef RENDER_H
#define RENDER_H

#include <GL/glut.h>
#include <stdint.h>
#include "buffer.h"

void render_init(int width, int height);
void render_frame(void);
void render_resize(int width, int height);




#endif 