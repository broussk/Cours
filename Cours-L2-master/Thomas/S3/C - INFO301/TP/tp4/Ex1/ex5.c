#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
int tab[20] = {1,2,3,4,5,1,7,8,9,1,11,3,13,14,3,16,17,1,19,20};
int i,j = 0;
int val = 0;
int res = 0;

for (i = 0; i < 20 ; i++){
  val = tab[i];
  for ( j = 0; j < 20 ; j++){
    if (val == tab[j]){
      res ++;
    }
  }
  printf("Nombre d'occurence de %d = %d \n", val , res);
  res = 0;
}
  
  return 0;

}