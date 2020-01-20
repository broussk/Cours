#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAILLE_MAX 100

int main (int argc, char *argv[]){
/*
  int i,j,k,element;
  int occ=0;
  int matrice[2][2] = {{1,1},{1,4}};

  printf("Quel element vous recherchez ?\n" );
  scanf("%d", &element );

  for ( i = 0; i < 2; i++) {
    for ( j = 0; j < 2; j++) {
      if (matrice[i][j] == element) {
        occ++;
      }
    }
  }

  printf("Nb d'occurence : %d\n", occ );
*/

/*
int i,j,k;
int somme = 0;
int somme2 = 0;
int val = 0;
int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

for ( i = 0; i < 3; i++) {
  for ( j = 2 ; j >= val ; j--) {
    somme = somme + matrice[i][j];
  }
  val ++;
}

val = 0;

for ( i = 0; i < 3; i++) {
  for ( j = 0 ; j <= val ; j++) {
    somme2 = somme2 + matrice[i][j];
  }
  val ++;
}
printf("Somme triangle superieur :  %d\n", somme );
printf("Somme triangle inferieur :  %d\n", somme2 );
*/

/*
int i,j,temp;
int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

for ( i = 0; i < 3; i++) {
  printf("Colone %d \n", i+1 );
  for ( j = 0; j < 3; j++) {
    printf("%d", matrice[i][j] );
  }
  printf("\n" );
}

for (i = 0; i < 3; i++) {
    for (j = 0; j < i; j++) {
        temp = matrice[i][j];
        matrice[i][j] = matrice[j][i];
        matrice[j][i] = temp;
  }
}
printf("\n\nTranspose : \n\n" );

for ( i = 0; i < 3; i++) {
  printf("Colone %d \n", i+1 );
  for ( j = 0; j < 3; j++) {
    printf("%d", matrice[i][j] );
  }
  printf("\n" );
}
*/

/*
int i;
int j = 2;
int produit = 1;
int produit2 = 1;

int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

for ( i = 0; i < 3; i++) {
  produit *= matrice[i][i];
}

for ( i = 0; i < 3; i++) {
    produit2 *= matrice[i][j];
    j--;
}
printf("Produit diagonale :  %d\n", produit );
printf("Produit anti-diagonale :  %d\n", produit2);
*/

/*
int i,j;
int somme = 0;

int matrice[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

for ( i = 0; i < 3; i++) {
  for ( j = 0; j < 3; j++) {
    somme += matrice[i][j];
  }
  printf("Somme de la ligne %d = %d \n", i+1 , somme );
  somme = 0;
}
*/

/*
int i,j;
int somme = 0;
int det;
int matrice[2][2] = {{1,2},{3,4}};

det=(matrice[0][0] * matrice[1][1])-(matrice[1][0] * matrice[0][1]);
printf("Determinant = %d \n", det);
*/




return 0;

}
