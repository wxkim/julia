//
// AUTHOR WILLIAM KIM
// DATE JUNE 6 2025
//

#include "main.h"

int width = 1280;
int height = 720;

void display_wrapper() {
    render_frame();
}

void reshape_wrapper(int w, int h) {
    render_resize(w, h);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    int awin = glutCreateWindow("Julia Fractal");

    glutFullScreen();
    glutSetWindow(awin);
    glutPopWindow();       
    glutShowWindow();
    glutPostRedisplay();

    render_init(width, height);
    buffer_init(width, height);
    glutDisplayFunc(display_wrapper);
    glutReshapeFunc(reshape_wrapper);

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            buffer_set(x, y, 0, 0, 0);

    glutMainLoop();
    return 0;
}