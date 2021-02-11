#include <stdio.h>
int main()
{
    char c1, c2;
    printf("Merci de saisir le caractère 1 : ");
    scanf("%c%*c", &c1);
    printf("Le caractère 1 = %c (codeascii=%d)\n", c1, c1);
    printf("Merci de saisir le caractère 2 : ");
    scanf("%c%*c", &c2);
    printf("Le caractère 2 = %c (codeascii=%d)\n", c2, c2);
    return (0);
}