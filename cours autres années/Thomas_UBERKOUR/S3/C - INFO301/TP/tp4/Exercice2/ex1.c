#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));

  double a=5;
double b=5;

double *pa = &a;
double *pb = &b;

printf("L'addition de %.1lf + %.1lf = %.1lf\n", *pa , *pb , *pa + *pb );
  return 0;

}