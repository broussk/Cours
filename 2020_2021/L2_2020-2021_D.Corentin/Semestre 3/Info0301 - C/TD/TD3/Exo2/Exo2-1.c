#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 15

int main(){

    int tab[max];
    int i;
    float total;

    total = 0;
    srand(time(NULL));

    for(i = 0; i < max ; i++){
        *(tab + i) = rand() % 21;
        printf("%d ", *(tab + i));
        total += *(tab+i);
    }


    printf("La moyenne est: %f", (total/max));

    return 0;
}
