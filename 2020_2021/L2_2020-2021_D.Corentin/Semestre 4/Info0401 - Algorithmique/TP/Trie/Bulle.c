#include <stdio.h>

int main() {
    int tab[10], i, j, tmp, size, finish = 1;

    do {
        printf("Entrez une taille <20\n");
        scanf("%d", &size);
    } while (size <= 0);

    for (i = 0; i < size; i++){
        printf("tab[%d]: ", i);
        scanf("%d", &tab[i]);
    }

    printf("Avant trie a bulle:\n");
    for (i = 0; i < size; i++){
        printf("[%d] | ", tab[i]);
    }
    printf("\n");

    while (finish){
        finish = 0;
        for (j = 0; j < size-1; j++){
            if(tab[j] > tab[j+1]){
                tmp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = tmp;

                finish = 1;
            }
        }
    }

    printf("\nApres trie a bulle:\n");
    for (i = 0; i < size; i++){
        printf("[%d] | ", tab[i]);
    }

    return 0;
}
