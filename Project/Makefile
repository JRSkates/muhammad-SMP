# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I src  # Add src directory to the include path for headers

# Files and directories
SRCDIR = src
BINDIR = bin
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SOURCES))
TARGET = $(BINDIR)/main

# Rules
all: $(TARGET)

# Link all object files to create the final executable
$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CC) -o $(TARGET) $(OBJECTS)

# Compile each .c file into an object file (doesn't assume corresponding .h file for every .c file)
$(BINDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -rf $(BINDIR)

# Run the program
run: $(TARGET)
	./$(TARGET)
