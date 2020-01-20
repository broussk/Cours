#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAILLE_MAX 100

int main (int argc, char *argv[]){

  srand(time(NULL));

  int i,j,k;
  int occ=0;
  int max=0;
  int ligneocc;
  int lignedup = 9;
  int matrice[4][6] = {0};
  int choix;

  for ( i = 0; i < 4; i++) {
    for ( j = 0; j < 6; j++) {
      matrice[i][j] = (rand() % 2);
    }
  }


  do {
    printf("\n==============================================================\n");
    printf("                                                              \n");
    printf("                              Menu                            \n");
    printf("                                                              \n");
    printf("1- Recherche ligne comportant le maximum d'occurrence de 1    \n");
    printf("2- Suppression lignes duplique dans la matrice                \n");
    printf("3- Recherche sous-matrice maximale dont les elements sont 1   \n");
    printf("                                                              \n");
    printf("Veuillez choisir une option : ");
    scanf("%d", &choix );
    printf("==============================================================\n\n");
  } while(choix != 1 && choix != 3 && choix != 2);

  printf("Voici votre tableau :\n\n");

  for ( i = 0; i < 4; i++) {
    printf("Ligne %d : ", i+1 );
    for ( j = 0; j < 6; j++) {
      printf("%d", matrice[i][j] );
    }
    printf("\n" );
  }

  switch (choix) {
    case 1:
    for ( i = 0; i < 4; i++) {
      for ( j = 0; j < 6; j++) {
        if (matrice[i][j] == 1) {
          occ++;
        }
      }
      if (occ > max){
        ligneocc = i;
        max = occ;
      }
      occ=0;
    }

    printf("Ligne du plus grand nombre d'occurence de 1 : %d\n", ligneocc+1 );
    break;
    case 2:
    for ( i = 0; i < 3; i++) {
      for ( j = 0; j < 6; j++) {
        if (matrice[i][j] == matrice[i+1][j]) {
          occ++;
        }
      }
      if (occ == 6) {
        for (k = 0; k < 6; k++) {
          matrice[i+1][k] = 0;
        }
      }
      occ=0;
    }

    printf("\n\nSuppression des lignes doubles :\n\n" );
    for ( i = 0; i < 4; i++) {
      printf("Ligne %d : ", i+1 );
      for ( j = 0; j < 6; j++) {
        printf("%d", matrice[i][j] );
      }
      printf("\n" );
    }

    break;
    case 3:

    break;
  }


return 0;

}
