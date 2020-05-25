#include <stdio.h>

void main(){

    /*init*/
    int max,i,j;


    /*commande*/
    printf(" Donnez votre entier \n");
    scanf("%d",&max);
    for(i=0;i<=max;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%d",i+j-(i-1));
        }
        printf("\n");
    }


}