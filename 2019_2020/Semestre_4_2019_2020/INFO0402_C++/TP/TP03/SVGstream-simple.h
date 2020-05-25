#ifndef _SVGSTREAM_H
#define _SVGSTREAM_H
#include <iostream>
#include <iomanip>
#include <fstream>

////////////////////////////////////////////////////////////////////////////////////////
class SVGstream {
private:
        std::ofstream    svgstream;
        inline void write_header(bool PureSVG = false) {
                if (!PureSVG) svgstream << "<!doctype html>";
                svgstream << "<svg width=\"1000\" height=\"1000\">\n";
        }
        inline void write_trailer() { *this << "<\\svg>\n"; }
public:
        void close() {
                if (svgstream.is_open()) {
                        write_trailer();
                        svgstream.close();
                }
        }
        bool open(const char *fname, bool PureSVG = false) {
                close();
                svgstream.open(fname, std::ios::out | std::ios::trunc);
                bool status = svgstream.is_open();
                if (status) write_header(PureSVG);
                return status;
        }
        SVGstream(const char *fname, bool PureSVG = false) :
                svgstream(fname, std::ios::out | std::ios::trunc) {
                if (svgstream.is_open()) write_header(PureSVG);
        }
        ~SVGstream() { svgstream.close(); }
        friend SVGstream& operator<<(SVGstream& s, const char *str) {
                std::ofstream &f = s.svgstream;
								f << str;
                return s;
        }
};
#endif
