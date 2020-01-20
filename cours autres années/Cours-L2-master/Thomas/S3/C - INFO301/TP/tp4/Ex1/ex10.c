#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
int tab[20] = {};
int i,j,k,l;
int val , res , temp, indice = 0;

for (i = 0; i < 20 ; i++){
  tab[i] = (rand() % 2);
}

for (k = 0; k < 20 ; k++){
    printf("%d : %d\n", k ,tab[k]);
  }

for (j = 0; j < 20 ; j++){

  if (tab[j] == 1) {

    for (l = j; l < 20; l++) {
      if(tab[l] == 1){
        res++;
      } else {
        break;
      }
    }
    if ( res > temp){
      indice = j;
    }
    temp = res;
    res = 0;
  }
  res = 0;
}

printf("Indice de debut de la plus longue serie : %d\n", indice );
  
  return 0;

}