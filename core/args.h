#ifndef ARGS_H
#define ARGS_H

#include <stdint.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/complex.h"

typedef enum {
    FRACTAL_MANDELBROT,
    FRACTAL_JULIA
} fractal_t;

typedef enum {
    COLOR_INVERTED,
    COLOR_GREYSCALE,
    COLOR_GRADIENT,
    COLOR_FLAT_RGB,
    COLOR_BLACK_WHITE
} color_scheme_t;

typedef enum {  
    FILTER_NONE,
    FILTER_D_BAYER,
    FILTER_D_NOISE,
    FILTER_D_FLOYD
} filtering_option_t;

typedef enum {  
    OUTPUT_PPM,
    OUTPUT_PNG, 
    OUTPUT_JPG
} output_format_t;

typedef enum {
    WINDOW_FULLSCREEN,
    WINDOW_WINDOWED
} window_t;

typedef struct {
    fractal_t fractal_type;
    color_scheme_t coloring;
    filtering_option_t applied_filter;
    output_format_t output_file_type;
    window_t windowd;
    uint8_t multithread;
    char** starting_z;
    char** starting_c;
    complex_t starting_z;
    complex_t starting_c;
    char** file_path_save;
    int help_wanted;
} args_t;

void parse_args(int argc, char** argv);

#endif