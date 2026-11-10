
CXX = g++
CXXFLAGS = -std=c++17 -Wall -IInclude
RAYLIB = $(shell pkg-config --cflags --libs raylib)
TARGET = main
SOURCES = $(wildcard *.cpp) \
          $(wildcard Map/*.cpp) \
          $(wildcard MovingThings/*.cpp) \
          $(wildcard Frontend/*.cpp)
all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(RAYLIB)
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)

.PHONY: all run clean
