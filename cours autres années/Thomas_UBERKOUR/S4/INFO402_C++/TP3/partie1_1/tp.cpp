//
// Created by Thomas on 31/01/2019.
//
#include "tp.h"
using namespace std;

const char* Color::name[]={"white", "yellow", "orange", "turquoise", "violet", "pink", "red", "green", "grey", "cyan", "blue", "brown"};

void ex1_2(){
    Point2D *p = new Point2D(5,2);
    Color c = Color::green;
    Color c1 = Color();
    cout << c.getName() << " " << c1.getName();

    };

void ex1_3(){
    SVGstream svg("test.html");

    svg << "<circle cx=\"100\" cy=\"100\" r=\"75\" fill=\"red\"/>";


}
void ex1_4() {
    Disc *c1=new Disc (52,Point2D(100,100),Color::red);
    Rectangle *r1=new Rectangle(200,400,Point2D(50,50),Color::green);
    SVGstream svg("test.html");
    c1->Scale(0.33);
    svg << "<rect x=\""<<r1->getOrigine().getX()<<"\" y=\""<<r1->getOrigine().getY()<<"\" width=\""<<r1->getWitdh()<<"\" height=\""<<r1->getHeight()<<"\" fill=\""<<r1->getColor().getName()<<"\"/>";
    svg << "<circle cx=\""<<c1->getOrigine().getX()<<"\" cy=\""<<c1->getOrigine().getY()<<"\" r=\""<<c1->getRayon()<<"\" fill=\""<<c1->getColor().getName()<<"\"/>";
    Square *s1 = new Square(500,Point2D(70,70),Color::yellow);
    svg << "<rect x=\""<<s1->getOrigine().getX()<<"\" y=\""<<s1->getOrigine().getY()<<"\" width=\""<<s1->getWitdh()<<"\" height=\""<<s1->getHeight()<<"\" fill=\""<<s1->getColor().getName()<<"\"/>";
    // svg << "<circle cx=\"100\" cy=\"100\" r=\"75\" fill=\"red\"/>" << 7.5f;

}
void ex1_5() {
    Point2D *T = new PointsArray(&T);
    for (int i = 0; i < 3; i++) {

        printf("T[%d] = %lf/%lf \n", i, T[i].getX(), T[i].getY());

    }

};
