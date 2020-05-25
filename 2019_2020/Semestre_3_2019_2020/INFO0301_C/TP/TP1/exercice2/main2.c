#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Merci de saisir un premier caractere : ");
    scanf("%c",&c);
    printf("Le caractere saisi est \'%c\' est son code ascii est %d",c,c);
    return 0;
}
