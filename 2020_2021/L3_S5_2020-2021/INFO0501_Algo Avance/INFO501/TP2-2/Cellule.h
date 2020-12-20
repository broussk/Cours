/*
 * TONNELLE Nathan
 * 11-09-2020
*/

#ifndef CELLULE_H
#define CELLULE_H

#include <stdio.h>

typedef struct Cellule Cellule;
struct Cellule
{
    int sommet;
    Cellule *precedant;
    Cellule *successeur;
};

void initCellule(Cellule *cell, int id_sommet);

#endif //CELLULE_H