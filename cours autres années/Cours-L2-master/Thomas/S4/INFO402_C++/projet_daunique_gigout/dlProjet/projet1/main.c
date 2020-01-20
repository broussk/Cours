#include <stdio.h>
#include "Arbres.h"


int main(int argc, char *argv[])
{
    TArbre arbre;
    int nombre;
    char choix;
    
    do
    {
        printf("\n\n---------------------------------");
        printf("\nMENU\n1- Creer un arbre Vide");
        printf("\n2- Ajouter une valeur");
        printf("\n3- Calculer la Somme des elements");
        printf("\n4- Nombre d'elements de l'arbre");
        printf("\n5- Hauteur de l'arbre");
        printf("\n6- Afficher l'arbre");
        printf("\nAUTRE- Quitter");
        printf("\n---------------------------------\n\n");
        
        fflush( stdin ); // réinitialise le Buffer d'entrée.
        
        scanf("%c", &choix );
                  
        switch (choix)
        {
                case '1' :
                                arbre = NouvelArbreVide() ;
                                printf("arbre cree");
                                break ;
                case '2' :
                                printf("\nEntrer une valeur a ajouter : ");
                                scanf("%d", &nombre );
                                Ajouter( &arbre , nombre );
                                break ;
                case '3' :
                                printf("Somme : %d", Somme( arbre ) );
                                break ;
                case '4' :
                                printf("Il y a %d element(s)", NombreElements( arbre ) );
                                break ;
                case '5' :
                                printf("Hauteur : %d", Hauteur( arbre ) );
                                break ;
                case '6' :
                                Afficher(arbre);
                                break ;
                default :
                                choix = 'q';
                                break ;
        }
    
    }
    while( choix != 'q' );
        
    return (0);
}
