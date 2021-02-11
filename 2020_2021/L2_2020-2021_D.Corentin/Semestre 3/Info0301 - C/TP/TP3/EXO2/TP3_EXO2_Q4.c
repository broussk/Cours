#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAILLE_MAX 20


int main() {
    bool trouve;
    int i, id, ifin , im, val;
    int tab[TAILLE_MAX];

    trouve = false;
    id = 0;
    ifin = TAILLE_MAX;

    srand(time(NULL));

    for(i = 0;i<TAILLE_MAX; i++){
        tab[i] = rand() % 16;
    }

    printf("Quel valeur souhaitez vous recherchez entre 0 et 15: \n");
    scanf("%d", &val);

    while(!trouve && ((ifin - id) > 1)){
        im = (id + ifin)/2;
        trouve = (tab[im] == val);

        if(tab[im] > val){
            ifin = im;
        } else {
            id = im;
        }
    }

    if(tab[id] == val){
        printf("Le rang de %d est %d", val, id);
    } else {
        printf("Le rang de %d est %d", val, -1);
    }

    return 0;
}