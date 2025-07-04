#include "GL/glut.h"
#include "julia.h"

#include "../core/core.h"
#include "../core/thread.h"
#include "../display/render.h"
#include "../display/buffer.h"
#include "../core/args.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void display_wrapper(void);
void reshape_wrapper(int w, int h);
void force_fullscreen(int window_id);
void init_rendering(int w, int h, fractal_compute_fn_t fn);

void init_glut_instance(int argc, char **argv, int w, int h, char *window_name);