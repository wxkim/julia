//
// AUTHOR WILLIAM KIM
// DATE JUNE 6 2025
//

#include "main.h"

int width = 800;
int height = 600;

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
    glutCreateWindow("Julia Fractal - Test");

    render_init(width, height);

    glutDisplayFunc(display_wrapper);
    glutReshapeFunc(reshape_wrapper);

    glutMainLoop();
    return 0;
}