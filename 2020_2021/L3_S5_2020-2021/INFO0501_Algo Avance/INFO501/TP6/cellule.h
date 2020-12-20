/*
 * TONNELLE Nathan
 * 06-11-2020
*/

#ifndef CELLULE_H
#define CELLULE_H

#include <stdio.h>

typedef struct Cellule Cellule;
struct Cellule
{
    char chaine[27];
    Cellule *precedant;
    Cellule *successeur;
};

void initCellule(Cellule *cell, char chaine[27]);

#endif //CELLULE_H