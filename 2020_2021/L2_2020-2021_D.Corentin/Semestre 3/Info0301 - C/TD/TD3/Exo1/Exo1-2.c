#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 5

int main(){

    int tab[max];
    int i,nb,ind;

    srand(time(NULL));

    printf("Tab: \n");
    for (i=0; i<max; i++){
        tab[i] = rand();
        printf("ind[%d]: %d \n",i , tab[i]);
    }

    do{
        printf("Entrez un indice et un nombre: ");
        scanf("%d %d ",&ind, &nb);
    } while (ind > max + 1);

    tab[ind]=nb;

    printf("Tab:\n ");

    for (i=0; i<max; i++){
        printf("ind[%d]: %d \n",i , tab[i]);
    }

    return 0;
}
