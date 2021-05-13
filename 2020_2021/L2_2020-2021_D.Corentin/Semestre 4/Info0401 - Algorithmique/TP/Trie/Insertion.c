#include <stdio.h>

#define SIZE 10

int main() {
    int i, j, tmp, tab[20] = {10,5,8,9,3,4,6,1,2,7};

    //Affichage
    printf("Avant le trie insertion_rec: \n");
    for(i=0 ; i < SIZE ; i++){
        printf("[%d] | ",tab[i]);
    }

    //traitement
    for(i=0; i< SIZE; i++){
        j = i;
        while (j > 0 && tab[j-1] > tab[j]) {
            tmp = tab[j];
            tab[j] = tab[j-1];
            tab[j-1] = tmp;
            j--;
        }
    }

    //Affichage
    printf("\nApres le trie insertion_rec: \n");
    for(i=0 ; i < SIZE ; i++){
        printf("[%d] | ",tab[i]);
    }
}