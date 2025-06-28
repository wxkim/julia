# Julia 

## Fractal Renderer (Minimal C/OpenGL)

This project renders Julia fractals using custom-implemented math functions in C, avoiding standard libraries except OpenGL for visualization. It is intended for low-level exploration of complex arithmetic, numerical methods, and graphics.

Developed on Windows 11 Pro (x86_64).

## Features

- Manual implementation of `sin`, `cos`, `tan`, `sqrt`, `abs`, and other math utilities
- Custom complex number type and operations 
- Polar/phasor support for rotation and scaling
- OpenGL rendering via GLUT
- Abstracted


## Build and Run

Make sure you have OpenGL and GLUT development libraries installed. Install `make` to support the `makefile`.

> If you are on Windows, use MINGW64.

### To build:
```bash
make
```

### To run:
```bash
make run
```

### To clean:
```bash
make clean
```

## Directory Structure

```.
├── README.md
├── makefile
├── inc
│   ├── complex.h
│   ├── error.h
│   ├── julia.h
│   ├── main.h
│   └── math.h
└── src
    ├── complex.c
    ├── error.c
    ├── julia.c
    ├── main.c
    └── math.c

3 directories, 13 files
```