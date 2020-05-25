#include "SVG.h"

void SVG::stream::write_header(bool PureSVG) {
	(!PureSVG) && *this << "<!doctype html>";
	*this << "<svg width=\"1000\" height=\"1000\">\n";
}

void SVG::stream::write_trailer() { 
	*this << "<\\svg>\n"; 
}

void SVG::stream::close() {
	if (is_open()) {
		write_trailer();
		std::ofstream::close();   // close h�rit�
	}
}

bool SVG::stream::open(const char *fname, bool PureSVG) {
	close(); // c'est toujours la surcharge
	std::ofstream::open(fname, std::ios::out | std::ios::trunc); // open h�rit�
	bool status = is_open();
	if (status) write_header(PureSVG);
	return status;
}

SVG::stream::stream(const char *fname, bool PureSVG) :
	std::ofstream(fname, std::ios::out | std::ios::trunc) {
	if (is_open()) write_header(PureSVG);
}

SVG::stream::~stream() { 
	close(); 
}


SVG::stream& SVG::operator<<(SVG::stream& s, const char *str) {
	std::ofstream &f = s;
	f << str;
	return s;
}
