#include <stdio.h>
#include <stdlib.h>

int main(){
    int size, i;
    float *tab, *tab2, max;

    do{
        printf("Entrer une taile : ");
        scanf("%d", &size);
    } while (size < 0);

    tab = malloc(size * sizeof(float));
    tab2 = malloc(size * sizeof(float));
    if(tab == NULL || tab2 == NULL ){
        printf("Error!");
        exit(0);
    }

    for (i = 0; i < size; i++){
        printf("Entrer une valeur pour t[%d]: \n", i);
        scanf("%f", &tab[i]);
    }

    printf("Tableau 1: \n");
    for (i = 0; i < size; i++){
        printf("t1[%i] = %.2f\n", i, tab[i]);
    }

    max = tab[0];
    for (i = 0; i < size; i++){
        if(tab[i] >= max) max = tab[i];
    }

    printf("Max : %.2f", max);
    for (i = 0; i < size; i++){
       tab2[i] = tab[i] / max;
    }

    printf("Tableau 2: \n");
    for (i = 0; i < size; i++){
        printf("t2[%i] = %.2f\n", i, tab2[i]);
    }
}