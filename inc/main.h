#include "GL/glut.h"
#include "julia.h"
#include "../core/core.h"
#include "../display/render.h"
#include "../display/buffer.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define USE_MANDELBROT   1       
#define ENABLE_FULLSCREEN 0 

void force_fullscreen(int awin);
void reshape_wrapper(int w, int h);
void display_wrapper();

void init_glut_instance(int argc, char **argv, int w, int h, char *window_name);