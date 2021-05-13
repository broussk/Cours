#include <cstdio>
#include "GeomBase.h"
#include "Surface.h"
#include "Curve.h"
#include "SVG.h"
#include "Figure.h"

int main() {
	using namespace Geom2D;

    Array::Static<Point, 4>  lp1 = { { 1,2 },{ 3,4 },{ 5,6 },{ 7,8 } };
    Array::Static<Point, 4> lp2(lp1);
    // Point p = Array::Geometry::Center(lp1);
    Array::Geometry::Translate(lp1, Point(1.f,2.f));
    Array::Geometry::Rotate(lp1, 2.f);
    Array::Geometry::Scale(lp1, 3.f);
    std::cout << lp1 << std::endl;
    std::cout << lp2 << std::endl;
    lp1 = lp2;
    std::cout << lp1 << std::endl;

	Figure fig({
		new Surface::Disk({ 100,100 }, 50),
		new Surface::Polygon(6,{ 100,400 }, 80, Color::blue),
		new Surface::Triangle({ 200,200 }, 150, Color::yellow),
		new Surface::Rectangle({ 400, 200 }, 200, 300, Color::cyan),
		new Surface::Square({ 200,400 }, 300, Color::green),
		new Curve::Circle({ 600,400 }, 300, Color::green, 4),
		new Curve::Polyline(4,{ 500,500 }, 80, Color::blue, 2),
		new Curve::Segment({ 100,200 },{ 500,300 },Color::turquoise,6)
	});

	fig.Translate(Point{2,3});
    fig.Rotate(2.f);
    fig.Scale(2.f);

	fig.info();
	fig.save("test04.html");

	return 0;
}