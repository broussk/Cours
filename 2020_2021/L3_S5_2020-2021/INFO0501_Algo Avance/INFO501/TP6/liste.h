/*
 * TONNELLE Nathan
 * 06-11-2020
*/

#ifndef LISTE_CHAINEE
#define LISTE_CHAINEE

#include <stdio.h>
#include "cellule.h"

typedef struct Liste{
    Cellule *precedant;
    Cellule *tete;
    int taille;
}Liste;

void initialiser_liste(Liste *l);
//void detruire_liste(Liste *l);
void inserer(Liste *l, Cellule *c);
void afficher_liste(Liste *l);
Cellule* rechercher(Liste *l, char chaine[27]);
void supprimer(Liste *l, char chaine[27]);

#endif //LISTE_CHAINEE