#ifndef __SOMMET__H__
#define __SOMMET__H__
#include <stdio.h>
#include <stdlib.h>
#include "COULEUR.h"
#include "cellule.h"

// Définition de la structure Sommet
typedef struct Sommet Sommet;
struct Sommet{
    COULEUR c;
    int id;
    int distance;
    struct Sommet *pere;
    int debut; 
    int fin;

};

// Prototypes des méthodes

void init_sommet(Sommet *s);
void afficher_sommet(Sommet *s);

#endif // !__SOMMET__H__
