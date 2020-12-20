/*
 * TONNELLE Nathan
 * 11-09-2020
*/

#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include "cellule.h"

typedef struct liste{
    struct cellule *precedant;
    struct cellule *tete;
}liste;

void initialiser_liste(liste *l);
void detruire_liste(liste *l);
void inserer(liste *l, struct cellule *c);
void afficher_liste(liste *l);
struct cellule* rechercher(liste *l, int id_s);
void supprimer(liste *l, struct cellule *c);

#endif //LISTE_H