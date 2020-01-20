#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i1;
    printf("Ecrivez un entier quelconque : ");
    scanf("%d",&i1);
    if(i1%2==0){
        printf("Votre chiffre est pair !");
    }
    else{
        printf("Votre chiffre est impaire !");
    }
    return 0;
}
