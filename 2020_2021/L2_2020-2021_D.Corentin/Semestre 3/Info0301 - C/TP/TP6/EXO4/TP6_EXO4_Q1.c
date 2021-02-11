#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void tri_bulle(int* tab){
    int i, inc = 0, swap = 1;

    while (swap == 1) {
        swap = 0;
        inc++;
        for (i = 0;i < MAX - inc; i++) {
            if (tab[i]>tab[i+1]){
                swap = 1;
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
            }
        }
    }
}

void affichage(int* tab){
    int i;
    for (i = 0; i < MAX; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int main(){
    int i;
    int tab[MAX];
    srand(time(NULL));

    for (i = 0; i < MAX; i++){
        tab[i] = rand() % 21;
    }

    printf("Avant tri: \n");
    affichage(tab);
    tri_bulle(tab);
    printf("Apres tri: \n");
    affichage(tab);

    return 0;
}