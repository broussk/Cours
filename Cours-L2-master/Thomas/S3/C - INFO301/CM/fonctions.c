#include "fonctions.h"
#include <stdio.h>

void affichage(int T[], int n){
  int i;
  for(i=0 ; i<n ; i++){
    printf("T[%d] = %d",i,T[i]);
  }
}
