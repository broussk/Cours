#include <stdio.h>
#include <stdlib.h>

#define MAXA 100
#define MAXB 50
int main(){

    int tabA[MAXA], tabB[MAXB];
    int n, m, i;

    printf("Entrer une taille pour le tableau A avec n < %d: \n", MAXA);
    scanf("%d", &n);

    printf("Entrer une taille pour le tableau B avec m < %d: \n", MAXB);
    scanf("%d", &m);

    if(n < m){
        printf("Error N est plus petit que M !");
        exit(0);
    }

    printf("\nValeur tableau A: \n");
    for(i = 0; i < n ; i++){
        printf("tabA[%d]: ", i);
        scanf("%d", tabA+i);
    }

    printf("\nValeur tableau B: \n");
    for(i = 0; i < m ; i++){
        printf("tabB[%d]: ", i);
        scanf("%d", tabB+i);
    }


    printf("\nTableau A: \n");
    for(i = 0; i < n ; i++){
        printf("[%d] | ", *(tabA+i));
    }

    printf("\n");
    printf("\nTableau B: \n");
    for(i = 0; i < m ; i++){
        printf("[%d] | ", *(tabB+i));
    }


    for(i = 0; i < n ; i++){
        *(tabA+n+i) = *(tabB+i);
    }

    n = n + m;

    printf("\n");
    printf("\nTableau A final: \n");
    for(i = 0; i < n ; i++){
        printf("[%d] | ", *(tabA+i));
    }

    return 0;
}