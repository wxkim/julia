# Julia

## Fractal Renderer (Minimal C/OpenGL)

This project renders Julia fractals using custom-implemented math functions in C, avoiding standard libraries except OpenGL for visualization. It is intended for low-level exploration of complex arithmetic, numerical methods, and graphics.

Developed on Windows 11 Pro (x86_64).

## Features

- Custom math back end (supports complex numbers, trig, and rational algorithms)
- Custom complex number type and operations
- Polar/phasor support for rotation and scaling
- OpenGL rendering via GLUT
- Abstracted for multi platform

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
.
├── README.md
├── makefile
├── core
│   ├── core.h
│   └── error.h
├── display
│   ├── buffer.c
│   ├── buffer.h
│   ├── color.c
│   ├── color.h
│   ├── render.c
│   └── render.h
├── inc
│   ├── complex.h
│   ├── julia.h
│   ├── main.h
│   └── math.h
└── src
    ├── complex.c
    ├── julia.c
    ├── main.c
    └── math.c

5 directories, 19 files

```
