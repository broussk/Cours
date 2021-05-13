CXX=g++
PROJ=set
OBJ=main.o
OBJint=main-int.o
CPPFLAGS=-g -std=c++17 -Wall -Wconversion

$(PROJ): $(OBJ)
	$(CXX) $(OBJ) -o $@

$(PROJ)-int: $(OBJint)
	$(CXX) $(OBJint) -o $@

all: clean $(PROJ) $(PROJ)-int

clean:
	rm -f $(OBJ) $(OBJint) $(PROJ) $(PROJ)-int
	make -C catch clean

$(OBJ):     $(OBJ:.o=.cpp) $(PROJ).h
$(OBJint):  $(OBJint:.o=.cpp) $(PROJ)-int.h
