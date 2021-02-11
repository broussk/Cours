#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10

int main(){

    int i, same;
    int tab[max], tab2[max];

    same = 0;

    srand(time(NULL));

    for (i=0; i<max; i++){
        tab[i] = rand() % 11;
        tab2[i] = rand() % 11;
    }


    printf("Tab1: \n");
    for (i=0; i<max; i++){
        printf("%d ", tab[i]);
    }

    printf("\nTab2: \n");
    for (i=0; i<max; i++){
        printf("%d ", tab2[i]);
    }

    for (i=0; i<max; i++){
        if(tab[i] != tab2[i]){
            same = 1;
            break;
        }
    }

    if(same==0){
        printf("\nLes deux tableaux sont identiques.");
    } else{
        printf("\nLes deux tableaux ne sont pas identiques.");
    }

    return 0;

}
