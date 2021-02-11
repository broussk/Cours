#include <stdio.h>
int main()
{
    char c1, c2, tmp;
    printf("Merci de saisir le caractère 1 : ");
    scanf("%c", &c1);
    scanf("%c", &tmp);
    printf("Le caractère 1 = %c (code ascii=%d)\n",c1, c1);
    printf("Merci de saisir le caractère 2 : ");
    scanf("%c", &c2);
    scanf("%c", &tmp);
    printf("Le caractère 2 = %c (code ascii=%d)\n",c2, c2);
    return (0);
}