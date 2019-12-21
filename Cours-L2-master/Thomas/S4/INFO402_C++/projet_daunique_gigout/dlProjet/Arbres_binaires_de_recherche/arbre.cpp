
#include <iostream>
#include <stdio.h>
#include <cassert>
using namespace std;

#include "arbre.h"


Arbre::Arbre()
{
    racine = VIDE;
}

Arbre::Arbre(Noeud *n)
{
    racine = n;
}

void Arbre::videArbre()
{
    racine = racine->videSousArbre();
}

bool Arbre::vide()
{
    if(racine == VIDE) return true;
    else return false;
}

int Arbre::hauteur()
{
    if( vide() ) return 0;
    else return (*racine).hauteur();
}

int Arbre::cardinal()
{
	if( vide() )
		return 0;
	else
		return racine->cardinal();
}


int Arbre::etiquette()
{
    if( vide() ){
        cerr<<endl<<"a.etiquette : arbre binaire vide !"<<endl;
        return 0;
    }
    else return (*racine).etiquette();
}

void Arbre::insertion(int nb)
{
    if( vide() )
        racine = new Noeud(nb);
    else
        racine->insertion(nb);
}

bool Arbre::appartient(int nb)
{
    if( vide() )
        return false;
    else 
        return( racine->appartient(nb) );
}

Noeud *Arbre::recherche(int nb)
{
    if( vide() )
        return VIDE;
    else
        return( racine->recherche(nb) );
}

Noeud *Arbre::recherche_pere(int nb)
{
    if( vide() )
        return VIDE;
    else
        if(racine->fils_gauche() != VIDE && racine->etiquette_fg() == nb)
            return racine;
        else
            if(racine->fils_droit() != VIDE && racine->etiquette_fd() == nb)
                return racine;
            else
                return (racine->recherche_pere(nb));
}

int Arbre::max()
{
    if( vide() ){
        cerr<<endl<<"a.max() : arbre binaire vide !"<<endl;
        return 0;
    }
    else
        return( racine->max() );
}

int Arbre::min()
{
    if( vide() ){
        cerr<<endl<<"a.min() : arbre binaire vide !"<<endl;
        return 0;
    }
    else
        return( racine->min() );
}

void Arbre::supprime(int nb)
{
    if( vide() )
        cerr<<endl<<"a.supprime("<<nb<<") : arbre vide !"<<endl;
    else

        if (racine->etiquette() == nb)
            if (racine->fils_gauche() == VIDE && racine->fils_droit() == VIDE) {
                delete racine;
                racine = VIDE;
            } else
                racine->supprime_racine();
        else
            racine->supprime(nb);

}

void Arbre::affiche_arbre()
{
    if( vide() )
        cout<<"arbre binaire vide !";
    else
        racine->affiche_sous_arbre();
}

void Arbre::affiche_arbre_1()
{
    if( vide() )
        cout<<"arbre binaire vide !";
    else
        racine->affiche_sous_arbre_1();
}

ostream& operator<<(ostream& o, Arbre a)
{
    if( a.vide() )
        o<<"arbre binaire vide !";
    else
        o<<*(a.racine);
    return o;
}

