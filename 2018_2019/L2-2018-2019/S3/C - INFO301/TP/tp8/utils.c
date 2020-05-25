#include <stdlib.h>
#include <stdio.h>

void showTabInt(int *tab, int length){
  for(int i=0; i<length ; i++){
    printf("[%d]%d ",i,tab[i]);
  }
  printf("\n");
}
