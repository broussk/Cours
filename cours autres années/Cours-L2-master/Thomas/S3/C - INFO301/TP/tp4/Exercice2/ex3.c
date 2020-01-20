#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
int a = 7;
int b = 8;
int *pa = &a;
int *pb = &b;
int temp;

printf("Avant : %d,%d \n", *pa , *pb );

temp = *pa;
*pa = *pb;
*pb = temp;

printf("Apres : %d,%d \n", *pa , *pb );
  
  return 0;

}