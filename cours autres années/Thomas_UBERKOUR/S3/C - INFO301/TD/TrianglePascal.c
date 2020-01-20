//Jeudi 22 Nov
#include <stdio.h>
#include <stdlib.h>

int main(){
  int **TP;
  int nbLignes,i,j;
  do{
    printf("Donnez le nombre de lignes : ");
    scanf("%d",&nbLignes);
  }while(nbLignes<=0);
  TP = (int**)malloc(nbLignes*sizeof(int*));
  for(i=0 ; i<nbLignes ; i++){
    TP[i] = (int *)malloc(sizeof(int)*(i+1));
    TP[i][0] = 1;
    TP[i][i] = 1;
  }

  for(i=2 ; i<nbLignes ; i++){
    for(j=1 ; j<i ; j++){
      TP[i][j] = TP[i-1][j-1] + TP[i-1][j];
    }
  }

  for(i=0 ; i<nbLignes ; i++){
    for(j=0 ; j<=i ; j++){
      printf("%d ",TP[i][j]);
    }
    printf("\n");
  }
    for(i=0 ; i<nbLignes ; i++){
      free(TP[i]);
      TP[i] = NULL;
    }
    free(TP);
    TP=NULL;
    return EXIT_SUCCESS;
}
