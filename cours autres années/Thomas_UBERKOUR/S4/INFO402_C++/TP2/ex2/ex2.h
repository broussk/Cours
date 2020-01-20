#include <iostream>
#include <cmath>
#ifndef EX2_H
#define EX2_H

using namespace std;

//Structures

struct Complex{
  //champs
  float r,i;

  //constructeurs
  inline Complex(){cout <<"Generation par defaut"<<endl;r=i=0;};
  inline Complex(float v){cout <<"Generation avec 1 argument"<<endl;r=i=v;};
  inline Complex(float u, float v){cout <<"Generation avec 2 arguments"<<endl;r=u;i=v;};

  //destructeur
  ~Complex(){cout << "Destruction de l'objet..."<<endl;};

  //constructeur par copie
  // Complex(Complex const &);
  //méthodes Complex
  void view(){
    cout << r << " + "<<i<<"i"<<endl;
  }
  Complex& operator=(const Complex &z){
    printf("Operator=(in=%p,out=%p)\n",&z,this);
    this->r=z.r;
    this->i=z.i;
    //faire affectation de z à l'objet courant comme indiqué dans le sujet
    return *this;
  }
};

//méthodes
float norm(Complex);
Complex sqr(const Complex &);
Complex operator+(const Complex &, const Complex &);
#endif
