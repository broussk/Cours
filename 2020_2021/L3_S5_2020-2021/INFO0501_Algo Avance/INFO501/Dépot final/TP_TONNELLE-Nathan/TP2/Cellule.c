/*
 * TONNELLE Nathan
 * 11-09-2020
*/

#include "Cellule.h"

void initCellule(Cellule *cell, int id_sommet){
    cell->sommet = id_sommet;
    cell->precedant = NULL;
    cell->successeur = NULL;
}