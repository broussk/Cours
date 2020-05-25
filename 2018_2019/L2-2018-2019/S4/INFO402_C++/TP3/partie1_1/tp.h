//
// Created by Thomas on 31/01/2019.
//

#ifndef PARTIE1_1_TP_H
#define PARTIE1_1_TP_H
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

void ex1_2();
void ex1_3();
void ex1_4();
void ex1_5();

class Point2D{
protected : float x,y;

public :
    Point2D():x(1),y(2){}                     //Par défaut
    Point2D(float u, float v):x(u),y(v){}         //Par initialisation
    Point2D(const Point2D &p):x(p.x),y(p.y){} //Par copie
    float getX()const{
    return x;
}
    float getY()const{
    return y;
}

};

class Color{
public :
    enum color{ white, yellow, orange, turquoise, violet, pink, red, green, grey, cyan, blue, brown };
protected :
    color c;
    static const char* name[];

public :
    const char* getName()const{return name[c];}
    Color():c(red){};
    Color(const color x):c(x){};
};

/*
class SVGstream{
private:ofstream fichier;

public :SVGstream(const char* name):fichier(name, ios::out | ios::trunc){
            if(fichier){
                fichier <<  "<!doctype html><svg width=\"1000\" height=\"1000\">" << endl;
            }
        };
        ~SVGstream(){
            fichier << "</svg>";
            fichier.close();
        }
        friend SVGstream &operator <<(SVGstream &svg, const char* str){
            svg.fichier << str;
            return svg;
        };

};
*/

class SVGstream : public ofstream{

public :SVGstream(const char* name): ofstream(name, ios::out | ios::trunc){
    if(is_open()){
            *this <<  "<!doctype html><svg width=\"1000\" height=\"1000\">" << endl;
        }
    };
    ~SVGstream() {
        *this << "</svg>";
        close();
    }
};



class Transform{
public:
    virtual void Rotate(){};
    virtual void Translate(){};
    virtual void Scale(){};
};

class Geom2D : public Transform{

};

class FillProperty : public Color{
protected:
    Color c;
public:
    void setColor(Color col){
        c = col;
        cout << "Couleur changée"<<endl;
    }
};

class Surface : public FillProperty, public Geom2D{
public:
    virtual void info(){};
    virtual void aire(){};
};

class Disc : public Surface, public Point2D{
protected:
    double rayon;
    Point2D origine;
    Color color;
public:
    Disc(double rayon, Point2D p, Color color){
        this->rayon = rayon;
        this->origine = p;
        this->color = color;
    }


    void setRayon(double rayon){
        this->rayon=rayon;
    }
    void setOrigine(Point2D p){
        origine=p;
    }
    void setColor(Color c){
        color=c;
    }
    double getRayon(){
        return rayon;
    }
    Point2D getOrigine(){
        return origine;
    }
    Color getColor(){
        return color;
    }
    void Translate(Point2D p){
        setOrigine(p);
    };
    void Scale(double r){
        r*=rayon;
        setRayon(r);
    };

};

class Rectangle : public Surface{
protected:
    double witdh;
    double height;
    Point2D origine;
    Color color;
public:
    Rectangle(double witdh, double height, Point2D p,Color color){
        this->witdh = witdh;
        this->height = height;
        this->origine = p;
        this->color = color;
    }
    void setWitdh(double witdh){
        this->witdh=witdh;
    }
    void setHeight(double height) {
        this->height=height;
    }
    void setOrigine(Point2D p){
        origine=p;
    }
    void setColor(Color c){
        color=c;
    }
    double getWitdh(){
        return witdh;
    }
    double getHeight(){
        return height;
    }
    Point2D getOrigine(){
        return origine;
    }
    Color getColor(){
        return color;
    }
    void Rotate(double x){

    }
    void Translate(Point2D p){
        setOrigine(p);
    };
    void Scale(double pc){
            if(pc>0 && pc<1){
            setWitdh(witdh*pc);
            setHeight(height*pc);
        }
    };
};

class Square : public Rectangle{
protected:
    double side;
    Point2D p;
    Color color;
public:

    Square(double side,Point2D p, Color color):Rectangle(side,side,p,color){

    }

    void setSide(double side){
        setWitdh(side);
        setHeight(side);
    }



};
class PointsArray : public Point2D {

protected: Point2D *T[2];

public:
    PointsArray(Point2D **T){

        T[0]=new Point2D();
        T[1]=new Point2D(2,4);
        T[2]=new Point2D(5.0,5.4);

    }


};
#endif //PARTIE1_1_TP_H
