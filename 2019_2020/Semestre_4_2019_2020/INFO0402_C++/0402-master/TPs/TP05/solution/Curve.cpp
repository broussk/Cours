#include "SVG.h"
#include "Curve.h"

namespace Geom2D {
	namespace Curve {
		// stroke
		std::ostream& operator<<(std::ostream& s, const Stroke& p) {
			return s << "stroke=" << p.stroke_color << ",width=" << p.stroke_width;
		}

		SVG::stream& operator<<(SVG::stream& s, const Stroke& p) {
			s << SVGstr("stroke", p.stroke_color);
			s << SVGstr("stroke-width", p.stroke_width);
			s << " fill=\"none\" ";
			return s;
		}

		// Circle
		std::ostream& operator<<(std::ostream& s, const Circle& d) {
			return s << "Circle[center=" << d.center << ",radius=" << d.radius
				<< "," << d.getStroke()	<< "]";
		}

		SVG::stream& operator<<(SVG::stream& s, const Circle& p) {
			s << "<circle "
				<< SVGarg(cx, p.center.getx()) << SVGarg(cy, p.center.gety())
				<< SVGarg(r, p.radius);
			s << p.getStroke();
			s << "/>\n";
			return s;
		}

		// Polyline
		std::ostream& operator<<(std::ostream& s, const Polyline& p) {
			const Array::Fixed<Point> &pp = p;
			return s << "Polyline[nVertex=" << p.size() << "," << pp << "," << p.getStroke() << "]";
		}

		SVG::stream& operator<<(SVG::stream& s, const Polyline& p) {
            const Array::Fixed<Point> &pp = p;
            s << "<polygon ";
            s << SVGarg(points, pp);
            s << p.getStroke();
            s << "/>\n";
			return s;
		}

		// Segment
		std::ostream& operator<<(std::ostream& s, const Segment& p) {
            const Array::Static<Point,2>  &pp = p;
			return s << "Segment[" << pp << "," << p.getStroke() << "]";
		}

		SVG::stream& operator<<(SVG::stream& s, const Segment& p) {
            const Array::Static<Point,2>  &pp = p;
			s << "<polygon " << SVGarg(points, pp) << p.getStroke() << "/>\n";
            return s;
		}

	}
}