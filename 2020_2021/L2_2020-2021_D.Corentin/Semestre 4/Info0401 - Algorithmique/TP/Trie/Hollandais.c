#include <stdio.h>

#define SIZE 9



int main() {
    //Bleu = 1 | Blanc = 2 | Rouge = 3
    int tab[SIZE] = {1, 3, 2, 2, 3, 1, 2, 3, 1};
    int x, i = 0, j = 0, k = SIZE, temp;

    //Affichage avant
    printf("Avant trie Hollandais : \n");
    for(x = 0 ; x < SIZE ; x++){
        printf("[%d] | ",tab[x]);
    }
    printf("\n");

    //Tri
    while(j<=k){
        if(tab[j]==2){
            j++;
        }
        else if(tab[j]==1){
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j++;
        }
        else{
            temp = tab[j];
            tab[j] = tab[k];
            tab[k] = temp;
            k--;
        }
    }

    //Affichage
    printf("Apres trie Hollandais : \n");
    for(x = 0 ; x < SIZE ; x++) {
        printf("[%d] | ", tab[x]);
    }

    return 0;
}