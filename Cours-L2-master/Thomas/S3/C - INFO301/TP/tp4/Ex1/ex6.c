#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));
int i,j = 0;
int tab1[20] = {1,2,3,4,5,1,7,8,9,1,11,3,13,14,3,16,17,1,19,20};
int tab2[20] = {1,2,3,4,5,1,7,8,9,1,11,3,13,14,3,16,17,1,19,20};
int tab3[20] = {0};

for (i = 0; i < 20 ; i++){
    tab3[i] = tab1[i] + tab2[i];
  }

  for (j = 0; j < 20 ; j++){
      printf("%d\n",tab3[j]);
    }
  
  return 0;

}