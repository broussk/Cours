#include <stdio.h>
#include <stdlib.h>
#define max 5

int main(){

    int tab[max];
    int i;

    printf("Entrez %d valeur(s): \n", max);

    for (i=0; i<max; i++){
        scanf("%d", &tab[i]);
    }

    printf("Tableau: \n");

    for (i=0; i<max; i++){
        printf("%d ", tab[i]);
    }

    printf("\nTableau inverse: \n");

    for (i=max-1; i>=0; i--){
        printf("%d ", tab[i]);
    }

    return 0;
}
