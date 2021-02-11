#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 5

int main(){

    int tab[max], tab2[max];

    int i;
    long ps;

    srand(time(NULL));

    for (i=0; i<max; i++){
        tab[i] = rand() % 6;
        tab2[i] = rand() % 6;
    }

    printf("Tab1: \n");
    for (i=0; i<max; i++){
        printf("%d ", tab[i]);
    }

    printf("\nTab2: \n");
    for (i=0; i<max; i++){
        printf("%d ", tab2[i]);
    }

    for (ps=0, i=0; i<max; i++){
        ps += (long)(tab[i]*tab2[i]);
    }


    printf("\nProduit scalaire : %ld\n", ps);

    return 0;
}
