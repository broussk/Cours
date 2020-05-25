#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include "SVGstream.h"
#include "Color.h"

#if defined(__GNUC__) && !defined(__INTEL_COMPILER) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 800)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wclass-memaccess"
#endif

constexpr float pi_f = 3.14159265358979323846f;

////////////////////////////////////////////////////////////////////////////////////////
class ReallocatablePointsArray;
struct Point {
    float x, y;
    Point() : x(0), y(0) {};
    Point(float u, float v) : x(u), y(v) {};
    Point& operator=(const Point& v) {
        if (&v != this) { x = v.x; y = v.y; }
        return *this;
    }
    void operator+=(const Point &p) { x += p.getx(); y += p.gety();  }

    inline void set(float u, float v) { x = u; y = v; }
    inline float getx() const { return x; }
    inline float gety() const { return y; }
    void min(const Point &p) {
        x = std::min(x, p.x);
        y = std::min(y, p.y);
    }
    void max(const Point &p) {
        x = std::max(x, p.x);
        y = std::max(y, p.y);
    }
};

std::ostream& operator<<(std::ostream& s, const Point& p) {
    return s << "(" << p.x << "," << p.y << ")";
}
SVGstream& operator<<(SVGstream& s, const Point& p) {
    s << p.x << "," << p.y;
    return s;
}

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

////////////////////////////////////////////////////////////////////////////////////////
///  PointsArray : tableau de points de taille fixe
class PointsArray : public Transform {
protected:
    size_t   nPoints;
    Point    *Array;
public:
    explicit PointsArray(size_t size) :
            nPoints(size), Array( new Point[size] ) {}
    ~PointsArray() {
        delete [] Array;
    }
    void set(size_t i, const Point &p) {
        if (i<nPoints) Array[i] = p;
    }
    explicit PointsArray(const std::initializer_list<Point> &list, size_t defsize = 0) :
        PointsArray( defsize ? defsize : list.size() ) {
        size_t i=0;
        for (const Point &p : list) {
            set(i++,p);
            if (i == defsize) break;
        }
    }
    PointsArray(const Point& center, float radius, size_t nPoints) : PointsArray(nPoints) {
        for(size_t i=0;i<nPoints;++i) {
            float   theta = i * 2*pi_f / nPoints;
            Array[i].set(center.x + radius * cos(theta), center.y + radius * sin(theta) );
        }
    }

    void Translate(const Point &v) {
        for (size_t i = 0; i < nPoints; i++) Array[i] += v;
    }
    Point Center() {
        // Point c=Point(); car Point c(); d�clare un prototype
        if (nPoints == 0) return Point();
        Point  cMin = Array[0], cMax = Array[0];
        for (size_t i = 1; i < nPoints; i++) {
            cMin.min(Array[i]);
            cMax.max(Array[i]);
        }
        return Point((cMin.x + cMax.x)*0.5f, (cMin.y + cMax.y)*0.5f );
    }

    void Scale(float s) {
        Point c = Center();
        for (size_t i = 0; i < nPoints; i++) {
            Array[i].x += c.x + (Array[i].x - c.x) * s;
            Array[i].y += c.y + (Array[i].y - c.y) * s;
        }
    }
    void Rotate(float a) {
        Point c = Center();
        float sina = sin(a), cosa = cos(a);
        for (size_t i = 0; i < nPoints; i++) {
            float x = Array[i].x, y = Array[i].y;
            Array[i].x = c.x + (x - c.x)*cosa - (y - c.y)*sina;
            Array[i].y = c.y + (x - c.x)*sina + (x - c.x)*cosa;
        }
    }
    friend std::ostream& operator<<(std::ostream& s, const PointsArray& p) {
        s << "{";
        for (size_t i = 0; i < p.nPoints; i++)
            s << (i==0?"":",") << p.Array[i];
        return s << "}";
    }
    friend SVGstream& operator<<(SVGstream& s, const PointsArray& p) {
        for (size_t i = 0; i < p.nPoints; i++) {
            if (i != 0) s << " ";
            s << p.Array[i];
        }
        return s;
    }
};



