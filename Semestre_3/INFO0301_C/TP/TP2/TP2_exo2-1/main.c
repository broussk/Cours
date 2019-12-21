#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i1,i2,max;
    printf("Ecrivez le premier chiffre : ");
    scanf("%d",&i1);
    printf("Ecrivez le deuxieme chiffre : ");
    scanf("%d",&i2);
    max=(i1<i2)?i2:i1;
    printf("Le max est : %d",max);
    return 0;
}
