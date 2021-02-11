#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_MAX 20

int main() {

    int i, j, k, size = TAILLE_MAX;
    int tab[TAILLE_MAX];

    srand(time(NULL));

    for(i = 0;i<TAILLE_MAX; i++){
        tab[i] = rand() % 21;
    }
    printf("\nAvant: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\nApres: ");
    for(i = 0; i < size; i++){
        for(j = i+1; j < size; ){
            if(tab[j] == tab[i]){
                for(k = j; k < size; k++){
                    tab[k] = tab[k+1];
                }
                size--;
            }
            else{
                j++;
            }
        }
    }

    for(i = 0; i < size; i++){
        printf("%d ", tab[i]);
    }

    return 0;
}