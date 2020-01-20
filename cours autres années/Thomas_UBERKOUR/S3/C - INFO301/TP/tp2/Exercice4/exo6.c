#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]){

char reponse;
printf("Quelle est la bonne facon de déclarer une variable entière en language C ?\n\t a. \tEntier x ;\n\t b. \tInt x ;\n\t c. \tintegrer x ;\n\t d. \tint x ;\n\t e. \tLong x ;\n" );
printf("Choisissez la lettre de reponse :" );
scanf("%c", &reponse );

switch (reponse) {
  case 'a':
  printf("FAUX\n");
  break;
  case 'b':
  printf("FAUX\n");
  break;
  case 'c':
  printf("FAUX\n");
  break;
  case 'd':
  printf("BRAVO !\n");
  break;
  case 'e':
  printf("FAUX\n");
  break;
  default:
  printf("FAUX\n");
  break;
}
return 0;

}
