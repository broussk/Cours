#include <string>
#include "SVGstream.h"
#include "Color.h"

constexpr float pi_f = 3.14159265358979323846f;

////////////////////////////////////////////////////////////////////////////////////////
struct Point {
    float x, y;
    inline Point() : x(0), y(0) {};
    inline Point(float u, float v) : x(u), y(v) {};
    inline void set(float u, float v) { x = u; y = v; }
    inline void operator+=(const Point &p) { x += p.x; y += p.y;  }
    friend inline std::ostream& operator<<(std::ostream& s, const Point& p) {
        return s << "(" << p.x << "," << p.y << ")";
    }
    friend inline SVGstream& operator<<(SVGstream& s, const Point& p) {
        s << p.x << "," << p.y;
        return s;
    }
};

////////////////////////////////////////////////////////////////////////////////////////
// interface transformation
class Transform {
public:
	virtual void Translate(const Point &p) = 0;
	virtual void Rotate(float a) = 0;
	virtual void Scale(float s) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////
// interface FillProperty
class FillProperty {
protected:
	Color   fill_color;
public:
	explicit FillProperty(const Color &c = Color::red) : fill_color(c) {};
	void setFillColor(const Color &c) { fill_color = c; }
};

////////////////////////////////////////////////////////////////////////////////////////
///  object géométrique
class Geom2D : public Transform {
public:
    // tous les constructeurs sont ceux par défaut
	virtual std::ostream& info(std::ostream&) const = 0;
	virtual SVGstream& write(SVGstream&) const = 0;
	virtual ~Geom2D();
    friend std::ostream& operator<<(std::ostream& s, const Geom2D *g) {
        return g->info(s);
    }
    friend SVGstream& operator<<(SVGstream& s, const Geom2D *g) {
        return g->write(s);
    }
};
Geom2D::~Geom2D() = default;

////////////////////////////////////////////////////////////////////////////////////////
///  Surface
class Surface : 
	public Geom2D,      
	public FillProperty 
{
public:
	Surface() : Geom2D(), FillProperty() {}
	explicit Surface(const Color &c) : FillProperty(c) {}
    virtual std::ostream& info(std::ostream&) const = 0;
    virtual SVGstream& write(SVGstream&) const = 0;
	virtual float area() = 0;
	virtual ~Surface();
    friend std::ostream& operator<<(std::ostream& s, const Surface *g) {
        return g->info(s);
    }
    friend SVGstream& operator<<(SVGstream& s, const Surface *g) {
        return g->write(s);
    }
};
Surface::~Surface() = default;

////////////////////////////////////////////////////////////////////////////////////////
///  Disk
#define SVGarg(p,v) " " #p "=\"" << v << "\" "

class Disk : public Surface {
protected: 
	Point center;
	float radius;
public:
	Disk(const Point &xy, float r, const Color &c) 
		: Surface(c), center(xy), radius(r) {}
	float area() { return pi_f*radius*radius; }
	virtual ~Disk() {};
	void Translate(const Point &v) { center += v; }
	void Scale(float s) { radius *= s; }
	void Rotate(float a) {};
    std::ostream& info(std::ostream& s) const {
        return s << "Disk[center=" << center << ",radius=" << radius << "]" << std::endl;
    }
    SVGstream& write(SVGstream &s) const {
        s << "<circle "
          << SVGarg(cx, center.x) << SVGarg(cy, center.y)
          << SVGarg(r, radius) << SVGarg(fill, fill_color)
          << "/>\n";
        return s;
    }
	friend std::ostream& operator<<(std::ostream& s, const Disk& d) { return d.info(s); }
	friend SVGstream& operator<<(SVGstream& s, const Disk& d) { return d.write(s); }
};


////////////////////////////////////////////////////////////////////////////////////////
///  Rectangle
class Rectangle : public Surface {
protected:
	Point corner;
	float width, height;
	float rotate;
public:
	explicit Rectangle(const Point &xy, float w, float h, const Color &c)
		: Surface(c), corner(xy), width(w), height(h), rotate(0.f) {}
	float area() { return width*height; }
	virtual ~Rectangle() {};
	void Translate(const Point &v) { corner += v; }
	void Scale(float s) { width *= s; height *= s; }
	void Rotate(float a) { rotate += a; }
	Rectangle *real_type() { return this; }

    std::ostream& info(std::ostream& s) const {
        return s << "Rectangle[corner=" << corner
                 << ",width="  << width
                 << ",height=" << height
                 << "]" << std::endl;
    }
    SVGstream& write(SVGstream &s) const {
        s << "<rect"
          << SVGarg(x, corner.x) << SVGarg(y, corner.y)
          << SVGarg(width, width) << SVGarg(height, height)
          << SVGarg(fill, fill_color);
        if (rotate) {
            Point center(corner.x + width/2.f, corner.y + height/2.f);
            s << " transform=\"rotate(" << rotate << " "
              << center.x << "," << center.y << ")\"";
        }
        s << "/>\n";
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const Rectangle& r) { return r.info(s); }
    friend SVGstream& operator<<(SVGstream& s, const Rectangle& r) { return r.write(s); }
};


////////////////////////////////////////////////////////////////////////////////////////
///  Square
class Square : public Rectangle {
public:
	explicit Square(const Point &xy, float s, const Color &c) 
		: Rectangle(xy, s, s, c) {}
	virtual ~Square() {};

    std::ostream& info(std::ostream& s) const {
        return s << "Square[corner=" << corner
                 << ",sidelen=" << width << "]"
                 << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& s, const Square& r) { return r.info(s); }
    friend SVGstream& operator<<(SVGstream& s, const Square& r) { return r.write(s); }
};


/// Test d'affichage des objets
void Test01() {
    using namespace std;
    cout << "Test 1: redirection directe d'objets sur le flux de sortie" << endl;
    cout << "\t" << Rectangle({ 40,40 }, 100, 200, Color::yellow);

    Disk d(Point(50, 50), 30, Color::blue);
    cout << "\t" << d;
}

/// Test écriture au format SVG
void Test02() {
    std::string  svgfile("test01.html");
    std::cout << "Test 2: écriture directe d'objets dans un fichier svg" << std::endl;
    std::cout << "\t" << "génération svg dans " << svgfile << std::endl;
	SVGstream    svg(svgfile.c_str());
	svg << Disk(Point(50, 50), 30, Color::blue);
	svg << Rectangle({ 40,40 }, 100, 200, Color::yellow);
	svg << Square({ 80,80 }, 150, Color::brown);
	svg.close();
}

/// Test sous forme polymorphique
void Test03() {
    std::cout << "Test 3: idem test 1 et 2 avec utilisation d'objets sous forme polymorphique" << std::endl;
    const int nGeoms = 3;
	Geom2D   *Geoms[nGeoms] = {
		new Disk({ 400, 400 }, 240, Color::blue),
		new Rectangle({ 40,40 }, 100, 200, Color::orange),
		new Square({ 280,280 }, 150, Color::green)
	};

	// affichage
    for(int i=0;i<nGeoms;i++) std::cout << "\t" << Geoms[i];

    // écriture dans un fichier
    std::string  svgfile("test02.html");
    SVGstream    svg(svgfile.c_str());
    std::cout << "\t" << "génération svg dans " << svgfile << std::endl;
    for(int i=0;i<nGeoms;i++) svg << Geoms[i];
    svg.close();
}

int main() {
	Test01();
	Test02();
    Test03();
	return 0;
}