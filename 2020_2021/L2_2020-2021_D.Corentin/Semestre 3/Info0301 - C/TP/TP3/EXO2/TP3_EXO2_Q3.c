#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_MAX 20

int main(){
    int i;
    int tab[TAILLE_MAX], tab1[TAILLE_MAX], tab2[TAILLE_MAX];

    srand(time(NULL));

    for(i = 0;i<TAILLE_MAX; i++){
        tab[i] = rand();
        tab1[i] = rand();
        tab2[i] = tab[i] + tab1[i];
        printf("[%d]: %d + %d = %d\n", i, tab[i], tab1[i], tab2[i]);
    }

    return 0;
}