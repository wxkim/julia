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
    .file_path_save = NULL,
    .help_wanted = 0
};

// settings_t

void print_help() {
    const char* help =
        "Usage: ./julia [flags]\n"
        "  --fractal <julia | mandelbrot>\n"
        "  --color <inverted | greyscale | gradient | flat | bw>\n"
        "  --filter <none | bayer | noise | floyd>\n"
        "  --output <png | ppm | jpg>\n"
        "  --fullscreen <fullscreen | windowed>\n"
        "  --multithread=<int>    [default: 12]\n"
        "  --starting-z=<float>+<float>i\n"
        "  --starting-c=<float>+<float>i\n"
        "  --save <path/filename>\n";
    
    
        printf("%s", help);
}

void parse_args(int argc, char** argv) {
    static struct option long_options[] = {
        {"fractal", required_argument, 0, 0},
        {"color", required_argument, 0, 0},
        {"filter", required_argument, 0, 0},
        {"output", required_argument, 0, 0},
        {"window", required_argument, 0, 0},
        {"multithread", required_argument, 0, 0},
        {"starting-z", required_argument, 0, 0},
        {"starting-c", required_argument, 0, 0},
        {"save", required_argument, 0, 0},
        {"help", no_argument, 0, 0},
        {0, 0, 0, 0}
    };

    while (1) {
        int option_index = 0;
        int c = getopt_long(argc, argv, "", long_options, &option_index);
        if (c == -1) break;

        const char* name = long_options[option_index].name;

        if (strcmp(name, "fractal") == 0) {
            if (strcmp(optarg, "julia") == 0) 
                config.fractal_type = FRACTAL_JULIA;
            else if (strcmp(optarg, "mandelbrot") == 0) 
                config.fractal_type = FRACTAL_MANDELBROT;
        }

        else if (strcmp(name, "color") == 0) {
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
        }

        else if (strcmp(name, "filter") == 0) {
            if (strcmp(optarg, "bayer") == 0) 
                config.applied_filter = FILTER_D_BAYER;
            else if (strcmp(optarg, "noise") == 0) 
                config.applied_filter = FILTER_D_NOISE;
            else if (strcmp(optarg, "floyd") == 0) 
                config.applied_filter = FILTER_D_FLOYD;
            else 
                config.applied_filter = FILTER_NONE;
        }

        else if (strcmp(name, "output") == 0) {
            if (strcmp(optarg, "png") == 0) 
                config.output_file_type = OUTPUT_PNG;
            else if (strcmp(optarg, "ppm") == 0) 
                config.output_file_type = OUTPUT_PPM;
            else if (strcmp(optarg, "jpg") == 0) 
                config.output_file_type = OUTPUT_JPG;
        }

        else if (strcmp(name, "window") == 0) {
            if (strcmp(optarg, "fullscreen") == 0) 
                config.windowd = WINDOW_FULLSCREEN;
            else 
                config.windowd = WINDOW_WINDOWED;
        }

        else if (strcmp(name, "multithread") == 0) {
            config.multithread = (uint8_t)atoi(optarg);
        }

        else if (strcmp(name, "starting-z") == 0) {
            config.starting_z = &optarg;
        }

        else if (strcmp(name, "starting-c") == 0) {
            config.starting_c = &optarg;
        }

        else if (strcmp(name, "save") == 0) {
            config.file_path_save = &optarg;
        }

        else if (strcmp(name, "help") == 0) {
            config.help_wanted = 1;
        }
    }

    if (argc == 1 || config.help_wanted) {
        print_help();
        exit(0);
    }
}
