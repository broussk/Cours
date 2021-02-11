#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAX 5

int main(){

    int tab[TAILLE_MAX];
    int i,min,max;

    srand(time(NULL));

    min=tab[0];
    max=0;

    for (i=0; i<TAILLE_MAX; i++){
        tab[i] = rand() % 101;
        printf("ind[%d]: %d\n", i , tab[i]);

        min = tab[i] < min ? tab[i] : min;
        max = tab[i] > max ? tab[i] : max;
    }

    printf("min: %d | max: %d",min, max);

    return 0;

}
