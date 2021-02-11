#include<stdio.h>

#define ROW 2
#define COLUMN 2

int main(){

    int i, j, k,choix;
    int matA [ROW][COLUMN] = {{2, 2},
                              {2, 2}};
    int matB [ROW][COLUMN] = {{4, 4},
                              {4, 4}};


    printf("Voici 2 matrices (2,2): \n");

    printf("Matrice A: \n");
    for (i = 0; i < ROW; i++) {
        for ( j = 0; j < COLUMN; j++) {
            printf("%d ", *(*(matA + i) + j));
        }
        printf("\n");
    }

    printf("Matrice B: \n");
    for (i = 0; i < ROW; i++) {
        for ( j = 0; j < COLUMN; j++) {
            printf("%d ", *(*(matB + i) + j));
        }
        printf("\n");
    }


    printf("Que voulez-vous faire ? \n1) A+B  \n2) A-B  \n3) A*B \nChoix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            for (i = 0; i < ROW; i++) {
                for ( j = 0; j < COLUMN; j++) {
                    printf("%d ", (*(*(matA + i) + j) + *(*(matB + i) + j)));
                }
                printf("\n");
            }
            break;
        case 2:
            for (i = 0; i < ROW; i++) {
                for ( j = 0; j < COLUMN; j++) {
                    printf("%d ", (*(*(matA + i) + j) - *(*(matB + i) + j)));
                }
                printf("\n");
            }
            break;
        case 3:
            for(i = 0; i < ROW; i++){
                for(j = 0; j < COLUMN; j++){
                    printf("%d ", ((*(*(matA + i) + j)) * (*(*(matB + i) + j))));
                }
                printf("\n");
            }
            break;
        default:  printf("Choix inconnu !");
    }

    return 0;
}