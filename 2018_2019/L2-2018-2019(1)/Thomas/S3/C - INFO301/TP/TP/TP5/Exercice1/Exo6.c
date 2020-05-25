#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE_MAX 100

int main (int argc, char *argv[]){

  int i,j,k,indice;
  int taille_utile = 0;
  int taille_utile2 = 0;
  int res = 0;
  char chaine[TAILLE_MAX];
  char mot[TAILLE_MAX];


  printf("Saisir une chaine de caractere : ");
  scanf("%s", chaine );

  printf("Saisir un mot : ");
  scanf("%s", mot );

while (chaine[taille_utile] != '\0'){
  taille_utile++;
}
while (mot[taille_utile2] != '\0'){
  taille_utile2++;
}

for (i = 0; i < taille_utile; i++) {
  if (chaine[i] == mot[0]) {
    indice = i;
    for (j = i+1 , k = 1; j < taille_utile; j++ , k++) {
      if (chaine[j] == mot[k]){
        res++;
      }
    }
  }
}

if (res == taille_utile2 - 1) {
  printf("Le mot commence a l'indice %d\n", indice );
}

return 0;

}
