/*
 * TONNELLE Nathan
 * 11-09-2020
 * 09-10-2020
*/

#ifndef CELLULE_H
#define CELLULE_H

#include <stdio.h>
#include "arete.h"

typedef struct cellule cellule;
struct cellule
{
    int sommet;
    cellule *precedant;
    cellule *successeur;
    struct arete *areteCellule;
};

void initCellule(cellule *cell, int id_sommet, int poidsParam);

#endif //CELLULE_H