#include <stdio.h>
#include <stdlib.h>

#define MAX 2

int main() {

    int mat1[MAX][MAX];
    int mat2[MAX][MAX];
    int inter[MAX][MAX];
    int i,j;


    //Initialisation
    printf("Premiere matrice binaire: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            do{
                printf("mat1[%d][%d]", i, j);
                scanf("%d",&mat1[i][j]);
            } while (mat1[i][j] < 0 || mat1[i][j] > 1);
        }
    }

    printf("Seconde matrice binaire: \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            do{
                printf("mat2[%d][%d]", i, j);
                scanf("%d",&mat2[i][j]);
            } while (mat2[i][j] < 0 || mat2[i][j] > 1);
        }
    }

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if((mat1[i][j]==mat2[i][j]) && mat1[i][j]==1){
                inter[i][j]=1;
            }else if((mat1[i][j]==mat2[i][j]) && mat1[i][j]==0){
                inter[i][j]=0;
            }else {
                inter[i][j]=1;
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

    printf("Matrice avec AND : \n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ", inter[i][j]);
        }
        printf("\n");
    }

    return 0;

}