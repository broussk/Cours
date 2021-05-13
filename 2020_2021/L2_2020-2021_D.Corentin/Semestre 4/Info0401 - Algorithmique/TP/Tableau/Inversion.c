#include <stdio.h>

#define MAX 20

int main(){

    int tab[MAX], i, tmp, size, *p1, *p2;

    do{
        printf("Entrez une taille <%d: \n", MAX);
        scanf("%d", &size);
    } while (size < 0 || size > MAX);



    for(i = 0; i < size; i++){
        printf("tab[%d]: ", i);
        scanf("%d", (tab+i));
    }


    printf("\nTableau normal: \n");
    for(i = 0; i < size; i++){
        printf("[%d] | ", *(tab+i));
    }

    for(i = 0; i < size / 2; i++){
        p1 = (tab+i);
        p2= (tab+size-i-1);

        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
    }

    printf("\nTableau inverse: \n");
    for(i = 0; i < size; i++){
        printf("[%d] | ", *(tab+i));
    }

    return 0;
}