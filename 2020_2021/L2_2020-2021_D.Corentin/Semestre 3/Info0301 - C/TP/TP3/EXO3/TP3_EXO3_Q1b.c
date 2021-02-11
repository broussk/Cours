#include<stdio.h>

#define TAILLE_MAX 5

int main(){

    int i;
    int tab[TAILLE_MAX];

    printf("Entrez %d valeurs entieres: \n", TAILLE_MAX);
    for(i=0; i < TAILLE_MAX; i++){
        scanf("%d\n", &(tab[i]));
    }

    for(i =0; i < TAILLE_MAX; i++){
        printf("%d ", *(tab + i));
    }

    return 0;
}