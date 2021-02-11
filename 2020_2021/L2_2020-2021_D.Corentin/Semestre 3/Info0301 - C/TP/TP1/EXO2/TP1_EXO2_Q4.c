#include <stdio.h>

int main(){

    char a, b;
    printf("Merci de saisir un premier caractere: \n");
    scanf("%c", &a);
    printf("Le caractere saisi est \'%c\' et son code ascii est: %d\n", a,a);
    printf("Merci de saisir un deuxieme caractere: \n");
    scanf("%d%*d", &b);
    scanf("%c", &b);
    printf("Le caractere saisi est \'%c\' et son code ascii est: %d", b,b);


    return 0;

}