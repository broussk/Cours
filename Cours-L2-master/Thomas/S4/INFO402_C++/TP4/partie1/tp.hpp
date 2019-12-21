//
// Created by Thomas on 31/01/2019.
//

#ifndef TP_H
#define TP_H
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <initializer_list>
#include <vector>
#include <cmath>

#define PI 3.14159265

using namespace std;

void tp3ex1_2();
void tp3ex1_3(void);
void tp4ex1();

class Point2D{
protected :
  float x,y;

public :
    Point2D():x(1),y(2){}                     //Par défaut
    Point2D(int u, int v):x(u),y(v){}         //Par initialisation
    Point2D(const Point2D &p):x(p.x),y(p.y){} //Par copie
    float getPoint2Dx(){return x;}
    float getPoint2Dy(){return y;}
    void setPoint2Dx(float x){this->x = x;}
    void setPoint2Dy(float x){this->y = y;}
    void info(){cout << "(" << x << "," << y <<")";}
};

class Color{
public :
    enum color{ white, yellow, orange, turquoise, violet, pink, red, green, grey, cyan, blue, brown };
protected :
    color c;
    static const char* name[];

public :
    const char* getName()const{return name[c];}
    Color():c(red){}
    Color(const color x):c(x){}
};

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

class Transform{
public:
    virtual void Rotate(){};
    virtual void Translate(){};
    virtual void Scale(){};
};

class Geom2D : public Transform{
protected:
  Point2D p;
public:
  Geom2D():p(){}
  Geom2D(float x, float y):p(x,y){}

  Point2D getPoint(){return p;}
  void setX(float x){p.setPoint2Dx(x);}
  void setY(float y){p.setPoint2Dy(y);}
};

class FillProperty : public Color{
protected:
    Color c;
public:
  FillProperty():c(){}
  void setColor(Color col){
    c = col;
    cout << "Couleur changée"<<endl;
  }
  const char* getColor(){
    return c.getName();
  }
};

class Surface : public FillProperty, public Geom2D{
protected:
  float S_rotate;
public:
  Surface():Geom2D(),FillProperty(),S_rotate(0){cout << "Surface par defaut" << endl;}
  Surface(float x, float y, const Color& color):Geom2D(x,y),FillProperty(),S_rotate(0){cout << "S_tout spécifier\n" << endl;};
  virtual void info(){}
  virtual double aire(){return 0;}
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
    }
    void Scale(int r){
        setRayon(r);
    }

};

class Rectangle : public Surface{
protected:
    double witdh;
    double height;
    Point2D origine;
    Color color;
public:
    Rectangle(){
      this->witdh = 200;
      this->height = 100;
      this->origine = Point2D(0,0);
      this->color = red;
    }
    Rectangle(double witdh, double height, Point2D p, Color color){
        this->witdh = witdh;
        this->height = height;
        this->origine = p;
        this->color = color;
    }
    void setWitdh(double witdh){
        this->witdh=witdh;
    }
    void setHeight(double height){
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
    }
    void Scale(double pc){
        if(pc>0 && pc<1){
            setWitdh(witdh*pc);
            setHeight(height*pc);
        }
    }
};

class Square : public Rectangle{
  Square():Rectangle(){}
  Square(double wh, Point2D origine, Color color):Rectangle(wh,wh,origine,color){}
  void info(){
    cout << "Square : \n\tCouleur : "<<c.getName() << "\n\tGeom2D(x,y) : ("<<origine.getPoint2Dx()<<","<<origine.getPoint2Dy()<<")\n\tLongueur de cote : "<<witdh<<"\n"<<endl;
  }
  double aire(){return height*height;}
  virtual void Scale(float s){height*=s;}
};

