#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]){

  float a;
  int y,x;

  printf("Entrez une valeur\n");
  scanf("%f", &a );
  y=(a/fabs(a));

  switch (y) {
    case -1:
    printf("nombre négatif\n" );
    break;
    case 1:
    printf("nombre positif\n" );
    break;
    default:
    printf("Nombre nul\n" );
    break;
  }

return 0;

}
