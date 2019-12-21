#include <iostream>
#include "ex2.h"

using namespace std;
int main(){
  // Complex e1;
  // Complex e2(2.2,3.3);
  // Complex e3(2.5,8.2);
  // Complex *pe3 = new Complex (2.f);
  // Complex *pe4 = new Complex (3.f);
  // e1.view();
  // e2.view();
  // pe3->view();
  // float retour(norm(e2));
  // cout << retour << endl;
  //
  // cout << "e1 avant "; e1.view();
  // cout << "e2 avant "; e2.view();
  // e1=e2;
  // cout << "e1 apres "; e1.view();
  // cout << "e2 apres "; e2.view();
  //
  // cout << "e1 avant "; e3.view();
  // e3=e3;
  // cout << "e2 apres "; e3.view();
  // Complex e4 = sqr(e3); //RVO Return Value Optimization
  // e4.view();
  // Complex zz2 = sqr(3.f) ;
  // zz2.view();
  Complex z2=(2.f),z3=(3.f),z1;
  cout << endl;
  z1 = z2 + z3 +3.f;



  return 0;
}
