#include <stdio.h>
#include <stdlib.h>

#define MAX 2

int main() {

    int mat1[MAX][MAX];
    int mat2[MAX][MAX];
    int max[MAX][MAX];
    int min[MAX][MAX];
    int i,j;

    //Initialisation
    printf("Premiere matrice binaire: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("mat1[%d][%d]", i, j);
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("Seconde matrice binaire: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("mat2[%d][%d]", i, j);
            scanf("%d",&mat2[i][j]);
        }
    }

    //Traitement
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(mat1[i][j] <= mat2[i][j]){
                max[i][j] = mat2[i][j];
            }else{
                max[i][j] = mat1[i][j];
            }
        }
    }

    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(mat1[i][j]>=mat2[i][j]){
                min[i][j]=mat2[i][j];
            }else{
                min[i][j]=mat1[i][j];
            }
        }
    }


    //Affichage
    printf("Matrice 1: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("Matrice 2: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    printf("Min: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ", min[i][j]);
        }
        printf("\n");
    }

    printf("Max: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    return 0;
}