#ifndef _SVG_H
#define _SVG_H
#include <fstream>

////////////////////////////////////////////////////////////////////////////////////////
namespace SVG {
	class stream : public std::ofstream {
	private:
		void write_header(bool PureSVG = false);
		void write_trailer();
	public:
		void close();
		bool open(const char *fname, bool PureSVG = false);
		stream(const char *fname, bool PureSVG = false);
		~stream();
		friend stream& operator<<(stream& s, const char *str);
	};

	class Write {
	protected:
		virtual void write(SVG::stream&) const = 0;
	};

    stream& operator<<(stream& s, const char *str);
}


#define SVGarg(p,v) " " #p "=\"" << v << "\" "
#define SVGstr(p,v) " " p "=\"" << v << "\" "

#endif