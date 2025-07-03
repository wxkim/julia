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
    render_frame(width, height);
}

void reshape_wrapper(int w, int h) {
    buffer_init(w, h);         
    julia_compute(w, h);      
    render_resize(w, h);       
}

// int main(int argc, char **argv) {
//     buffer_init(width, height);
//     buffer_dump_ppm("julia.ppm", width, height);
//     buffer_free();
//     return 0;
// }

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv) {
    // size_t size = 100 * sizeof(pixel_t);
    // pixel_t *buffer = (pixel_t *)calloc(100, sizeof(pixel_t));

    // if (buffer == NULL) {
    //     printf("Failed to allocate %zu bytes\n", size);
    //     return 1;
    // }

    // printf("Allocation success: first byte = %u\n", ((uint8_t *)buffer)[0]);

    // free(buffer);
    // return 0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);

    int awin = glutCreateWindow("Julia Fractal");
    //force_fullscreen(awin);

    buffer_init(width, height);
    julia_compute(width, height);
    render_init(width, height);

    
    //buffer_dump_ppm("julia.ppm", width, height);

    glutDisplayFunc(display_wrapper);
    glutReshapeFunc(reshape_wrapper);

    uint8_t* raw = (uint8_t*)buffer_pixels();
    printf("First pixel RGB: %d %d %d\n", raw[0], raw[1], raw[2]);

    glutPostRedisplay();

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


/*
glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(width, height);

    int awin = glutCreateWindow("Julia Fractal");
    //force_fullscreen(awin);

    buffer_init(width, height);
    //julia_compute(width, height);
    render_init(width, height);

    
    buffer_dump_ppm("julia.ppm", width, height);



    glutDisplayFunc(display_wrapper);
    glutReshapeFunc(reshape_wrapper);

    uint8_t* raw = (uint8_t*)buffer_pixels();
    printf("First pixel RGB: %d %d %d\n", raw[0], raw[1], raw[2]);

    glutPostRedisplay();

    glutMainLoop();
    return 0;*/