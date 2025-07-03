//
// AUTHOR WILLIAM KIM
// DATE JUNE 6 2025
//

#include "main.h"
#include "complex.h"
#include "julia.h"
#include "../core/core.h"
#include "../display/render.h"
#include "../display/buffer.h"


const int width = 1280;
const int height = 720;

extern pixel_t *buffer;

void display_wrapper() {
    render_frame();
}

void reshape_wrapper(int w, int h) {
    render_resize(w, h);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    int awin = glutCreateWindow("Julia Fractal");

    force_fullscreen(awin);

    buffer_init(width, height);
    
    julia_compute(width, height);

    render_init(width, height);
    buffer_init(width, height);
    glutDisplayFunc(display_wrapper);
    glutReshapeFunc(reshape_wrapper);

    glutMainLoop();
    return 0;
}

void force_fullscreen(int awin) {
    glutFullScreen();
    glutSetWindow(awin);
    glutPopWindow();       
    glutShowWindow();
    glutPostRedisplay();
}