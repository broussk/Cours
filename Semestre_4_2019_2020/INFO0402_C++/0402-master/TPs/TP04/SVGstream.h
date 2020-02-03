#ifndef _SVGSTREAM_H
#define _SVGSTREAM_H
#include <iostream>
#include <iomanip>
#include <fstream>

////////////////////////////////////////////////////////////////////////////////////////
class SVGstream : public std::ofstream {
private:
        inline void write_header(bool PureSVG = false) {
                (!PureSVG) && *this << "<!doctype html>";
                *this << "<svg width=\"1000\" height=\"1000\">\n";
        }
        inline void write_trailer() { *this << "<\\svg>\n"; }
public:
        void close() {
                if (is_open()) {
                        write_trailer();
                        std::ofstream::close();   // close h�rit�
                }
        }
        bool open(const char *fname, bool PureSVG = false) {
                close(); // c'est toujours la surcharge
                std::ofstream::open(fname, std::ios::out | std::ios::trunc); // open h�rit�
                bool status = is_open();
                if (status) write_header(PureSVG);
                return status;
        }
        SVGstream(const char *fname, bool PureSVG = false) :
                std::ofstream(fname, std::ios::out | std::ios::trunc) {
                if (is_open()) write_header(PureSVG);
        }
        ~SVGstream() { close(); }
        friend SVGstream& operator<<(SVGstream& s, const char *str) {
                std::ofstream &f = s;
								f << str;
                return s;
        }
};
#endif
