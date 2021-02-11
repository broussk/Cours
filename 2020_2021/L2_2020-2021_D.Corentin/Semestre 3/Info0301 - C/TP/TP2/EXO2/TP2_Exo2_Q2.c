#include <stdio.h>

int main(){

    int a;

    printf("Entrez un premier nombre: \n");
    scanf("%d", &a);

    a % 2 == 0 ? printf("C'est un nombre pair !\n") : printf("C'est un nombre impair !\n");

    return 0;
}