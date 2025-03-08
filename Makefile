# Compiler
CC := gcc

# Compiler flags (optional, can be modified)
CFLAGS := -Wall -Wextra -O2

# Source and output files
SRC := main.c
OUT := main

# Default target: Compile, build, and run the program
all: build run

# Compile and build
build:
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@echo "Build successful!"

# Run the program
run:
	@echo "Running the program..."
	@./$(OUT)

# Clean up generated files
clean:
	@rm -f $(OUT)
	@echo "Cleaned up!"
