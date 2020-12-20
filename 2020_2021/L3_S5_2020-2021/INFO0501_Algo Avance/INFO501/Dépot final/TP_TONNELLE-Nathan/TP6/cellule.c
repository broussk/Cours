/*
 * TONNELLE Nathan
 * 06-11-2020
*/

#include "cellule.h"

void initCellule(Cellule *cell, char chaine[27]){
    for(int i=0; chaine[i] != '\0'; i++){
        cell->chaine[i] = chaine[i];
    }
    cell->chaine[26] = '\0';
    cell->precedant = NULL;
    cell->successeur = NULL;
}