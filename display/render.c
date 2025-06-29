#include "render.h"

static int window_width, window_length;

void render_init(int width, int height) {
    win_width = width;
    win_height = height;
    glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
    buffer_init(width, height);
    
}


void render_frame(void) {
    win_width = width;
    win_height = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    buffer_resize(width, height);
}


void render_resize(int width, int height) {
    glClear(GL_COLOR_BUFFER_BIT);

    glRasterPos2i(0, 0);
    glDrawPixels(win_width, win_height, GL_RGB, GL_UNSIGNED_BYTE, buffer_pixels());

    glutSwapBuffers();
}


