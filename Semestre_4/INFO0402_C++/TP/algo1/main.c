#include <stdio.h>

int main( )
{
    //initialisation des variables usuelles
    int taille, i, j;

    //titre du programme
    printf("Calcul du maximum de 2 images binaires\n");

    //initialisation des matrices carrées
    printf("entrez une taille des matrice carree\n");
    scanf("%d",&taille);
    int M1[taille][taille],M2[taille][taille],M3[taille][taille];

    //initialisation de la matrice M1
    printf("entrez les valeurs de la matrice M1\n");
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            printf("M1[%d][%d] =",i,j);
            scanf("%d",&M1[i][j]);
        }
    }

    //initilisation de la matrice M2
    printf("entrez les valeurs de la matrice M2\n");
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            printf("M2[%d][%d] =",i,j);
            scanf("%d",&M2[i][j]);
        }
    }

    //affichage de la matrice M1
    printf("affichage matrice M1 :\n");
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            printf("%d",M1[i][j]);
        }
        printf("\n");
    }

    //affichage de la matrice M2
    printf("affichage matrice M2 : \n");
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            printf("%d",M2[i][j]);
        }
        printf("\n");
    }

    //calcul du maximum des 2 images
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            if (M1[i][j]==0 && M2[i][j]==0)
            {
                M3[i][j]=0;
            }
            else
            {
                M3[i][j]=1;
            }
        }
    }

    //affichage de la matrice M3
    printf("affichage matrice M3 : \n");
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            printf("%d   ",M3[i][j]);
        }
        printf("\n");
    }

    //fin
    return 0;
}
