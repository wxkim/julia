//
// AUTHOR: William Kim
// DATE:   June 6, 2025
//

#include "main.h"

static int window_width = WINDOW_WIDTH;
static int window_height = WINDOW_HEIGHT;
extern pixel_t *buffer;

void display_wrapper(void);
void reshape_wrapper(int w, int h);
void force_fullscreen(int window_id);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(window_width, window_height);

    int win = glutCreateWindow(USE_MANDELBROT ? "Mandelbrot Fractal" : "Julia Fractal");

    #if ENABLE_FULLSCREEN //turn this into CLI Arg
        force_fullscreen(win);
        window_width = 1920;
        window_height = 1080;
    #endif

    buffer_init(window_width, window_height);

    #if USE_MANDELBROT //turn this into CLI Arg
        mandelbrot_compute(window_width, window_height);
    #else
        julia_compute(window_width, window_height);
    #endif

    render_init(window_width, window_height);

    glutDisplayFunc(display_wrapper);
    glutReshapeFunc(reshape_wrapper);

    glutPostRedisplay();
    glutMainLoop();

    return 0;
}

void display_wrapper(void) {
    render_frame(window_width, window_height);
}

void reshape_wrapper(int w, int h) {
    window_width = w;
    window_height = h;

    buffer_init(w, h);

#if USE_MANDELBROT
    mandelbrot_compute(w, h);
#else
    julia_compute(w, h);
#endif

    render_resize(w, h);
}

void force_fullscreen(int window_id) {
    glutFullScreen();
    glutSetWindow(window_id);
    glutPopWindow();
    glutShowWindow();
    glutPostRedisplay();
}
