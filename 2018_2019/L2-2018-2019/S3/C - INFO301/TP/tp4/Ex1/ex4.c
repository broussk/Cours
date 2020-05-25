#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
  int tab[11] = {1,2,3,4,5,5,5,8,9,10,11};
int val = tab[1];
int i = 0;
for (i = 0; i < 11 ; i++){
  if(val != tab[i]){
    printf("%d\n", tab[i] );
    val = tab[i];
  }
}
  
  return 0;

}