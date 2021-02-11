#include <stdio.h>

int main(){
    long a;

    printf("Enrez un nombre: \n");
    scanf("%ld", &a);

    printf("La valeur absolue de %ld est %ld \n", a, (a < 0 ? -a : a));
}