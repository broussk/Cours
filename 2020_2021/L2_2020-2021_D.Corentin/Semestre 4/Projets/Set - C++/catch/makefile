CXX=g++
PROJ=unit-test
OBJ=$(PROJ).o
CPPFLAGS=-g -std=c++17 -Wall -Wconversion

$(PROJ): $(OBJ)
	$(CXX) $(OBJ) -o $@

all: clean $(PROJ)

clean:
	rm -f $(OBJ) $(PROJ)

$(OBJ): $(OBJ:.o=.cpp) catch.h
