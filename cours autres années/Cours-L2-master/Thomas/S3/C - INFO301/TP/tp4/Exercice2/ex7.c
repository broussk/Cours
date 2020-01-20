#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
int tab[20] = {1,2,3,4,5,1,7,8,9,1,11,3,13,14,3,16,17,1,19,20};
int tab2[20] = {2,2,7,4,5,4,7,8,56,1,11,874,13,14,32,16,127,21,129,220};
int j,temp,temp2 = 0;

temp = *(tab2+7);
*(tab2+7) = *(tab+10);
*(tab+10) = temp;

temp2 = *(tab2+15);
*(tab2+15) = *(tab+4);
*(tab+4) = temp;

for (j = 0; j < 20; j++) {
  printf("%d : %d\n", j, *(tab2+j) );
}
  
  return 0;

}