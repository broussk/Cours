#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define ROW 3
#define COLUMN 4

int main(){
    int i ,j, val;
    int tab[ROW][COLUMN] = {
            {54, 95, 54, 878},
            {5654, 586, 12, 4},
            {7, 852, 963, 47}
    };

    int tab2[ROW][COLUMN] = {0};

    int tabR[ROW][COLUMN];
    int tabUser[ROW][COLUMN];

    val = 1;

    srand(time(NULL));


    printf("Tableau suite: \n");
    for (i = 0; i < ROW; i++) {
        for ( j = 0; j < COLUMN; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    printf("Tableau suite: \n");
    for (i = 0; i < ROW; i++) {
        for ( j = 0; j < COLUMN; j++) {
            *(*(tab2 + i) + j) = val;
            printf("%d ", tab2[i][j]);
            val++;
        }
        printf("\n");
    }

    printf("\nTableau random: \n");
    for (i = 0; i < ROW; i++) {
        for ( j = 0; j < COLUMN; j++) {
            *(*(tabR + i) + j) = rand() % 101;
            printf("%d ", tabR[i][j]);
        }
        printf("\n");
    }


    printf("\nEntrez 12 valeurs (1 par ligne): \n");
    for (i = 0; i < ROW ; i++) {
        for ( j = 0; j < COLUMN; j++) {
            scanf("%d", &tabUser[i][j]);
        }
    }

    printf("\nTableau utilisateur: \n");
    for (i = 0; i < ROW; i++) {
        for ( j = 0; j < COLUMN; j++) {
            printf("%d ", tabUser[i][j]);
        }
        printf("\n");
    }


    return 0;
}