CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = src/main.cpp
OUT = bin/shell

all:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)