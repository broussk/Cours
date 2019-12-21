//
// Created by Thomas on 31/01/2019.
//
#include "tp.hpp"
using namespace std;

const char* Color::name[]={"white", "yellow", "orange", "turquoise", "violet", "pink", "red", "green", "grey", "cyan", "blue", "brown"};

void tp3ex1_2(){
    Point2D *p = new Point2D(5,2);
    Color c = Color::green;
    Color c1 = Color();
    cout << c.getName() << " " << c1.getName();

    };

void tp3ex1_3(){
    SVGstream svg("test.html");
    svg << "<circle cx=\"100\" cy=\"100\" r=\"75\" fill=\"red\"/>";
}

void tp4ex1(){
  // Point2D p1(5,5);
  // p1.info();
  PointsArray b(5);
  b.info();
  PointsArray a {Point2D(5,1),Point2D(2,4)};
  a.info();
}
