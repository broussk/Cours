#include "ex2.h"
#include <iostream>
#include <cmath>

using namespace std;
float norm(Complex c){
  return sqrt((c.r*c.r)+(c.i*c.i));
}
Complex sqr(const Complex &z){
  Complex retour;
  retour.r = z.r * z.r;
  retour.i = z.i * z.i;
  return retour;
}
Complex operator+(const Complex &a, const Complex &b){
  cout << "addition" << endl;
  return Complex(a.r+b.r,a.i+b.i);
}
