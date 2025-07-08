#include "args.h"



args_t config = {
    .fractal_type = FRACTAL_JULIA,
    .coloring = COLOR_GRADIENT,
    .applied_filter = FILTER_NONE,
    .output_file_type = OUTPUT_PNG,
    .windowd = WINDOW_WINDOWED,
    .multithread = 12,
    .starting_z = NULL,
    .starting_c = NULL,
    .starting_z_complex = {0},
    .starting_c_complex = {0.355, 0.355},
    .file_path_save = NULL,
    .help_wanted = 0
};


void print_help() {
    const char* help =
        "Usage: ./julia [flags]\n"
        "  --fractal <julia | mandelbrot>\n"
        "  --color <inverted | greyscale | gradient | flat | bw>\n"
        "  --filter <none | bayer | noise | floyd> ... (Coming Soon)\n"
        "  --output <png | ppm | jpg> ... (Coming Soon)\n"
        "  --fullscreen <fullscreen | windowed>\n"
        "  --multithread=<int>    [default: 12]\n"
        "  --starting-z=<float>(+)/(-)<float>i\n"
        "  --starting-c=<float>(+)/(-)<float>i\n"
        "  --save <path/filename> ... (Coming Soon)\n";
    
    
        printf("%s", help);
}

void parse_args(int argc, char** argv) {

    static struct option long_options[] = {
        {"fractal",      required_argument, 0, 'f'},
        {"color",        required_argument, 0, 'c'},
        {"filter",       required_argument, 0, 'l'},
        {"output",       required_argument, 0, 'o'},
        {"window",       required_argument, 0, 'w'},
        {"multithread",  required_argument, 0, 't'},
        {"starting-z",   required_argument, 0, 'z'},
        {"starting-c",   required_argument, 0, 'x'},
        {"save",         required_argument, 0, 's'},
        {"help",         no_argument,       0, 'h'},
        {0, 0, 0, 0}
    };

    int c;
    while ((c = getopt_long(argc, argv, "f:c:l:o:w:t:z:x:s:h", long_options, NULL)) != -1) {
        switch (c) {
            case 'f':
                if (strcmp(optarg, "julia") == 0)
                    config.fractal_type = FRACTAL_JULIA;
                else if (strcmp(optarg, "mandelbrot") == 0)
                    config.fractal_type = FRACTAL_MANDELBROT;
                else
                    fprintf(stderr, "[error] Unknown fractal type: %s\n", optarg);
                break;

            case 'c':
                if (strcmp(optarg, "inverted") == 0)
                    config.coloring = COLOR_INVERTED;
                else if (strcmp(optarg, "greyscale") == 0)
                    config.coloring = COLOR_GREYSCALE;
                else if (strcmp(optarg, "gradient") == 0)
                    config.coloring = COLOR_GRADIENT;
                else if (strcmp(optarg, "flat") == 0)
                    config.coloring = COLOR_FLAT_RGB;
                else if (strcmp(optarg, "bw") == 0)
                    config.coloring = COLOR_BLACK_WHITE;
                break;

            case 'l':
                if (strcmp(optarg, "bayer") == 0)
                    config.applied_filter = FILTER_D_BAYER;
                else if (strcmp(optarg, "noise") == 0)
                    config.applied_filter = FILTER_D_NOISE;
                else if (strcmp(optarg, "floyd") == 0)
                    config.applied_filter = FILTER_D_FLOYD;
                else
                    config.applied_filter = FILTER_NONE;
                break;

            case 'o':
                if (strcmp(optarg, "png") == 0)
                    config.output_file_type = OUTPUT_PNG;
                else if (strcmp(optarg, "ppm") == 0)
                    config.output_file_type = OUTPUT_PPM;
                else if (strcmp(optarg, "jpg") == 0)
                    config.output_file_type = OUTPUT_JPG;
                break;

            case 'w':
                if (strcmp(optarg, "fullscreen") == 0)
                    config.windowd = WINDOW_FULLSCREEN;
                else
                    config.windowd = WINDOW_WINDOWED;
                break;

            case 't':
                config.multithread = (uint8_t)atoi(optarg);
                break;

            case 'z':
                config.starting_z = &optarg;
                config.starting_z_complex = complex_from_str(optarg);
                break;

            case 'x':
                config.starting_c = &optarg;
                config.starting_c_complex = complex_from_str(optarg);
                break;

            case 's':
                config.file_path_save = &optarg;
                break;

            case 'h':
                config.help_wanted = 1;
                break;

            case '?':
            default:
                fprintf(stderr, "[error] Unknown or malformed option.\n");
                config.help_wanted = 1;
                break;
        }
    }

    if (config.help_wanted) {
        print_help();
        exit(0);
    }
}

complex_t complex_from_str(const char* str) {
    complex_t c = {0};

    char* i_ptr = strchr(str, 'i');
    if (!i_ptr) {
        fprintf(stderr, "Invalid complex format (missing 'i'): %s\n", str);
        return c;
    }

    char* plus_minus = NULL;
    for (char* p = (char*)str + 1; *p && p < i_ptr; p++) {
        if (*p == '+' || *p == '-') {
            plus_minus = p;
        }
    }

    if (!plus_minus) {
        fprintf(stderr, "Invalid complex format (missing + or - between real/imag): %s\n", str);
        return c;
    }

    char real_buf[32] = {0};
    char imag_buf[32] = {0};

    strncpy(real_buf, str, plus_minus - str);
    strncpy(imag_buf, plus_minus, i_ptr - plus_minus);

    c.re = atof(real_buf);
    c.im = atof(imag_buf);

    return c;
}

#include <stdio.h>

void print_config_summary() {
    printf("\n[CONFIG SUMMARY]\n");
    printf("  Fractal:         %s\n", config.fractal_type == FRACTAL_JULIA ? "Julia" : "Mandelbrot");
    
    const char* color_names[] = {
        "Inverted", "Greyscale", "Gradient", "Flat RGB", "Black & White"
    };
    printf("  Color Scheme:    %s\n", color_names[config.coloring]);

    const char* filter_names[] = {
        "None", "Bayer", "Noise", "Floyd–Steinberg"
    };
    printf("  Dithering:       %s\n", filter_names[config.applied_filter]);

    const char* output_names[] = {
        "PPM", "PNG", "JPG"
    };
    printf("  Output Format:   %s\n", output_names[config.output_file_type]);

    printf("  Window Mode:     %s\n", config.windowd == WINDOW_FULLSCREEN ? "Fullscreen" : "Windowed");
    printf("  Threads:         %d\n", config.multithread);
    printf("  Starting Z:      %.4f + %.4fi\n", config.starting_z_complex.re, config.starting_z_complex.im);
    printf("  Starting C:      %.4f + %.4fi\n", config.starting_c_complex.re, config.starting_c_complex.im);
    printf("  Save Path:       %s\n", config.file_path_save ? *config.file_path_save : "(not set)");
    printf("\n");
}
