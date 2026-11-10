
# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -IInclude

# Raylib configuration
RAYLIB = $(shell pkg-config --cflags --libs raylib)

# Executable name
TARGET = main

# All C++ source files
SOURCES = $(wildcard *.cpp) \
          $(wildcard Map/*.cpp) \
          $(wildcard MovingThings/*.cpp) \
          $(wildcard Frontend/*.cpp)

# Default target
all: $(TARGET)

# Compile the game
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(RAYLIB)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Remove compiled executable
clean:
	rm -f $(TARGET)

.PHONY: all run clean
