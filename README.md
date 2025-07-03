# Julia

## Fractal Renderer (Minimal C/OpenGL)

This project renders Julia fractals in C.

Developed on x86_64.

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
