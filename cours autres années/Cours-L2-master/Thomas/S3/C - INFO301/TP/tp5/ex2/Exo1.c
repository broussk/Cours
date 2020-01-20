#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAILLE_MAX 100

int main (int argc, char *argv[]){

srand(time(NULL));
/*
int i,j,k;
int matrice[3][4] = {{1,2,3,4},{1,2,2,3},{2,5,6,7}};

for ( i = 0; i < 3; i++) {
  printf("Colone %d \n", i+1 );
  for ( j = 0; j < 4; j++) {
    printf("%d", matrice[i][j] );
  }
  printf("\n" );
}
*/
/*
int i,j,k;
int matrice[3][4] = {0};
matrice[0][0]=1;
matrice[0][1]=2;
matrice[0][2]=3;
matrice[0][3]=4;
matrice[1][0]=5;
matrice[1][1]=6;
matrice[1][2]=7;
matrice[1][3]=8;
matrice[2][0]=9;
matrice[2][1]=10;
matrice[2][2]=11;
matrice[2][3]=12;

for ( i = 0; i < 3; i++) {
  printf("Colone %d \n", i+1 );
  for ( j = 0; j < 4; j++) {
    printf("%d", matrice[i][j]);
  }
  printf("\n" );
}
*/

/*
int i,j,k;
int matrice[3][4] = {0};

for ( i = 0; i < 3; i++) {
  for ( j = 0; j < 4; j++) {
    matrice[i][j] = (rand() % (10 - 1)+ 1);
  }
}

for ( i = 0; i < 3; i++) {
  printf("Ligne %d \n", i+1 );
  for ( j = 0; j < 4; j++) {
    printf("%d", matrice[i][j] );
  }
  printf("\n" );
}
*/
int i,j,k;
int matrice[3][4] = {0};

for ( i = 0; i < 3; i++) {
  for ( j = 0; j < 4; j++) {
    printf("Saisir un entier : " );
    scanf("%d", &matrice[i][j]);
  }
}

for ( i = 0; i < 3; i++) {
  printf("Colone %d \n", i+1 );
  for ( j = 0; j < 4; j++) {
    printf("%d", matrice[i][j] );
  }
  printf("\n" );
}


return 0;

}
