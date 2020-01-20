#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));

  int i;
int tab[11] = {1,2,3,4,5,6,7,8,9,10,11};

for (i = 0; i < 11 ; i++){
  if(tab[i] % 2 == 0){
    printf("%d\n", tab[i] );
  }
}
  return 0;

}