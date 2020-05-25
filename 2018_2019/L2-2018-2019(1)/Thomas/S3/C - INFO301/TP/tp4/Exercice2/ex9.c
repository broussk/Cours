#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main (int argc, char *argv[]){
  srand(time(NULL));

  int j,i,k = 0;
int a =1;
char chaine[]="Bonjour";
int nbcar = strlen(chaine);

printf("Nombre de caractere %d \n", k );

for (j = 0; j < sizeof(chaine); j++) {
  printf("%c\n", *(chaine+j) );
}

printf("Nombre de caractere %d  \n", nbcar );
  return 0;

}