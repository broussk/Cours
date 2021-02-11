#include <stdio.h>
#define max 5

int main(){

    int tab[max];
    int i, j,temp;

    printf("Entrez %d valeur(s): \n", max);
    for (i=0; i<max; i++){
        scanf("%d", &tab[i]);
    }

    printf("Tableau:\n");
    for (i=0; i<max; i++){
        printf("%d ", tab[i]);
    }

    for (i=0, j=max-1; i<j; i++,j--){
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }

    printf("\nTableau inverse:\n");
    for (i=0; i<max; i++){
        printf("%d ", tab[i]);
    }

    return 0;
}