class PointsArray : public Transform, public Point2D{
protected:
  Point2D *pArray;
  int size;

public:
  PointsArray(int s){
    size = s;
    pArray = new Point2D[size];
    for(int i=0 ; i<size ; i++){
      pArray[i] = Point2D(i,i);
    }
  }
  PointsArray(const PointsArray &p):pArray(p.pArray){}
  PointsArray& operator=(const PointsArray &p){
    if(this!=&p){
      for(int i=0 ; i<size ; i++){
        pArray[i] = p.pArray[i];
      }
    }
    return *this;
  }
  PointsArray(const initializer_list<Point2D> &list){
    size = list.size();
    pArray = new Point2D[size];
    int i=0;
    for(const Point2D& p:list){
      pArray[i++]=p;
    }
  }
  PointsArray(int nbPoints, Point2D centre, float rayon, float s){
    Point2D p;
    float theta;
    for(int i=0 ; i<nbPoints ; i++){
      theta = static_cast<float>(2.f*PI*i)/static_cast<float>(nbPoints);
      p.setPoint2Dx((centre.getPoint2Dx()+rayon)*cos(theta));
      p.setPoint2Dy((centre.getPoint2Dy()+rayon)*sin(theta));
      this->pArray[i] = p;
    }
  }

  void info(){
    // cout << size;
    for(int i=0 ; i<size ; i++){
      pArray[i].info();
    }
  }
  void translation(float a, float b){
    for(int i=0 ; i<size ; i++){
      pArray[i].setPoint2Dx(pArray[i].getPoint2Dx()+a);
      pArray[i].setPoint2Dy(pArray[i].getPoint2Dy()+b);
    }
  }
  void Rotate(float rotation){
    float cx=0,cy=0;
		for(int i = 0; i < size; i++){
			cx=pArray[i].getPoint2Dx()+cx;
			cy=pArray[i].getPoint2Dy()+cy;
		}
		cx = cx/static_cast<float>(size);
		cy = cy/static_cast<float>(size);
		//CALCUL AVEC CENTRE (0,0)
		Point2D *tableau= new Point2D[size];
		float x,y;
		for(int i = 0; i < size; i++){
			x=pArray[i].getPoint2Dx();
			y=pArray[i].getPoint2Dy();
			tableau[i].setPoint2Dx(x*cosf(rotation)-y*cosf(rotation));
			tableau[i].setPoint2Dy(x*cosf(rotation)+y*cosf(rotation));

		}
		//On met dans le tableau
		for(int i = 0; i < size ; i++){
			pArray[i].setPoint2Dx(cx+tableau[i].getPoint2Dx()-cx);
			pArray[i].setPoint2Dy(cy+tableau[i].getPoint2Dy()-cx);
		}
		delete [] tableau;
  }
  void Rescale(float s){
    float cx = 0.f,
      cy = 0.f;
    for(int i=0 ; i<size ; i++){
      cx=pArray[i].getPoint2Dx()+cx;
      cy=pArray[i].getPoint2Dy()+cy;
    }
    cx = cx/static_cast<float>(size);
    cy = cy/static_cast<float>(size);
    float x,y;
    for(int i=0 ; i<size; i++){
      x=pArray[i].getPoint2Dx();
      y=pArray[i].getPoint2Dy();
      pArray[i].setPoint2Dx(cx+s*(x-cx));
      pArray[i].setPoint2Dy(cy+s*(y-cy));
    }
  }
};

class ReallocatablePointsArray : public PointsArray{

public:
  ReallocatablePointsArray(size_t size):PointsArray(size){}
  ReallocatablePointsArray(const ReallocatablePointsArray &R):PointsArray(R.size){cout << "ReallocatablePointsArray Cc" << endl;}
  ReallocatablePointsArray& operator=(const ReallocatablePointsArray &p){
    if(this!=&p){
      for(int i=0 ; i<size ; i++){
        pArray[i] = p.pArray[i];
      }
    }
    return *this;
  }
  ReallocatablePointsArray(const initializer_list<Point2D> &list):PointsArray(list){}
  ReallocatablePointsArray(int nbPoints, Point2D centre, float rayon, float s):PointsArray(nbPoints, centre, rayon, s){}
};

class Polygon : public Surface, public ReallocatablePointsArray{
protected:
  ReallocatablePointsArray *poly;
  int size;
public:
  Polygon(){
    size = 3;
    poly = new ReallocatablePointsArray(size);
    for(int i=0 ; i<size ; i++){
      poly[i] = new Point2D(i,i);
    }
  }
};


#endif //TP_H
