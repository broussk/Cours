#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAILLE_MAX 100

int main (int argc, char *argv[]){

  int i,j;
  char temp,temp2;
  int res = 0;
  int taille_utile = 0;
  int taille_utile2 = 0;
  char chaine[TAILLE_MAX];
  char chaine2[TAILLE_MAX];

  printf("Saisir une chaine de caractere : ");
  scanf("%s", chaine );

  printf("Saisir une chaine de caractere : ");
  scanf("%s", chaine2 );

while (chaine[taille_utile] != '\0'){
  taille_utile++;
}
while (chaine[taille_utile2] != '\0'){
  taille_utile2++;
}

for (i = 0; i < taille_utile; i++) {
  for ( j = i+1; j < taille_utile; j++) {
    if (chaine[j] < chaine[i]) {
      temp = chaine[i];
      chaine[i]=chaine[j];
      chaine[j]=temp;
    }
  }
}

for (i = 0; i < taille_utile2; i++) {
  for ( j = i+1; j < taille_utile2; j++) {
    if (chaine2[j] < chaine2[i]) {
      temp2 = chaine2[i];
      chaine2[i]=chaine2[j];
      chaine2[j]=temp2;
    }
  }
}

printf("%s\n", chaine );
printf("%s\n", chaine2 );


return 0;

}
