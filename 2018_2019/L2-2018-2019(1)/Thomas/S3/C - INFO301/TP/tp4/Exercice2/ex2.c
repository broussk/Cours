#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
  int a = 12;
int b = 6;
int max = 0;

int *pa = &a;
int *pb = &b;

if (*pa > *pb){
  max = *pa;
} else {
  max = *pb;
}

printf("Le max est : %d\n", max );
  
  return 0;

}