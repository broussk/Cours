/*
 * TONNELLE Nathan
 * 11-09-2020
 * 09-10-2020
*/

#include "cellule.h"

void initCellule(cellule *cell, int id_sommet, int poidsParam){
    cell->sommet = id_sommet;
    cell->precedant = NULL;
    cell->successeur = NULL;
    initArete(cell->areteCellule, cell, poidsParam);
}