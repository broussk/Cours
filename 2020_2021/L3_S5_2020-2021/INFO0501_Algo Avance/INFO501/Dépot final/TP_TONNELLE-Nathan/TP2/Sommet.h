/*
 * TONNELLE Nathan
 * 25-09-2020
*/

#ifndef SOMMET_H
#define SOMMET_H
#include "COULEUR.h"

typedef struct Sommet Sommet;
struct Sommet{
    COULEUR couleur;
    int id;
    int distance;
    Sommet *pere;
};

//initialise un Sommet BLANC, vide, égal au point 0
void initialiserSommet(Sommet*);
//affiche l'id du Sommet
void afficherSommet(Sommet*);

#endif //SOMMET_H