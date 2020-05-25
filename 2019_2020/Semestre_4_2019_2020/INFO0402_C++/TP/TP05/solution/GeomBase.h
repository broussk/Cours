#pragma once
#include <algorithm>
#include <cstdlib>
#include "SVG.h"
#include <cmath>

////////////////////////////////////////////////////////////////////////////////////////
struct Default {};
extern Default	defaut;

struct None {};
extern None		none;

struct Empty {};
extern Empty	empty;
////////////////////////////////////////////////////////////////////////////////////////
// Forward declaration
class Figure;

////////////////////////////////////////////////////////////////////////////////////////
class Color {
public:
	enum colortype : uint8_t {
		red = 0, white, yellow, orange,
		turquoise, violet, pink, green, grey, cyan, blue, brown, none
	};
private:
	static const std::size_t nColor = 12;
	static const char *name[];	
	colortype  color;
public:
	static const colortype defaut = red;
	Color(const colortype &c) : color(c) {};
	Color(Default) : color(red) {};
	// note: construction et assignation par copie déjà définie

	Color(const Color &c) : color(c.color) {}
	Color& operator=(const Color& v) {
		if (&v != this) color = v.color;
		return *this;
	}
	const char *getName() const { return name[color]; }
	void set(const colortype &c) { color = c; }
	friend std::ostream &operator<<(std::ostream &s, const Color &c) {
		return s << c.getName();
	}
	friend SVG::stream& operator<<(SVG::stream& s, const Color &c) {
		return s << c.getName();
	}
};

namespace Geom2D {
	constexpr float pi_f = 3.14159265358979323846f;

	////////////////////////////////////////////////////////////////////////////////////////
	///  Point
	class Point {
	protected: float x, y;
	public:
		inline Point(float u, float v) : x(u), y(v) {};
		inline Point() : Point(0.f,0.f) {};
		inline Point(None) {};
		inline float getx() const { return x; }
		inline float gety() const { return y; }
		inline void set(float u, float v) { x = u; y = v; }
		inline void operator+=(const Point &p) { x += p.getx(); y += p.gety(); }
        inline void operator/=(float v) { x /= v; y/= v; }
        inline void min(const Point &p) { x = std::min(x, p.x); y = std::min(y, p.y); }
		inline void max(const Point &p) { x = std::max(x, p.x); y = std::max(y, p.y); }
		friend std::ostream& operator<<(std::ostream& s, const Point& p) { return s << "(" << p.x << "," << p.y << ")"; }
		friend SVG::stream& operator<<(SVG::stream& s, const Point& p) { s << int(p.x) << "," << int(p.y); return s; }
		friend class PointsArray;
        inline void translate(const Point &v) { x += v.x; y += v.y; }
        inline void scale(const Point &c, float s) {
            x = c.x + s*(x - c.x);
            y = c.y + s*(y - c.y);
        }
        inline void rotate(const Point &c, float a) {
            Point  p(x - c.x, y - c.y);
            float  sina = sinf(a), cosa = cosf(a);
            x = c.x + sina*p.x - cosa*p.y;
            y = c.y + cosa*p.x + sina*p.y;
        }
        inline void polar(float radius, float angle, const Point &center) {
            x = center.x + radius*cosf(angle);
            y = center.y + radius*sinf(angle);
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
	// classe de base de Geom2D
	class Base : public Transform, public SVG::Write {
	public:
		Base() {}
		virtual std::ostream& info(std::ostream&) const = 0;
		virtual ~Base() = 0;
		friend class ::Figure;
	};
}

