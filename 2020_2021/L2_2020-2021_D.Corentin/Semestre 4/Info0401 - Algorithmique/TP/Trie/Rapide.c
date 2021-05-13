#include <stdio.h>

#define SIZE 10

/**
 * Fonction recursive pour faire le trie rapide
 * @param tab le tableau
 * @param size la taille du tableau
 */
void rapide(int *tab, int size) {
    int wall, current, pivot, tmp;
    if (size < 2) return;

    // On prend comme pivot l element le plus à droite
    pivot = tab[size - 1];
    wall  = current = 0;
    while (current < size) {
        if (tab[current] <= pivot) {
            if (wall != current) {
                tmp=tab[current];
                tab[current]=tab[wall];
                tab[wall]=tmp;
            }
            wall ++;
        }
        current ++;
    }
    rapide(tab, wall - 1);
    rapide(tab + wall - 1, size - wall + 1);
}


int main() {
    int i, tab[20] = {25, 43, 1, 2, 9, 12, 0, 4};
    printf("Avant le trie rapide: \n");
    for(i=0 ; i < SIZE ; i++){
        printf("[%d] | ",tab[i]);
    }

    //traitement
    rapide(tab, SIZE);

    printf("\nApres le trie rapide: \n");
    for(i=0 ; i < SIZE ; i++){
        printf("[%d] | ",tab[i]);
    }
}