////////////////////////////////////////////////////////////////////////////////////////
///  ReallocatablePointsArray
class ReallocatablePointsArray : public PointsArray {
protected:
    static const size_t    AllocGranularity = 4;
    size_t   Allocated;
    void realloc(size_t newsize) { // newsize<Allocated non test� car interne=>cf appel realloc
        Point *tmp = static_cast<Point*>(::operator new(newsize*sizeof(Point)));
        memcpy(tmp, Array, nPoints*sizeof(Point));
        std::swap(tmp, Array);
        ::operator delete(tmp);
        Allocated = newsize;
    }
public:
    explicit ReallocatablePointsArray(size_t alloc = AllocGranularity) :
            PointsArray(alloc), Allocated(alloc) { nPoints = 0; }
    virtual ~ReallocatablePointsArray() {}
    void Add(const Point &p) {
        if (nPoints == Allocated) realloc(Allocated + AllocGranularity);
        new(&Array[nPoints++]) Point(p);
    }
    explicit ReallocatablePointsArray(const std::initializer_list<Point> &list) : PointsArray(list) {}
    friend std::ostream& operator<<(std::ostream& s, const ReallocatablePointsArray& p) {
        const PointsArray& pp = p;  // utilise pour ReallocatablePointsArray la surcharde de PointsArray
        return s << pp;
    }
    friend SVGstream& operator<<(SVGstream& s, const ReallocatablePointsArray& p) {
        const PointsArray& pp = p;  // utilise pour ReallocatablePointsArray la surcharde de PointsArray
        return s << pp;
    }
};

////////////////////////////////////////////////////////////////////////////////////////
///  Triangle
class Triangle : public Surface, public PointsArray {
public:
    explicit Triangle(const Color &c = Color::red) :
            Surface(c), PointsArray(3) {}
    Triangle(const std::initializer_list<Point> &list, const Color &c = Color::red) :
            Surface(c), PointsArray(list,3) {}
    float area() { // calcul de la surface d'un polygone quelconque
        float  s = 0.f;
        for (size_t i = 0; i < nPoints; i++)
            s += (Array[(i + 1) % nPoints].getx() - Array[i].getx())
                 * (Array[(i + 1) % nPoints].gety() + Array[i].gety());
        return fabsf(s)/2.f;
    }

    void Translate(const Point &v) { PointsArray::Translate(v); }
    void Scale(float s) { PointsArray::Scale(s); }
    void Rotate(float a) { PointsArray::Rotate(a); }

    std::ostream& info(std::ostream& s) const {
        const PointsArray &pp = *this;
        return s << "Triangle[nVertex=" << nPoints << "," << pp << "]";
    }
    SVGstream& write(SVGstream &s) const {
        const PointsArray &pp = *this;
        return s << "<polygon " << SVGarg(POINTS, pp) << SVGarg(fill,fill_color) << "/>\n";
    }
    virtual ~Triangle() {};

    friend std::ostream& operator<<(std::ostream& s, const Triangle& p) { return p.info(s); }
    friend SVGstream& operator<<(SVGstream& s, const Triangle& p) { return p.write(s); }
};


////////////////////////////////////////////////////////////////////////////////////////
///  Polygon
class Polygon : public Surface, public ReallocatablePointsArray {
public:
    explicit Polygon(size_t alloc, const Color &c = Color::red) :
            Surface(c), ReallocatablePointsArray(alloc) {}
    Polygon(const std::initializer_list<Point> &list, const Color &c = Color::red) :
            Surface(c), ReallocatablePointsArray(list) {}
    float area() { // calcul de la surface d'un polygone quelconque
        float  s = 0.f;
        for (size_t i = 0; i < nPoints; i++)
            s += (Array[(i + 1) % nPoints].getx() - Array[i].getx())
                 * (Array[(i + 1) % nPoints].gety() + Array[i].gety());
        return fabsf(s)/2.f;
    }

    void Translate(const Point &v) { ReallocatablePointsArray::Translate(v); }
    void Scale(float s) { ReallocatablePointsArray::Scale(s); }
    void Rotate(float a) { ReallocatablePointsArray::Rotate(a); }

    std::ostream& info(std::ostream& s) const {
        const ReallocatablePointsArray &pp = *this;
        return s << "Polygon[nVertex=" << nPoints << "," << pp << "]";
    }
    SVGstream& write(SVGstream &s) const {
        const ReallocatablePointsArray &pp = *this;
        return s << "<polygon " << SVGarg(POINTS, pp) << SVGarg(fill,fill_color) << "/>\n";
    }
    virtual ~Polygon() {};

    friend std::ostream& operator<<(std::ostream& s, const Polygon& p) { return p.info(s); }
    friend SVGstream& operator<<(SVGstream& s, const Polygon& p) { return p.write(s); }
};

