#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAX 20

int main(){
    int i, j = 0, taille, find;
    int tab[TAILLE_MAX];

    srand(time(NULL));

    do {
        printf("Entrez une valuer entre 1 et %d: \n", TAILLE_MAX);
        scanf("%d", &taille);
    } while(taille <= 0  || taille > TAILLE_MAX );


    for(i = 0;i<taille; i++){
        tab[i] = rand() % 11;
    }

    printf("Quel valeur souhaitez vous recherchez entre 0 et 10: \n");
    scanf("%d", &find);

    while(j<taille && tab[j] != find){
        j++;
    }

    if(j == taille){
        printf("Le rang de %d est %d", find, -1);
    } else {
        printf("Le rang de %d est %d", find, j);
    }

    return 0;
}