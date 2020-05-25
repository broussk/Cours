//
// Created by Nathan TONNELLE on 14/01/2020.
//

#include <stdio.h>
#define TAILLEMAX 255

int main()
{
    int t1[TAILLEMAX],t2[TAILLEMAX];
    int max, i, taille;
    printf("Entrez une taille de tableau");
    scanf("%d",&taille);
    printf("Vous allez entrez les valeurs de chaque case du tableau : ");
    for(i=0;i<taille;i++)
    {
        printf("Case [%d] : ",i);
        scanf("%d",&t1[i]);
    }
    //affichage tableau
    for(i=0;i<taille;i++)
    {
        printf("case [%d]= %d",i, t1[i]);
    }
}