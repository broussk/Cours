#include <stdio.h>

#define max 5

int main(){

    int tab[max];
    int i;

    printf("Entrez %d valeur(s): \n", max);

    for (i=0; i<max; i++){
        scanf("%d", &tab[i]);
    }

    printf("Les entiers positif sont: \n");

    for (i=0; i<max; i++){
        if(tab[i] >= 0){
            printf("%d ", tab[i]);
        }
    }
    return 0;

}
