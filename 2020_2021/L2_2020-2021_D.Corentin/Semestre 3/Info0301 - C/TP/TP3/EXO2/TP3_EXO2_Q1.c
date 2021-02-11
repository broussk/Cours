#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 20

int main(){
    int i, taille;
    printf("Entrez une valuer entre 1 et %d: \n", TAILLE_MAX);
    scanf("%d", &taille);
    while(taille <= 0  || taille >= TAILLE_MAX ){
        printf("Mauvaise saisie reessayez: \n");
        scanf("%d", &taille);
    }
    int tab[taille];

    for(i = 0;i<taille; i++){
        tab[i] = rand();
        if(tab[i]%2==0){
            printf("%d est un nombre pair.\n",tab[i]);
        }
    }

    return 0;
}