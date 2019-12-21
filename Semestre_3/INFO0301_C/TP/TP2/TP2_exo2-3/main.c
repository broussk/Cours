#include <stdio.h>
#include <stdlib.h>

int main()
{
    long i;
    printf("ecrivez un entier long :");
    scanf("%d",&i);
    if(i<0){
        i=i*-1;
    }
    printf("La valeur absolue de votre chiffre est : %d",i);
    return 0;
}
