#include <stdio.h>
#include <stdlib.h>

#define MAX 2

int main() {

    int mat[2][2];
    int comp[2][2];
    int i,j;

    //Initialisation
    printf("Matrice: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            do{
                printf("mat1[%d][%d]", i, j);
                scanf("%d",&mat[i][j]);
            } while (mat[i][j] < 0 || mat[i][j] > 1);
        }
    }

    //Traitement
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(mat[i][j]==1){
                comp[i][j]=0;
            }else {
                comp[i][j]=1;
            }
        }
    }

    //Affichage
    printf("Matrice : \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Complementaire: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ",comp[i][j]);
        }
        printf("\n");
    }
    return 0;
}