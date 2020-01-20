#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main (int argc, char *argv[]){
  srand(time(NULL));

  int i,j, k = 0;
int boolean = 1;
int tab1[10] = {0};
int tab2[10] = {0};

for (i = 0; i < 10 ; i++){
  printf("Entrez la valeur %d du tab 1\n", i+1 );
  scanf("%d", &tab1[i]);
}
for (j = 0; j < 10 ; j++){
  printf("Entrez la valeur %d du tab 2\n", j+1 );
  scanf("%d", &tab2[j]);
}

for (k = 0; k < 10 ; k++){
  if (tab1[k] != tab2[k]){
    boolean = 0;
  }
}

if (boolean == 0){
  printf("Vos tableaux ne sont pas identiques\n" );
} else {
  printf("Vos tableaux sont identiques\n" );
}
  return 0;

}