#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]){

char x;

printf("Tapez M ou F\n" );
scanf("%c", &x );

switch (x) {
  case 'F' :
  printf("Sexe féminin\n" );
  break;
  case 'M' :
  printf("Sexe masculin\n" );
  break;
  default:
  printf("Vous avez rentre la mauvaise valeur\n" );

  break;
}

return 0;

}
