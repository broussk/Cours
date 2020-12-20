/*
 * TONNELLE Nathan
 * 16-10-2020
*/

#ifndef TAS_H
#define TAS_H

#include "arete.h"

typedef struct tas tas;
struct tas{
  arete *parent;
  arete *gauche;
  arete *droite;

};

//initialise un tas max a partir d'un tableau de sorte à ce que ces éléments soient structurés sous forme de tas max
tas* initialiser_tas(arete **t, int size);
//entasse l’élément d’indice i afin de rétablir la propriété de tas ;
void entasser_max(tas *tasIn,int i);
//détruit un tas en libérant les ressources mémoires
void detruire_tas(tas *tasIn, int size);
//trie le tableau d'arêtes
void tri(tas *tasIn, int n);
//affiche le tas
void afficher_tas(tas *tasIn);

#endif //TAS_H