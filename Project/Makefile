CC = gcc
OBJECTS = $(wildcard src/*.c)
TARGET = bin/main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p bin
	$(CC) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf bin/*

run: $(TARGET)
	./$(TARGET)