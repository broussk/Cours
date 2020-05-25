#include "SVG.h"
#include "Surface.h"

namespace Geom2D {
	namespace Surface {
        // Fill
        std::ostream& operator<<(std::ostream& s, const Fill& p) {
            return s << "fill=" << p.getFillColor();
        }

		// Disk
        std::ostream& Disk::info(std::ostream& stream) const { return stream << *this; }

		std::ostream& operator<<(std::ostream& s, const Disk& d) {
			return s << "Disk[center=" << d.center << ",radius=" << d.radius 
				<< ",fill=" << d.fill_color << "]";
		}

		SVG::stream& operator<<(SVG::stream& s, const Disk& p) {
			s << "<circle "
				<< SVGarg(cx, p.center.getx()) << SVGarg(cy, p.center.gety())
				<< SVGarg(r, p.radius) << SVGarg(fill, p.fill_color)
				<< "/>\n";
			return s;
		}

		// Polygon
        std::ostream& Polygon::info(std::ostream& stream) const { return stream << *this; }

		std::ostream& operator<<(std::ostream& s, const Polygon& p) {
			const Array::Fixed<Point> &pp = p;
			return s << "Polygon[nVertex=" << p.size() << "," << pp
				<< ",fill=" << p.fill_color << "]";
		}

		SVG::stream& operator<<(SVG::stream& s, const Polygon& p) {
            const Array::Fixed<Point> &pp = p;
            s << "<polygon ";
            s << SVGarg(points, pp);
            s << p.fill_color;
            s << "/>\n";
            return s;
		}

		// Triangle
        std::ostream& Triangle::info(std::ostream& stream) const { return stream << *this; }

		std::ostream& operator<<(std::ostream& s, const Triangle& p) {
            const Array::Static<Point,3> &pp = p;
			return s << "Triangle["  << pp << ", fill=" << p.fill_color << "]";
		}

		SVG::stream& operator<<(SVG::stream& s, const Triangle& p) {
            const Array::Static<Point,3> &pp = p;
            s << "<polygon "<< SVGarg(points, pp) << SVGarg(fill, p.fill_color) << "/>\n";
			return s;
		}

		// Rectangle
        std::ostream& Rectangle::info(std::ostream& stream) const { return stream << *this; }

        std::ostream& operator<<(std::ostream& s, const Rectangle& d) {
			return s << "Rectangle[corner=" << d.corner
				<< ",width=" << d.width	 << ",height=" << d.height
				<< ",angle=" << d.rotate << ",fill=" << d.fill_color
				<<"]";
		}

		SVG::stream& operator<<(SVG::stream& s, const Rectangle& p) {
			s << "<rect"
				<< SVGarg(x, p.corner.getx()) << SVGarg(y, p.corner.gety())
				<< SVGarg(width, p.width) << SVGarg(height, p.height)
				<< SVGarg(fill, p.fill_color);
			if (p.rotate) {
				Point center(p.corner.getx() + p.width / 2.f, p.corner.gety() + p.height / 2.f);
				s << " transform=\"rotate(" << p.rotate << " "
					<< center.getx() << "," << center.gety() << ")\"";
			}
			s << "/>\n";
			return s;
		}

		// Square
        std::ostream& Square::info(std::ostream& stream) const { return stream << *this; }

        std::ostream& operator<<(std::ostream& s, const Square& d) {
			return s << "Square[corner=" << d.corner
				<< ",sidelen=" << d.width 
				<< ",fill=" << d.fill_color << "]";
		}
		SVG::stream& operator<<(SVG::stream& s, const Square& p) {
			const Rectangle& pp = p;
			return s << pp;
		}

	}
}