////////////////////////////////////////////////////////////////////////////////////////
///  Figure

class Figure {
protected:
    static const size_t             AllocGranularity = 16;
    size_t                          Allocated, nGeoms;
    Geom2D                          **GeomArray;
    void realloc(size_t newsize) {
        Geom2D **tmp = new Geom2D*[newsize];
        if (GeomArray != nullptr) {
            memcpy(tmp, GeomArray, nGeoms * sizeof(Geom2D));
            delete[] GeomArray;
        }
        std::swap(tmp, GeomArray);
        Allocated = newsize;
    }
public:
    explicit Figure(size_t alloc = AllocGranularity) :
            Allocated(alloc), nGeoms(0),
            GeomArray(alloc ? new Geom2D*[alloc] : nullptr) {}

    ~Figure() {
        for (size_t i = 0; i < nGeoms; i++) delete GeomArray[i];
        delete[] GeomArray;
    }

    void Add(Geom2D *g) {
        if (nGeoms == Allocated) realloc(Allocated + AllocGranularity);
        GeomArray[nGeoms++] = g;
    }

    bool Remove(Geom2D *g) {
        for (size_t i = 0; i < nGeoms;i++)
            if (GeomArray[i] == g) {
                Remove(i);
                return true;
            }
        return false;
    }
    void Remove(size_t pos) {
        assert(pos < nGeoms);
        delete GeomArray[pos];
        if (pos < nGeoms - 1)
            std::memmove(GeomArray+pos, GeomArray+pos+1, (nGeoms-pos-1));
        --nGeoms;
    }

    Figure(const std::initializer_list<Geom2D*> &list) :
            Figure(list.size()) {
        for (Geom2D* p : list) Add(p);
    }

    void Translate(const Point &v) {
        for (size_t i = 0; i < nGeoms; i++) GeomArray[i]->Translate(v);
    }

    void Scale(float s) {
        for (size_t i = 0; i < nGeoms; i++) GeomArray[i]->Scale(s);
    }

    void Rotate(float a) {
        for (size_t i = 0; i < nGeoms; i++) GeomArray[i]->Rotate(a);
    }

    void info() const {
        for (size_t i = 0; i < nGeoms; i++)
            std::cout << std::setw(2) << i << ": " << GeomArray[i];
    }

    // accés aux éléments de la figure par l'opérateur crochet
    const Geom2D& operator[](size_t i) const {  return *(GeomArray[i]); }
    Geom2D& operator[](size_t i) {    return *(GeomArray[i]); }

    void save(const char *fname) {
        SVGstream   output(fname);
        for (size_t i = 0; i < nGeoms; i++) output << GeomArray[i];
        output.close();
    }
};

////////////////////////////////////////////////////////////////////////////////////////

/// Test d'affichage des objets
void Test01() {
    using namespace std;
    cout << "Test 1: redirection directe d'objets sur le flux de sortie" << endl;
    cout << "\t" << Rectangle({ 40,40 }, 100, 200, Color::yellow);

    Disk d(Point(50, 50), 30, Color::blue);
    cout << "\t" << d;

    Triangle t({ { 20,80 }, { 180,80 }, { 80,180 } }, Color::red);
    cout << "\t" << t << "\n";
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
    svg << Triangle({ { 20,80 }, { 180,80 }, { 80,180 } }, Color::red);
	svg.close();
}

/// Test sous forme polymorphique
void Test03() {
    std::cout << "Test 3: idem test 1 et 2 avec utilisation d'objets sous forme polymorphique" << std::endl;
    const int nGeoms = 4;
	Geom2D   *Geoms[nGeoms] = {
		new Disk({ 400, 400 }, 240, Color::blue),
		new Rectangle({ 40,40 }, 100, 200, Color::orange),
		new Square({ 280,280 }, 150, Color::green),
		new Polygon({{100,0},{0,100},{100,100}}, Color::blue)
	};

	// affichage
    for(int i=0;i<nGeoms;i++) std::cout << "\t" << Geoms[i];

    // écriture dans un fichier
    std::string  svgfile("test02.html");
    SVGstream    svg(svgfile.c_str());
    std::cout << "\n\t" << "génération svg dans " << svgfile << std::endl;
    for(int i=0;i<nGeoms;i++) svg << Geoms[i];
    svg.close();
}

int main() {
	Test01();
	Test02();
    Test03();

    Polygon p({{100,0},{0,100},{100,100}}, Color::blue);
    p.Scale(3.2f);
	return 0;
}