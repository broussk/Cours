#include <stdio.h>

struct Noeud
{
    int valeur ;
    struct Noeud* gauche ;
    struct Noeud* droit ;
};

typedef struct Noeud TNoeud; 
typedef struct Noeud* TArbre; 

//**************************************************************


TArbre NouvelArbreVide( void )
{
    return NULL;
}

//**************************************************************
// Toutes les fonctions sont basées sur la récursivité, parfaite
// ment adaptée aux arbres binaires.
//**************************************************************

void Ajouter( TArbre* arbre , int val )
{
    if( *arbre == NULL )
    {
        *arbre = ( TArbre )malloc( sizeof( TNoeud ) );
        (*arbre)->valeur = val ;
        (*arbre)->gauche = NULL ;
        (*arbre)->droit = NULL ;
    }
    else
    {
        if( val < (*arbre)->valeur )
        {
                Ajouter( &(*arbre)->gauche , val ) ;
        }
        else
        {
                Ajouter( &(*arbre)->droit , val ) ;
        }
    }
}

//**************************************************************

void Afficher( TArbre arbre )
{
    if( arbre != NULL )
    {
        Afficher( arbre->gauche ) ;
        printf( "%d " , arbre->valeur ) ;
        Afficher( arbre->droit ) ;
    }
}

//**************************************************************

int NombreElements( TArbre arbre )
{
    if( arbre == NULL )
    {
        return (0) ;
    }
    else
    {
        return( 1 + NombreElements( arbre->gauche ) + NombreElements( arbre->droit ) ) ;
    }
}

//**************************************************************

int Hauteur( TArbre arbre )
{
    if( arbre == NULL )
    {
        return (0);
    }
    else
    {
    
        int h1,h2 ;
        
        h1 = Hauteur( arbre->gauche ) ;
        h2 = Hauteur( arbre->droit ) ;
        
        if( h1 < h2 )
        {
                return( 1 + h2 ) ;
        }
        else
        {
                return( 1 + h1 ) ;
        }
    }
}

//***************************************************************

int Somme( TArbre arbre )
{
    if( arbre == NULL )
    {
        return (0) ;
    }
    else
    {
        return ( arbre->valeur + Somme( arbre->droit ) + Somme( arbre->gauche ) ) ;
    }
}
