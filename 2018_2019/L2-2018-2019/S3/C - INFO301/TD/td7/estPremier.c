#include <math.h>

int estPremier(int n){
  int i,premier=1;
  float racine;

  racine = sqrt(n);
  while((i<racine)&&(premier==1)){
    if(n%i==0){
      premier = 0;
    }
    i++;
  }
  return premier;
}
