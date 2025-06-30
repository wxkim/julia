#include "render.h"

static int win_width = 800;
static int win_height = 600;

void render_init(int width, int height) {
    win_width = width;
    win_height = height;
    glClearColor(0.2f, 0.2f, 0.25f, 1.0f); // light blue-gray
}

void render_resize(int width, int height) {
    win_width = width;
    win_height = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void render_frame(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(win_width/2 - 50, win_height/2 - 50);
        glVertex2f(win_width/2 + 50, win_height/2 - 50);
        glVertex2f(win_width/2 + 50, win_height/2 + 50);
        glVertex2f(win_width/2 - 50, win_height/2 + 50);
    glEnd();

    glutSwapBuffers();
}




