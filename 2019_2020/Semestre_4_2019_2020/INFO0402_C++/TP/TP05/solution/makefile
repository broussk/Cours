CPPFLAGS= -std=c++17 -g -Wall -Wconversion
SRCs=Curve.cpp Figure.cpp GeomBase.cpp Surface.cpp SVG.cpp main.cpp
OBJs=$(SRCs:.cpp=.o)
LDLIBs=
EXE=TPmain
CXX=g++

$(EXE): $(OBJs)
	$(CXX) $(OBJs) $(LDLIBs) -o $@

clean:
	rm -f $(OBJs) $(EXE)

Curve.o: SVG.h Curve.h GeomBase.h Array.h
Figure.o: Figure.h GeomBase.h SVG.h Array.h
GeomBase.o: GeomBase.h SVG.h
main.o: GeomBase.h SVG.h Surface.h Array.h Curve.h Figure.h
Surface.o: SVG.h Surface.h GeomBase.h Array.h
SVG.o: SVG.h
