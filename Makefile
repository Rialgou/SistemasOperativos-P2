CC = g++
TARGET = Proyecto2
FILES := $(wildcard src/*.c)
HEADERS := $(wildcard src/*.h)

$(TARGET): $(FILES) $(HEADERS) | bin
	$(CC) $^ -o bin/$@

bin:
	mkdir bin

.PHONY: run

run: $(TARGET)
	./bin/$(TARGET)
