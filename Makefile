CC = g++
TARGET = Proyecto2
FILES := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.h)

$(TARGET): $(FILES) $(HEADERS) | bin
	$(CC) $^ -pthread -o bin/$@

bin:
	mkdir bin

.PHONY: run

run: $(TARGET)
	./bin/$(TARGET)
