/*
 * TONNELLE Nathan
 * 09-10-2020
 * 16-10-2020
*/

#ifndef ARETE_H
#define ARETE_H

#include <stdio.h>
#include "cellule.h"
#include "graphe.h"

typedef struct arete arete;
struct arete
{
    struct cellule *sommetCelluleOrigine;
    struct cellule *sommetCelluleExtremite;
    int poids;
};

//initialise une arête de cellDebut à cellFin, de poids poidsParam
void initArete(arete *art, struct cellule *cellDebut, int poidsParam);
//récupère la liste des aretes dans le graphe à partir des listes d'adjacences et les remets dans le tableau int passé en param
void aretesGrapheListeAdjacence(int *arts, graphe *g);
//récupère la liste des aretes dans le graphe à partir de la matrice d'adjacences et les remets dans le tableau int passé en param
void aretesGrapheMatriceAdjacence(int *arts, graphe *g);
//tri par insertion
void triInsertion(arete **t,int size);

#endif //ARETE_H