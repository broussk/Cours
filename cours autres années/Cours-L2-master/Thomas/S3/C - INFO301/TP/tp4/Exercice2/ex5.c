#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
int tab[20] = {};
int i,j;

for (i = 0; i < 20; i++) {
  *(tab+i) = (rand() % 2);
}

for (j = 0; j < 20; j++) {
  printf("%d\n", *(tab+j) );
}
  
  return 0;

}