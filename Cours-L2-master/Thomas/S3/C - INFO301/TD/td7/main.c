#include <stdio.h>
#include <stdlib.h>

int main(){
  int *A,*B;
  int taille,i;

  do{
    printf("Donnez la taille de A : ");
    scanf("%d",&taille);
    }while(taille<=0);
    A = malloc(sizeof(int)*taille);
    for(i=0 ; i<taille ; i++){
      printf("Donnez la valeur ième du tableau (i=%d)",%i);
      scanf("%d",&A[i]);
    }
    B = copyPositive(A,taille);
    for(i=0 ; i<taille ; i++){
      printf("B[%d] = %d",i,B[i]);
    }
    free(B);
    free(A);
    return 0;
}
