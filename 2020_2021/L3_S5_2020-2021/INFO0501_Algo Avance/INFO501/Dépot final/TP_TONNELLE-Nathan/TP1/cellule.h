/*
 * TONNELLE Nathan
 * 11-09-2020
*/

#ifndef CELLULE_H
#define CELLULE_H

#include <stdio.h>

typedef struct cellule cellule;
struct cellule
{
    int sommet;
    cellule *precedant;
    cellule *successeur;
};

void initCellule(cellule *cell, int id_sommet);

#endif //CELLULE_H