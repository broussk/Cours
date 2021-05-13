#include<stdio.h>

#define MAX 3

int main(){
    int mat1[MAX][MAX], mat2[MAX][MAX], mul[MAX][MAX];

    int i,j,k;

    printf("Première matrice\n");
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            printf("mat1[%d][%d] : " , i, j);
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("Seconde matrice\n");
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            printf("mat2[%d][%d] : " , i, j);
            scanf("%d",&mat2[i][j]);
        }
    }

    //Traitement
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            mul[i][j]=0;
            for(k = 0; k < MAX; k++){
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Résultat : \n");
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            printf("%d\t",mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}