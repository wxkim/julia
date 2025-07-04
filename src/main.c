//
// AUTHOR: William Kim
// DATE:   June 28, 2025
//


#include "../core/core.h"
#include "../core/thread.h"
#include "../display/color.h"
#include "../display/buffer.h"

#include "main.h"
#include "julia.h"

static int window_width = WINDOW_WIDTH;
static int window_height = WINDOW_HEIGHT;

extern pixel_t *buffer;


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(window_width, window_height);

    int win = glutCreateWindow("Fractal");

    init_rendering(window_width, window_height, mandelbrot_compute);

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

void init_rendering(int w, int h, fractal_compute_fn_t fn) {
    buffer_init(w, h);
    pixel_t* framebuffer = buffer_pixels();

    int num_threads = 8;
    frame_dimensions_t* regions = frame_delegation(num_threads, w, h);

    thread_arg_t thread_args[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        thread_args[i] = (thread_arg_t){
            .thread_id = i,
            .max_iter = 1000,
            .frame_dimensions = regions[i],
            .framebuffer = framebuffer,
            .fractal_type_fn = fn
        };
    }

    launch_rendering_threads(num_threads, thread_args);
    free(regions);
}

void reshape_wrapper(int w, int h) {
    window_width = w;
    window_height = h;

    buffer_init(w,h);

    pixel_t* framebuffer = buffer_pixels();

    int num_threads = 8;
    frame_dimensions_t* regions = frame_delegation(num_threads, w, h);

    thread_arg_t thread_args[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        thread_args[i] = (thread_arg_t){
            .thread_id = i,
            .max_iter = 1000,
            .frame_dimensions = regions[i],
            .framebuffer = framebuffer,
            .fractal_type_fn = julia_compute
        };
    }

    launch_rendering_threads(num_threads, thread_args);
    free(regions);

    render_resize(w, h);
}

void force_fullscreen(int window_id) {
    glutFullScreen();
    glutSetWindow(window_id);
    glutPopWindow();
    glutShowWindow();
    glutPostRedisplay();
}
