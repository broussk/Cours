#include <stdio.h>

int main(){

    int a,b, max;

    printf("Entrez un premier nombre: \n");
    scanf("%d", &a);
    printf("Entrez un deuxoeme nombre: \n");
    scanf("%d", &b);

    max = a > b ? a : b;

    printf("Le maximum est: %d\n", max);

    return 0;
}