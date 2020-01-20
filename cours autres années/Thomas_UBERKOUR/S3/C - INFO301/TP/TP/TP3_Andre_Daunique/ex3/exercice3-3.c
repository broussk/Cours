#include <stdio.h>

void main(){

    /*init*/
    int max,i,cube;


    /*commande*/
    printf(" Donnez votre entier \n");
    scanf("%d",&max);
    for(i=1;i<=max;i++)
    {
        cube=i*i*i;
        printf("%d^3 = %d \n",i,cube);
    }


}