TARGET = julia
CC = gcc
CFLAGS = -Wall -Wextra -I"C:/msys62/include" -I"C:/msys64/include/GL" 
IFLAGS = -I./include -Iinc
LDFLAGS = -lopengl32 -lglu32 -lfreeglut
SRC = src/main.C
OUT = julia.exe



all:

	$(CC) $(CFLAGS) $(IFLAGS) $(SRC) -o $(TARGET).exe $(LDFLAGS)

run:

	./$(OUT)

clean:

	rm -f $(OUT)