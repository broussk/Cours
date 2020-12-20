/*
 * TONNELLE Nathan
 * 25-09-2020
*/

#ifndef SOMMET_H
#define SOMMET_H
#include "COULEUR.h"

typedef struct sommet sommet;
struct sommet{
    COULEUR couleur;
    int id;
    int distance;
    sommet *pere;
};

//initialise un sommet BLANC, vide, égal au point 0
void initialiserSommet(sommet*);
//affiche l'id du sommet
void afficherSommet(sommet*);

#endif //SOMMET_H