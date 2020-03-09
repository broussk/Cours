#pragma once
#include <iostream>
#include <cassert>
#include "GeomBase.h"
#include "SVG.h"
#include "Array.h"

namespace Geom2D {
	namespace Surface {
		////////////////////////////////////////////////////////////////////////////////////////
		// interface FillProperty
		class Fill {
		protected:
			Color   fill_color;
		public:
			explicit Fill(const Color &c = Color::defaut) : fill_color(c) {};
			void setFillColor(const Color &color) { fill_color = color; }
            const Color &getFillColor() const { return fill_color; }
            friend std::ostream& operator<<(std::ostream& s, const Fill& d);
            friend SVG::stream& operator<<(SVG::stream& s, const Fill& p);
		};

        ////////////////////////////////////////////////////////////////////////////////////////
		//  Surface
		class Base :
			public Geom2D::Base,
			public Fill {
		protected:			
		public:
			Base() : Geom2D::Base(), Fill() {}
			Base(const Color &color) : Fill(color) {}
			Base(const Point &cent, const Color &col = Color::defaut) : Fill(col) {}
			virtual ~Base() {};
		};

		////////////////////////////////////////////////////////////////////////////////////////
		//  Disk
		class Disk : 
			public Surface::Base {
		protected:
			Point center;
			float radius;
		public:
			Disk(const Point &xy, float r, const Color &c = Color::defaut) : 
				Base(xy,c), center(xy), radius(r) {}
			virtual ~Disk() {}
            virtual std::ostream &info(std::ostream &stream) const;
            virtual void write(SVG::stream &stream) const { stream << *this; }
			void Translate(const Point &v) override { center += v; }
			void Scale(float s) override { radius *= s; }
			void Rotate(float a) override {}
			friend std::ostream& operator<<(std::ostream& s, const Disk& d);
			friend SVG::stream& operator<<(SVG::stream& s, const Disk& p);
        };

		////////////////////////////////////////////////////////////////////////////////////////
		//  Polygon
    	class Polygon : public Base, public Array::Fixed<Point> {
		public:
			Polygon(std::size_t npoints, const Point &centre, float size, const Color &c = Color::defaut);
			Polygon(const std::initializer_list<Point> &list, const Color &c = Color::defaut);
			virtual ~Polygon() {};
            std::ostream& info(std::ostream& stream) const;
            void write(SVG::stream &stream) const { stream << *this; }
			void Translate(const Point &v) { Array::Geometry::Translate(*this,v); }
			void Scale(float s)            { Array::Geometry::Scale(*this,s); }
			void Rotate(float a)           { Array::Geometry::Rotate(*this,a); };
			friend std::ostream& operator<<(std::ostream& s, const Polygon& p);
			friend SVG::stream& operator<<(SVG::stream& s, const Polygon& p);
		};

		////////////////////////////////////////////////////////////////////////////////////////
		//  Triangle
	class Triangle : public Base, public Array::Static<Point,3> {
		public:
			Triangle(const Point &cent, std::size_t size, const Color &col = Color::defaut) :
				Base(cent,col), Array::Static<Point,3>()
				{ Array::Geometry::FillnGon(*this,cent,3); };
			Triangle(const std::initializer_list<Point> &list, const Color &col = Color::defaut) :
				Base(col), Array::Static<Point,3>(list) {}
			virtual ~Triangle() {}
            std::ostream& info(std::ostream& stream) const;
            void write(SVG::stream &stream) const { stream << *this; }
			void Translate(const Point &v) { Array::Geometry::Translate(*this,v); }
			void Scale(float s) { Array::Geometry::Scale(*this,s); }
			void Rotate(float a) { Array::Geometry::Rotate(*this,a); };
			friend std::ostream& operator<<(std::ostream& s, const Triangle& p);
			friend SVG::stream& operator<<(SVG::stream& s, const Triangle& p);
		};

		////////////////////////////////////////////////////////////////////////////////////////
		//  Rectangle
		class Rectangle : public Base {
		protected:
			Point corner;
			float width, height;
			float rotate;
		public:
			Rectangle(const Point &xy, float w, float h, const Color &c)
				: Base(c), corner(xy), width(w), height(h), rotate(0.f) {}
			virtual ~Rectangle() {};
            std::ostream& info(std::ostream& stream) const;
            void write(SVG::stream &stream) const { stream << *this; }
			void Translate(const Point &v) { corner += v; }
			void Scale(float s) { width *= s; height *= s; }
			void Rotate(float a) { rotate += a; }
			Rectangle *real_type() { return this; }
			friend std::ostream& operator<<(std::ostream& s, const Rectangle& d);
			friend SVG::stream& operator<<(SVG::stream& s, const Rectangle& p);
		};

		////////////////////////////////////////////////////////////////////////////////////////
		///  Square
		class Square : public Rectangle {
		public:
			Square(const Point &xy, float s, const Color &c)
				: Rectangle(xy, s, s, c) {}
			virtual ~Square() {};
            std::ostream& info(std::ostream& stream) const;
            void write(SVG::stream &stream) const { stream << *this; }
			friend std::ostream& operator<<(std::ostream& s, const Square& d);
			friend SVG::stream& operator<<(SVG::stream& s, const Square& p);
		};
		
		////////////////////////////////////////////////////////////////////////////////////////
		//  inline definitions
		
		// polygon
		inline Polygon::Polygon(std::size_t npts, const Point &cent, float size, const Color &color) :
			Base(color), Array::Fixed<Point>(npts) {
            Array::Geometry::FillnGon(*this,cent,size);
		}
		inline Polygon::Polygon(const std::initializer_list<Point> &list, const Color &color) :
			Base(color), Array::Fixed<Point>(list) {}
	}
}
