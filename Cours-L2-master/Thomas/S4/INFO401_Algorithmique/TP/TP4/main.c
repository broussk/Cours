#include <stdio.h>
#include <string.h>
#include "exercices.h"


int main(){
  //ex1();
  //ex2();
  //Exo 3
  // printf("%d",factoriel(5));
  // printf("%d",fibo(10));
  // printf("%d",acker(3,3));
  int x = ex4();
  if(x){
    printf("Trouve a la place %d",x);
  }
  else{
    printf("Pas trouve dans le tableau");
  }
  return 0;
}
