#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_MAX 5

int main() {

    int i, tmp;
    int tab[TAILLE_MAX], tab2[TAILLE_MAX];

    printf("Entrez les valeurs pour le premier tableau: \n");
    for (i = 0; i < TAILLE_MAX; i++){
        scanf("%d", &tab[i]);
    }
    printf("Entrez les valeurs pour le deuxième tableau: \n");
    for (i = 0; i < TAILLE_MAX; i++){
        scanf("%d", &tab2[i]);
    }

    tmp= 0;
    for (i = 0; i < TAILLE_MAX; i++){
        if(tab[i] == tab2[i]){
            tmp++;
        }
    }

    if(tmp == TAILLE_MAX){
        printf("Les deux tableaux sont identique.");
    } else {
        printf("Les deux tableaux ne sont pas identique.");
    }

    return 0;
}