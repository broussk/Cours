#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int main(){

    int tab[MAX];
    int i;

    srand(time(NULL));

    for (i=0; i<MAX; i++){
        tab[i] = rand() % 101;
        printf("ind[%d]: %d\n",i, tab[i]);
    }
    return 0;

}
