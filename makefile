TARGET = julia
CC = gcc
CFLAGS = -Wall -Wextra 
IGNOREFLAGS = -Wno-unused-parameter -Wno-unused-variable
INFLAGS = -Iinclude -Idisplay -Icore -Isrc

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    OS_TYPE = LINUX
else ifeq ($(UNAME_S),Darwin)
    OS_TYPE = MACOS
else ifeq ($(findstring CYGWIN_NT,$(UNAME_S)),CYGWIN_NT)
    OS_TYPE = CYGWIN
else ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
    OS_TYPE = MINGW
else
    OS_TYPE = UNKNOWN_UNIX
endif

ifeq ($(OS_TYPE),MINGW)
    IFLAGS = -I"C:/msys64/include" -I"C:/msys64/include/GL" -I./include -Iinc
    LDFLAGS = -lopengl32 -lglu32 -lfreeglut
    OUT = julia.exe
else
    IFLAGS = -I./include -Iinc
    LDFLAGS = -lGL -lGLU -lglut
    OUT = julia
endif

SRC = $(wildcard src/*.c) $(wildcard display/*.c)

# IGNOREFLAGS ON

all:
	$(CC) $(CFLAGS) $(INFLAGS) $(IFLAGS) $(SRC) -o $(OUT) $(LDFLAGS) 

run:

	./$(OUT)

clean:

	rm -f $(OUT)