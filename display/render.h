#ifndef RENDER_H
#define RENDER_H

#include <GL/glut.h>
#include <stdint.h>
#include "buffer.h"

void render_init(int w, int h);
void render_frame(int w, int h);
void render_resize(int w, int h);

#endif 