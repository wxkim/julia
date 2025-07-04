# Julia

[![Linux](https://github.com/wxkim/julia/actions/workflows/linux.yml/badge.svg)](https://github.com/wxkim/julia/actions/workflows/linux.yml)

## Fractal Renderer (Minimal C/OpenGL)

This project renders Julia fractals in C using multithreading.

Developed on x86_64.

## Build and Run

Make sure you have OpenGL and GLUT development libraries installed. Install `make` to support the `makefile`.

> If you are on Windows, use MINGW64.

### To build:

```bash
make -jN
```

### To run:

```bash
make run
```

### To clean:

```bash
make clean
```

### All in one command on default settings:

```bash
clear; make clean; make; make run
```

## Arguments

## Directory Structure

```.
├── README.md
├── core
│   ├── args.c
│   ├── args.h
│   ├── core.h
│   ├── error.h
│   ├── thread.c
│   └── thread.h
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
│   └── pmath.h
├── julia.exe
├── makefile
└── src
    ├── complex.c
    ├── julia.c
    ├── main.c
    └── pmath.c

5 directories, 23 files


```
