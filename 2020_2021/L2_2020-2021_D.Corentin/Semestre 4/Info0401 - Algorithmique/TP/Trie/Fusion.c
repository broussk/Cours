#include <stdio.h>

#define SIZE_A 8
#define SIZE_B 11

int main() {

    //Variables
    int a[SIZE_A] = {0, 1, 2, 4, 5, 8, 9, 512};
    int b[SIZE_B] = {3, 4, 5, 6, 8, 10, 11, 42, 65, 89, 101};
    int fullLength = SIZE_A + SIZE_B;
    int res[fullLength];
    int i, aIndex, bIndex;

    //Affichage tableau 1
    printf("Tableau 1:\n");
    for (i = 0; i < SIZE_A; i++){
        printf("[%d] | ", a[i]);
    }
    printf("\n");

    //Affichage tableau 2
    printf("Tableau 2:\n");
    for (i = 0; i < SIZE_A; i++){
        printf("[%d] | ", b[i]);
    }
    printf("\n");

    //Traitement
    for (i = 0, aIndex = 0, bIndex = 0; i < fullLength; i++) {
        if (aIndex >= SIZE_A ) {
            res[i] = b[bIndex];
            bIndex ++;
        } else if (bIndex >= SIZE_B) {
            res[i] = a[aIndex];
            aIndex ++;
        } else if (a[aIndex] > b[bIndex]) {
            res[i] = b[bIndex];
            bIndex++;
        } else {
            res[i] = a[aIndex];
            aIndex++;
        }
    }

    //Affichage final
    printf("\nApres trie fusion:\n");
    for (i = 0; i < fullLength; i++){
        printf("[%d] | ", res[i]);
    }

    return 0;
}