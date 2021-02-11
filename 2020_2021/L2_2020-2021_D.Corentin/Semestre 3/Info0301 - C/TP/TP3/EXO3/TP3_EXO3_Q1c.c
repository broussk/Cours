#include<stdio.h>

#define TAILLE_MAX 5


int main(){

    int i, tmp;
    int tab[TAILLE_MAX] = {1, 2, 3, 4, 5};
    int tab2[TAILLE_MAX] = {6, 7, 8, 9, 10};

    printf("Tab1: ");

    for(i =0; i < TAILLE_MAX; i++){
        printf("%d ", *(tab + i));
    }

    printf("\nTab2: ");

    for(i =0; i < TAILLE_MAX; i++){
        printf("%d ", *(tab2 + i));
    }

    printf("\n");


    for(i =0; i < TAILLE_MAX; i++){
        tmp = *(tab+i);
        *(tab+i) = *(tab2+i);
        *(tab2+i) = tmp;
    }

    printf("Tab1: ");
    for(i =0; i < TAILLE_MAX; i++){
        printf("%d ", *(tab + i));
    }

    printf("\nTab2: ");

    for(i =0; i < TAILLE_MAX; i++){
        printf("%d ", *(tab2 + i));
    }

    printf("\n");

    return 0;
}