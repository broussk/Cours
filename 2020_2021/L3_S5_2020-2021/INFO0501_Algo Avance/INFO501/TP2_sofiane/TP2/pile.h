#ifndef __PILE__H__
#define __PILE__H__
#include "sommet.h"
#include "file.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Definition d'une pile*/
typedef struct Pile{
    int value;
    struct Pile *suivant;
}Pile;

/* Prototypes des fonctions */

Pile *initialiser_pile();
bool pile_vide(Pile *p);
Pile *empiler(Pile *p,Sommet *s);
Pile *detruire_pile(Pile *p);
void afficher_pile(Pile *p);
Pile *depiler(Pile *p);
int sommet(Pile *p);
int taille_pile(Pile *p);
bool pile_pleine(Pile *p);
#endif // !__FILE__H__

