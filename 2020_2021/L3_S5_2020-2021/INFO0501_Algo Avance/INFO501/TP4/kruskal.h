/*
 * TONNELLE Nathan
 * 16-10-2020
*/

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "arete.h"
#include "graphe.h"

//génère l'arbre couvrant de poids minimal avec un tableau
arete** generer_acpm_kruskal_tableau(arete** t);

//affiche l'arbre généré
//void afficherAcpm();
//génère l'arbre couvrant de poids minimal avec les ensembles
//ensemble generer_acpm_kruskal_ensemble();

#endif //KRUSKAL_H