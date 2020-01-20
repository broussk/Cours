#include <stdio.h>

int main()
{
    /*déclaration*/
    long perimetre,aire,r=25.2,pi=3.14;

    /*instruction*/
    /*calcul préalable*/
    perimetre=2*pi*r;
    aire=pi*(r*r);

    /*affichage*/
    printf("Le perimetre d'un cercle de rayon %ld est %ld; son aire est %ld",r,perimetre,aire);

    return(0);


}
