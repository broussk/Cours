CPPFLAGS= -std=c++17 -g -Wall -Wconversion
EXE1=main-static
EXE2=main-fixed
EXE3=main-dynamic

SRC1=$(EXE1).cpp
SRC2=$(EXE2).cpp
SRC3=$(EXE3).cpp
OBJ1=$(SRC1:.cpp=.o)
OBJ2=$(SRC2:.cpp=.o)
OBJ3=$(SRC3:.cpp=.o)
LDLIBs=
CXX=g++

all: $(EXE1) $(EXE2) $(EXE3)
$(EXE1): $(OBJ1)
	$(CXX) $(OBJ1) $(LDLIBs) -o $@
$(EXE2): $(OBJ2)
	$(CXX) $(OBJ2) $(LDLIBs) -o $@
$(EXE3): $(OBJ3)
	$(CXX) $(OBJ3) $(LDLIBs) -o $@
clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(EXE1) $(EXE2) $(EXE3)

main-static.o: Array.h classA.h ObjectCounters.h
main-fixed.o: Array.h classA.h ObjectCounters.h
main-dynamic.o: Array.h classA.h ObjectCounters.h
