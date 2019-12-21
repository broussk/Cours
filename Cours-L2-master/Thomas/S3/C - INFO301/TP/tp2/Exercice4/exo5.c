#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]){

int val=0;

printf("Entrez un chiffre\n" );
scanf("%d", &val );

switch (val) {
  case 0 :
  printf("zéro\n");
  break;
  case 1 :
  printf("un\n");
  break;
  case 2 :
  printf("deux\n");
  break;
  case 3 :
  printf("trois\n");
  break;
  case 4 :
  printf("quatre\n");
  break;
  case 5 :
  printf("cinq\n");
  break;
  case 6 :
  printf("six\n");
  break;
  case 7 :
  printf("sept\n");
  break;
  case 8 :
  printf("huit\n");
  break;
  case 9 :
  printf("neuf\n");
  break;
}

return 0;

}
