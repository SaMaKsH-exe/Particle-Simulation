# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Target executable
TARGET = particle_sim.exe

# Source files
SRC = main.c

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Clean build files
clean:
	del /Q $(TARGET)

# Run the program
run: $(TARGET)
	.\$(TARGET)

.PHONY: all clean run
