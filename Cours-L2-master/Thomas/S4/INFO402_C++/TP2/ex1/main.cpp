#include <iostream>
#include "ex1.h"

using namespace std;
int main(){
  ensemble e1;
  ensemble e2(1.1,2.2);
  ensemble e3(1.1,2.2,3,4);
  alternance a1;
  alternance a2(1.2,2.3);
  alternance a3(1.2,2.3,4,5);
  ensemble *e4 = new ensemble();
  alternance *a4 = new alternance();
  cout << sizeof(int) << endl << sizeof(long int) << endl << sizeof(int*) << endl;
  return 0;
}
