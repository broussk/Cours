#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Figure.h"

Figure::~Figure() {
	for (size_t i = 0; i < size(); i++) delete tab[i];
	// destruction du tableau assuré par le destructeur de Dynamic
}

void Figure::Translate(const Geom2D::Point &v) {
	for (size_t i = 0; i < size(); i++) tab[i]->Translate(v);
}

void Figure::Scale(float s) {
	for (size_t i = 0; i < size(); i++) tab[i]->Scale(s);
}

void Figure::Rotate(float a) {
	for (size_t i = 0; i < size(); i++) tab[i]->Rotate(a);
}

void Figure::info() {
	for (size_t i = 0; i < size(); i++) {
		std::cout << std::setw(2) << i << ": ";
		tab[i]->info(std::cout);
		std::cout << std::endl;
	}
}

// sauvegarde
void Figure::save(const char *fname) {
	SVG::stream   output(fname);
	for (size_t i = 0; i < size(); i++) tab[i]->write(output);
	output.close();
}
