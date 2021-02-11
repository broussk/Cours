#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main(void){
    int size, i;
    complex* tab = NULL;

    do {
        printf("Entrez le nombre de complexe a stocker: ");
        scanf("%d", &size);
    } while (size <= 0);

    tab = (complex*) malloc(size * sizeof(complex));

    for (i = 0; i < size; i++){
        printf("C%d: \n", i);
        tab[i] = lecture_complex();
    }

    for (i = 0; i < size; i++){
        printf("C%d: mod(c%d) = %.2lf | arg(c%d) = %.2lf \n",i, i, Module_C(tab[i]), i , Argument_C(tab[i]));
    }

    return 0;
}