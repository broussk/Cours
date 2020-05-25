#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE_MAX 100

int main (int argc, char *argv[]){

  int i,j,k;
  int taille_utile = 0;
  char chaine[TAILLE_MAX];

  printf("Saisir une chaine de caractere : ");
  scanf("%s", chaine );

while (chaine[taille_utile] != '\0'){
  taille_utile++;
}

for (i = 0; i < taille_utile; i++) {
  if (chaine[i] < 65 || chaine[i] > 122) {
    chaine[i]=' ';
  } else if (chaine[i] >= 91 && chaine[i] <= 96){
    chaine[i]=' ';
  }
}

printf("%s\n", chaine );

return 0;

}
