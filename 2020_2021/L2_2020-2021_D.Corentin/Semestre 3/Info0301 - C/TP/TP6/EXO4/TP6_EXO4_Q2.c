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

void analyse(const int* tab, int* p, int* i){
    int k;
    int cpt_pair = 0;
    int cpt_impair = 0;
    for (k = 0; k < MAX; k++){
        if(tab[k] % 2 == 0){
            p[cpt_pair] = tab[k];
            cpt_pair++;
        } else {
            i[cpt_impair] = tab[k];
            cpt_impair++;
        }
    }
    tri_bulle(p);
    tri_bulle(i);
    printf("Valeurs paires: \n");
    affichage(p);
    printf("Valeurs impaires: \n");
    affichage(i);
}




int main(){
    int k;
    int tab[MAX], P[MAX] = {0}, I[MAX] = {0};
    srand(time(NULL));

    for (k = 0; k < MAX; k++){
        tab[k] = rand() % 21;
    }

    printf("Tableau initiale: \n");
    affichage(tab);
    analyse(tab, P, I);


    return 0;
}