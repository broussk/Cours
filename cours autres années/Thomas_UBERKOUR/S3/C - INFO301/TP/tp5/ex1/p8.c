#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE_MAX 100

int main (int argc, char *argv[]){

  int i,j,k,indice;
  int taille_utile = 0;
  int taille_utile2 = 0;
  char chaine[TAILLE_MAX];
  char chaine2[TAILLE_MAX];
  char chaine3[TAILLE_MAX];


  printf("Saisir une chaine de caractere : ");
  scanf("%s", chaine );

  printf("Saisir une chaine de caractere : ");
  scanf("%s", chaine2 );

while (chaine[taille_utile] != '\0'){
  taille_utile++;
}
while (chaine2[taille_utile2] != '\0'){
  taille_utile2++;
}

for (i = 0; i < taille_utile ; i++) {
  chaine3[i]=chaine[i];
}
for (j = i, k=0 ; j < (taille_utile + taille_utile2); j++ , k++) {
  chaine3[j]=chaine2[k];
}

printf("Chaine concatene : %s \n", chaine3 );

return 0;

}
