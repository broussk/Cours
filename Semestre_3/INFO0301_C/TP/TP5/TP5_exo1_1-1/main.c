#include <stdio.h>
#include <stdlib.h>
#define taille 9999

int main()
{
    int nb,nb1, i=0,j, tailleBin,cpt0=0,cpt1=0;
    int bin[taille],bin2[taille];
    printf("Saisissez un entier positif :");
    scanf("%d",&nb);
    nb1=nb;
    do{
        bin[i]=nb1%2;
        nb1=nb1/2;
        i++;
    }while(nb1!=0);
    tailleBin=i;
    printf("Votre nombre %d est ecrit en binaire en %d chiffres : ",nb,tailleBin);
    for (j=tailleBin-1;j>=0;j--){
        printf("%d",bin[j]);
        if(bin[j]==0){
            cpt0++;
        }
        else{
            cpt1++;
        }
    }
    printf(" il y a %d de 0 et %d de 1 \n",cpt0,cpt1);
    return 0;
}
