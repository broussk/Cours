/*
 * TONNELLE Nathan
 * 11-09-2020
*/

#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include "Cellule.h"

typedef struct Liste{
    Cellule *precedant;
    Cellule *tete;
}Liste;

void initialiser_liste(Liste *l);
void detruire_liste(Liste *l);
void inserer(Liste *l, Cellule *c);
void afficher_liste(Liste *l);
Cellule* rechercher(Liste *l, int id_s);
void supprimer(Liste *l, Cellule *c);

#endif //LISTE_H