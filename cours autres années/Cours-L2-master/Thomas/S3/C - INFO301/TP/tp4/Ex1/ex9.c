#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));

  int tab[20] = {1,2,3,4,5,1,7,8,9,1,11,3,13,14,3,16,17,1,19,20};
int tab2[20] = {};
int temp = 0;
int i,j,k= 0;

for ( i = 19 , j=0 ; i >= 0 ; i--, j++){
  tab2[j] = tab[i];
}

for (k = 0; k < 20 ; k++){
    printf("%d\n",tab2[k]);
  }
  return 0;

}